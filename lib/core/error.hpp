#pragma once

#include <source_location>
#include <sstream>
#include <stdexcept>


namespace sala::sym
{

namespace detail
{

template< typename... Args >
std::runtime_error fail( std::source_location loc, Args &&... args )
{
    std::ostringstream oss;
    oss << loc.file_name() << ":" << loc.line() << ":" << loc.column() << "\n";
    ( oss << ... << args ) << "\n";

    throw std::runtime_error( oss.str() );
}

[[noreturn]] inline void unreachable()
{
#   if defined(_MSC_VER) && !defined(__clang__)
        __assume(false);
#   else
        __builtin_unreachable();
#   endif
}

} // namespace detail


#define ERROR( ... ) detail::fail( \
    std::source_location::current() __VA_OPT__(,) __VA_ARGS__ )

#define ASSERT( COND, ... ) do { const bool cond = ( COND ); \
    if ( !cond ) throw ERROR( __VA_ARGS__ ); } while ( false )

#define UNREACHABLE() detail::unreachable()


} // namespace sala::sym
