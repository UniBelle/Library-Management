#ifndef LIBRARIAN_H
#define LIBRARIAN_H
#include <string>
using namespace std;
#include "User.h"


class Librarian : public User
{
    private:
        string shift;
    public:
        Librarian();
        void setLibrarianData(string shifts,string id,string nam,string eAddress);
        void getLibrarianName();
};

#endif // LIBRARIAN_H
