#include <iostream>
#include "forum.h"
#include <ctime>
#include <random>
namespace forum{
    int random(int a, int b){
        std::random_device rd;   // non-deterministic generator
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(a,b);
        return dist(gen);
    }
    int getvalue(const int a, const int b) {
        int num;
        while (true) {
            std::cout << "[" << a << "; " << b << "]: ";
            std::cin >> num;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number.\n";
                continue;
            }
            if (num <= b && num >= a) {
                return num;
            } else {
                std::cout << "That is wrong, please, repeat.\n";
            }
        }
    }
    Member::Member(){
        login = "Guest";
        time_t now = time(nullptr);
        tm *ltm = localtime(&now);
        TimeReg.h = ltm->tm_hour;
        TimeReg.m = ltm->tm_min;
        section = none;
        messages = 0;
        status = 2;
    }
    Member::Member(std::string& l){
        login = l;
        time_t now = time(nullptr);
        tm *ltm = localtime(&now);
        TimeReg.h = ltm->tm_hour;
        TimeReg.m = ltm->tm_min;
        section = none;
        messages = 0;
        status = 2;
    }
    void Member::online(){
        status = 1;
    }
    void Member::offline(){
        status = 2;
    }
    void Member::banned(){
        status = 3;
    }
    std::string Member::getlogin() const{
        return login;
    }
    Member& Member::operator= (const Member& mem)= default;

    std::ostream& operator<< (std::ostream& o, Member& member){
        o << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        o << member.login << "  Registered at " << member.TimeReg.h << ":" << member.TimeReg.m << "\nMessages: " << member.messages;
        o << "\nSection: \"" << member.section << "\"; Status: ";
        if(member.status == 1){
            o << "online";
        }else if(member.status == 2){
            o << "offline";
        }else{
            o << "banned ";
        }
        o << ";\n";
        return o;
    }

    //Moderator
    Moderator::Moderator(Member &member) : member(member) {
        mind = random(1, 10);
    }
    std::string Moderator::getlogin(){
        return member.getlogin();
    }
    Member& Moderator::getmember(){
        return member;
    }
    void Moderator::setmind(int m){
        mind = m;
    }
    void Moderator::setbanned(){
        member.banned();
    }
    std::ostream& operator<< (std::ostream& o, Moderator& moderator){
        o << moderator.member;
        o << "Smart index: " << moderator.mind << "\n";
        return o;
    }

    //Troll
    Troll::Troll(Member& mem):member(mem){
        thickness = (1 / (float)random(1, 10));
        banned = 0;
    }
    Troll::Troll(Moderator& mod):member(mod.getmember()){
        thickness = (1 / (float)random(1, 10));
        banned = 0;
    }
    Member& Troll::getmember(){
        return member;
    }
    std::string Troll::getlogin(){
        return member.getlogin();
    }
    std::ostream& operator<< (std::ostream& o, Troll& troll){
        o << troll.member;
        o << "Thickness: " << troll.thickness;
        o << "\nNumber of banned users: " << troll.banned << "\n";
        return o;
    }
    float Troll::getthick()const{
        return thickness;
    }

    //Section
    Section::Section(std::string& sname): name(sname) {}
    std::string Section::getname(){
        return name;
    }

    void Section::addmember(Member& mem){
        Members.push_back(mem);
    }
    std::ostream& operator<< (std::ostream& o, Section& section){
        o << "Section name: " << section.getname();

        o << "\n";
        return o;
    }
/*    void Section::addmoderator(Moderator& mod){
        Moderators.push_back(mod);
    }
    void Section::addtroll(Troll& troll){
        Trolls.push_back(troll);
    }*/





    //Forum
    void Forum::addMember(Member& member){
        Members.push_back(member);
    }
    void Forum::addSection(Section& section){
        Sections.push_back(section);
    }
    void Forum::showMembers(){
        if(Members.empty()) {
            std::cout << "There is no users;";
        }else {

            for (int i = 0; i < Members.size(); i++) {
                std::cout << i + 1 << ") " << Members.at(i).getlogin() << "; ";
            }
        }
        std::cout << "\n";
    }
    void Forum::showSections(){
        if(Sections.empty()){
            std::cout << "There is no sections.";
        }else {
            for (int i = 0; i < Sections.size(); i++) {
                std::cout << i + 1 << ") " << Sections.at(i).getname() << "; ";
            }
        }
        std::cout << std::endl;
    }

    Member& TrollMem(Troll& troll){
        return troll.getmember();
    }
}




/*
Member& Member::operator= (const Member& mem){
    login = mem.login;
    TimeReg = mem.TimeReg;
    messages = mem.messages;
    status = mem.status;
    section = mem.section;
    return *this;
}*/
