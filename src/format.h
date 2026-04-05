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

#ifndef FORMAT_H
#define FORMAT_H

#include <stddef.h>

/**
 * @file format.h
 * @author Maury Markowitz
 * @date 5 April 2024
 * @brief Format specification parsing and application for PRINT USING and USING$ functions
 *
 * This module provides comprehensive support for BASIC formatting specifications across
 * multiple BASIC dialects: HP TimeShare BASIC IMAGE format, MS-BASIC-80, and QBasic.
 * It parses format strings into structured format_spec_t arrays and applies them to
 * values to produce formatted output strings.
 *
 * The module supports:
 * - HP TimeShare IMAGE: nD, nA, nX, S modifiers, carriage control (+, -, #)
 * - MS-BASIC-80: #, ., +, -, $, *, &, ^^^, %, _ formats
 * - QBasic: !, \...\, &, **, $$, **$, ^^^^ formats
 *
 * Format strings are parsed into an array of format_spec_t structures, which can
 * then be applied to value arrays using format_apply_values() to produce formatted output.
 *
 */

/**
 * @enum format_dialect_t
 * @brief BASIC dialect identifiers for format string parsing
 */
typedef enum {
    DIALECT_HP,           /**< HP TimeShare BASIC IMAGE format */
    DIALECT_MSBASIC80,    /**< MS-BASIC-80 format */
    DIALECT_QBASIC        /**< QBasic extended format */
} format_dialect_t;

/**
 * @enum format_spec_type_t
 * @brief Individual format specification types
 */
typedef enum {
    SPEC_TYPE_STRING,     /**< String field (A, !, \...\, & formats) */
    SPEC_TYPE_INTEGER,    /**< Integer numeric field (D format) */
    SPEC_TYPE_FIXED,      /**< Fixed-point numeric field (D.D format) */
    SPEC_TYPE_FLOAT,      /**< Floating-point numeric field (...E format) */
    SPEC_TYPE_LITERAL,    /**< Literal string from format (quoted or unquoted) */
    SPEC_TYPE_SPACING,    /**< Spacing directive (X, TAB, LIN, SPA) */
    SPEC_TYPE_SEPARATOR   /**< Format separator (comma) */
} format_spec_type_t;

/**
 * @enum int_format_variant_t
 * @brief Integer format variants for QBasic compatibility
 */
typedef enum {
    INT_NORMAL,           /**< # placeholder */
    INT_ASTERISK,         /**< ** asterisk fill */
    INT_DOLLAR,           /**< $$ dollar prefix */
    INT_ASTERISK_DOLLAR   /**< **$ combined */
} int_format_variant_t;

/**
 * @enum str_format_variant_t
 * @brief String format variants across dialects
 */
typedef enum {
    STR_FIXED_WIDTH,      /**< nA or n\...\  format */
    STR_VARIABLE,         /**< & format (QBasic) */
    STR_FIRST_CHAR        /**< ! format (QBasic) */
} str_format_variant_t;

/**
 * @enum sign_placement_t
 * @brief Sign positioning for numeric formats
 */
typedef enum {
    SIGN_NONE,            /**< No sign */
    SIGN_FLOATING_LEFT,   /**< S before digits, floats to first non-blank */
    SIGN_FIXED_LEFT,      /**< S before digits, fixed position */
    SIGN_FIXED_RIGHT,     /**< S after digits, fixed position */
    SIGN_TRAILING         /**< - after digits (QBasic) */
} sign_placement_t;

/**
 * @struct format_spec_t
 * @brief Individual format specification
 */
