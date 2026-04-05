/* Format specification handling for RetroBASIC
 Copyright (C) 2024 Maury Markowitz

 This file is part of RetroBASIC.
 
 RetroBASIC is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2, or (at your option)
 any later version.
 
 RetroBASIC is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with RetroBASIC; see the file COPYING.  If not, write to
 the Free Software Foundation, 59 Temple Place - Suite 330,
 Boston, MA 02111-1307, USA.  */

/**
 * @file format.c
 * @author Maury Markowitz
 * @date 5 April 2024
 * @brief Implementation of BASIC format specification parsing and application
 *
 * This file implements the core formatting engine for RetroBASIC, supporting PRINT USING
 * and USING$ functions across multiple BASIC dialects. It includes:
 *
 * - Dialect detection (HP, MS-BASIC-80, QBasic) based on format characteristics
 * - Parsing of format strings into structured format_spec_t arrays
 * - Application of format specifications to numeric and string values
 * - Dynamic buffer management for output string generation
 * - Support for all standard BASIC format codes and modifiers
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "format.h"

/**
 * @defgroup FormatHelpers Format Parsing Helper Functions
 * @{
 */

/* Helper functions for parsing */
static int parse_integer(const char *str, int *pos);
static int parse_repetition_factor(const char *str, int *pos);
static format_spec_t parse_spec_from_char(char c, const char *str, int *pos, format_dialect_t dialect);
static int is_format_terminator(char c);

/* HP format parsing helpers */
static format_string_t* parse_hp_format(const char *format_str);
/**
 * @brief Parse HP numeric specification: [rep]D[.D][E][S]
 * Examples: "D", "5D", "5D.2D", "S4D", "5D.2DE"
 * @param str Format string
 * @param pos Current position (updated on return)
 * @return Parsed format_spec_t (SPEC_TYPE_INTEGER, FIXED, or FLOAT)
 */
static format_spec_t parse_hp_numeric_spec(const char *str, int *pos);
/**
 * @brief Parse HP string specification: [rep]A or [rep]X
 * Examples: "A", "5A", "10X"
 * @param str Format string
 * @param pos Current position (updated on return)
 * @return Parsed format_spec_t (SPEC_TYPE_STRING or SPACING)
 */
static format_spec_t parse_hp_string_spec(const char *str, int *pos);

/* MS-BASIC-80 format parsing helpers */
/**
 * @brief Parse MS-BASIC-80 format string (placeholder - TODO)
 * @param format_str Format string
 * @return Parsed format_string_t structure
 */
static format_string_t* parse_msbasic80_format(const char *format_str);

/* QBasic format parsing helpers */
/**
 * @brief Parse QBasic format string (placeholder - TODO)
 * @param format_str Format string
 * @return Parsed format_string_t structure
 */
static format_string_t* parse_qbasic_format(const char *format_str);

/* Value formatting helpers */
/**
 * @brief Format a string value according to string format specification
 * @param spec Format specification (SPEC_TYPE_STRING)
 * @param value String value to format
 * @return Malloc'd formatted string (caller must free)
 */
static char* format_string_value(const format_spec_t *spec, const char *value);
/**
 * @brief Format an integer value according to integer format specification
 * @param spec Format specification (SPEC_TYPE_INTEGER)
 * @param value Numeric value to format as integer
 * @return Malloc'd formatted string (caller must free)
 */
static char* format_integer_value(const format_spec_t *spec, double value);
/**
 * @brief Format a fixed-point value according to fixed format specification
 * @param spec Format specification (SPEC_TYPE_FIXED)
 * @param value Numeric value to format with fixed decimals
 * @return Malloc'd formatted string (caller must free)
 */
static char* format_fixed_value(const format_spec_t *spec, double value);
/**
 * @brief Format a floating-point value according to float format specification
 * @param spec Format specification (SPEC_TYPE_FLOAT)
 * @param value Numeric value to format as exponential
 * @return Malloc'd formatted string (caller must free)
 */
static char* format_float_value(const format_spec_t *spec, double value);

/** @} */

/* Utility macros */
#define ALLOC_SPECS(n) ((format_spec_t*)malloc(sizeof(format_spec_t) * (n)))
#define REALLOC_SPECS(p, n) ((format_spec_t*)realloc((p), sizeof(format_spec_t) * (n)))

