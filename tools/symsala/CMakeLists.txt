
add_executable(symsala)

target_sources(symsala
    PRIVATE
        main.cpp
)

target_link_libraries(symsala PRIVATE symsala-lib)
