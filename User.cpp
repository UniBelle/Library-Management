#include "User.h"
using namespace std;
#include <iostream>

User::User()
{
      ID = "AB0000";
      name = "Default";
      emailAddress = "name@email.com";
}
void User::setUserData(string id,string nam,string eAddress)
{
   this-> ID = id;
   this-> name = nam;
   this-> emailAddress = eAddress;
}
string User::getID()
{
    return ID;
}
string User::getName()
{
    return name;
}
string User::getEmailAddress()
{
   return emailAddress;
}
