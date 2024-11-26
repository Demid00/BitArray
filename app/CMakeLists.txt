# Создаем исполняемый файл
add_executable(BitArrayApp main.cpp)

# Линкуем библиотеку
target_link_libraries(BitArrayApp PRIVATE BitArray)
