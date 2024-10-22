/*
* Copyright 2017-2023 Elk Audio AB
*
* SUSHI is free software: you can redistribute it and/or modify it under the terms of
* the GNU Affero General Public License as published by the Free Software Foundation,
* either version 3 of the License, or (at your option) any later version.
*
* SUSHI is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
* without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
* PURPOSE. See the GNU Affero General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public License along with
* SUSHI. If not, see http://www.gnu.org/licenses/
*/

/**
* @brief Warning Suppressor
* @Copyright 2017-2023 Elk Audio AB, Stockholm
*/

/**
 * This allows suppressing specific warnings for certain (third-party) includes,
 * in a manner that is compiler-independent.
 * It should work with Clang, GCC, and MSVC (MSVC is untested).
 *
 * Usage example:
 *
 * #include "warning_suppressor.h"
 *
 * ELK_PUSH_WARNING
 * ELK_DISABLE_SHADOW_FIELD
 * #include <JuceHeader.h>
 * ELK_POP_WARNING
 */

#pragma once

#if defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)
#define DO_PRAGMA_(x) _Pragma (#x)
#elif defined(_MSC_VER)
#define DO_PRAGMA_(x) _Pragma (#x)
#endif
#define DO_PRAGMA(x) DO_PRAGMA_(x)

#if defined(__clang__)
#define ELK_PUSH_WARNING DO_PRAGMA(clang diagnostic push)
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_PUSH_WARNING DO_PRAGMA(GCC diagnostic push)
#elif defined(_MSC_VER)
#define ELK_PUSH_WARNING DO_PRAGMA(warning(push))
#endif

#if defined(__clang__)
#define ELK_POP_WARNING DO_PRAGMA(clang diagnostic pop)
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_POP_WARNING DO_PRAGMA(GCC diagnostic pop)
#elif defined(_MSC_VER)
#define ELK_POP_WARNING DO_PRAGMA(warning(pop))
#endif

// -Woverloaded-virtual
#if defined(__clang__)
#define ELK_DISABLE_OVERLOADED_VIRTUAL DO_PRAGMA(clang diagnostic ignored "-Woverloaded-virtual")
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_OVERLOADED_VIRTUAL DO_PRAGMA(GCC diagnostic ignored "-Woverloaded-virtual")
#elif defined(_MSC_VER)
#define ELK_DISABLE_OVERLOADED_VIRTUAL // DO_PRAGMA(warning(disable:))
#endif

// "-Wextra"
#if defined(__clang__)
#define ELK_DISABLE_EXTRA DO_PRAGMA(clang diagnostic ignored "-Wextra")
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_EXTRA DO_PRAGMA(GCC diagnostic ignored "-Wextra")
#elif defined(_MSC_VER)
#define ELK_DISABLE_EXTRA // TODO
#endif

//  "-Wunused-parameter"
#if defined(__clang__)
#define ELK_DISABLE_UNUSED_PARAMETER DO_PRAGMA(clang diagnostic ignored "-Wunused-parameter")
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_UNUSED_PARAMETER DO_PRAGMA(GCC diagnostic ignored "-Wunused-parameter")
#elif defined(_MSC_VER)
#define ELK_DISABLE_UNUSED_PARAMETER DO_PRAGMA(warning(disable:4100))
#endif

// "-Wkeyword-macro"
#if defined(__clang__)
#define ELK_DISABLE_KEYWORD_MACRO DO_PRAGMA(clang diagnostic ignored "-Wkeyword-macro")
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_KEYWORD_MACRO // Doesn't exist
#elif defined(_MSC_VER)
#define ELK_DISABLE_KEYWORD_MACRO // TODO
#endif

// "-Wunused-function"
#if defined(__clang__)
#define ELK_DISABLE_UNUSED_FUNCTION DO_PRAGMA(clang diagnostic ignored "-Wunused-function")
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_UNUSED_FUNCTION DO_PRAGMA(GCC diagnostic ignored "-Wunused-function")
#elif defined(_MSC_VER)
#define ELK_DISABLE_UNUSED_FUNCTION // TODO
#endif

