#ifndef OOPPROG3_STACK_H
#define OOPPROG3_STACK_H

#include <iostream>

namespace Prog3 {

    class Stack {
    private:
        static const int SZ = 10; // максимальный размер вектора
        int top; // индекс вершины стека; первый элемент вектора, доступный для записи в стек
        int ar[SZ];
    public:
        Stack() : top(0) {}

        void push(int); // занесение в стек
        int pop(); // выборка из стека
        bool empty() const { return top == 0; } // проверка стека на пустоту
        void copy(const Stack &); // копирование данных из одного стека в другой
        int getSize() const { return top; } // текущий размер стека
        int getMaxSize() const { return SZ; } // максимальный размер стека
        std::ostream &print(std::ostream &) const;
    };

} // Stack

#endif //OOPPROG3_STACK_H
