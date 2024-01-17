# создание библиотеки stack_static
add_library(stack_static stack.h stack.cpp)

# создание тестирующей программы
add_executable(main_static main.cpp)

# подключение библиотеки к тестирующей программе
target_link_libraries(main_static stack_static)