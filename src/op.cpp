/**********************************************************************************/
/* This file is part of spla project                                              */
/* https://github.com/SparseLinearAlgebra/spla                                    */
/**********************************************************************************/
/* MIT License                                                                    */
/*                                                                                */
/* Copyright (c) 2023 SparseLinearAlgebra                                         */
/*                                                                                */
/* Permission is hereby granted, free of charge, to any person obtaining a copy   */
/* of this software and associated documentation files (the "Software"), to deal  */
/* in the Software without restriction, including without limitation the rights   */
/* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      */
/* copies of the Software, and to permit persons to whom the Software is          */
/* furnished to do so, subject to the following conditions:                       */
/*                                                                                */
/* The above copyright notice and this permission notice shall be included in all */
/* copies or substantial portions of the Software.                                */
/*                                                                                */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     */
/* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       */
/* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    */
/* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         */
/* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  */
/* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  */
/* SOFTWARE.                                                                      */
/**********************************************************************************/

#include <core/top.hpp>
#include <iostream>

#include "spla/op.hpp"

#include <algorithm>
#include <cmath>

namespace spla {

    ref_ptr<OpUnary> IDENTITY_INT;
    ref_ptr<OpUnary> IDENTITY_UINT;
    ref_ptr<OpUnary> IDENTITY_FLOAT;
    ref_ptr<OpUnary> AINV_INT;
    ref_ptr<OpUnary> AINV_UINT;
    ref_ptr<OpUnary> AINV_FLOAT;
    ref_ptr<OpUnary> MINV_INT;
    ref_ptr<OpUnary> MINV_UINT;
    ref_ptr<OpUnary> MINV_FLOAT;
    ref_ptr<OpUnary> LNOT_INT;
    ref_ptr<OpUnary> LNOT_UINT;
    ref_ptr<OpUnary> LNOT_FLOAT;
    ref_ptr<OpUnary> UONE_INT;
    ref_ptr<OpUnary> UONE_UINT;
    ref_ptr<OpUnary> UONE_FLOAT;
    ref_ptr<OpUnary> ABS_INT;
    ref_ptr<OpUnary> ABS_UINT;
    ref_ptr<OpUnary> ABS_FLOAT;

    ref_ptr<OpUnary> BNOT_INT;
    ref_ptr<OpUnary> BNOT_UINT;

    ref_ptr<OpUnary> SQRT_FLOAT;
    ref_ptr<OpUnary> LOG_FLOAT;
    ref_ptr<OpUnary> EXP_FLOAT;
    ref_ptr<OpUnary> SIN_FLOAT;
    ref_ptr<OpUnary> COS_FLOAT;
    ref_ptr<OpUnary> TAN_FLOAT;
    ref_ptr<OpUnary> ASIN_FLOAT;
    ref_ptr<OpUnary> ACOS_FLOAT;
    ref_ptr<OpUnary> ATAN_FLOAT;
    ref_ptr<OpUnary> CEIL_FLOAT;
    ref_ptr<OpUnary> FLOOR_FLOAT;
    ref_ptr<OpUnary> ROUND_FLOAT;
    ref_ptr<OpUnary> TRUNC_FLOAT;

    //////////////////////////////////////////////////////////////////////////////

    ref_ptr<OpBinary> PLUS_INT;
    ref_ptr<OpBinary> PLUS_UINT;
    ref_ptr<OpBinary> PLUS_FLOAT;
    ref_ptr<OpBinary> MINUS_INT;
    ref_ptr<OpBinary> MINUS_UINT;
    ref_ptr<OpBinary> MINUS_FLOAT;
    ref_ptr<OpBinary> MULT_INT;
    ref_ptr<OpBinary> MULT_UINT;
    ref_ptr<OpBinary> MULT_FLOAT;
    ref_ptr<OpBinary> DIV_INT;
    ref_ptr<OpBinary> DIV_UINT;
    ref_ptr<OpBinary> DIV_FLOAT;

    ref_ptr<OpBinary> MINUS_POW2_INT;
    ref_ptr<OpBinary> MINUS_POW2_UINT;
    ref_ptr<OpBinary> MINUS_POW2_FLOAT;

    ref_ptr<OpBinary> FIRST_INT;
    ref_ptr<OpBinary> FIRST_UINT;
    ref_ptr<OpBinary> FIRST_FLOAT;
    ref_ptr<OpBinary> SECOND_INT;
    ref_ptr<OpBinary> SECOND_UINT;
    ref_ptr<OpBinary> SECOND_FLOAT;

