#ifndef USER_H
#define USER_H
#include <string>
using namespace std;


class User
{
    private:
      string ID;
      string name;
      string emailAddress;
    public:
        User();
        void setUserData(string id,string nam,string eAddress);
        string getName();
        string getEmailAddress();
        string getID();


};

#endif // USER_H
