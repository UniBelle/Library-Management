#ifndef BOOKS_H
#define BOOKS_H
#include <string>
using namespace std;
#include "Member.h"


class Books : public Member
{
    private:
        string title;
        string author;
        int isbn;
        int price;
        string edition;
        string category;
        struct date {
          int day;
          int month;
          int year;
        } DateOfPublication;
    public:
        Books();
        void issueBook(string titles,int isb, string edt, string cat,string id,string name,string eaddress, int price );
        void setBookData(string titles, string auth, int isb, string edt, string cat,int dd, int mm, int yyyy, int amount);
        void getBook();
        int getISBN();
        string getTitle();
        void OwingMembers();
        string getEdition();
        string getCategory();
        int getPrice();

};

#endif // BOOKS_H
