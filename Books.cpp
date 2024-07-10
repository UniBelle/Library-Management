#include "Books.h"
#include <iostream>

using namespace std;

Books::Books()
{
    title = "default";
    author = "Name";
    isbn = 0;
    edition = "1st edition";
    category = "Default";
    DateOfPublication.day = 1;
    DateOfPublication.month = 1;
    DateOfPublication.year = 0000;
    price = 0;
}
void Books::setBookData(string titles, string auth, int isb, string edt, string cat, int dd, int mm, int yyyy, int amount)
{
    title = titles;
    author = auth;
    isbn = isb;
    edition = edt;
    category = cat;
    price = amount;
    DateOfPublication.day = dd;
    DateOfPublication.month = mm;
    DateOfPublication.year = yyyy;
}
int Books::getPrice()
{
    return price;
}
string Books::getCategory()
{
    return category;
}
string Books::getEdition()
{
    return edition;
}
int Books::getISBN()
{
    return isbn;
}

void Books::getBook()
{
    cout << "|" << title << "\t" << author << "\t" << category << "\t" << edition << "\t" << DateOfPublication.day << "/" << DateOfPublication.month << "/" << DateOfPublication.year << endl;
    cout << "_____________________________________________________________________________________________" << endl;
}
string Books::getTitle()
{
    return title;
}
void Books::issueBook(string titles, int isb, string edt, string cat, string id, string name, string eaddress, int price)
{
    title = titles;
    isbn = isb;
    edition = edt;
    category = cat;
    price = price;
    setUserData(id, name, eaddress);
}
void Books::OwingMembers()
{
    cout<<title<<"\t";
    getID();
    cout<<"\t";
    getName();
    cout<<"\t";
    getPrice();
}
