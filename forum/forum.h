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
        int messages;//number of messages
        int status;//1 - online, 2 - offline, 3 - banned
        std::string section;//in what section user remains
    public:
        Member();
        explicit Member(std::string& l);
        void online();
        void offline();
        void banned();
        [[nodiscard]] std::string getlogin()const;
        Member& operator= (const Member& mem);
        friend std::ostream& operator<< (std::ostream& o, Member& member);
    };

    class Moderator{
        Member& member;
        int mind;
    public:
//        Moderator();
        explicit Moderator(Member &member);
        std::string getlogin();
        Member& getmember();
        void setmind(int m);
        void setbanned();
        friend std::ostream& operator<< (std::ostream& o, Moderator& moderator);
    };

    class Troll{
        Member& member;
        float thickness;
        int banned;
    public:
//        Troll();
        explicit Troll(Member& mem);
        explicit Troll(Moderator& mod);
        std::string getlogin();
        Member& getmember();
        float getthick()const;
        int getbanned();
        void setthick();
        friend std::ostream& operator<< (std::ostream& o, Troll& troll);
    };

    class Section{
        std::string name;
        std::vector <Member> Members;
        std::vector <Moderator> Moderators;
        std::vector <Troll> Trolls;
    public:
        Section(std::string& sname);
        void ModelOne();
        void ModelResult();
        Troll& successful_troll();
        void addmember(Member& mem);
/*        void addmoderator(Moderator& mod);
        void addtroll(Troll& troll);*/
        std::string getname();
        friend std::ostream& operator<< (std::ostream& o, Section& section);
    };

    class Forum{
    public:
        std::vector<Member> Members;
        std::vector<Section> Sections;

        void addMember(Member& member);
        void addSection(Section& section);
        void showMembers();
        void showSections();
    };

    Member& TrollMem(Troll& troll);
}
#endif //LAB3_FORUM_H
