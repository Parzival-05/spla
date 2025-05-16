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

#ifndef SPLA_OP_HPP
#define SPLA_OP_HPP

#include "object.hpp"
#include "type.hpp"

#include <string>

namespace spla {

    /**
     * @addtogroup spla
     * @{
     */

     /**
      * @class Op
      * @brief An callable operation to parametrize execution of math computations
      */
    class Op : public Object {
    public:
        SPLA_API ~Op() override = default;
        SPLA_API virtual ref_ptr<Type> get_type_res() = 0;
        SPLA_API virtual std::string   get_name() = 0;
        SPLA_API virtual std::string   get_key() = 0;
        SPLA_API virtual std::string   get_source_cl() = 0;
    };

    /**
     * @class OpUnary
     * @brief Unary operation with 1-arity
     */
    class OpUnary : public Op {
    public:
        SPLA_API ~OpUnary() override = default;
        SPLA_API virtual ref_ptr<Type>   get_type_arg_0() = 0;
        SPLA_API static ref_ptr<OpUnary> make_int(std::string name, std::string code, std::function<T_INT(T_INT)> function);
        SPLA_API static ref_ptr<OpUnary> make_uint(std::string name, std::string code, std::function<T_UINT(T_UINT)> function);
        SPLA_API static ref_ptr<OpUnary> make_float(std::string name, std::string code, std::function<T_FLOAT(T_FLOAT)> function);
    };

    /**
     * @class OpBinary
     * @brief Binary operation with 2-arity
     */
    class OpBinary : public Op {
    public:
        SPLA_API ~OpBinary() override = default;
        SPLA_API virtual ref_ptr<Type>    get_type_arg_0() = 0;
        SPLA_API virtual ref_ptr<Type>    get_type_arg_1() = 0;
        SPLA_API static ref_ptr<OpBinary> make_int(std::string name, std::string code, std::function<T_INT(T_INT, T_INT)> function);
        SPLA_API static ref_ptr<OpBinary> make_uint(std::string name, std::string code, std::function<T_UINT(T_UINT, T_UINT)> function);
        SPLA_API static ref_ptr<OpBinary> make_float(std::string name, std::string code, std::function<T_FLOAT(T_FLOAT, T_FLOAT)> function);
    };

    /**
     * @class OpSelect
     * @brief Select operation with 1-arity and bool return type
     */
    class OpSelect : public Op {
    public:
        SPLA_API ~OpSelect() override = default;
        SPLA_API virtual ref_ptr<Type>    get_type_arg_0() = 0;
        SPLA_API static ref_ptr<OpSelect> make_int(std::string name, std::string code, std::function<bool(T_INT)> function);
        SPLA_API static ref_ptr<OpSelect> make_uint(std::string name, std::string code, std::function<bool(T_UINT)> function);
        SPLA_API static ref_ptr<OpSelect> make_float(std::string name, std::string code, std::function<bool(T_FLOAT)> function);
    };

    //////////////////////////////// Unary ////////////////////////////////

    SPLA_API extern ref_ptr<OpUnary> IDENTITY_INT;
    SPLA_API extern ref_ptr<OpUnary> IDENTITY_UINT;
    SPLA_API extern ref_ptr<OpUnary> IDENTITY_FLOAT;
    SPLA_API extern ref_ptr<OpUnary> AINV_INT;
    SPLA_API extern ref_ptr<OpUnary> AINV_UINT;
    SPLA_API extern ref_ptr<OpUnary> AINV_FLOAT;
    SPLA_API extern ref_ptr<OpUnary> MINV_INT;
    SPLA_API extern ref_ptr<OpUnary> MINV_UINT;
    SPLA_API extern ref_ptr<OpUnary> MINV_FLOAT;
    SPLA_API extern ref_ptr<OpUnary> LNOT_INT;
    SPLA_API extern ref_ptr<OpUnary> LNOT_UINT;
    SPLA_API extern ref_ptr<OpUnary> LNOT_FLOAT;
    SPLA_API extern ref_ptr<OpUnary> UONE_INT;
    SPLA_API extern ref_ptr<OpUnary> UONE_UINT;
    SPLA_API extern ref_ptr<OpUnary> UONE_FLOAT;
    SPLA_API extern ref_ptr<OpUnary> ABS_INT;
    SPLA_API extern ref_ptr<OpUnary> ABS_UINT;
    SPLA_API extern ref_ptr<OpUnary> ABS_FLOAT;

