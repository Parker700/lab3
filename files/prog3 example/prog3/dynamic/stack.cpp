#include "stack.h"

namespace Prog3 {

    // копирующий конструктор
    Stack::Stack(const Stack &st) : SZ(st.SZ), top(st.top) {
        ar = new int[SZ];
        std::copy(st.ar, st.ar + st.top, ar);
    }

    // перемещающий конструктор
    Stack::Stack(Stack &&st) noexcept: SZ(st.SZ), top(st.top), ar(st.ar) {
        st.ar = nullptr;
    }

    // изменение размера стека
    void Stack::resize(int new_size) {
        if(new_size < top) {
            throw std::runtime_error("New size is too small");
        }
        int *new_ar = new int[new_size];
        std::move(ar, ar + top, new_ar);
        delete[] ar;
        SZ = new_size;
        ar = new_ar;
    }

    // перегруженный оператор присваивания
    Stack &Stack::operator=(const Stack &st) {
        if(this != &st) {
            // сначала выделяем память и только потом освобождаем старую,
            // чтобы в случае исключения не нарушить согласованность данных
            // (strong exception safety)
            int *new_ar = new int[SZ];
            top = st.top;
            SZ = st.SZ;
            delete[] ar;
            ar = new_ar;
            std::copy(st.ar, st.ar + st.top, ar);
        }
        return *this;
    }

    // перемещающий оператор присваивания
    Stack &Stack::operator=(Stack &&st) noexcept {
        std::swap(top, st.top);
        std::swap(SZ, st.SZ);
        std::swap(ar, st.ar);
        return *this;
    }

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
            resize(SZ + QUOTA);
        }
        ar[top++] = el;
    }

    // Копирование данных из одного стека в другой.
    // Данные из стека-операнда записываются в стек-адресат
    // Состояние стека-операнда не изменяется.
    Stack &Stack::operator+=(const Stack &st) {
        int new_top = top + st.top;
        if(new_top >= SZ) {
            resize(new_top + QUOTA);
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