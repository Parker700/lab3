# создание библиотеки stack_operators
add_library(stack_dynamic stack.h stack.cpp)

# создание тестирующей программы
add_executable(main_dynamic main.cpp)

# подключение библиотеки к тестирующей программе
target_link_libraries(main_dynamic stack_dynamic)