/* ============================================================================
 * Public API Functions
 * ========================================================================== */

/**
 * Detect BASIC dialect from format string characteristics.
 *
 * Examines the format string for dialect-specific markers:
 * - HP: D, A, S modifiers for numeric/string specs
 * - QBasic: !, &, ^, **, $$, *** operators or backslash strings
 * - MS-BASIC-80: Default if no specific markers found
 *
 * @param format_str The format string to analyze
 * @return Detected format_dialect_t value
 */
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

/**
 * Parse a format string into a format_string_t structure.
 *
 * Automatically detects the BASIC dialect from the format string characteristics
 * and dispatches to the appropriate dialect-specific parser. The returned structure
 * contains an array of format_spec_t entries that can be applied to values.
 *
 * @param format_str The format string to parse (e.g., "5D.2D" for HP)
 * @param dialect_hint Suggested dialect (can be overridden by format detection)
 * @return Allocated format_string_t structure on success, NULL on parse error
 */
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

/**
 * Create a single format_value_t from a numeric value.
 *
 * Convenience function for building format_value_t arrays to pass to
 * format_apply_values(). Sets the type field to 0 (numeric) and stores
 * the double precision floating point value.
 *
 * @param num The numeric value to store (double precision)
 * @return format_value_t with numeric type and value set
 */
format_value_t format_value_numeric(double num)
{
    format_value_t v;
    v.type = 0;  /* numeric */
    v.value.numeric = num;
    return v;
}

/**
 * Create a single format_value_t from a string value.
 *
 * Convenience function for building format_value_t arrays to pass to
 * format_apply_values(). Sets the type field to 1 (string) and stores
 * a pointer to the string value. The string is referenced, not copied.
 *
 * @param str The string value to reference (pointer not copied)
 * @return format_value_t with string type and value set
 */
format_value_t format_value_string(const char *str)
{
    format_value_t v;
    v.type = 1;  /* string */
    v.value.string = (char*)str;
    return v;
}

/**
 * Free a parsed format string structure and all allocated memory.
 *
 * Safely deallocates a format_string_t and all nested allocations, including
 * the specs array, literal strings within specs, and group tracking arrays.
 * Safe to call with NULL pointer.
 *
 * @param fmt Format string structure to free
 */
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

