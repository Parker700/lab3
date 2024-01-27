#ifndef LAB3_FORUM_H
#define LAB3_FORUM_H
#include <iostream>
#include <vector>
namespace forum{
//    const std::string none = "none";
    const std::string none = "none";
    int getvalue(int a, int b);
    typedef struct Time{
        int h;
        int m;
    }Time;
    class Moderator;
    class Troll;
    class Member{
        std::string login; //name
        Time TimeReg;// time of reg
        int status;//1 - online, 2 - offline, 3 - banned
        int messages;//number of messages
    public:
        Member();
        explicit Member(const std::string& l);
        Member(Moderator& mod);
        Member(Troll& troll);
        //getters
        std::string& getlogin();
        Time& gettimereg();
        int getstatus()const;
        int getmessages()const;
        //setters
        void setlogin(const std::string& name);
        void settimereg(Time& time);
        void setstatus(const int stat);
        void setmessages(int mess);
        //operators
        friend std::ostream& operator<< (std::ostream& o, Member& member);
//        Member& operator= (const Member& mem);
    };

    class Moderator: public Member{
        int mind;
    public:
        explicit Moderator(const std::string& l);
        explicit Moderator(Member& mem);
        explicit Moderator(Troll& troll);
        //getters
        int getmind()const;
        //setters
        void setmind(int m);
        //operators
        friend std::ostream& operator<< (std::ostream& o, Moderator& moderator);
//        Moderator& operator= (const Moderator& mem);
    };

    class Troll: public Member{
        float thickness;
        int banned;
    public:
        explicit Troll(std::string& l);
        explicit Troll(Member& mem);
        explicit Troll(Moderator& mod);//for what
        //getters
        float getthick()const;
        int getbanned() const;
        //setters
        void setthick(const float thick);
        void setbanned(const int ban);
        //operators
        friend std::ostream& operator<< (std::ostream& o, Troll& troll);
        //Troll& operator= (const Troll& troll);
    };

    class Section{
    private:
        std::string name;
        std::vector <Member> Members;
        std::vector <Moderator> Moderators;
        std::vector <Troll> Trolls;
    public:
        Section(const std::string& sname);
        //Modeling
        void ModelOne();
        void ModelResult();
        Troll& successful_troll();//done
        //getters
        std::string& getname();
        std::vector<Member>& getmembers();
        std::vector<Moderator>& getmoderators();
        std::vector<Troll>& gettrolls();
        //add setter
        void addmember(Member& mem);
        void addmoderator(Moderator& mod);
        void addtroll(Troll& troll);
        //delete
        void delmember(std::string& nm);
        void delmoderator(std::string& nm);
        void deltroll(std::string& nm);
        //modification
        void makemember(Moderator& mod);
        void makemember(Troll& troll);
        void makemoder(Member& mem);//sts::string login
        void makemoder(Troll& troll);
        void maketroll(Member& mem);
        void maketroll(Moderator& mod);
        //additional
        bool isthere(std::string& str);
        bool isinmember(std::string& str);
        bool isinmoderator(std::string& str);
        bool isintroll(std::string& str);
        //operators
        friend std::ostream& operator<< (std::ostream& o, Section& section);
    };

    class Forum{
    private:
        std::vector<Section> Sections;
    public:
        Forum();
        //getter
        std::vector<Section>& getsections();
        //add setter
        void addMember(Member& member, Section& section);
        void addSection(Section& section);
        //sow
//        void showMembers();
        void showSections();
        //additional
        bool istherename(std::string str);
    };
}
#endif //LAB3_FORUM_H
