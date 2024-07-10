#include "Member.h"
using namespace std;
#include <iostream>

Member::Member()
{
    address = "Default";
    gender = "Male/Female/Other";

}
void Member::setMemberData(string addr, string gen,string id,string nam,string eAddress)
{
    setUserData(id,nam,eAddress);
    this-> address = addr;
    this-> gender = gen;
}
string Member::getMemberName()
{
    return getName();
}
string Member::getMemberEmail()
{
    return getEmailAddress();
}
void Member::getMemberData()
{
   cout<< "_____________________________________________________________________________________________"<<endl;
   cout<< "|                  HA TSOLO COMMUNITY LIBRARY MANAGEMENT SYSTEM                             |"<<endl;
   cout<< "|___________________________________________________________________________________________|"<<endl;
   cout<< "|                            >>Library Members<<                                            |"<<endl;
   cout<< "|___________________________________________________________________________________________|"<<endl;
   cout<< "|                                                                                           |"<<endl;
   cout<< "|  ID         NAME                EMAIL ADDRESS          ADDRESS          GENDER            |"<<endl;
   cout<< "|___________________________________________________________________________________________|"<<endl;
   cout<< "|";
   getID();
   cout<<"\t\t";
   getName();
   cout<<"\t\t";
   getEmailAddress();
   cout<<"\t\t";
   cout<< address;
   cout<<"\t\t";
   cout<< gender;
   cout<< "|                                                                                           |"<<endl;
   cout<< "|___________________________________________________________________________________________|"<<endl<<endl;
}
