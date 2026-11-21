#include "exec.hpp"

namespace sala::sym
{

Executor::Executor( const Program &program )
    : _program( program )
{}

RunResult Executor::run()
{
    return RunResult::Incomplete;
}

} // namespace sala::sym
