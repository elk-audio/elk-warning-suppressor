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

#define DO_PRAGMA_(x) _Pragma (#x)
#define DO_PRAGMA(x) DO_PRAGMA_(x)

#if defined(__clang__)
#define ELK_PUSH_WARNING DO_PRAGMA(clang diagnostic push)
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_PUSH_WARNING DO_PRAGMA(GCC diagnostic push)
#elif defined(_MSC_VER)
#define ELK_PUSH_WARNING // TODO
#endif

#if defined(__clang__)
#define ELK_POP_WARNING DO_PRAGMA(clang diagnostic pop)
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_POP_WARNING DO_PRAGMA(GCC diagnostic pop)
#elif defined(_MSC_VER)
#define ELK_POP_WARNING // TODO
#endif

// -Woverloaded-virtual
#if defined(__clang__)
#define ELK_DISABLE_OVERLOADED_VIRTUAL DO_PRAGMA(clang diagnostic ignored "-Woverloaded-virtual")
#elif defined(__GNUC__) || defined(__GNUG__)
#define ELK_DISABLE_OVERLOADED_VIRTUAL DO_PRAGMA(GCC diagnostic ignored "-Woverloaded-virtual")
#elif defined(_MSC_VER)
#define ELK_DISABLE_EXTRA // TODO
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
#define ELK_DISABLE_UNUSED_PARAMETER // TODO
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
#define ELK_DISABLE_DEPRECATED // TODO
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