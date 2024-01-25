//lab3, 26 variant, forum
#include <iostream>
#include "forum/forum.h"
int main(){
    using namespace forum;
    Forum forum;//create forum
    int command;
    int ind;
    int sind;
    int b = 1;//flag for info of user
    int a = 1;//flag for going to section
    int stat;
    std::string name;
    std::string sname;

    std::cin >> name;
    Member mem(name);
    std::cin >> name;
    Member mem2(name);
    Moderator mod(mem);
    forum.addMember(mem);
    forum.addMember(mem2);
    forum.showMembers();
std::string str = "Lexus";
    Section section2(str);
    forum.addSection(section2);
    forum.Sections.at(0).addmember(mem);
    forum.Sections.at(0).addmember(mem2);
    forum.Sections.at(0).makemoder(mem);
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
                        if(forum.istherename(name)){
                            std::cout << "Sorry, we already have a member with that name\n";
                        }else {
                            Member member(name);
                            forum.addMember(member);
                        }
                        break;
                    }
                    case 4: {//add a section
                        std::cin >> sname;
                        Section section(sname);
                        std::cout << "Enter a index of user: ";
                        ind = getvalue(1, forum.Members.size());
                        Moderator moder(forum.Members.at(ind - 1));
                        section.addmoderator(moder);
                        forum.addSection(section);
                        break;
                    }
                    case 5: {//go to a section
                        if(forum.Sections.size() > 0) {
                            std::cout << "Enter an index of Section: ";
                            sind = getvalue(1, forum.Sections.size());
                            while (a == 1) {
                                std::cout << "\n__________________________________________________________\n";
                                std::cout << "1. Show section               2. One model process\n"
                                          << "3. Result of model processes  4. The most successful troll\n"
                                          << "5. Make moderator             6. Make troll\n"
                                          << "7. Change moderator           8. Change troll\n"
                                          << "9. Exit\n"
                                          << "__________________________________________________________" << std::endl;
                                command = getvalue(1, 9);
                                switch (command) {
                                    case 1: {
                                        std::cout << forum.Sections.at(sind - 1);
                                        break;
                                    }
                                    case 2: {
                                        break;
                                    }
                                    case 3: {
                                        break;
                                    }
                                    case 4: {
                                        break;
                                    }
                                    case 5: {
                                        std::cout << "Enter a index of user: ";
                                        ind = getvalue(1, forum.Sections.at(sind - 1).Members.size());
                                        std::cout << forum.Sections.at(sind - 1).Members.at(ind - 1);
                                        Moderator mod(forum.Sections.at(sind - 1).Members.at(ind - 1));
                                        forum.Sections.at(ind - 1).addmoderator(mod);
                                        forum.Sections.at(ind - 1).delmember(forum.Sections.at(sind - 1).Members.at(ind - 1).getlogin());
                                        break;
                                    }
                                    case 6: {
                                        std::cout << "Enter a index of user: ";
                                        ind = getvalue(1, forum.Sections.at(sind - 1).Members.size());
                                        Troll troll(forum.Sections.at(sind - 1).Members.at(ind - 1));
                                        forum.Sections.at(ind - 1).addtroll(troll);
                                        forum.Sections.at(ind - 1).delmember(troll.getmember().getlogin());
                                        break;
                                    }
                                    case 7: {
                                        break;
                                    }
                                    case 8: {
                                        break;
                                    }
                                    case 9: {
                                        a = 0;
                                        break;
                                    }
                                }
                            }
                            a = 1;
                        }else{
                            std::cout << "No section to show" << std::endl;
                        }
                        /*std::cout << "Enter a index of the section where you can add a user: ";
                        sind = getvalue(1, forum.Sections.size());
                        std::cout << forum.Sections.at(sind - 1);*/
                        break;
                    }
                    case 6: {//add a user
                        std::cout << "Enter a index of user: ";
                        ind = getvalue(1, forum.Members.size());
                        std::cout << "Enter a index of the section where you can add a user: ";
                        sind = getvalue(1, forum.Sections.size());
                        if(forum.Members.at(ind - 1).getsection() == none){
                            forum.Sections.at(sind - 1).addmember(forum.Members.at(ind - 1));
                            forum.Members.at(ind - 1).changesection(forum.Sections.at(sind - 1).getname());
                            forum.Members.at(ind - 1.).online();
                        }else{
                            std::cout << "Oops, that member is busy!\n";
                        }
                        break;
                    }
                    case 7: {//info about user
                        if(forum.Members.size() > 0) {
                            std::cout << "Enter a index of user";
                            ind = getvalue(1, forum.Members.size());
                            while (b == 1) {
                                std::cout << "__________________________________\n";
                                std::cout << "1. Show details   2. Change status\n"
                                          << "3. Delete user    4. Exit \n"
                                          << "__________________________________" << std::endl;
                                command = getvalue(1, 4);
                                switch (command) {
                                    case 1: {
                                        std::cout << "The user you asked for: \n";
                                        if (forum.Members.empty()) {
                                            std::cout << "Nobody to show" << std::endl;
                                        } else {
                                            std::cout << forum.Members.at(ind - 1);
                                        }
                                        break;
                                    }
                                    case 2: {
                                        std::cout << "What status do you want: (online, offline, banned)";
                                        stat = getvalue(1, 3);
                                        switch(stat){
                                            case 1: {
                                                forum.Members.at(ind - 1).online();
                                                break;
                                            }
                                            case 2: {
                                                forum.Members.at(ind - 1).offline();
                                                break;
                                            }
                                            case 3: {
                                                forum.Members.at(ind - 1).banned();
                                                break;
                                            }
                                        }
                                        std::cout << "The status changed." << std::endl;
                                        break;
                                    }
                                    case 3: {
                                        forum.Members.erase(forum.Members.begin() + ind - 1,
                                                            forum.Members.begin() + ind);
                                        std::cout << "User with number " << ind << " was deleted." << std::endl;
                                        b = 0;
                                        break;
                                    }
                                    case 4: {
                                        b = 0;
                                        break;
                                    }
                                }
                            }
                            b = 1;
                        }else{
                            std::cout << "Nobody to show" << std::endl;
                        };
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