add_library(symsala-lib)

target_sources(symsala-lib
    PRIVATE
        exec/exec.cpp
    PUBLIC
        core/error.hpp
        core/types.hpp
        exec/exec.hpp
)

add_library(symsala::lib ALIAS symsala-lib)

target_include_directories(symsala-lib
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
)

target_link_libraries(symsala-lib PUBLIC sala utility)