/**
 * Apply format specifications to a list of values, producing formatted output.
 *
 * Iterates through format specifications in the parsed format string and applies
 * each specification to the corresponding value. Handles format cycling (if more
 * values than specs, wraps back to the beginning of the spec list). Manages
 * dynamic buffer allocation and reallocation as output grows.
 *
 * The returned string is malloc'd and must be freed by the caller.
 *
 * @param fmt   Parsed format string structure
 * @param values Array of format_value_t values to format
 * @param num_values Number of values in the array
 * @return Malloc'd output string containing formatted result (caller must free),
 *         or NULL on error (invalid parameters or memory allocation failure)
 */
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
 * Parse HP TimeShare BASIC IMAGE format string.
 *
 * Supports the complete HP IMAGE format specification including:
 * - Carriage control modifiers: +, (suppress LF), -, (suppress CR), #, (suppress both)
 * - Numeric specs: [S]nD[.mD][E][S] for integer, fixed, and floating formats
 * - String specs: nA for character fields, nX for spacing
 * - Literals: quoted strings in double quotes
 * - Separators: commas for format grouping
 * - Line breaks: forward slash (/) for CR/LF
 *
 * @param format_str The HP IMAGE format string to parse
 * @return Allocated format_string_t structure, or NULL on parse error
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
 * Parse HP numeric specification: [S]nD[.mD][E][S]
 *
 * Parses HP numeric format specifications where:
 * - S (optional, leading): Sign modifier (floating left)
 * - n (optional): Repetition factor (field width for D's)
 * - D (required): Digit placeholder character
 * - .mD (optional): Decimal point with repetition factor m and D's
 * - E (optional): Exponential notation indicator
 * - S (optional, trailing): Sign modifier (fixed right)
 *
 * Examples: "D", "5D", "5D.2D", "S4D", "5D.2DE"
 *
 * Creates format_spec_t of type: SPEC_TYPE_INTEGER, FIXED, or FLOAT
 *
 * @param str The format string
 * @param pos Pointer to current position (updated on return)
 * @return Populated format_spec_t with appropriate type and detail fields
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
 * Parse HP string specification: [n]A or [n]X
 *
 * Parses HP string format specifications where:
 * - [n] (optional): Repetition factor (number of characters)
 * - A: Character field (outputs string left-justified, padded with spaces)
 * - X: Spacing/blank field (outputs n spaces)
 *
 * Examples: "A", "5A", "10X"
 *
 * Creates format_spec_t of type: SPEC_TYPE_STRING (for A) or SPEC_TYPE_SPACING (for X)
 *
 * @param str The format string
 * @param pos Pointer to current position (updated on return)
 * @return Populated format_spec_t with STRING or SPACING type
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
 * Parse MS-BASIC-80 format string.
 *
 * This is a placeholder function for MS-BASIC-80 format support.
 * MS-BASIC-80 format specifications include:
 * - #: Digit placeholder
 * - .: Decimal point
 * - +/-: Sign indicators
 * - $: Currency symbol
 * - *: Asterisk fill
 * - &/^^^: String and exponential formats
 * - %, _: Overflow and spacing
 *
 * TODO: Implement full MS-BASIC-80 parsing
 *
 * @param format_str The MS-BASIC-80 format string
 * @return Empty format_string_t structure (not yet implemented)
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
 * Parse QBasic format string.
 *
 * This is a placeholder function for QBasic format support.
 * QBasic format specifications include:
 * - !: First character only (string)
 * - \...\: Fixed-width string field
 * - &: Variable-width string field
 * - #: Digit placeholder
 * - **: Asterisk fill
 * - $$: Dollar prefix currency
 * - ****$: Asterisk fill with dollar
 * - ^^^^: Exponential format (4 carets)
 * - _: Underscore (literal output)
 * - %: Percent separator
 *
 * TODO: Implement full QBasic parsing
 *
 * @param format_str The QBasic format string
 * @return Empty format_string_t structure (not yet implemented)
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

/**
 * Format a string value according to format specification.
 *
 * Formats a string value using the SPEC_TYPE_STRING specification,
 * implementing the HP nA format: outputs the string left-justified in a
 * field of specified width, padded with spaces on the right.
 *
 * Allocates and returns a malloc'd string that must be freed by the caller.
 *
 * @param spec Format specification (must have type SPEC_TYPE_STRING)
 * @param value String value to format
 * @return Malloc'd formatted string (caller must free), or NULL on error
 */
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

/**
 * Format an integer value according to format specification.
 *
 * Formats a numeric value as an integer using the SPEC_TYPE_INTEGER specification,
 * with support for field width and optional sign display. Uses snprintf with
 * appropriate format string based on width and sign requirements.
 *
 * Allocates and returns a malloc'd string that must be freed by the caller.
 *
 * @param spec Format specification (must have type SPEC_TYPE_INTEGER)
 * @param value Numeric value to convert and format
 * @return Malloc'd formatted string (caller must free), or NULL on error
 */
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

/**
 * Format a fixed-point value according to format specification.
 *
 * Formats a numeric value with fixed decimal places using the SPEC_TYPE_FIXED
 * specification (e.g., HP nD.mD format). Displays the specified number of digits
 * before and after the decimal point, with optional sign display.
 *
 * Allocates and returns a malloc'd string that must be freed by the caller.
 *
 * @param spec Format specification (must have type SPEC_TYPE_FIXED)
 * @param value Numeric value to format with fixed decimals
 * @return Malloc'd formatted string (caller must free), or NULL on error
 */
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

/**
 * Format a floating-point value according to format specification.
 *
 * Formats a numeric value in exponential notation using the SPEC_TYPE_FLOAT
 * specification (e.g., HP nD.mDE format). Displays the value in scientific notation
 * with the specified number of significant digits and optional sign display.
 *
 * Allocates and returns a malloc'd string that must be freed by the caller.
 *
 * @param spec Format specification (must have type SPEC_TYPE_FLOAT)
 * @param value Numeric value to format in exponential notation
 * @return Malloc'd formatted string (caller must free), or NULL on error
 */
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
