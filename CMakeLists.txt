cmake_minimum_required(VERSION 3.10)

project(MultiThreadParser)

set(CMAKE_CXX_STANDARD 20)

add_executable (MultiThreadParser "MultiThreadParser.cpp" "MultiThreadParser.h" "Parser/Parser.cpp" "Parser/Parser.h" "Parser/Analytics.h" "Parser/ParseSettings.h" "Parser/Analytics.cpp" "Parser/ParseSettings.cpp")

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

find_package(libpqxx CONFIG REQUIRED)
target_link_libraries(MultiThreadParser PRIVATE libpqxx::pqxx)

set_target_properties(MultiThreadParser PROPERTIES
    WIN32_EXECUTABLE OFF
)