#ifndef LAB3_FORUM_H
#define LAB3_FORUM_H
#include <iostream>
#include <vector>
namespace forum{
    const std::string none = "none";
    int getvalue(int a, int b);
    struct Time{
        int h;
        int m;
    };
    class Member{
        std::string login; //name
        Time TimeReg;// time of reg
        int status;//1 - online, 2 - offline, 3 - banned
        int messages;//number of messages
        std::string section;//in what section user remains
    public:
        Member();
        explicit Member(const std::string& l);
        void online();
        void offline();
        void banned();
        void changesection(const std::string& sname);//
        [[nodiscard]] std::string getlogin()const;
        std::string& getsection() const;
        Member& operator= (const Member& mem);
        friend std::ostream& operator<< (std::ostream& o, Member& member);
    };

    class Moderator:public Member{
//        Member& member;
        int mind;
    public:
//        Moderator();
        explicit Moderator(Member &member);
//        std::string getlogin();
//        Member& getmember();
        void setmind(int m);
//        void setbanned();
        Moderator& operator= (const Moderator& mem);
        friend std::ostream& operator<< (std::ostream& o, Moderator& moderator);
    };

    class Troll: public Member{
//        Member& member;
        float thickness;
        int banned;
    public:
//        Troll();
        explicit Troll(Member& mem);
        explicit Troll(Moderator& mod);//
//        std::string getlogin();
//        Member& getmember();
        float getthick()const;
        int getbanned() const;
        void setthick();
        Troll& operator= (const Troll& troll);
        friend std::ostream& operator<< (std::ostream& o, Troll& troll);
    };

    class Section{
    public:
        std::string name;
        std::vector <Member*> Members;
       // std::vector <Moderator> Moderators;
       // std::vector <Troll> Trolls;
        Section(const std::string& sname);
        void ModelOne();
        void ModelResult();
        Troll& successful_troll()const;
        void addmember(const Member& mem);
        void makemoder(const Member& mem);//sts::string login
        void addmoderator(Moderator& mod);
        void addtroll(Troll& troll);
        std::string getname() const;
        void delmember(std::string name);
        void delmod(std::string name);
        void deltroll(std::string name);
        bool istherename(std::string str);
        friend std::ostream& operator<< (std::ostream& o, Section& section);
    };

    class Forum{
    public:
        //std::vector<Member*> Members;
        std::vector<Section> Sections;

        void addMember(Member& member, Section& section);
        void addSection(Section& section);
        void showMembers();
        void showSections();
        bool istherename(std::string str);
    };

    Member& TrollMem(Troll& troll);
}
#endif //LAB3_FORUM_H
