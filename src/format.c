#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "format.h"

/* Helper functions for parsing */
static int parse_integer(const char *str, int *pos);
static int parse_repetition_factor(const char *str, int *pos);
static format_spec_t parse_spec_from_char(char c, const char *str, int *pos, format_dialect_t dialect);
static int is_format_terminator(char c);

/* HP format parsing helpers */
static format_string_t* parse_hp_format(const char *format_str);
static format_spec_t parse_hp_numeric_spec(const char *str, int *pos);
static format_spec_t parse_hp_string_spec(const char *str, int *pos);

/* MS-BASIC-80 format parsing helpers */
static format_string_t* parse_msbasic80_format(const char *format_str);

/* QBasic format parsing helpers */
static format_string_t* parse_qbasic_format(const char *format_str);

/* Value formatting helpers */
static char* format_string_value(const format_spec_t *spec, const char *value);
static char* format_integer_value(const format_spec_t *spec, double value);
static char* format_fixed_value(const format_spec_t *spec, double value);
static char* format_float_value(const format_spec_t *spec, double value);

/* Utility macros */
#define ALLOC_SPECS(n) ((format_spec_t*)malloc(sizeof(format_spec_t) * (n)))
#define REALLOC_SPECS(p, n) ((format_spec_t*)realloc((p), sizeof(format_spec_t) * (n)))

/* ============================================================================
 * Public API Functions
 * ========================================================================== */

format_dialect_t format_detect_dialect(const char *format_str)
{
    if (!format_str || *format_str == '\0')
        return DIALECT_MSBASIC80;
    
    /* Look for HP-specific indicators */
    for (int i = 0; format_str[i] != '\0'; i++) {
        /* HP uses S for sign positioning (not + or -) */
        if (format_str[i] == 'S' && (i == 0 || !isdigit(format_str[i-1])))
            return DIALECT_HP;
        
        /* HP uses D for digit placeholder (not #) */
        if (format_str[i] == 'D' && (i == 0 || isdigit(format_str[i-1]) || format_str[i-1] == ','))
            return DIALECT_HP;
        
        /* HP uses A for character (not provided in MS/QBasic) */
        if (format_str[i] == 'A')
            return DIALECT_HP;
        
        /* QBasic-specific: ^ for exponential (not E or D) */
        if (format_str[i] == '^')
            return DIALECT_QBASIC;
        
        /* QBasic-specific: ! for first char, & for variable string */
        if (format_str[i] == '!' || format_str[i] == '&')
            return DIALECT_QBASIC;
        
        /* QBasic-specific: ** or $$ decorators */
        if (format_str[i] == '*' && i + 1 < strlen(format_str) && format_str[i+1] == '*')
            return DIALECT_QBASIC;
        
        if (format_str[i] == '$' && i + 1 < strlen(format_str) && format_str[i+1] == '$')
            return DIALECT_QBASIC;
        
        /* Backslash string format is QBasic */
        if (format_str[i] == '\\')
            return DIALECT_QBASIC;
        
        /* Plus/minus outside of parentheses at start suggests QBasic */
        if (i == 0 && (format_str[i] == '+' || format_str[i] == '-'))
            return DIALECT_QBASIC;
    }
    
    /* Default to MS-BASIC-80 */
    return DIALECT_MSBASIC80;
}

format_string_t* format_parse(const char *format_str, format_dialect_t dialect_hint)
{
    if (!format_str) {
        fprintf(stderr, "format_parse: NULL format string\n");
        return NULL;
    }
    
    /* Auto-detect if hint suggests default */
    format_dialect_t dialect = format_detect_dialect(format_str);
    
    switch (dialect) {
        case DIALECT_HP:
            return parse_hp_format(format_str);
        case DIALECT_MSBASIC80:
            return parse_msbasic80_format(format_str);
        case DIALECT_QBASIC:
            return parse_qbasic_format(format_str);
        default:
            return parse_msbasic80_format(format_str);
    }
}

format_value_t format_value_numeric(double num)
{
    format_value_t v;
    v.type = 0;  /* numeric */
    v.value.numeric = num;
    return v;
}

format_value_t format_value_string(const char *str)
{
    format_value_t v;
    v.type = 1;  /* string */
    v.value.string = (char*)str;
    return v;
}

