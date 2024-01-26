//lab3, 26 variant, forum
#include <iostream>
#include "forum/forum.h"
int main(){
    using namespace forum;
    Forum forum;//create forum
    std::string name = "Alibi";
    Member mem(name);
    std::cout << mem;
    Moderator mod(name);
    std::cout << mod;
    Troll troll(name);
    Member mem2("Nabi");
    Section section(name);
    section.addmember(mem);
//    section.addmember(mem);
//    section.addmember(mem2);
    section.addmoderator(mod);
    std::string nm2 = "Nabi";
//    section.delmember(nm2);
//    section.delmoderator(name);
    Moderator mod2(mem2);
    section.addmoderator(mod2);
    std::cout << section;
    section.makemember(section.getmoderators().at(2 - 1));
    std::cout << section;
    section.makemoder(section.getmembers().at(2 - 1));
    std::cout << section;
    std::cout << section.isinmember(name);
    std::string lexus = "Lexus";
    std::cout << section.isinmoderator(name);
    forum.addSection(section);
    section.addtroll(troll);
    std::cout << "all: " <<  forum.istherename(name) << std::endl;
    section.getmoderators().at(1).setstatus(2);
    std::cout << section;
    section.ModelOne();
    std::cout << section;
    section.ModelResult();
    try {
        while (false) {
            try {

            }catch(const std::bad_alloc &ex){
                std::cerr << "Not enough memory" << std::endl;
            }catch (const std::invalid_argument) {
                    std::cout << "Please try again" << std::endl;
            }
        }
    }catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    return 0;
}