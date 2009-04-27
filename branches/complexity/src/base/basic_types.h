// Copyright (c) 2008, Jacob Burnim (jburnim@cs.berkeley.edu)
//
// This file is part of CREST, which is distributed under the revised
// BSD license.  A copy of this license can be found in the file LICENSE.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See LICENSE
// for details.

#ifndef BASE_BASIC_TYPES_H__
#define BASE_BASIC_TYPES_H__

#include <cstddef>

namespace crest {

typedef int id_t;
typedef int branch_id_t;
typedef unsigned int function_id_t;
typedef unsigned int var_t;
typedef long long int value_t;
typedef unsigned long int addr_t;


// Virtual "branch ID's" used to represent function calls and returns.

static const branch_id_t kCallId = -1;
static const branch_id_t kReturnId = -2;


// Operator enums and utility function.

namespace ops {
enum compare_op_t { EQ   = 0,  NEQ  = 1,
                    GT   = 2,  LE   = 3,  LT   = 4,  GE = 5,
                    S_GT = 6,  S_LE = 7,  S_LT = 8,  S_GE = 9 };

enum binary_op_t { ADD,          SUBTRACT,    MULTIPLY,
                   DIV,          S_DIV,
                   MOD,          S_MOD,
                   SHIFT_L,      SHIFT_R,     S_SHIFT_R,
                   BITWISE_AND,  BITWISE_OR,  BITWISE_XOR,
                   CONCAT,       EXTRACT,     CONCRETE };

enum unary_op_t { NEGATE, LOGICAL_NOT, BITWISE_NOT, CAST };

}  // namespace ops

using ops::compare_op_t;
using ops::binary_op_t;
using ops::unary_op_t;

compare_op_t NegateCompareOp(compare_op_t op);


// C numeric types.

namespace types {
enum type_t {
	BOOLEAN = -1,
  U_CHAR = 0,       CHAR = 1,
  U_SHORT = 2,      SHORT = 3,
  U_INT = 4,        INT = 5,
  U_LONG = 6,       LONG = 7,
  U_LONG_LONG = 8,  LONG_LONG = 9,
  STRUCT = 10
};
}
using types::type_t;

extern const char* kMinValueStr[];
extern const char* kMaxValueStr[];

extern const value_t kMinValue[];
extern const value_t kMaxValue[];

extern const size_t kSizeOfType[];

}  // namespace crest

#endif  // BASE_BASIC_TYPES_H__