void format_free(format_string_t *fmt)
{
    if (!fmt) return;
    
    if (fmt->specs) {
        for (int i = 0; i < fmt->num_specs; i++) {
            if (fmt->specs[i].type == SPEC_TYPE_LITERAL && fmt->specs[i].detail.literal.text) {
                free(fmt->specs[i].detail.literal.text);
            }
        }
        free(fmt->specs);
    }
    
    if (fmt->group_starts) free(fmt->group_starts);
    if (fmt->group_sizes) free(fmt->group_sizes);
    
    free(fmt);
}

char* format_apply_values(const format_string_t *fmt,
                         const format_value_t *values,
                         int num_values)
{
    if (!fmt || !values || num_values < 1) {
        fprintf(stderr, "DEBUG: format_apply_values called with empty params\n");
        return NULL;
    }
    
    fprintf(stderr, "DEBUG: format_apply_values: fmt has %d specs, %d values\n", fmt->num_specs, num_values);
    
    /* Allocate output buffer - will be reallocated as needed */
    size_t output_size = 1024;
    char *output = (char*)malloc(output_size);
    if (!output) return NULL;
    
    size_t output_pos = 0;
    int spec_idx = 0;
    int value_idx = 0;
    
    /* Process all specs, cycling through values as needed */
    while (spec_idx < fmt->num_specs) {
        format_spec_t *spec = &fmt->specs[spec_idx];
        char *formatted = NULL;
        size_t formatted_len = 0;
        
        fprintf(stderr, "DEBUG: Processing spec %d type=%d\n", spec_idx, spec->type);
        
        switch (spec->type) {
            case SPEC_TYPE_LITERAL:
                formatted = spec->detail.literal.text;
                formatted_len = spec->detail.literal.length;
                fprintf(stderr, "DEBUG: LITERAL: %s (len=%zu)\n", formatted, formatted_len);
                break;
            
            case SPEC_TYPE_STRING:
                fprintf(stderr, "DEBUG: STRING spec\n");
                if (value_idx < num_values && values[value_idx].type == 1) {
                    formatted = format_string_value(spec, values[value_idx].value.string);
                    formatted_len = formatted ? strlen(formatted) : 0;
                    fprintf(stderr, "DEBUG: STRING value: %s (len=%zu)\n", formatted, formatted_len);
                    value_idx++;
                }
                break;
            
            case SPEC_TYPE_INTEGER:
            case SPEC_TYPE_FIXED:
            case SPEC_TYPE_FLOAT:
                fprintf(stderr, "DEBUG: NUMERIC spec type=%d\n", spec->type);
                if (value_idx < num_values && values[value_idx].type == 0) {
                    if (spec->type == SPEC_TYPE_INTEGER) {
                        formatted = format_integer_value(spec, values[value_idx].value.numeric);
                    } else if (spec->type == SPEC_TYPE_FIXED) {
                        formatted = format_fixed_value(spec, values[value_idx].value.numeric);
                    } else {
                        formatted = format_float_value(spec, values[value_idx].value.numeric);
                    }
                    formatted_len = formatted ? strlen(formatted) : 0;
                    fprintf(stderr, "DEBUG: NUMERIC value: %s (len=%zu)\n", formatted, formatted_len);
                    value_idx++;
                }
                break;
            
            case SPEC_TYPE_SPACING:
                /* Add spacing to output */
                for (int i = 0; i < spec->detail.spacing.count; i++) {
                    formatted_len++;
                }
                fprintf(stderr, "DEBUG: SPACING %d\n", spec->detail.spacing.count);
                break;
            
            case SPEC_TYPE_SEPARATOR:
                /* Commas are typically not output in formatted specs */
                fprintf(stderr, "DEBUG: SEPARATOR\n");
                break;
        }
        
        /* Append to output buffer */
        if (formatted_len > 0) {
            /* Resize buffer if needed */
            while (output_pos + formatted_len >= output_size) {
                output_size *= 2;
                char *new_output = (char*)realloc(output, output_size);
                if (!new_output) {
                    free(output);
                    return NULL;
                }
                output = new_output;
            }
            
            if (spec->type == SPEC_TYPE_SPACING) {
                /* Add spaces */
                for (int i = 0; i < spec->detail.spacing.count; i++) {
                    output[output_pos++] = ' ';
                }
            } else if (formatted) {
                memcpy(&output[output_pos], formatted, formatted_len);
                output_pos += formatted_len;
            }
        }
        
        /* Free formatted string if it wasn't a literal or spacing */
        if (formatted && spec->type != SPEC_TYPE_LITERAL && spec->type != SPEC_TYPE_SPACING) {
            free(formatted);
        }
        
        spec_idx++;
        
        /* Cycle back to beginning if we've consumed all specs but have more values */
        if (spec_idx >= fmt->num_specs && value_idx < num_values) {
            spec_idx = 0;
        }
    }
    
    /* Null-terminate output */
    if (output_pos >= output_size) {
        output_size++;
        char *new_output = (char*)realloc(output, output_size);
        if (!new_output) {
            free(output);
            return NULL;
        }
        output = new_output;
    }
    output[output_pos] = '\0';
    
    fprintf(stderr, "DEBUG: Returning formatted output: %s\n", output);
    return output;
}

