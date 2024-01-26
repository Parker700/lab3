#include <iostream>
#include "forum.h"
#include <ctime>
#include <random>
namespace forum {
    int random(int a, int b) {
        std::random_device rd;   // non-deterministic generator
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(a, b);
        return dist(gen);
    }
    int getvalue(const int a, const int b) {
        int num;
        while (true) {
            std::cout << "[" << a << "; " << b << "]: ";
            std::cin >> num;
            if (std::cin.fail()) {
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
        messages = 0;
        status = 2;
//        section = none;
    }
    Member::Member(const std::string &l) {
        login = l;
        time_t now = time(nullptr);
        tm *ltm = localtime(&now);
        TimeReg.h = ltm->tm_hour;
        TimeReg.m = ltm->tm_min;
        messages = 0;
        status = 2;
    }
    Member::Member(Moderator& mod){
        login = mod.getlogin();
        TimeReg = mod.gettimereg();
        status = mod.getstatus();
        messages = mod.getmessages();
    }
    Member::Member(Troll& troll){
        login = troll.getlogin();
        TimeReg = troll.gettimereg();
        status = troll.getstatus();
        messages = troll.getmessages();
    }

    //getters
    std::string &Member::getlogin(){
        return login;
    }
    Time &Member::gettimereg(){
    return TimeReg;
    }
    int Member::getstatus()const{
        return status;
    }
    int Member::getmessages()const{
        return messages;
    }
    //setters
    void Member::setlogin(const std::string& name){
        login = name;
    }
    void Member::settimereg(Time& time){
        TimeReg = time;
    }
    void Member::setstatus(const int stat){
        status = stat;
    }
    void Member::setmessages(int mess){
        messages = mess;
    }

    //operators
    std::ostream& operator<< (std::ostream& o, Member& member){
        o << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        o << member.login << "  Registered at " << member.TimeReg.h << ":" << member.TimeReg.m;
        o << "\nStatus: ";
        if(member.status == 1){
            o << "online";
        }else if(member.status == 2){
            o << "offline";
        }else{
            o << "banned ";
        }
        o << ";\nMessages: " << member.messages << std::endl;
        return o;
    }
    //    Member& Member::operator= (const Member& mem)= default;



    //Moderator
    Moderator::Moderator(const std::string &l) {
        setlogin(l);
        mind = random(1, 10);
    }
    Moderator::Moderator(Member& mem){
        setlogin(mem.getlogin());
        settimereg(mem.gettimereg());
        setstatus(mem.getstatus());
        setmessages(mem.getmessages());
        mind = random(1, 10);
    }
    Moderator::Moderator(Troll& troll){
        setlogin(troll.getlogin());
        settimereg(troll.gettimereg());
        setstatus(troll.getstatus());
        setmessages(troll.getmessages());
        mind = random(1, 10);
    }
    //getter
    int Moderator::getmind()const{
        return mind;
    }
    //setter{
    void Moderator::setmind(int m){
        mind = m;
    }
    //operators
    std::ostream& operator<< (std::ostream& o, Moderator& moderator){
        o << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        o << moderator.getlogin() << "  Registered at " << moderator.gettimereg().h << ":" << moderator.gettimereg().m;
        o << "\nStatus: ";
        if(moderator.getstatus() == 1){
            o << "online";
        }else if(moderator.getstatus() == 2){
            o << "offline";
        }else{
            o << "banned ";
        }
        o << ";\nMessages: " << moderator.getmessages() << "\n";
        o << "Smart index: " << moderator.mind << std::endl;
        return o;
    }

    //Troll
    Troll::Troll(std::string& l) {
        setlogin(l);
        thickness = (1 / (float)random(1, 10));
        banned = 0;
    }
    Troll::Troll(Member& mem){
        setlogin(mem.getlogin());
        settimereg(mem.gettimereg());
        setstatus(mem.getstatus());
        setmessages(mem.getmessages());
        thickness = (1 / (float)random(1, 10));
        banned = 0;
    }
    Troll::Troll(Moderator& mod){
        setlogin(mod.getlogin());
        settimereg(mod.gettimereg());
        setstatus(mod.getstatus());
        setmessages(mod.getmessages());
        thickness = (1 / (float)random(1, 10));
        banned = 0;
    }
    //getters
    float Troll::getthick()const{
        return thickness;
    }
    int Troll::getbanned() const{
        return banned;
    }
    //setters
    void Troll::setthick(const float thick){
        thickness = thick;
    }
    void Troll::setbanned(const int ban){
        banned = ban;
    }
    //operators
    std::ostream& operator<< (std::ostream& o, Troll& troll){
        o << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        o << troll.getlogin() << "  Registered at " << troll.gettimereg().h << ":" << troll.gettimereg().m;
        o << "\nStatus: ";
        if(troll.getstatus() == 1){
            o << "online";
        }else if(troll.getstatus() == 2){
            o << "offline";
        }else{
            o << "banned";
        }
        o << ";\nMessages: " << troll.getmessages() << "\n";
        o << "Thickness: " << troll.thickness;
        o << "\nBanned users: " << troll.banned << std::endl;
        return o;
    }
    /*Troll& Troll::operator= (const Troll& troll){
        Troll trol(troll.member);
        trol.thickness = troll.thickness;
        trol.banned = troll.banned;
        return trol;
    }*/




    //Section
    Section::Section(const std::string& sname){
        name = sname;
    }
    std::string& Section::getname(){
        return name;
    }
    //Modeling
    void Section::ModelOne(){
        int mind = 0;
        float thick = 0;
        for(int i = 0; i < Moderators.size(); i++){
            if(Moderators.at(i).getstatus() == 1) {
                mind += Moderators.at(i).getmind();
            }
        }
        for(int i = 0; i < Trolls.size(); i++){
            if(Trolls.at(i).getstatus() == 1) {
                thick += (1 / Trolls.at(i).getthick());
            }
        }

        int w = 0;//trolls online
        for(int i = 0; i < Trolls.size(); i++){
            if(Trolls.at(i).getstatus() == 1){
                w = 1;//online moderator
            }
        }
        if((float)mind > thick){
            if(w == 1) {//was !Trolls.empty()
                Trolls.at(random(0, Trolls.size() - 1)).setstatus(3);
            }
        }else{
            if(!Trolls.empty()) {
                int d = 0;
                int b;
                int c;
                while(d == 0){//selecting member of moder
                    b = random(1, 2);
                    if(b == 1){
                        for(int i = 0; i < Members.size(); i++){
                            if(Members.at(i).getstatus() == 1){
                                d = 1;
                            }
                        }
                    }else{
                        for(int i = 0; i < Moderators.size(); i++){
                            if(Moderators.at(i).getstatus() == 1){
                                d = 1;
                            }
                        }
                    }

                }
                d = 0;
                if(b == 1){//banning
                    Member m;
                    m.setstatus(2);
                    while(m.getstatus() != 1){
                        c = random(0, Members.size() - 1);
                        m = Members.at(c);
                    }
                    Members.at(c).setstatus(3);
                }else{
                    Moderator moder(none);
                    moder.setstatus(2);
                    while(moder.getstatus() != 1) {
                        c = random(0, Moderators.size() - 1);
                        moder = Moderators.at(c);
                    }
                    Moderators.at(c).setstatus(3);
                }
                while(d == 0){//selecting member of moder
                    b = random(1, 2);
                    if(b == 1){
                        for(int i = 0; i < Members.size(); i++){
                            if(Members.at(i).getstatus() == 1){
                                d = 1;
                            }
                        }
                    }else{
                        for(int i = 0; i < Moderators.size(); i++){
                            if(Moderators.at(i).getstatus() == 1){
                                d = 1;
                            }
                        }
                    }
                }
                d = 0;
                if(b == 1){//making new troll
                    Member m;
                    m.setstatus(2);
                    while(m.getstatus() != 1){
                        c = random(0, Members.size() - 1);
                        m = Members.at(c);
                    }
                    maketroll(Members.at(c));
                }else{
                    Moderator moder(none);
                    moder.setstatus(2);
                    while(moder.getstatus() != 1) {
                        c = random(0, Moderators.size() - 1);
                        moder = Moderators.at(c);
                    }
                    maketroll(Moderators.at(c));
                }
                //starting making new moder
                int z = 0;//finding online member
                for(int i = 0; i < Moderators.size(); i++){
                    if(Moderators.at(i).getstatus() == 1){
                        d = 1;//online moderator
                    }
                }
                if(d == 0){// no online moderator
                    for(int i = 0; i < Members.size(); i++){
                        if(Members.at(i).getstatus() == 1){
                            z = 1;//online moderator
                        }
                    }
                    if(z == 1) {
                        Member m;
                        m.setstatus(2);
                        while (m.getstatus() != 1) {
                            c = random(0, Members.size() - 1);
                            m = Members.at(c);
                        }
                        makemoder(Members.at(c));
                    }
                }//end makeing new moder
            }
        }
        std::cout << mind << " - " << thick << "\n";
    }
    void Section::ModelResult(){
        int mind = 0;
        float thick = 0;
        for(int i = 0; i < Moderators.size(); i++){
            if(Moderators.at(i).getstatus() == 1) {
                mind += Moderators.at(i).getmind();
            }
        }
        for(int i = 0; i < Trolls.size(); i++){
            if(Trolls.at(i).getstatus() == 1) {
                thick += (1 / Trolls.at(i).getthick());
            }
        }
        if((float)mind > thick){
            std::cout << "Moderator are smarter than trolls.";
        }else{
            std::cout << "Trolls are smarter that moderators.";
        }
        std::cout << std::endl;
    }
    Troll& Section::successful_troll(){
        int b = 0;
        float th = 0;
        for(int i = 0; i < Trolls.size(); i++){
            if(Trolls.at(i).getthick() > th){
                b = i;
                th = Trolls.at(i).getthick();
            }
        }
        return Trolls.at(b);
    }
    //getters
    std::vector<Member>& Section::getmembers(){
        return Members;
    }
    std::vector<Moderator>& Section::getmoderators(){
        return Moderators;
    }
    std::vector<Troll>& Section::gettrolls(){
        return Trolls;
    }

    //add
    void Section::addmember(Member& mem){
        mem.setstatus(1);
        Members.push_back(mem);
    }
    void Section::addmoderator(Moderator& mod){
        mod.setstatus(1);
        Moderators.push_back(mod);
    }
    void Section::addtroll(Troll& troll){
        troll.setstatus(1);
        Trolls.push_back(troll);
    }
    //delete
    void Section::delmember(std::string& nm){
        for(int i = 0; i < Members.size(); ++i){
            if(nm == Members.at(i).getlogin()){
                Members.erase(Members.begin() + i);
            }
        }
    }
    void Section::delmoderator(std::string& nm){
        for(int i = 0; i < Moderators.size(); ++i){
            if(nm == Moderators.at(i).getlogin()){
                Moderators.erase(Moderators.begin() + i);
            }
        }
    }
    void Section::deltroll(std::string& nm){
        for(int i = 0; i < Trolls.size(); ++i){
            if(nm == Trolls.at(i).getlogin()){
                Trolls.erase(Trolls.begin() + i);
            }
        }
    }
    //modification
    void Section::makemember(Moderator& mod){
        Member mem(mod);
        delmoderator( mem.getlogin());
        Members.push_back(mem);
    }
    void Section::makemember(Troll& troll){
        Member mem(troll);
        delmoderator( mem.getlogin());
        Members.push_back(mem);
    }
    void Section::makemoder(Member& mem){
        Moderator mod(mem);
        delmember(mod.getlogin());
        Moderators.push_back(mod);

    }
    void Section::makemoder(Troll& troll){
        Moderator mod(troll);
        deltroll(mod.getlogin());
        Moderators.push_back(mod);
    }
    void Section::maketroll(Member& mem){
        Troll troll(mem);
        delmember(troll.getlogin());
        Trolls.push_back(troll);
    }
    void Section::maketroll(Moderator& mod){
        Troll troll(mod);
        delmoderator(troll.getlogin());
        Trolls.push_back(troll);
    }
    //additional
    bool Section::isthere(std::string& str){
        bool u = isinmember(str);
        bool m = isinmoderator(str);
        bool t = isintroll(str);
        if(u || m || t){
            return true;
        }else{
            return false;
        }
    }
    bool Section::isinmember(std::string& str){
        for(int i = 0; i < Members.size(); ++i){
            if(str == Members.at(i).getlogin()){
                return true;
            }
        }
        return false;
    }
    bool Section::isinmoderator(std::string& str){
        for(int i = 0; i < Moderators.size(); ++i){
            if(str == Moderators.at(i).getlogin()){
                return true;
            }
        }
        return false;
    }
    bool Section::isintroll(std::string& str){
        for(int i = 0; i < Trolls.size(); ++i){
            if(str == Trolls.at(i).getlogin()){
                return true;
            }
        }
        return false;
    }
    //operators
    std::ostream& operator<< (std::ostream& o, Section& section){
        o << "#########################\n";
        o << "Section name: " << section.name << "\nUsers: ";
        for(int i = 0; i < section.Members.size(); i ++){
            o << i + 1 << ") " << section.Members.at(i).getlogin() << "(";
            if(section.Members.at(i).getstatus() == 1){
                o << "online";
            }else if(section.Members.at(i).getstatus() == 2){
                o << "offline";
            }else{
                o << "banned";
            }
            o << "); ";
        }
        std:: cout << std::endl << "Moderators: ";
        for(int i = 0; i < section.Moderators.size(); i ++){
            o << i + 1 << ") " << section.Moderators.at(i).getlogin() << "(";
            if(section.Moderators.at(i).getstatus() == 1){
                o << "online";
            }else if(section.Moderators.at(i).getstatus() == 2){
                o << "offline";
            }else{
                o << "banned";
            }
            o << ", ." << section.Moderators.at(i).getmind() << "); ";
        }
        std:: cout << std::endl << "Trolls: ";
        for(int i = 0; i < section.Trolls.size(); i ++){
            o << i + 1 << ") " << section.Trolls.at(i).getlogin() << "(";
            if(section.Trolls.at(i).getstatus() == 1){
                o << "online";
            }else if(section.Trolls.at(i).getstatus() == 2){
                o << "offline";
            }else{
                o << "banned";
            }
            o << ", #" << section.Trolls.at(i).getthick() << "); ";
        }
        o << "\n";
        return o;
    }



    //Forum
    Forum::Forum(){}
    //getters
    std::vector<Section>& Forum::getsections(){
        return Sections;
    }
    //setters

    //add
    void Forum::addSection(Section& section){
        Sections.push_back(section);
    }
    //show
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
     //additional
    bool Forum::istherename(std::string str){
        for(int i = 0; i < Sections.size(); i++){
            if(Sections.at(i).isthere(str)){
                return true;
            }
        }
        return false;
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
