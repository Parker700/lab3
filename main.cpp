//lab3, 26 variant, forum
#include <iostream>
#include "forum/forum.h"
int main(){
    using namespace forum;
    try {
        Forum forum;//create forum
        std::string sstr = "Table";
        std::string str = "Ali";
        Member memb(str);
        Section section(sstr);
        forum.addSection(section);
        forum.getsections().at(0).addmember(memb);
        str = "Tom";
        Moderator mod(str);
        forum.getsections().at(0).addmoderator(mod);
        int command;
//        int ind;
        int sind;
        int p;//for member, mod or troll
        int a = 1;//for little loop
        std::string sname;//name for section
        std::string name;//name for user
        while (true) {
            std::cout << "\n____________________________________\n";
            std::cout << "1. Show sections    2. Go to section\n"
                      << "3. New user         4. New section\n"
                      << "5. Quit\n"
                      << "____________________________________" << std::endl;
            try {
                std::cout << "Enter a command number ";
                command = getvalue(1, 5);
                switch(command){
                    case 1: {//show sections
                        std::cout << "Sections of the forum: ";
                        forum.showSections();
                        break;
                    }
                    case 2: {//go to section
                        if(forum.getsections().size() > 0) {
                            forum.showSections();
                            std::cout << "Enter an index of Section: ";
                            sind = getvalue(1, forum.getsections().size());
                            int x;//2 choice
                            int w;
                            int y; //index of section
                            while (a == 1) {
                                std::cout << "\n__________________________________________________________\n";
                                std::cout << "1. Show section               2. One model process\n"
                                          << "3. Result of model processes  4. The most successful troll\n"
                                          << "5. Make member                6. Make moderator\n"
                                          << "7. Make troll                 8. Replace user\n"
                                          << "9. Change status of user      0. Exit\n"
                                          << "__________________________________________________________" << std::endl;
                                command = getvalue(1, 9);
                                switch(command){
                                    case 1: {
                                        std::cout << forum.getsections().at(sind - 1);
                                        break;
                                    }
                                    case 2: {
                                        forum.getsections().at(sind - 1).ModelOne();
                                        break;
                                    }
                                    case 3: {
                                        forum.getsections().at(sind - 1).ModelResult();
                                        break;
                                    }
                                    case 4: {
                                        std::cout << forum.getsections().at(sind - 1).successful_troll();
                                        break;
                                    }
                                    case 5: {
                                        std::cout << "You want to make Member 1.Moderator or 2.Troll: ";
                                        x = getvalue(1, 2);
                                        switch(x){
                                            case 1: {
                                                if(!forum.getsections().at(sind - 1).getmoderators().empty()) {
                                                    std::cout << "Index of Moderator: ";
                                                    w = getvalue(1, forum.getsections().at(sind - 1).getmoderators().size());
                                                    forum.getsections().at(sind - 1).makemember((forum.getsections().at(sind - 1).getmoderators().at(w - 1)));
                                                }else{
                                                    std::cout << "OOps" << std::endl;
                                                }
                                                break;
                                            }
                                            case 2: {
                                                    if(!forum.getsections().at(sind - 1).gettrolls().empty()) {
                                                        std::cout << "Index of Troll: ";
                                                        w = getvalue(1,forum.getsections().at(sind - 1).gettrolls().size());
                                                        forum.getsections().at(sind - 1).makemember((forum.getsections().at(sind - 1).gettrolls().at(w - 1)));
                                                    }else{
                                                        std::cout << "OOps" << std::endl;
                                                    }
                                                    break;
                                                }
                                        }
                                        break;
                                    }
                                    case 6: {
                                        std::cout << "You want to make Moderator 1.Member or 2.Troll: ";
                                        x = getvalue(1, 2);
                                        switch(x) {
                                            case 1: {
                                                if (!forum.getsections().at(sind - 1).getmembers().empty()) {
                                                    std::cout << "Index of Member: ";
                                                    w = getvalue(1, forum.getsections().at(
                                                            sind - 1).getmembers().size());
                                                    forum.getsections().at(sind - 1).makemoder(
                                                            (forum.getsections().at(sind - 1).getmembers().at(
                                                                    w - 1)));
                                                } else {
                                                    std::cout << "OOps, there is nothing" << std::endl;
                                                }
                                                break;
                                            }
                                            case 2: {
                                                if (!forum.getsections().at(sind - 1).gettrolls().empty()) {
                                                    std::cout << "Index of Troll: ";
                                                    w = getvalue(1,
                                                                 forum.getsections().at(sind - 1).gettrolls().size());
                                                    forum.getsections().at(sind - 1).makemoder(
                                                            (forum.getsections().at(sind - 1).gettrolls().at(w - 1)));
                                                } else {
                                                    std::cout << "OOps there is nothing" << std::endl;
                                                }
                                                break;
                                            }
                                        }
                                        break;
                                    }
                                    case 7: {
                                        std::cout << "You want to make Troll 1.Member or 2.Moderator: ";
                                        x = getvalue(1, 2);
                                        switch(x) {
                                            case 1: {
                                                if (!forum.getsections().at(sind - 1).getmembers().empty()) {
                                                    std::cout << "Index of Member: ";
                                                    w = getvalue(1, forum.getsections().at(
                                                            sind - 1).getmembers().size());
                                                    forum.getsections().at(sind - 1).maketroll(
                                                            (forum.getsections().at(sind - 1).getmembers().at(
                                                                    w - 1)));
                                                } else {
                                                    std::cout << "OOps, there is nothing" << std::endl;
                                                }
                                                break;
                                            }
                                            case 2: {
                                                if (!forum.getsections().at(sind - 1).getmoderators().empty()) {
                                                    std::cout << "Index of Moderator: ";
                                                    w = getvalue(1,
                                                                 forum.getsections().at(sind - 1).getmoderators().size());
                                                    forum.getsections().at(sind - 1).maketroll(
                                                            (forum.getsections().at(sind - 1).getmoderators().at(w - 1)));
                                                } else {
                                                    std::cout << "OOps there is nothing" << std::endl;
                                                }
                                                break;
                                            }
                                        }
                                        break;
                                    }
                                    case 8: {
                                        forum.showSections();
                                        if (!forum.getsections().empty()) {
                                            std::cout << "To what section: ";
                                            y = getvalue(1, forum.getsections().size());
                                            std::cout << "What do you want ot make out: 1.Member 2. Moderator 3. Troll";
                                            x = getvalue(1, 3);
                                            switch (x) {
                                                case 1: {
                                                    if (!forum.getsections().at(sind - 1).getmembers().empty()) {
                                                        std::cout << "Index of Member: ";
                                                        w = getvalue(1,forum.getsections().at(sind - 1).getmembers().size());
                                                        forum.getsections().at(y - 1).addmember(forum.getsections().at(sind - 1).getmembers().at(w-1));
                                                        forum.getsections().at(sind - 1).delmember(forum.getsections().at(sind-1).getmembers().at(w-1).getlogin());
                                                    } else {
                                                        std::cout << "OOps, there is nothing" << std::endl;
                                                    }
                                                    break;
                                                }
                                                case 2: {
                                                    if (!forum.getsections().at(sind - 1).getmoderators().empty()) {
                                                        std::cout << "Index of Moderator: ";
                                                        w = getvalue(1,forum.getsections().at(sind - 1).getmoderators().size());
                                                        forum.getsections().at(y - 1).addmoderator(forum.getsections().at(sind - 1).getmoderators().at(w-1));
                                                        forum.getsections().at(sind - 1).delmoderator(forum.getsections().at(sind-1).getmoderators().at(w-1).getlogin());
                                                    } else {
                                                        std::cout << "OOps, there is nothing" << std::endl;
                                                    }
                                                    break;
                                                }
                                                case 3: {
                                                    if (!forum.getsections().at(sind - 1).gettrolls().empty()) {
                                                        std::cout << "Index of Troll: ";
                                                        w = getvalue(1,forum.getsections().at(sind - 1).gettrolls().size());
                                                        forum.getsections().at(y - 1).addtroll(forum.getsections().at(sind - 1).gettrolls().at(w-1));
                                                        forum.getsections().at(sind - 1).deltroll(forum.getsections().at(sind-1).gettrolls().at(w-1).getlogin());
                                                    } else {
                                                        std::cout << "OOps, there is nothing" << std::endl;
                                                    }
                                                    break;
                                                }
                                            }
                                        }
                                        break;
                                    }
                                    case 9: {
                                        std::cout << "Do you want to change 1.status, 2.mind or 3.thickness: ";
                                        x = getvalue(1, 3);
                                        switch(x){
                                            case 1: {
                                                std::cout << "\nYou want to change for 1.Member, 2.Moderator or 3.Troll: ";
                                                y = getvalue(1, 3);
                                                switch(y){
                                                    case 1: {
                                                        if(!forum.getsections().at(sind-1).getmembers().empty()) {
                                                            int s;
                                                            std::cout << "Enter an index for member: ";
                                                            w = getvalue(1, forum.getsections().at(
                                                                    sind - 1).getmembers().size());
                                                            std::cout
                                                                    << "Enter a status 1.online, 2.offline or 3.banned: ";
                                                            s = getvalue(1, 3);
                                                            forum.getsections().at(sind - 1).getmembers().at(
                                                                    w - 1).setstatus(s);
                                                        }else{
                                                            std::cout << "OOps, there is nothing, sorry" << std::endl;
                                                        }
                                                        break;
                                                    }
                                                    case 2: {
                                                        if(!forum.getsections().at(sind-1).getmoderators().empty()) {
                                                            int s;
                                                            std::cout << "Enter an index for moderator: ";
                                                            w = getvalue(1, forum.getsections().at(
                                                                    sind - 1).getmoderators().size());
                                                            std::cout
                                                                    << "Enter a status 1.online, 2.offline or 3.banned: ";
                                                            s = getvalue(1, 3);
                                                            forum.getsections().at(sind - 1).getmoderators().at(
                                                                    w - 1).setstatus(s);
                                                        }else{
                                                            std::cout << "OOps, there is nothing, sorry" << std::endl;
                                                        }
                                                        break;
                                                    }
                                                    case 3: {
                                                        if(!forum.getsections().at(sind-1).gettrolls().empty()) {
                                                            int s;
                                                            std::cout << "Enter an index for troll: ";
                                                            w = getvalue(1, forum.getsections().at(
                                                                    sind - 1).gettrolls().size());
                                                            std::cout
                                                                    << "Enter a status 1.online, 2.offline or 3.banned: ";
                                                            s = getvalue(1, 3);
                                                            forum.getsections().at(sind - 1).gettrolls().at(
                                                                    w - 1).setstatus(s);
                                                        }else{
                                                            std::cout << "OOps, there is nothing, sorry" << std::endl;
                                                        }
                                                        break;
                                                    }
                                                }
                                                break;
                                            }case 2: {
                                                if(!forum.getsections().at(sind-1).getmoderators().empty()) {
                                                    int m;
                                                    std::cout << "Enter a number of mind for moderator: ";
                                                    m = getvalue(1, 10);
                                                    std::cout << "Enter an index of moderator: ";
                                                    int i = getvalue(1, forum.getsections().at(
                                                            sind - 1).getmoderators().size());
                                                    forum.getsections().at(sind - 1).getmoderators().at(i - 1).setmind(
                                                            m);
                                                }else{
                                                    std::cout << "There is no moderator, sorry" << std::endl;
                                                }
                                                break;
                                            }
                                            case 3: {
                                                if(!forum.getsections().at(sind-1).gettrolls().empty()) {
                                                    float th;
                                                    std::cout << "\nEnter a denominator: ";
                                                    y = getvalue(1, 10);
                                                    th = 1 / (float) y;
                                                    std::cout << "\nEnter an index of troll: ";
                                                    int i = getvalue(1, forum.getsections().at(
                                                            sind - 1).gettrolls().size());
                                                    forum.getsections().at(sind - 1).gettrolls().at(i - 1).setthick(th);
                                                }else{
                                                    std::cout << "There is no troll, sorry" << std::endl;
                                                }
                                                break;
                                            }
                                        }
                                        break;
                                    }
                                    case 0: {
                                        a = 0;
                                        break;
                                    }
                                }
                            }
                            a = 1;
                        }
                        break;
                    }
                    case 3: {//new user
                        std::cout << "Enter a name of user: ";
                        std::cin >> name;
                        if(forum.istherename(name)) {
                            std::cout << "Oops, that member is busy!\n";
                        }else{
                            forum.showSections();
                            if(!forum.getsections().empty()){
                                std::cout << "Enter a index of the section where you can add a user: ";
                                sind = getvalue(1, forum.getsections().size());
                                std::cout << "Do you want 1.Member, 2.Moderator or 3.Troll: ";
                                p = getvalue(1, 3);
                                switch (p) {
                                    case 1: {
                                        Member mem(name);
                                        forum.getsections().at(sind - 1).addmember(mem);
                                        break;
                                    }
                                    case 2: {
                                        Moderator mod(name);
                                        forum.getsections().at(sind - 1).addmoderator(mod);
                                        break;
                                    }
                                    case 3: {
                                        Troll troll(name);
                                        forum.getsections().at(sind - 1).addtroll(troll);
                                        break;
                                    }
                                }
                            }
                        }
                        break;
                    }
                    case 4: {//new section
                        std::cout << "The name of a new section: ";
                        std::cin >> sname;
                        Section section(sname);
                        std::cout << "Moderator of the section: ";
                        std::cin >> name;
                        Moderator mod(name);
                        section.addmoderator(mod);
                        forum.addSection(section);
                        break;
                    }
                    case 5: {//quit
                        return 0;
                    }
                }
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