    ref_ptr<OpBinary> BONE_INT;
    ref_ptr<OpBinary> BONE_UINT;
    ref_ptr<OpBinary> BONE_FLOAT;

    ref_ptr<OpBinary> MIN_INT;
    ref_ptr<OpBinary> MIN_UINT;
    ref_ptr<OpBinary> MIN_FLOAT;
    ref_ptr<OpBinary> MAX_INT;
    ref_ptr<OpBinary> MAX_UINT;
    ref_ptr<OpBinary> MAX_FLOAT;

    ref_ptr<OpBinary> LOR_INT;
    ref_ptr<OpBinary> LOR_UINT;
    ref_ptr<OpBinary> LOR_FLOAT;
    ref_ptr<OpBinary> LAND_INT;
    ref_ptr<OpBinary> LAND_UINT;
    ref_ptr<OpBinary> LAND_FLOAT;

    ref_ptr<OpBinary> BOR_INT;
    ref_ptr<OpBinary> BOR_UINT;
    ref_ptr<OpBinary> BAND_INT;
    ref_ptr<OpBinary> BAND_UINT;
    ref_ptr<OpBinary> BXOR_INT;
    ref_ptr<OpBinary> BXOR_UINT;

    ref_ptr<OpBinary> FIRST_NON_MAX_INT;
    ref_ptr<OpBinary> MIN_NON_MAX_INT;
    ref_ptr<OpBinary> CONST_MAX_INT;
    ref_ptr<OpBinary> SECOND_MAX_INT;
    ref_ptr<OpBinary> MIN_NON_ZERO_INT;
    ref_ptr<OpBinary> S1ST_IF_SND_MAX_INT;
    ref_ptr<OpBinary> FST_MINUS_ONE_INT;
    ref_ptr<OpBinary> SELECT_MIN_WEIGHT_UINT;
    ref_ptr<OpBinary> CONSTRUCT_PAIR_UINT;

    //////////////////////////////////////////////////////////////////////////////

    ref_ptr<OpSelect> EQZERO_INT;
    ref_ptr<OpSelect> EQZERO_UINT;
    ref_ptr<OpSelect> EQZERO_FLOAT;
    ref_ptr<OpSelect> NQZERO_INT;
    ref_ptr<OpSelect> NQZERO_UINT;
    ref_ptr<OpSelect> NQZERO_FLOAT;
    ref_ptr<OpSelect> GTZERO_INT;
    ref_ptr<OpSelect> GTZERO_UINT;
    ref_ptr<OpSelect> GTZERO_FLOAT;
    ref_ptr<OpSelect> GEZERO_INT;
    ref_ptr<OpSelect> GEZERO_UINT;
    ref_ptr<OpSelect> GEZERO_FLOAT;
    ref_ptr<OpSelect> LTZERO_INT;
    ref_ptr<OpSelect> LTZERO_UINT;
    ref_ptr<OpSelect> LTZERO_FLOAT;
    ref_ptr<OpSelect> LEZERO_INT;
    ref_ptr<OpSelect> LEZERO_UINT;
    ref_ptr<OpSelect> LEZERO_FLOAT;
    ref_ptr<OpSelect> ALWAYS_INT;
    ref_ptr<OpSelect> ALWAYS_UINT;
    ref_ptr<OpSelect> ALWAYS_FLOAT;
    ref_ptr<OpSelect> NEVER_INT;
    ref_ptr<OpSelect> NEVER_UINT;
    ref_ptr<OpSelect> NEVER_FLOAT;

    ref_ptr<OpSelect> EQUALS_MINF_FLOAT;
    ref_ptr<OpSelect> EQUALS_MAX_INT;
    ref_ptr<OpSelect> EQUALS_MAX_UINT;
    ref_ptr<OpSelect> NEQUALS_MAX_INT;
    ref_ptr<OpSelect> NEQUALS_MAX_UINT;

    template<typename T>
    inline T min(T a, T b) { return std::min(a, b); }

    template<typename T>
    inline T max(T a, T b) { return std::max(a, b); }

