include(FetchContent)
find_package(Boost REQUIRED COMPONENTS json)

FetchContent_Declare(
    libutility
    GIT_REPOSITORY https://github.com/staticafi/libutility.git
    GIT_TAG        main
    GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(libutility)
target_include_directories(utility PUBLIC "${libutility_SOURCE_DIR}/include")

FetchContent_Declare(
    libsala
    GIT_REPOSITORY https://github.com/staticafi/libsala.git
    GIT_TAG        main
    GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(libsala)
target_include_directories(sala PUBLIC "${libsala_SOURCE_DIR}/include")
target_link_libraries(sala PUBLIC utility Boost::json)
