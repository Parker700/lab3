#include "stack.h"

namespace Prog3 {
    // выборка из стека; генерируется исключение, если стек пуст
    int Stack::pop() {
        if(top == 0)
            throw std::logic_error("Stack is empty");
        int el = ar[--top];
        return el;
    }

    // запись в стек; генерируется исключение, если стек полон
    void Stack::push(int el) {
        if(top >= SZ) {
            throw std::runtime_error("Stack overflow!");
        }
        ar[top++] = el;
    }


    // Копирование данных из одного стека в другой.
    // Данные из стека-операнда записываются в стек-адресат
    // Состояние стека-операнда не изменяется.
    Stack &Stack::operator+=(const Stack &st) {
        int new_top = top + st.top;
        if(new_top >= SZ) {
            throw std::runtime_error("Stack overflow!");
        }
        std::copy(st.ar, st.ar + st.top, ar + top);
        top = new_top;
        return *this;
    }

    // вывод содержимого стека в поток (в порядке, соответствующем выборке из стека)
    std::ostream &operator<<(std::ostream &s, const Stack &st) {
        if(st.top == 0)
            s << "Stack is empty";
        else
            for(int i = st.top - 1; i >= 0; --i)
                s << st.ar[i] << ' ';
        s << std::endl;
        return s;
    }
}