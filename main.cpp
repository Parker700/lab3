//lab3, 26 variant, forum
#include <iostream>
#include "forum/forum.h"
int main(){
    using namespace forum;
    Forum forum;//create forum
    int command;
    int ind;
    int sind;
    std::string name;
    std::string sname;

/*
    std::cin >> name;
    Member mem(name);
    Member mem2;
    mem2 = mem;
    Moderator mod(mem);
    std::cout << mod;
    mod.setbanned();
    std::cout << mod;
    std::cout << mem;
    Troll troll (mod);
    std::cout << troll;
    forum.addMember(mem);
    forum.addMember(mem2);
    forum.showMembers();*/
    try {
        while(true) {
            std::cout << "____________________________________\n";
            std::cout << "1. Show users       2. Show sections\n"
            << "3. reg a user       4. Add a section\n"
            << "5. Go to a section  6. add a user to a section\n"
            << "7. Info of user     8. Quit\n"
            << "______________________________________________" << std::endl;
            try{
                std::cout << "Enter a command number ";
                command = getvalue(1, 8);
                switch(command){
                    case 1: {//show users
                        std::cout << "Users of forum: ";
                        forum.showMembers();
                        break;
                    }
                    case 2: {//show sections
                        std::cout << "Sections of the forum: ";
                        forum.showSections();
                        break;
                    }
                    case 3: {//reg a user
                        std::cin >> name;
                        Member member(name);
                        forum.addMember(member);
                        break;
                    }
                    case 4: {//add a section
                        std::cin >> sname;
                        Section section(sname);
                        forum.addSection(section);
                        break;
                    }
                    case 5: {//go to a section
                        std::cout << "Enter a index of the section where you can add a user: ";
                        sind = getvalue(1, forum.Sections.size());
                        std::cout << forum.Sections.at(sind - 1);
                        break;
                    }
                    case 6: {//add a user
                        std::cout << "Enter a index of user: ";
                        ind = getvalue(1, forum.Members.size());
                        std::cout << "Enter a index of the section where you can add a user: ";
                        sind = getvalue(1, forum.Sections.size());
                        forum.Sections.at(sind - 1).addmember(forum.Members.at(ind - 1));
                        break;
                    }
                    case 7: {//info about user
                        std::cout << "Enter a index of user";
                        ind = getvalue(1, forum.Members.size());
                        std::cout << "The user you asked for: \n" << forum.Members.at(ind - 1);
                        break;
                    }//quit
                    case 8: {
                        return 0;
                    }
                }
            }catch(const std::bad_alloc& ex)
            {
                std::cerr << "Not enough memory" << std::endl;
            }catch (const std::invalid_argument)
            {
                std::cout << "Please try again"<<std::endl;
            }
        }
    }catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    return 0;
}