    void register_ops() {
        DECL_OP_UNA_S(IDENTITY_INT, IDENSTITY, T_INT, { return a; });
        DECL_OP_UNA_S(IDENTITY_UINT, IDENSTITY, T_UINT, { return a; });
        DECL_OP_UNA_S(IDENTITY_FLOAT, IDENSTITY, T_FLOAT, { return a; });
        DECL_OP_UNA_S(AINV_INT, AINV, T_INT, { return -a; });
        DECL_OP_UNA_S(AINV_UINT, AINV, T_UINT, { return -a; });
        DECL_OP_UNA_S(AINV_FLOAT, AINV, T_FLOAT, { return -a; });
        DECL_OP_UNA_S(MINV_INT, MINV, T_INT, { return 1 / a; });
        DECL_OP_UNA_S(MINV_UINT, MINV, T_UINT, { return 1 / a; });
        DECL_OP_UNA_S(MINV_FLOAT, MINV, T_FLOAT, { return 1.0f / a; });
        DECL_OP_UNA_S(LNOT_INT, LNOT, T_INT, { return !(a != 0); });
        DECL_OP_UNA_S(LNOT_UINT, LNOT, T_UINT, { return !(a != 0); });
        DECL_OP_UNA_S(LNOT_FLOAT, LNOT, T_FLOAT, { return !(a != 0); });
        DECL_OP_UNA_S(UONE_INT, UONE, T_INT, { return 1; });
        DECL_OP_UNA_S(UONE_UINT, UONE, T_UINT, { return 1; });
        DECL_OP_UNA_S(UONE_FLOAT, UONE, T_FLOAT, { return 1; });
        DECL_OP_UNA_S(ABS_INT, ABS, T_INT, { return abs(a); });
        DECL_OP_UNA_S(ABS_UINT, ABS, T_UINT, { return a; });
        DECL_OP_UNA_S(ABS_FLOAT, ABS, T_FLOAT, { return fabs(a); });

        DECL_OP_UNA_S(BNOT_INT, BNOT, T_INT, { return ~a; });
        DECL_OP_UNA_S(BNOT_UINT, BNOT, T_UINT, { return ~a; });

        DECL_OP_UNA_S(SQRT_FLOAT, SQRT, T_FLOAT, { return sqrt(a); });
        DECL_OP_UNA_S(LOG_FLOAT, LOG, T_FLOAT, { return log(a); });
        DECL_OP_UNA_S(EXP_FLOAT, EXP, T_FLOAT, { return exp(a); });
        DECL_OP_UNA_S(SIN_FLOAT, SIN, T_FLOAT, { return sin(a); });
        DECL_OP_UNA_S(COS_FLOAT, COS, T_FLOAT, { return cos(a); });
        DECL_OP_UNA_S(TAN_FLOAT, TAN, T_FLOAT, { return tan(a); });
        DECL_OP_UNA_S(ASIN_FLOAT, ASIN, T_FLOAT, { return asin(a); });
        DECL_OP_UNA_S(ACOS_FLOAT, ACOS, T_FLOAT, { return acos(a); });
        DECL_OP_UNA_S(ATAN_FLOAT, ATAN, T_FLOAT, { return atan(a); });
        DECL_OP_UNA_S(CEIL_FLOAT, CEIL, T_FLOAT, { return ceil(a); });
        DECL_OP_UNA_S(FLOOR_FLOAT, FLOOR, T_FLOAT, { return floor(a); });
        DECL_OP_UNA_S(ROUND_FLOAT, ROUND, T_FLOAT, { return round(a); });
        DECL_OP_UNA_S(TRUNC_FLOAT, TRUNC, T_FLOAT, { return trunc(a); });

        DECL_OP_BIN_S(PLUS_INT, PLUS, T_INT, { return a + b; });
        DECL_OP_BIN_S(PLUS_UINT, PLUS, T_UINT, { return a + b; });
        DECL_OP_BIN_S(PLUS_FLOAT, PLUS, T_FLOAT, { return a + b; });
        DECL_OP_BIN_S(MINUS_INT, MINUS, T_INT, { return a - b; });
        DECL_OP_BIN_S(MINUS_UINT, MINUS, T_UINT, { return a - b; });
        DECL_OP_BIN_S(MINUS_FLOAT, MINUS, T_FLOAT, { return a - b; });
        DECL_OP_BIN_S(MULT_INT, MULT, T_INT, { return a * b; });
        DECL_OP_BIN_S(MULT_UINT, MULT, T_UINT, { return a * b; });
        DECL_OP_BIN_S(MULT_FLOAT, MULT, T_FLOAT, { return a * b; });
        DECL_OP_BIN_S(DIV_INT, DIV, T_INT, { return a / b; });
        DECL_OP_BIN_S(DIV_UINT, DIV, T_UINT, { return a / b; });
        DECL_OP_BIN_S(DIV_FLOAT, DIV, T_FLOAT, { return a / b; });

        DECL_OP_BIN_S(MINUS_POW2_INT, MINUS_POW2, T_INT, { return (a - b) * (a - b); });
        DECL_OP_BIN_S(MINUS_POW2_UINT, MINUS_POW2, T_UINT, { return (a - b) * (a - b); });
        DECL_OP_BIN_S(MINUS_POW2_FLOAT, MINUS_POW2, T_FLOAT, { return (a - b) * (a - b); });

        DECL_OP_BIN_S(FIRST_INT, FIRST, T_INT, { return a; });
        DECL_OP_BIN_S(FIRST_UINT, FIRST, T_UINT, { return a; });
        DECL_OP_BIN_S(FIRST_FLOAT, FIRST, T_FLOAT, { return a; });
        DECL_OP_BIN_S(SECOND_INT, SECOND, T_INT, { return b; });
        DECL_OP_BIN_S(SECOND_UINT, SECOND, T_UINT, { return b; });
        DECL_OP_BIN_S(SECOND_FLOAT, SECOND, T_FLOAT, { return b; });

        DECL_OP_BIN_S(BONE_INT, BONE, T_INT, { return 1; });
        DECL_OP_BIN_S(BONE_UINT, BONE, T_UINT, { return 1; });
        DECL_OP_BIN_S(BONE_FLOAT, BONE, T_FLOAT, { return 1; });

        DECL_OP_BIN_S(MIN_INT, MIN, T_INT, { return min(a, b); });
        DECL_OP_BIN_S(MIN_UINT, MIN, T_UINT, { return min(a, b); });
        DECL_OP_BIN_S(MIN_FLOAT, MIN, T_FLOAT, { return min(a, b); });
        DECL_OP_BIN_S(MAX_INT, MAX, T_INT, { return max(a, b); });
        DECL_OP_BIN_S(MAX_UINT, MAX, T_UINT, { return max(a, b); });
        DECL_OP_BIN_S(MAX_FLOAT, MAX, T_FLOAT, { return max(a, b); });

        DECL_OP_BIN_S(LOR_INT, LOR, T_INT, { return a || b; });
        DECL_OP_BIN_S(LOR_UINT, LOR, T_UINT, { return a || b; });
        DECL_OP_BIN_S(LOR_FLOAT, LOR, T_FLOAT, { return a || b; });
        DECL_OP_BIN_S(LAND_INT, LAND, T_INT, { return a && b; });
        DECL_OP_BIN_S(LAND_UINT, LAND, T_UINT, { return a && b; });
        DECL_OP_BIN_S(LAND_FLOAT, LAND, T_FLOAT, { return a && b; });

        DECL_OP_BIN_S(BOR_INT, BOR, T_INT, { return a | b; });
        DECL_OP_BIN_S(BOR_UINT, BOR, T_UINT, { return a | b; });
        DECL_OP_BIN_S(BAND_INT, BAND, T_INT, { return a & b; });
        DECL_OP_BIN_S(BAND_UINT, BAND, T_UINT, { return a & b; });
        DECL_OP_BIN_S(BXOR_INT, BXOR, T_INT, { return a ^ b; });
        DECL_OP_BIN_S(BXOR_UINT, BXOR, T_UINT, { return a ^ b; });

        DECL_OP_BIN_S(FIRST_NON_MAX_INT, FIRST_NON_MAX_INT, T_INT, {
            if (a == INT_MAX || b == INT_MAX) {
                return INT_MAX;
            }
                return a;
            });
        DECL_OP_BIN_S(MIN_NON_MAX_INT, MIN_NON_MAX_INT, T_INT, {
            if (a == INT_MAX || b == INT_MAX) { return INT_MAX; }
            return min(a, b);
            });
        DECL_OP_BIN_S(CONST_MAX_INT, CONST_MAX_INT, T_INT, { return INT_MAX; });
        DECL_OP_BIN_S(SECOND_MAX_INT, SECOND_MAX_INT, T_INT, {
            if (a == INT_MAX) {
                return b;
            }
            return a;
            });
        DECL_OP_BIN_S(MIN_NON_ZERO_INT, MIN_NON_ZERO_INT, T_INT, {
            if (a == 0) {
                return b;
            }
            return min(a, b);
            });

        DECL_OP_BIN_S(S1ST_IF_SND_MAX_INT, S1ST_IF_SND_MAX_INT, T_INT, {
            if (b == INT_MAX) {
                return a;
            }
            return INT_MAX;
            });

        DECL_OP_BIN_S(FST_MINUS_ONE_INT, FST_MINUS_ONE_INT, T_INT, {
            if (a == INT_MAX && b == INT_MAX) {
                return INT_MAX;
            }
            return a - 1;
            });

        DECL_OP_BIN_S(SELECT_MIN_WEIGHT_UINT, SELECT_MIN_WEIGHT_UINT, T_UINT, {
            // 11 bits for weight == 2048 values
            uint weight_a = a >> 21;
            uint weight_b = b >> 21;
            uint value_a = a & 0x1FFFFF;
            uint value_b = b & 0x1FFFFF;
            if (weight_a <= weight_b) {
                return (weight_a << 21) + value_a;
            }
            return (weight_b << 21) + value_b;
            });

        DECL_OP_BIN_S(CONSTRUCT_PAIR_UINT, CONSTRUCT_PAIR_UINT, T_UINT, {
            uint weight_a = a >> 21;
            uint weight_b = b >> 21;
            uint value_a = a & 0x1FFFFF;
            uint value_b = b & 0x1FFFFF;
            return (weight_b << 21) + value_a;
            });

        DECL_OP_SELECT(EQZERO_INT, EQZERO, T_INT, { return a == 0; });
        DECL_OP_SELECT(EQZERO_UINT, EQZERO, T_UINT, { return a == 0; });
        DECL_OP_SELECT(EQZERO_FLOAT, EQZERO, T_FLOAT, { return a == 0; });
        DECL_OP_SELECT(NQZERO_INT, NQZERO, T_INT, { return a != 0; });
        DECL_OP_SELECT(NQZERO_UINT, NQZERO, T_UINT, { return a != 0; });
        DECL_OP_SELECT(NQZERO_FLOAT, NQZERO, T_FLOAT, { return a != 0; });
        DECL_OP_SELECT(GTZERO_INT, GTZERO, T_INT, { return a > 0; });
        DECL_OP_SELECT(GTZERO_UINT, GTZERO, T_UINT, { return a > 0; });
        DECL_OP_SELECT(GTZERO_FLOAT, GTZERO, T_FLOAT, { return a > 0; });
        DECL_OP_SELECT(GEZERO_INT, GEZERO, T_INT, { return a >= 0; });
        DECL_OP_SELECT(GEZERO_UINT, GEZERO, T_UINT, { return a >= 0; });
        DECL_OP_SELECT(GEZERO_FLOAT, GEZERO, T_FLOAT, { return a >= 0; });
        DECL_OP_SELECT(LTZERO_INT, LTZERO, T_INT, { return a < 0; });
        DECL_OP_SELECT(LTZERO_UINT, LTZERO, T_UINT, { return a < 0; });
        DECL_OP_SELECT(LTZERO_FLOAT, LTZERO, T_FLOAT, { return a < 0; });
        DECL_OP_SELECT(LEZERO_INT, LEZERO, T_INT, { return a <= 0; });
        DECL_OP_SELECT(LEZERO_UINT, LEZERO, T_UINT, { return a <= 0; });
        DECL_OP_SELECT(LEZERO_FLOAT, LEZERO, T_FLOAT, { return a <= 0; });
        DECL_OP_SELECT(ALWAYS_INT, ALWAYS, T_INT, { return 1; });
        DECL_OP_SELECT(ALWAYS_UINT, ALWAYS, T_UINT, { return 1; });
        DECL_OP_SELECT(ALWAYS_FLOAT, ALWAYS, T_FLOAT, { return 1; });
        DECL_OP_SELECT(NEVER_INT, NEVER, T_INT, { return 0; });
        DECL_OP_SELECT(NEVER_UINT, NEVER, T_UINT, { return 0; });
        DECL_OP_SELECT(NEVER_FLOAT, NEVER, T_FLOAT, { return 0; });

        DECL_OP_SELECT(EQUALS_MINF_FLOAT, EQUALS_MINF_FLOAT, T_FLOAT, { return a == -INFINITY; }); // MINF == -inf
        DECL_OP_SELECT(EQUALS_MAX_INT, EQUALS_MAX_INT, T_INT, { return a == INT_MAX; });
        DECL_OP_SELECT(EQUALS_MAX_UINT, EQUALS_MAX, T_UINT, { return a == UINT_MAX; });
        DECL_OP_SELECT(NEQUALS_MAX_INT, NEQUALS_MAX, T_INT, { return a != INT_MAX; });
        DECL_OP_SELECT(NEQUALS_MAX_UINT, NEQUALS_MAX, T_UINT, { return a != UINT_MAX; });
    }

