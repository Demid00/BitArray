# CMake generated Testfile for 
# Source directory: E:/С/VS_project/1_lectors_tasks/BitArrayProject/tests
# Build directory: E:/С/VS_project/1_lectors_tasks/BitArrayProject/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(MyTests "E:/С/VS_project/1_lectors_tasks/BitArrayProject/build/tests/Debug/MyTests.exe")
  set_tests_properties(MyTests PROPERTIES  _BACKTRACE_TRIPLES "E:/С/VS_project/1_lectors_tasks/BitArrayProject/tests/CMakeLists.txt;11;add_test;E:/С/VS_project/1_lectors_tasks/BitArrayProject/tests/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(MyTests "E:/С/VS_project/1_lectors_tasks/BitArrayProject/build/tests/Release/MyTests.exe")
  set_tests_properties(MyTests PROPERTIES  _BACKTRACE_TRIPLES "E:/С/VS_project/1_lectors_tasks/BitArrayProject/tests/CMakeLists.txt;11;add_test;E:/С/VS_project/1_lectors_tasks/BitArrayProject/tests/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(MyTests "E:/С/VS_project/1_lectors_tasks/BitArrayProject/build/tests/MinSizeRel/MyTests.exe")
  set_tests_properties(MyTests PROPERTIES  _BACKTRACE_TRIPLES "E:/С/VS_project/1_lectors_tasks/BitArrayProject/tests/CMakeLists.txt;11;add_test;E:/С/VS_project/1_lectors_tasks/BitArrayProject/tests/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(MyTests "E:/С/VS_project/1_lectors_tasks/BitArrayProject/build/tests/RelWithDebInfo/MyTests.exe")
  set_tests_properties(MyTests PROPERTIES  _BACKTRACE_TRIPLES "E:/С/VS_project/1_lectors_tasks/BitArrayProject/tests/CMakeLists.txt;11;add_test;E:/С/VS_project/1_lectors_tasks/BitArrayProject/tests/CMakeLists.txt;0;")
else()
  add_test(MyTests NOT_AVAILABLE)
endif()
