#include "options.hpp"

#include "sala/streaming.hpp"

#include "core/error.hpp"
#include "core/types.hpp"
#include "exec/exec.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>


namespace
{

using namespace sala::sym;

static Program parse_program( const std::string &input )
{
    std::ifstream in( input );

    sala::Program program;
    in >> program;

    return program;
}

void run( const Options &opts )
{
    Program program = parse_program( opts.input );

    Executor exec( program );
    exec.run();
}

} // namespace


int main( int argc, char **argv )
{
    try
    {
        Options opts = parse_options( argc, argv );
        run( opts );

        return 0;
    }
    catch ( std::exception &e )
    {
        std::cerr << "Error: " << e.what() << "\n";
    }
    catch ( ... )
    {
        std::cerr << "Unknown error\n";
    }

    return 1;
}
