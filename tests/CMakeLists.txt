# Включаем CTest
enable_testing()

# Добавляем исполняемый файл для тестов
add_executable(MyTests BitArrayTests.cpp)

# Линкуем с Google Test и основной библиотекой
target_link_libraries(MyTests PRIVATE BitArray gtest gtest_main)

# Регистрируем тесты для ctest
add_test(NAME MyTests COMMAND $<TARGET_FILE:MyTests>)