    ref_ptr<OpUnary> OpUnary::make_int(std::string name, std::string code, std::function<T_INT(T_INT)> function) {
        auto op = make_ref<TOpUnary<T_INT, T_INT>>();
        op->name = std::move(name);
        op->function = std::move(function);
        op->source = std::move(code);
        op->key = op->name + "_" + op->get_type_arg_0()->get_code() + op->get_type_res()->get_code();
        return op.as<OpUnary>();
    }
    ref_ptr<OpUnary> OpUnary::make_uint(std::string name, std::string code, std::function<T_UINT(T_UINT)> function) {
        auto op = make_ref<TOpUnary<T_UINT, T_UINT>>();
        op->name = std::move(name);
        op->function = std::move(function);
        op->source = std::move(code);
        op->key = op->name + "_" + op->get_type_arg_0()->get_code() + op->get_type_res()->get_code();
        return op.as<OpUnary>();
    }
    ref_ptr<OpUnary> OpUnary::make_float(std::string name, std::string code, std::function<T_FLOAT(T_FLOAT)> function) {
        auto op = make_ref<TOpUnary<T_FLOAT, T_FLOAT>>();
        op->name = std::move(name);
        op->function = std::move(function);
        op->source = std::move(code);
        op->key = op->name + "_" + op->get_type_arg_0()->get_code() + op->get_type_res()->get_code();
        return op.as<OpUnary>();
    }