// "-Wextra-semi"
#if defined(__clang__)
#define ELK_DISABLE_EXTRA_SEMI DO_PRAGMA(clang diagnostic ignored "-Wextra-semi")
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_EXTRA_SEMI DO_PRAGMA(GCC diagnostic ignored "-Wextra-semi")
#elif defined(_MSC_VER)
#define ELK_DISABLE_EXTRA_SEMI // TODO
#endif

// "-Wtype-limits"
#if defined(__clang__)
#define ELK_DISABLE_TYPE_LIMITS DO_PRAGMA(clang diagnostic ignored "-Wtype-limits")
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_TYPE_LIMITS DO_PRAGMA(GCC diagnostic ignored "-Wtype-limits")
#elif defined(_MSC_VER)
#define ELK_DISABLE_TYPE_LIMITS // TODO
#endif

// "-Wsign-conversion"
#if defined(__clang__)
#define ELK_DISABLE_SIGN_CONVERSION DO_PRAGMA(clang diagnostic ignored "-Wsign-conversion")
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_SIGN_CONVERSION DO_PRAGMA(GCC diagnostic ignored "-Wsign-conversion")
#elif defined(_MSC_VER)
#define ELK_DISABLE_SIGN_CONVERSION // TODO
#endif

// "-Wzero-as-null-pointer-constant"
#if defined(__clang__)
#define ELK_DISABLE_ZERO_AS_NULL_POINTER_CONSTANT DO_PRAGMA(clang diagnostic ignored "-Wzero-as-null-pointer-constant")
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_ZERO_AS_NULL_POINTER_CONSTANT DO_PRAGMA(GCC diagnostic ignored "-Wzero-as-null-pointer-constant")
#elif defined(_MSC_VER)
#define ELK_DISABLE_ZERO_AS_NULL_POINTER_CONSTANT // TODO
#endif

// "-Wconditional-uninitialized"
#if defined(__clang__)
#define ELK_DISABLE_CONDITIONAL_UNINITIALIZED DO_PRAGMA(clang diagnostic ignored "-Wconditional-uninitialized")
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_CONDITIONAL_UNINITIALIZED // Doesn't exist
#elif defined(_MSC_VER)
#define ELK_DISABLE_CONDITIONAL_UNINITIALIZED // TODO
#endif

// "-Wshorten-64-to-32"
#if defined(__clang__)
#define ELK_DISABLE_SHORTEN_64_TO_32 DO_PRAGMA(clang diagnostic ignored "-Wshorten-64-to-32")
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_SHORTEN_64_TO_32 // Doesn't exist
#elif defined(_MSC_VER)
#define ELK_DISABLE_SHORTEN_64_TO_32 // TODO
#endif

// "-Wshadow-field"
#if defined(__clang__)
#define ELK_DISABLE_SHADOW_FIELD DO_PRAGMA(clang diagnostic ignored "-Wshadow-field")
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_SHADOW_FIELD  // Doesn't exist
#elif defined(_MSC_VER)
#define ELK_DISABLE_SHADOW_FIELD // TODO
#endif

// "-Wpedantic"
#if defined(__clang__)
#define ELK_DISABLE_PEDANTIC DO_PRAGMA(clang diagnostic ignored "-Wpedantic")
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_PEDANTIC DO_PRAGMA(GCC diagnostic ignored "-Wpedantic")
#elif defined(_MSC_VER)
#define ELK_DISABLE_PEDANTIC // TODO
#endif

// "-Wdeprecated-declarations"
#if defined(__clang__)
#define ELK_DISABLE_DEPRECATED_DECLARATIONS DO_PRAGMA(clang diagnostic ignored "-Wdeprecated-declarations")
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_DEPRECATED_DECLARATIONS DO_PRAGMA(GCC diagnostic ignored "-Wdeprecated-declarations")
#elif defined(_MSC_VER)
#define ELK_DISABLE_DEPRECATED_DECLARATIONS // TODO
#endif

// "-Wdeprecated"
#if defined(__clang__)
#define ELK_DISABLE_DEPRECATED DO_PRAGMA(clang diagnostic ignored "-Wdeprecated")
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_DEPRECATED DO_PRAGMA(GCC diagnostic ignored "-Wdeprecated")
#elif defined(_MSC_VER)
#define ELK_DISABLE_DEPRECATED DO_PRAGMA(warning(disable:4996))
#endif