/* ============================================================================
 * FORMAT PARSING IMPLEMENTATIONS
 * ========================================================================== */

/**
 * Parse HP TimeShare BASIC IMAGE FORMAT
 * Format: nA, nX, nD, nD.mD, nD.mDE, with S for sign, literals in quotes
 */
static format_string_t* parse_hp_format(const char *format_str)
{
    if (!format_str) return NULL;
    
    fprintf(stderr, "DEBUG: Parsing HP format: %s\n", format_str);
    
    format_string_t *fmt = (format_string_t*)malloc(sizeof(format_string_t));
    if (!fmt) return NULL;
    
    fmt->specs = ALLOC_SPECS(100);
    fmt->num_specs = 0;
    fmt->capacity = 100;
    fmt->dialect = DIALECT_HP;
    fmt->suppress_cr = 0;
    fmt->suppress_lf = 0;
    fmt->suppress_both = 0;
    fmt->group_starts = NULL;
    fmt->group_sizes = NULL;
    fmt->num_groups = 0;
    
    int pos = 0;
    
    /* Check for carriage control modifiers at beginning */
    if (format_str[0] == '+' && format_str[1] == ',') {
        fmt->suppress_lf = 1;
        pos = 2;
    } else if (format_str[0] == '-' && format_str[1] == ',') {
        fmt->suppress_cr = 1;
        pos = 2;
    } else if (format_str[0] == '#' && format_str[1] == ',') {
        fmt->suppress_both = 1;
        pos = 2;
    }
    
    /* Parse format specifications */
    fprintf(stderr, "DEBUG: Starting parse at pos %d\n", pos);
    while (format_str[pos] != '\0') {
        char c = format_str[pos];
        fprintf(stderr, "DEBUG: At pos %d, char='%c'\n", pos, c);
        
        if (isspace(c)) {
            pos++;
            continue;
        }
        
        if (c == ',') {
            /* Format separator */
            format_spec_t sep;
            sep.type = SPEC_TYPE_SEPARATOR;
            
            if (fmt->num_specs >= fmt->capacity) {
                fmt->capacity *= 2;
                format_spec_t *new_specs = REALLOC_SPECS(fmt->specs, fmt->capacity);
                if (!new_specs) {
                    format_free(fmt);
                    return NULL;
                }
                fmt->specs = new_specs;
            }
            fmt->specs[fmt->num_specs++] = sep;
            fprintf(stderr, "DEBUG: Added SEPARATOR spec\n");
            pos++;
            continue;
        }
        
        if (c == '/') {
            /* Line break */
            format_spec_t br;
            br.type = SPEC_TYPE_SPACING;
            br.detail.spacing.variant = SPACE_BLANKS;
            br.detail.spacing.count = 2;  /* CR+LF representation */
            br.detail.spacing.suppress_cr = 0;
            
            if (fmt->num_specs >= fmt->capacity) {
                fmt->capacity *= 2;
                format_spec_t *new_specs = REALLOC_SPECS(fmt->specs, fmt->capacity);
                if (!new_specs) {
                    format_free(fmt);
                    return NULL;
                }
                fmt->specs = new_specs;
            }
            fmt->specs[fmt->num_specs++] = br;
            fprintf(stderr, "DEBUG: Added LINEBREAK spec\n");
            pos++;
            continue;
        }
        
        if (c == '"') {
            /* Quoted literal string */
            pos++;
            int lit_start = pos;
            while (format_str[pos] != '"' && format_str[pos] != '\0') {
                pos++;
            }
            
            format_spec_t lit;
            lit.type = SPEC_TYPE_LITERAL;
            lit.detail.literal.length = pos - lit_start;
            lit.detail.literal.text = (char*)malloc(lit.detail.literal.length + 1);
            if (!lit.detail.literal.text) {
                format_free(fmt);
                return NULL;
            }
            strncpy(lit.detail.literal.text, &format_str[lit_start], lit.detail.literal.length);
            lit.detail.literal.text[lit.detail.literal.length] = '\0';
            
            if (fmt->num_specs >= fmt->capacity) {
                fmt->capacity *= 2;
                format_spec_t *new_specs = REALLOC_SPECS(fmt->specs, fmt->capacity);
                if (!new_specs) {
                    format_free(fmt);
                    return NULL;
                }
                fmt->specs = new_specs;
            }
            fmt->specs[fmt->num_specs++] = lit;
            fprintf(stderr, "DEBUG: Added LITERAL spec: %s\n", lit.detail.literal.text);
            
            if (format_str[pos] == '"') pos++;
            continue;
        }
        
        /* Check for numeric spec with repetition factor or other numeric-starting spec */
        if (isdigit(c) || c == 'D' || c == 'S' || c == '.' || c == 'A' || c == 'X') {
            /* Try to parse as numeric first (handles leading digits like "5D") */
            if (isdigit(c) || c == 'D' || c == 'S' || c == '.') {
                format_spec_t spec = parse_hp_numeric_spec(format_str, &pos);
                if (fmt->num_specs >= fmt->capacity) {
                    fmt->capacity *= 2;
                    format_spec_t *new_specs = REALLOC_SPECS(fmt->specs, fmt->capacity);
                    if (!new_specs) {
                        format_free(fmt);
                        return NULL;
                    }
                    fmt->specs = new_specs;
                }
                fmt->specs[fmt->num_specs++] = spec;
                fprintf(stderr, "DEBUG: Added NUMERIC spec type=%d\n", spec.type);
            } else if (c == 'A' || c == 'X') {
                format_spec_t spec = parse_hp_string_spec(format_str, &pos);
                if (fmt->num_specs >= fmt->capacity) {
                    fmt->capacity *= 2;
                    format_spec_t *new_specs = REALLOC_SPECS(fmt->specs, fmt->capacity);
                    if (!new_specs) {
                        format_free(fmt);
                        return NULL;
                    }
                    fmt->specs = new_specs;
                }
                fmt->specs[fmt->num_specs++] = spec;
                fprintf(stderr, "DEBUG: Added STRING/SPACING spec type=%d\n", spec.type);
            }
        } else {
            fprintf(stderr, "DEBUG: Unknown char '%c', skipping\n", c);
            pos++;
        }
    }
    
    fprintf(stderr, "DEBUG: HP format parse complete, %d specs created\n", fmt->num_specs);
    return fmt;
}

