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

#ifndef SPLA_SCHEDULE_HPP
#define SPLA_SCHEDULE_HPP

#include "config.hpp"
#include "descriptor.hpp"
#include "object.hpp"

#include <string>
#include <vector>

namespace spla {

    /**
     * @addtogroup spla
     * @{
     */

    /**
     * @class ScheduleTask
     * @brief Represent single smallest evaluation tasks which can scheduled
     */
    class ScheduleTask : public Object {
    public:
        SPLA_API ~ScheduleTask() override                                   = default;
        SPLA_API virtual std::string                  get_name()            = 0;
        SPLA_API virtual std::string                  get_key()             = 0;
        SPLA_API virtual std::string                  get_key_full()        = 0;
        SPLA_API virtual std::vector<ref_ptr<Object>> get_args()            = 0;
        SPLA_API virtual ref_ptr<Descriptor>          get_desc()            = 0;
        SPLA_API virtual ref_ptr<Descriptor>          get_desc_or_default() = 0;
    };

    /**
     * @class Schedule
     * @brief Object with sequence of steps with tasks forming schedule for execution
     */
    class Schedule : public Object {
    public:
        SPLA_API ~Schedule() override                                                = default;
        SPLA_API virtual Status step_task(ref_ptr<ScheduleTask> task)                = 0;
        SPLA_API virtual Status step_tasks(std::vector<ref_ptr<ScheduleTask>> tasks) = 0;
        SPLA_API virtual Status submit()                                             = 0;
    };

    /**
     * @brief Makes new schedule for making execution schedule
     *
     * @return New created schedule
     */
    SPLA_API ref_ptr<Schedule> make_schedule();

    /**
     * @}
     */

}// namespace spla

#endif//SPLA_SCHEDULE_HPP