typedef struct {
    format_spec_type_t type;
    
    union {
        /* SPEC_TYPE_STRING */
        struct {
            str_format_variant_t variant;
            int width;                /**< Number of characters to output */
        } string;
        
        /* SPEC_TYPE_INTEGER */
        struct {
            int_format_variant_t variant;
            int width;                /**< Number of # placeholders */
            int has_sign;             /**< 1 if sign present */
            sign_placement_t sign_pos;
            int has_comma;            /**< 1 if thousands separator present */
            int percent_overflow;     /**< 1 if % indicator present */
        } integer;
        
        /* SPEC_TYPE_FIXED */
        struct {
            int_format_variant_t variant;
            int before_decimal;       /**< Digits before decimal */
            int after_decimal;        /**< Digits after decimal */
            int has_sign;
            sign_placement_t sign_pos;
            int has_comma;
            int percent_overflow;
        } fixed;
        
        /* SPEC_TYPE_FLOAT */
        struct {
            int_format_variant_t variant;
            int before_decimal;
            int after_decimal;
            int exponent_width;       /**< Usually 4 for E+xx */
            int has_sign;
            sign_placement_t sign_pos;
            int spaces_after_e;       /**< HP: spaces between E and exponent */
        } floating;
        
        /* SPEC_TYPE_LITERAL */
        struct {
            char *text;               /**< Malloc'd literal text */
            int length;
        } literal;
        
        /* SPEC_TYPE_SPACING */
        struct {
            enum {
                SPACE_BLANKS,         /**< X - blank spaces */
                SPACE_TAB,            /**< TAB(x) */
                SPACE_LIN,            /**< LIN(x) */
                SPACE_SPA             /**< SPA(x) */
            } variant;
            int count;                /**< Number of spaces/lines/column */
            int suppress_cr;          /**< For LIN: suppress carriage return */
        } spacing;
        
    } detail;
    
} format_spec_t;

/**
 * @struct format_string_t
 * @brief Complete parsed format string
 */
typedef struct {
    format_spec_t *specs;
    int num_specs;
    int capacity;
    
    /* Carriage control (HP IMAGE) */
    int suppress_cr;                  /**< -,  at start */
    int suppress_lf;                  /**< +,  at start */
    int suppress_both;                /**< #,  at start */
    
    /* Dialect used */
    format_dialect_t dialect;
    
    /* Grouping information (HP repetition factors) */
    int *group_starts;                /**< Indices where groups start */
    int *group_sizes;                 /**< Sizes of groups */
    int num_groups;
    
} format_string_t;

/**
 * @struct format_value_t
 * @brief Value to be formatted
 */
typedef struct {
    int type;                         /**< 0 = numeric, 1 = string */
    union {
        double numeric;
        char *string;                 /**< Pointer to string value */
    } value;
} format_value_t;

/* Public API functions */

/**
 * @brief Parse a format string into a format_string_t structure
 *
 * Automatically detects BASIC dialect based on format characteristics and applies
 * the appropriate parser (HP TimeShare, MS-BASIC-80, or QBasic).
 *
 * @param format_str The format string to parse
 * @param dialect_hint Suggested dialect (can be overridden by format detection)
 * @return Allocated format_string_t on success, or NULL on parse error
 */
format_string_t* format_parse(const char *format_str, format_dialect_t dialect_hint);

/**
 * @brief Apply format specifications to a list of values
 *
 * Produces a formatted output string by applying each format specification to
 * the corresponding value. Handles format cycling if more values than specs.
 * The returned string is allocated and must be freed by the caller.
 *
 * @param fmt Parsed format string structure
 * @param values Array of values to format
 * @param num_values Number of values in array
 * @return Malloc'd output string containing formatted result (caller must free)
 *         Returns NULL on error
 */
char* format_apply_values(const format_string_t *fmt,
                         const format_value_t *values,
                         int num_values);

/**
 * @brief Free a parsed format string structure and all allocated memory
 *
 * Safely deallocates a format_string_t and all nested allocations (specs array,
 * literal strings, group arrays, etc.).
 *
 * @param fmt Format string to free
 */
void format_free(format_string_t *fmt);

/**
 * @brief Detect BASIC dialect from format string characteristics
 *
 * Analyzes the format string for dialect-specific markers:
 * - HP: D, A, S modifiers
 * - QBasic: !, &, ^, *, \, carriage control operators
 * - MS-BASIC-80: #, ., +, -, $, %, &, ^^^
 *
 * @param format_str The format string to analyze
 * @return Detected format_dialect_t (defaults to DIALECT_MSBASIC80 if ambiguous)
 */
format_dialect_t format_detect_dialect(const char *format_str);

/**
 * @brief Create a single format_value_t from a numeric value
 *
 * Convenience function for building format_value_t arrays to pass
 * to format_apply_values().
 *
 * @param num The numeric value (double precision)
 * @return format_value_t with numeric type set
 */
format_value_t format_value_numeric(double num);

/**
 * @brief Create a single format_value_t from a string value
 *
 * Convenience function for building format_value_t arrays to pass
 * to format_apply_values(). The string is referenced, not copied.
 *
 * @param str The string value (pointer, not copied)
 * @return format_value_t with string type set
 */
format_value_t format_value_string(const char *str);

#endif /* FORMAT_H */
