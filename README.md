# MultiThreadParser

**Multithreaded text / log file parser with analytics and PostgreSQL storage**  
C++17 • std::thread + mutex • libpqxx • CMake + vcpkg • Windows

![C++](https://img.shields.io/badge/C++-17-blue.svg?style=flat&logo=c%2B%2B)
![Platform](https://img.shields.io/badge/platform-Windows-lightgrey)
![PostgreSQL](https://img.shields.io/badge/PostgreSQL-15-blue)
![License](https://img.shields.io/github/license/Leg1tDragan/MultiThreadParser)
![Build](https://img.shields.io/badge/build-passing-brightgreen)

## Evolution

| Before | After |
|-------|------|
| Single-threaded parser | **Multithreaded** (up to 8× speedup) |
| Console output only | **PostgreSQL storage** |
| Basic README | **Beautiful & detailed** |

---

## Features

- Multithreaded line processing (`std::thread` + `hardware_concurrency`)
- Thread-safe analytics via `std::mutex`
- Configurable parsing: `toLowerCase`, `removePunctuation`, `ignoreDigits`, `textLog`
- File validation (size, extension .txt/.log, permissions)
- PostgreSQL integration (`saveToPostgreSQL()` with parameterized INSERT)
- Handles huge files (100 MB+) smoothly

---

## Build & Run (Windows)

```powershell
# 1. Install vcpkg (once)
git clone https://github.com/microsoft/vcpkg.git
.\vcpkg\bootstrap-vcpkg.bat
.\vcpkg\vcpkg install libpqxx:x64-windows gtest:x64-windows

# 2. Clone & build
git clone https://github.com/Leg1tDragan/MultiThreadParser.git
cd MultiThreadParser
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build --config Release
