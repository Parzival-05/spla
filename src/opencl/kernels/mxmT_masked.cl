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

#include "common_def.cl"

__kernel void mxmT_masked_csr_scalar(__global const uint* g_Ap,
                                     __global const uint* g_Aj,
                                     __global const TYPE* g_Ax,
                                     __global const uint* g_Bp,
                                     __global const uint* g_Bj,
                                     __global const TYPE* g_Bx,
                                     __global const uint* g_maskp,
                                     __global const uint* g_maskj,
                                     __global const TYPE* g_maskx,
                                     __global TYPE*       g_Rx,
                                     const TYPE           init,
                                     const uint           n) {
    const uint lid     = get_local_id(1);   // thread id in a row
    const uint lsize   = get_local_size(1); // size of local group
    const uint gid     = get_global_id(0);  // id of row to touch
    const uint gstride = get_global_size(0);// step between row ids

    for (uint row_id = gid; row_id < n; row_id += gstride) {
        const uint mask_start = g_maskp[row_id];
        const uint mask_end   = g_maskp[row_id + 1];

        const uint A_start = g_Ap[row_id];
        const uint A_end   = g_Ap[row_id + 1];

        for (uint mask_k = mask_start + lid; mask_k < mask_end; mask_k += lsize) {
            const uint mask_j = g_maskj[mask_k];
            const TYPE mask_x = g_maskx[mask_k];

            TYPE r = init;

            if (OP_SELECT(mask_x)) {
                const uint B_start = g_Bp[mask_j];
                const uint B_end   = g_Bp[mask_j + 1];

                uint A_it = A_start;
                uint B_it = B_start;

                while (A_it < A_end && B_it < B_end) {
                    const uint A_j = g_Aj[A_it];
                    const uint B_j = g_Bj[B_it];

                    if (A_j == B_j) {
                        r = OP_BINARY2(r, OP_BINARY1(g_Ax[A_it], g_Bx[B_it]));
                        ++A_it;
                        ++B_it;
                    } else if (A_j < B_j) {
                        ++A_it;
                    } else {
                        ++B_it;
                    }
                }
            }

            g_Rx[mask_k] = r;
        }
    }
}