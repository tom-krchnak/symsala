#pragma once

#include "sala/program.hpp"

#include <cstdint>
#include <memory>


namespace sala::sym
{

using Program    = sala::Program;
using Instr      = sala::Instruction;

using Descriptor = Instr::Descriptor;
using Modifier   = Instr::Modifier;
using Opcode     = Instr::Opcode;

using  u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;


template< typename T >
using ptr = std::unique_ptr< T >;

template< typename T, typename... Args >
constexpr auto make_ptr( Args &&... args )
{
    return std::make_unique< T >( std::forward< Args >( args )... );
}

} // namespace sala::sym