// "-Wunknown-pragmas"
#if defined(__clang__)
#define ELK_DISABLE_UNKNOWN_PRAGMAS DO_PRAGMA(clang diagnostic ignored "-Wunknown-pragmas")
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_UNKNOWN_PRAGMAS DO_PRAGMA(GCC diagnostic ignored "-Wunknown-pragmas")
#elif defined(_MSC_VER)
#define ELK_DISABLE_UNKNOWN_PRAGMAS // TODO
#endif

// "-Wreturn-type"
#if defined(__clang__)
#define ELK_DISABLE_RETURN_TYPE DO_PRAGMA(clang diagnostic ignored "-Wreturn-type")
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_RETURN_TYPE DO_PRAGMA(GCC diagnostic ignored "-Wreturn-type")
#elif defined(_MSC_VER)
#define ELK_DISABLE_RETURN_TYPE // TODO
#endif

// "-Wunused-const-variable"
#if defined(__clang__)
#define ELK_DISABLE_UNUSED_CONST_VARIABLE DO_PRAGMA(clang diagnostic ignored "-Wunused-const-variable")
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_UNUSED_CONST_VARIABLE DO_PRAGMA(GCC diagnostic ignored "-Wunused-const-variable")
#elif defined(_MSC_VER)
#define ELK_DISABLE_UNUSED_CONST_VARIABLE // TODO
#endif

// "-Wreorder"
#if defined(__clang__)
#define ELK_DISABLE_REORDER DO_PRAGMA(clang diagnostic ignored "-Wreorder")
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_REORDER DO_PRAGMA(GCC diagnostic ignored "-Wreorder")
#elif defined(_MSC_VER)
#define ELK_DISABLE_REORDER // TODO
#endif

// "-Wnullability-completeness"
#if defined(__clang__)
#define ELK_DISABLE_NULLABILITY_COMPLETENESS DO_PRAGMA(clang diagnostic ignored "-Wnullability-completeness")
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_NULLABILITY_COMPLETENESS // Doesn't exist
#elif defined(_MSC_VER)
#define ELK_DISABLE_NULLABILITY_COMPLETENESS // TODO
#endif

// "-Wswitch-enum"
#if defined(__clang__)
#define ELK_DISABLE_SWITCH_ENUM DO_PRAGMA(clang diagnostic ignored "-Wswitch-enum")
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_SWITCH_ENUM // Doesn't exist
#elif defined(_MSC_VER)
#define ELK_DISABLE_SWITCH_ENUM // TODO
#endif

// "-Wfloat-equal"
#if defined(__clang__)
#define ELK_DISABLE_FLOAT_EQUAL DO_PRAGMA(clang diagnostic ignored "-Wfloat-equal")
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_FLOAT_EQUAL // Doesn't exist
#elif defined(_MSC_VER)
#define ELK_DISABLE_FLOAT_EQUAL // TODO
#endif

// "C4324 - structure was padded due to alignment specifier"
#if defined(__clang__)
#define ELK_DISABLE_ALIGNMENT_PADDING // Doesn't exist
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_ALIGNMENT_PADDING // Doesn't exist
#elif defined(_MSC_VER)
#define ELK_DISABLE_ALIGNMENT_PADDING DO_PRAGMA(warning(disable:4324))
#endif

// "C4706: assignment within conditional expression"
#if defined(__clang__)
#define ELK_DISABLE_ASSIGNMENT_WITHIN_CONDITIONAL // Doesn't exist
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_ASSIGNMENT_WITHIN_CONDITIONAL // Doesn't exist
#elif defined(_MSC_VER)
#define ELK_DISABLE_ASSIGNMENT_WITHIN_CONDITIONAL DO_PRAGMA(warning(disable:4706))
#endif