    SPLA_API extern ref_ptr<OpUnary> BNOT_INT;
    SPLA_API extern ref_ptr<OpUnary> BNOT_UINT;

    SPLA_API extern ref_ptr<OpUnary> SQRT_FLOAT;
    SPLA_API extern ref_ptr<OpUnary> LOG_FLOAT;
    SPLA_API extern ref_ptr<OpUnary> EXP_FLOAT;
    SPLA_API extern ref_ptr<OpUnary> SIN_FLOAT;
    SPLA_API extern ref_ptr<OpUnary> COS_FLOAT;
    SPLA_API extern ref_ptr<OpUnary> TAN_FLOAT;
    SPLA_API extern ref_ptr<OpUnary> ASIN_FLOAT;
    SPLA_API extern ref_ptr<OpUnary> ACOS_FLOAT;
    SPLA_API extern ref_ptr<OpUnary> ATAN_FLOAT;
    SPLA_API extern ref_ptr<OpUnary> CEIL_FLOAT;
    SPLA_API extern ref_ptr<OpUnary> FLOOR_FLOAT;
    SPLA_API extern ref_ptr<OpUnary> ROUND_FLOAT;
    SPLA_API extern ref_ptr<OpUnary> TRUNC_FLOAT;

    //////////////////////////////// Binary ////////////////////////////////

    SPLA_API extern ref_ptr<OpBinary> PLUS_INT;
    SPLA_API extern ref_ptr<OpBinary> PLUS_UINT;
    SPLA_API extern ref_ptr<OpBinary> PLUS_FLOAT;
    SPLA_API extern ref_ptr<OpBinary> MINUS_INT;
    SPLA_API extern ref_ptr<OpBinary> MINUS_UINT;
    SPLA_API extern ref_ptr<OpBinary> MINUS_FLOAT;
    SPLA_API extern ref_ptr<OpBinary> MULT_INT;
    SPLA_API extern ref_ptr<OpBinary> MULT_UINT;
    SPLA_API extern ref_ptr<OpBinary> MULT_FLOAT;
    SPLA_API extern ref_ptr<OpBinary> DIV_INT;
    SPLA_API extern ref_ptr<OpBinary> DIV_UINT;
    SPLA_API extern ref_ptr<OpBinary> DIV_FLOAT;

    SPLA_API extern ref_ptr<OpBinary> MINUS_POW2_INT;
    SPLA_API extern ref_ptr<OpBinary> MINUS_POW2_UINT;
    SPLA_API extern ref_ptr<OpBinary> MINUS_POW2_FLOAT;

    SPLA_API extern ref_ptr<OpBinary> FIRST_INT;
    SPLA_API extern ref_ptr<OpBinary> FIRST_UINT;
    SPLA_API extern ref_ptr<OpBinary> FIRST_FLOAT;
    SPLA_API extern ref_ptr<OpBinary> SECOND_INT;
    SPLA_API extern ref_ptr<OpBinary> SECOND_UINT;
    SPLA_API extern ref_ptr<OpBinary> SECOND_FLOAT;

    SPLA_API extern ref_ptr<OpBinary> BONE_INT;
    SPLA_API extern ref_ptr<OpBinary> BONE_UINT;
    SPLA_API extern ref_ptr<OpBinary> BONE_FLOAT;

    SPLA_API extern ref_ptr<OpBinary> MIN_INT;
    SPLA_API extern ref_ptr<OpBinary> MIN_UINT;
    SPLA_API extern ref_ptr<OpBinary> MIN_FLOAT;
    SPLA_API extern ref_ptr<OpBinary> MAX_INT;
    SPLA_API extern ref_ptr<OpBinary> MAX_UINT;
    SPLA_API extern ref_ptr<OpBinary> MAX_FLOAT;

