# Создаем библиотеку
add_library(BitArray STATIC BitArray.cpp)

# Указываем заголовочные файлы
target_include_directories(BitArray PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