// warning C5054: operator '|': deprecated between enumerations of different types
#if defined(__clang__)
#define ELK_DISABLE_DEPRECATED_BETWEEN_ENUMERATIONS // Doesn't exist
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_DEPRECATED_BETWEEN_ENUMERATIONS // Doesn't exist
#elif defined(_MSC_VER)
#define ELK_DISABLE_DEPRECATED_BETWEEN_ENUMERATIONS DO_PRAGMA(warning(disable:5054))
#endif

// warning C4250: inherits via dominance
#if defined(__clang__)
#define ELK_DISABLE_DOMINANCE_INHERITANCE // Doesn't exist
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_DOMINANCE_INHERITANCE // Doesn't exist
#elif defined(_MSC_VER)
#define ELK_DISABLE_DOMINANCE_INHERITANCE DO_PRAGMA(warning(disable:4250))
#endif

// warning C4702: unreachable code
#if defined(__clang__)
#define ELK_DISABLE_UNREACHABLE_CODE // Doesn't exist
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_UNREACHABLE_CODE // Doesn't exist
#elif defined(_MSC_VER)
#define ELK_DISABLE_UNREACHABLE_CODE DO_PRAGMA(warning(disable:4702))
#endif

// warning C4127: conditional expression is constant
#if defined(__clang__)
#define ELK_DISABLE_CONDITIONAL_EXPRESSION_IS_CONSTANT // Doesn't exist
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_CONDITIONAL_EXPRESSION_IS_CONSTANT // Doesn't exist
#elif defined(_MSC_VER)
#define ELK_DISABLE_CONDITIONAL_EXPRESSION_IS_CONSTANT DO_PRAGMA(warning(disable:4127))
#endif

// warning C5232: in C++20 this comparison calls 'name' recursively
#if defined(__clang__)
#define ELK_DISABLE_COMPARISON_CALLS_NAME_RECURSIVELY // Doesn't exist
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_COMPARISON_CALLS_NAME_RECURSIVELY // Doesn't exist
#elif defined(_MSC_VER)
#define ELK_DISABLE_COMPARISON_CALLS_NAME_RECURSIVELY DO_PRAGMA(warning(disable:5232))
#endif

// warning C5204: class has virtual functions, but its trivial destructor is not virtual; instances of objects derived from this class may not be destructed correctly
#if defined(__clang__)
#define ELK_DISABLE_TRIVIAL_DESTRUCTOR_NOT_VIRTUAL // Doesn't exist
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_TRIVIAL_DESTRUCTOR_NOT_VIRTUAL // Doesn't exist
#elif defined(_MSC_VER)
#define ELK_DISABLE_TRIVIAL_DESTRUCTOR_NOT_VIRTUAL DO_PRAGMA(warning(disable:5204))
#endif

// warning C4265: class has virtual functions, but its non-trivial destructor is not virtual; instances of objects derived from this class may not be destructed correctly
#if defined(__clang__)
#define ELK_DISABLE_NON_TRIVIAL_DESTRUCTOR_NOT_VIRTUAL // Doesn't exist
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_NON_TRIVIAL_DESTRUCTOR_NOT_VIRTUAL // Doesn't exist
#elif defined(_MSC_VER)
#define ELK_DISABLE_NON_TRIVIAL_DESTRUCTOR_NOT_VIRTUAL DO_PRAGMA(warning(disable:4265))
#endif

// warning C4244: 'argument': conversion from 'int' to 'float', possible loss of data
#if defined(__clang__)
#define ELK_DISABLE_CONVERSION_FROM_INT_TO_FLOAT // Doesn't exist
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_CONVERSION_FROM_INT_TO_FLOAT // Doesn't exist
#elif defined(_MSC_VER)
#define ELK_DISABLE_CONVERSION_FROM_INT_TO_FLOAT DO_PRAGMA(warning(disable:4244))
#endif

// warning C4267: 'argument': conversion from 'size_t' to 'int', possible loss of data
#if defined(__clang__)
#define ELK_DISABLE_CONVERSION_FROM_SIZE_T_TO_INT // Doesn't exist
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_CONVERSION_FROM_SIZE_T_TO_INT // Doesn't exist
#elif defined(_MSC_VER)
#define ELK_DISABLE_CONVERSION_FROM_SIZE_T_TO_INT DO_PRAGMA(warning(disable:4267))
#endif