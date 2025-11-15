cmake_minimum_required(VERSION 3.10)

project(MultiThreadParser)

set(CMAKE_CXX_STANDARD 20)

add_executable (MultiThreadParser "MultiThreadParser.cpp" "MultiThreadParser.h" "Parser/Parser.cpp" "Parser/Parser.h" "Parser/Analytics.h" "Parser/ParseSettings.h" "Parser/Analytics.cpp" "Parser/ParseSettings.cpp")

set_target_properties(MultiThreadParser PROPERTIES
    WIN32_EXECUTABLE OFF
)