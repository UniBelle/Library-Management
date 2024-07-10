#ifndef MEMBER_H
#define MEMBER_H
#include <string>
using namespace std;
#include "User.h"


class Member : public User
{
    private:
        string address;
        string gender;
    public:
        Member();
        void setMemberData(string addr, string gen,string id,string nam,string eAddress);
        void getMemberData();
        string getMemberName();
        string getMemberEmail();

};

#endif // MEMBER_H