    ref_ptr<OpBinary> OpBinary::make_int(std::string name, std::string code, std::function<T_INT(T_INT, T_INT)> function) {
        auto op = make_ref<TOpBinary<T_INT, T_INT, T_INT>>();
        op->name = std::move(name);
        op->function = std::move(function);
        op->source = std::move(code);
        op->key = op->name + "_" + op->get_type_arg_0()->get_code() + op->get_type_arg_1()->get_code() + op->get_type_res()->get_code();
        return op.as<OpBinary>();
    }
    ref_ptr<OpBinary> OpBinary::make_uint(std::string name, std::string code, std::function<T_UINT(T_UINT, T_UINT)> function) {
        auto op = make_ref<TOpBinary<T_UINT, T_UINT, T_UINT>>();
        op->name = std::move(name);
        op->function = std::move(function);
        op->source = std::move(code);
        op->key = op->name + "_" + op->get_type_arg_0()->get_code() + op->get_type_arg_1()->get_code() + op->get_type_res()->get_code();
        return op.as<OpBinary>();
    }
    ref_ptr<OpBinary> OpBinary::make_float(std::string name, std::string code, std::function<T_FLOAT(T_FLOAT, T_FLOAT)> function) {
        auto op = make_ref<TOpBinary<T_FLOAT, T_FLOAT, T_FLOAT>>();
        op->name = std::move(name);
        op->function = std::move(function);
        op->source = std::move(code);
        op->key = op->name + "_" + op->get_type_arg_0()->get_code() + op->get_type_arg_1()->get_code() + op->get_type_res()->get_code();
        return op.as<OpBinary>();
    }

    ref_ptr<OpSelect> OpSelect::make_int(std::string name, std::string code, std::function<bool(T_INT)> function) {
        auto op = make_ref<TOpSelect<T_INT>>();
        op->name = std::move(name);
        op->function = std::move(function);
        op->source = std::move(code);
        op->key = op->name + "_" + op->get_type_arg_0()->get_code();
        return op.as<OpSelect>();
    }
    ref_ptr<OpSelect> OpSelect::make_uint(std::string name, std::string code, std::function<bool(T_UINT)> function) {
        auto op = make_ref<TOpSelect<T_UINT>>();
        op->name = std::move(name);
        op->function = std::move(function);
        op->source = std::move(code);
        op->key = op->name + "_" + op->get_type_arg_0()->get_code();
        return op.as<OpSelect>();
    }
    ref_ptr<OpSelect> OpSelect::make_float(std::string name, std::string code, std::function<bool(T_FLOAT)> function) {
        auto op = make_ref<TOpSelect<T_FLOAT>>();
        op->name = std::move(name);
        op->function = std::move(function);
        op->source = std::move(code);
        op->key = op->name + "_" + op->get_type_arg_0()->get_code();
        return op.as<OpSelect>();
    }

}// namespace spla