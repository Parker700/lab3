# создание библиотеки stack_operators
add_library(stack_operators stack.h stack.cpp)

# создание тестирующей программы
add_executable(main_operators main.cpp)

# подключение библиотеки к тестирующей программе
target_link_libraries(main_operators stack_operators)