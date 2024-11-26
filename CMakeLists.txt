cmake_minimum_required(VERSION 3.15)
project(BitArrayProject)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_DEFAULT_CONFIGURATION Debug)

# Настройка для Visual Studio
if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
endif()

# Добавляем подкаталоги
add_subdirectory(BitArray)
add_subdirectory(app)
add_subdirectory(googletest)
add_subdirectory(tests)
