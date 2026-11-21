#pragma once

#include "core/error.hpp"

#include <string>


struct Options
{
    std::string input;
};

Options parse_options( int argc, char **argv )
{
    Options opts;
    opts.input = argv[ 1 ];

    return opts;
}