/**
 * Parse HP numeric specification: [repetition_factor]D[.D][E] with optional S modifiers  
 * Examples: "D" (1 digit), "5D" (5 digits), "5D.2D" (5 before, 2 after decimal), "S4D" (sign + 4)
 */
static format_spec_t parse_hp_numeric_spec(const char *str, int *pos)
{
    format_spec_t spec;
    memset(&spec, 0, sizeof(spec));
    
    int rep_factor = 1;  /* Repetition factor (e.g., 5 in "5D") */
    int before_decimal = 0;
    int after_decimal = 0;
    int has_sign = 0;
    int has_e = 0;
    sign_placement_t sign_pos = SIGN_NONE;
    
    fprintf(stderr, "  DEBUG: parse_hp_numeric_spec starting at pos %d, char='%c'\n", *pos, str[*pos]);
    
    /* Check for leading S (sign before digits) */
    if (str[*pos] == 'S') {
        has_sign = 1;
        sign_pos = SIGN_FLOATING_LEFT;
        (*pos)++;
        fprintf(stderr, "  DEBUG: Found leading S\n");
    }
    
    /* Parse repetition factor (leading digits before format character) */
    /* HP format is: [rep_factor]A or [rep_factor]D where rep_factor is optional */
    /* So "5D" = 5 digit positions, "D" = 1 digit position */
    if (isdigit(str[*pos])) {
        rep_factor = 0;
        while (isdigit(str[*pos])) {
            rep_factor = rep_factor * 10 + (str[*pos] - '0');
            (*pos)++;
        }
        fprintf(stderr, "  DEBUG: Found repetition factor %d\n", rep_factor);
    }
    
    /* Now we MUST see D's */
    if (str[*pos] != 'D') {
        /* No D found, this isn't a valid numeric spec. Return empty spec */
        fprintf(stderr, "  DEBUG: ERROR - Expected D after repetition factor, found '%c'\n", str[*pos]);
        spec.type = 0;  /* Empty/error spec */
        return spec;
    }
    
    /* Use rep_factor for digit count; consume all consecutive D's */
    before_decimal = rep_factor;  /* The rep_factor IS the field width */
    while (str[*pos] == 'D') {
        (*pos)++;  /* Skip the D's */
    }
    fprintf(stderr, "  DEBUG: Set before_decimal=%d from rep_factor\n", before_decimal);
    
    /* Check for decimal point */
    if (str[*pos] == '.') {
        fprintf(stderr, "  DEBUG: Found decimal point\n");
        (*pos)++;
        
        /* Parse repetition factor after decimal (if any) */
        int after_rep = 1;
        if (isdigit(str[*pos])) {
            after_rep = 0;
            while (isdigit(str[*pos])) {
                after_rep = after_rep * 10 + (str[*pos] - '0');
                (*pos)++;
            }
            fprintf(stderr, "  DEBUG: Found repetition factor after decimal: %d\n", after_rep);
        }
        
        /* Use rep factor for after-decimal field width; consume all consecutive D's */
        if (str[*pos] == 'D') {
            after_decimal = after_rep;
            while (str[*pos] == 'D') {
                (*pos)++;  /* Skip the D's */
            }
            fprintf(stderr, "  DEBUG: Set after_decimal=%d from rep_factor\n", after_decimal);
        }
    }
    
    /* Check for trailing S (sign after digits) */
    if (str[*pos] == 'S' && !has_sign) {
        has_sign = 1;
        sign_pos = SIGN_FIXED_RIGHT;
        (*pos)++;
        fprintf(stderr, "  DEBUG: Found trailing S\n");
    }
    
    /* Check for exponential E */
    if (str[*pos] == 'E') {
        has_e = 1;
        (*pos)++;
        fprintf(stderr, "  DEBUG: Found exponential E\n");
    }
    
    /* Determine spec type based on what we found */
    if (has_e) {
        spec.type = SPEC_TYPE_FLOAT;
        spec.detail.floating.before_decimal = before_decimal;
        spec.detail.floating.after_decimal = after_decimal;
        spec.detail.floating.exponent_width = 4;
        spec.detail.floating.has_sign = has_sign;
        spec.detail.floating.sign_pos = sign_pos;
        spec.detail.floating.variant = INT_NORMAL;
        fprintf(stderr, "  DEBUG: Created FLOAT spec: before=%d after=%d\n", before_decimal, after_decimal);
    } else if (after_decimal > 0) {
        spec.type = SPEC_TYPE_FIXED;
        spec.detail.fixed.before_decimal = before_decimal;
        spec.detail.fixed.after_decimal = after_decimal;
        spec.detail.fixed.has_sign = has_sign;
        spec.detail.fixed.sign_pos = sign_pos;
        spec.detail.fixed.variant = INT_NORMAL;
        spec.detail.fixed.has_comma = 0;
        spec.detail.fixed.percent_overflow = 0;
        fprintf(stderr, "  DEBUG: Created FIXED spec: before=%d after=%d\n", before_decimal, after_decimal);
    } else if (before_decimal > 0) {
        spec.type = SPEC_TYPE_INTEGER;
        spec.detail.integer.width = before_decimal;
        spec.detail.integer.has_sign = has_sign;
        spec.detail.integer.sign_pos = sign_pos;
        spec.detail.integer.variant = INT_NORMAL;
        spec.detail.integer.has_comma = 0;
        spec.detail.integer.percent_overflow = 0;
        fprintf(stderr, "  DEBUG: Created INTEGER spec: width=%d\n", before_decimal);
    }
    
    return spec;
}

