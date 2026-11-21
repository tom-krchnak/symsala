#pragma once

#include "core/types.hpp"


namespace sala::sym
{

enum class RunResult
{
    Exhausted,
    Covered,
    Incomplete
};


struct Executor
{
    Executor( const Program &program );

    RunResult run();

private:

    const Program &_program;
};

} // namespace sala::sym
