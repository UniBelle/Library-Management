#include "Librarian.h"
using namespace std;
#include <iostream>

Librarian::Librarian()
{
    shift = "Day/Night";
}
void Librarian::setLibrarianData(string shifts,string id,string nam,string eAddress)
{
    setUserData(id,nam,eAddress);
    this-> shift = shifts;
}
void Librarian::getLibrarianName()
{
    getName();
}