/**
 * Parse HP string specification: nA or nX
 */
static format_spec_t parse_hp_string_spec(const char *str, int *pos)
{
    format_spec_t spec;
    memset(&spec, 0, sizeof(spec));
    spec.type = SPEC_TYPE_STRING;
    
    int count = 0;
    char spec_char = str[*pos];
    
    /* Parse repetition factor */
    while (isdigit(str[*pos])) {
        count = count * 10 + (str[*pos] - '0');
        (*pos)++;
    }
    
    if (count == 0) count = 1;
    
    if (str[*pos] == 'A') {
        spec.detail.string.variant = STR_FIXED_WIDTH;
        spec.detail.string.width = count;
        (*pos)++;
    } else if (str[*pos] == 'X') {
        spec.type = SPEC_TYPE_SPACING;
        spec.detail.spacing.variant = SPACE_BLANKS;
        spec.detail.spacing.count = count;
        (*pos)++;
    }
    
    return spec;
}

/**
 * Parse MS-BASIC-80 format string 
 * (Placeholder - basic implementation)
 */
static format_string_t* parse_msbasic80_format(const char *format_str)
{
    if (!format_str) return NULL;
    
    format_string_t *fmt = (format_string_t*)malloc(sizeof(format_string_t));
    if (!fmt) return NULL;
    
    fmt->specs = ALLOC_SPECS(100);
    fmt->num_specs = 0;
    fmt->capacity = 100;
    fmt->dialect = DIALECT_MSBASIC80;
    fmt->suppress_cr = 0;
    fmt->suppress_lf = 0;
    fmt->suppress_both = 0;
    fmt->group_starts = NULL;
    fmt->group_sizes = NULL;
    fmt->num_groups = 0;
    
    /* TODO: Implement MS-BASIC-80 format parsing */
    
    return fmt;
}

