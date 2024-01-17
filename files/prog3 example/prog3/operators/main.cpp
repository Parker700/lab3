#include "stack.h"

using namespace Prog3;

int main() {
    Stack st;
    std::cout << "1. Push into stack: max size = " << st.getMaxSize() << std::endl;
    try {
        for(int i = 0; i < 12; ++i)
            st.push(12 + i * 10);
    }
    catch(const std::exception &msg) {
        std::cout << msg.what() << std::endl;
    }
    std::cout << "Current size = " << st.getSize() << "; In stack : \n";
    {
        Stack newst(st), tmpst;
        std::cout << "2. New block:\n in new stack: \n" << newst << std::endl;
        std::cout << "3. Push into local tmp stack: \n";
        for(int i = 0; i < 8; ++i)
            // перегруженный оператор += и преобразование типа вместо push()
            tmpst += (25 + i * 10);

        std::cout << "In tmp stack: \n" << tmpst << std::endl << std::endl;
        std::cout << "4. Copying from new stack into tmp stack: \n";
        try {
            tmpst += newst;
        }
        catch(const std::exception &msg) {
            std::cout << msg.what() << std::endl;
        }
        std::cout << "In new stack: \n" << newst << std::endl;
        std::cout << "In tmp stack: \n" << tmpst << std::endl << std::endl;
        std::cout << "5. Remove from new stack: \n";
        while(newst)
            std::cout << newst.pop() << ' ';
        std::cout << std::endl;
        std::cout << "In new stack: \n" << newst << std::endl << std::endl;
    }
    std::cout << "6. The first stack in the first block: \n" << st << std::endl;
    return 0;
}