    SPLA_API extern ref_ptr<OpBinary> LOR_INT;
    SPLA_API extern ref_ptr<OpBinary> LOR_UINT;
    SPLA_API extern ref_ptr<OpBinary> LOR_FLOAT;
    SPLA_API extern ref_ptr<OpBinary> LAND_INT;
    SPLA_API extern ref_ptr<OpBinary> LAND_UINT;
    SPLA_API extern ref_ptr<OpBinary> LAND_FLOAT;

    SPLA_API extern ref_ptr<OpBinary> BOR_INT;
    SPLA_API extern ref_ptr<OpBinary> BOR_UINT;
    SPLA_API extern ref_ptr<OpBinary> BAND_INT;
    SPLA_API extern ref_ptr<OpBinary> BAND_UINT;
    SPLA_API extern ref_ptr<OpBinary> BXOR_INT;
    SPLA_API extern ref_ptr<OpBinary> BXOR_UINT;

    SPLA_API extern ref_ptr<OpBinary> FIRST_NON_MAX_INT;
    SPLA_API extern ref_ptr<OpBinary> MIN_NON_MAX_INT;
    SPLA_API extern ref_ptr<OpBinary> CONST_MAX_INT;
    SPLA_API extern ref_ptr<OpBinary> SECOND_MAX_INT;
    SPLA_API extern ref_ptr<OpBinary> MIN_NON_ZERO_INT;
    SPLA_API extern ref_ptr<OpBinary> S1ST_IF_SND_MAX_INT;
    SPLA_API extern ref_ptr<OpBinary> FST_MINUS_ONE_INT;

    //////////////////////////////// Select ////////////////////////////////

    SPLA_API extern ref_ptr<OpSelect> EQZERO_INT;
    SPLA_API extern ref_ptr<OpSelect> EQZERO_UINT;
    SPLA_API extern ref_ptr<OpSelect> EQZERO_FLOAT;
    SPLA_API extern ref_ptr<OpSelect> NQZERO_INT;
    SPLA_API extern ref_ptr<OpSelect> NQZERO_UINT;
    SPLA_API extern ref_ptr<OpSelect> NQZERO_FLOAT;
    SPLA_API extern ref_ptr<OpSelect> GTZERO_INT;
    SPLA_API extern ref_ptr<OpSelect> GTZERO_UINT;
    SPLA_API extern ref_ptr<OpSelect> GTZERO_FLOAT;
    SPLA_API extern ref_ptr<OpSelect> GEZERO_INT;
    SPLA_API extern ref_ptr<OpSelect> GEZERO_UINT;
    SPLA_API extern ref_ptr<OpSelect> GEZERO_FLOAT;
    SPLA_API extern ref_ptr<OpSelect> LTZERO_INT;
    SPLA_API extern ref_ptr<OpSelect> LTZERO_UINT;
    SPLA_API extern ref_ptr<OpSelect> LTZERO_FLOAT;
    SPLA_API extern ref_ptr<OpSelect> LEZERO_INT;
    SPLA_API extern ref_ptr<OpSelect> LEZERO_UINT;
    SPLA_API extern ref_ptr<OpSelect> LEZERO_FLOAT;
    SPLA_API extern ref_ptr<OpSelect> ALWAYS_INT;
    SPLA_API extern ref_ptr<OpSelect> ALWAYS_UINT;
    SPLA_API extern ref_ptr<OpSelect> ALWAYS_FLOAT;
    SPLA_API extern ref_ptr<OpSelect> NEVER_INT;
    SPLA_API extern ref_ptr<OpSelect> NEVER_UINT;
    SPLA_API extern ref_ptr<OpSelect> NEVER_FLOAT;

    SPLA_API extern ref_ptr<OpSelect> EQUALS_MINF_FLOAT;
    SPLA_API extern ref_ptr<OpSelect> EQUALS_MAX_INT;
    SPLA_API extern ref_ptr<OpSelect> NEQUALS_MAX_INT;

    /**
     * @}
     */

}// namespace spla

#endif//SPLA_OP_HPP