/**
 * Parse QBasic format string
 * (Placeholder - basic implementation)
 */
static format_string_t* parse_qbasic_format(const char *format_str)
{
    if (!format_str) return NULL;
    
    format_string_t *fmt = (format_string_t*)malloc(sizeof(format_string_t));
    if (!fmt) return NULL;
    
    fmt->specs = ALLOC_SPECS(100);
    fmt->num_specs = 0;
    fmt->capacity = 100;
    fmt->dialect = DIALECT_QBASIC;
    fmt->suppress_cr = 0;
    fmt->suppress_lf = 0;
    fmt->suppress_both = 0;
    fmt->group_starts = NULL;
    fmt->group_sizes = NULL;
    fmt->num_groups = 0;
    
    /* TODO: Implement QBasic format parsing */
    
    return fmt;
}

/* ============================================================================
 * VALUE FORMATTING FUNCTIONS
 * ========================================================================== */

static char* format_string_value(const format_spec_t *spec, const char *value)
{
    if (!spec || !value) return NULL;
    
    char *result = NULL;
    int len = strlen(value);
    
    if (spec->detail.string.variant == STR_FIXED_WIDTH) {
        int width = spec->detail.string.width;
        result = (char*)malloc(width + 1);
        if (!result) return NULL;
        
        if (len >= width) {
            strncpy(result, value, width);
            result[width] = '\0';
        } else {
            /* Left-justify: copy string then pad with spaces */
            strncpy(result, value, len);
            for (int i = len; i < width; i++) {
                result[i] = ' ';
            }
            result[width] = '\0';
        }
    }
    
    return result;
}

static char* format_integer_value(const format_spec_t *spec, double value)
{
    if (!spec) return NULL;
    
    char *result = (char*)malloc(128);
    if (!result) return NULL;
    
    long int_val = (long)value;
    int width = spec->detail.integer.width;
    
    if (spec->detail.integer.has_sign) {
        snprintf(result, 128, "%+*ld", width, int_val);
    } else {
        snprintf(result, 128, "%*ld", width, int_val);
    }
    
    return result;
}

static char* format_fixed_value(const format_spec_t *spec, double value)
{
    if (!spec) return NULL;
    
    char *result = (char*)malloc(128);
    if (!result) return NULL;
    
    int before = spec->detail.fixed.before_decimal;
    int after = spec->detail.fixed.after_decimal;
    int width = before + 1 + after;  /* digits + dot + decimals */
    
    if (spec->detail.fixed.has_sign) {
        snprintf(result, 128, "%+*.*f", width, after, value);
    } else {
        snprintf(result, 128, "%*.*f", width, after, value);
    }
    
    return result;
}

static char* format_float_value(const format_spec_t *spec, double value)
{
    if (!spec) return NULL;
    
    char *result = (char*)malloc(128);
    if (!result) return NULL;
    
    int after = spec->detail.floating.after_decimal;
    
    if (spec->detail.floating.has_sign) {
        snprintf(result, 128, "%+.*e", after, value);
    } else {
        snprintf(result, 128, "%.*e", after, value);
    }
    
    return result;
}
