#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <stdbool.h>
#include <stdlib.h>
#include "User.h"
#include "Member.h"
#include "Books.h"
#include "Librarian.h"
using namespace std;

//global declarations (Variables and functions)
int choice;
int count = 0;
bool found=false;
int amount = 0;
void LoginMenu();
Member members[200];
Books books[150];
Books issued[200];
void LibrarianPortal();
void MemberPortal();
int number;
string reply;
int booksNum;

// system function
void clearScreen()
{
    system("cls");
}

//book related functions
void AddBook()
{
        string title,category,edition,author;
        int isbn=82300;
        int dd, mm, yyyy, amount;
        do
        {
        cout<< "Enter the number of books to add: ";
        cin>>booksNum;
        cout<< "_____________________________________________________________________________________________"<<endl;
        cout<< "|                  HA TSOLO COMMUNITY LIBRARY MANAGEMENT SYSTEM                             |"<<endl;
        cout<< "|___________________________________________________________________________________________|"<<endl;
        cout<< "|                               >>ADD  A  BOOK<<                                            |"<<endl;
        cout<< "|___________________________________________________________________________________________|"<<endl;
        for(int y=0;y<booksNum;y++)
        {
            cout<< "BOOK"<<y<<endl;
              cout<< "     International Standard Book Number (ISBN)       : ";
              cin>>isbn;
              cout<<endl;
              cout<< "     Enter Book Title                                : ";
        cin>>title;
        cout<<endl;
        cout<< "     Enter Book Date of publication (day/month/year) : ";
        cin>>dd;
        cout<<"/";
        cin>>mm;
        cout<<"/";
        cin>>yyyy;
        cout<<endl<< "     Enter Book Category                             : ";
        cin>>category;
        cout<<endl<< "     Enter Book Edition                              : ";
        cin>>edition;
        cout<<endl<< "     Enter Book Author                               : ";
        cin>>author;
        cout<<endl<< "     Enter Book Price                                : ";
        cin>>amount;
        books[y].setBookData(title,author,isbn,edition,category,dd,mm,yyyy,amount);
        }
        cout<<"Do You Wish To Add Another Book Record? Yes/No: ";
        cin>>reply;
        clearScreen();
        }
        while (reply=="Yes" || reply=="yes");
        LibrarianPortal();
}
void modifyBook()
{
        string title,category,edition,author;
        int dd, mm, yyyy,isbn,amount;
        cout<< "_____________________________________________________________________________________________"<<endl;
        cout<< "|                  HA TSOLO COMMUNITY LIBRARY MANAGEMENT SYSTEM                             |"<<endl;
        cout<< "|___________________________________________________________________________________________|"<<endl;
        cout<< "|                               >>MODIFY A BOOK<<                                           |"<<endl;
        cout<< "|___________________________________________________________________________________________|"<<endl;
        do
        {
        cout<<"Enter Book ISBN to modify...";
        cin>>isbn;
        for(int k=0;k<booksNum;k++)
        {
           if(books[k].getISBN() == isbn)
           {
                cout<< "     International Standard Book Number (ISBN)       : "<<isbn<<endl;
                cout<< "     Modify Book Title                                : ";
                cin>>title;
          cout<<endl<< "     Modify Book Date of publication (day/month/year) : ";
                cin>>dd;
                cout<<"/";
                cin>>mm;
                cout<<"/";
                cin>>yyyy;
           cout<<endl<< "     Modify Book Category                             : ";
           cin>>category;
           cout<<endl<< "     Modify Book Edition                              : ";
           cin>>edition;
           cout<<endl<< "     Modify Book Author                               : ";
           cin>>author;
           cout<<endl<< "     Modify Book Price                               : ";
           cin>>amount;
                books[k].setBookData(title,author,isbn,edition,category,dd,mm,yyyy,amount);
           }
            else
             {
                 cout<<"Book not found!";
             }
        }
            cout<<"Do You Wish To Modify Another Book Record? Yes/No: ";
            cin>>reply;
            clearScreen();
            }
            while (reply=="Yes" || reply=="yes");
          LibrarianPortal();
}
void deleteBook()
{
    cout << "_____________________________________________________________________________________________" << endl;
    cout << "|                  HA TSOLO COMMUNITY LIBRARY MANAGEMENT SYSTEM                             |" << endl;
    cout << "|___________________________________________________________________________________________|" << endl;
    cout << "|                               >>DELETE  BOOK<<                                            |" << endl;
    cout << "|___________________________________________________________________________________________|" << endl;
        do
    {
    cout << "Enter Book ISBN to delete: ";
    int isbn;
    cin >> isbn;

    int index = -1;
    for (int t = 0; t < booksNum; t++)
    {
        if (books[t].getISBN() == isbn)
        {
            index = t;
            found = true;
            break;
        }
    }

    if (index != -1)
    {
        for (int g = index; g < booksNum - 1; g++)
        {
            books[g] = books[g + 1];
        }
        booksNum--;
        cout << "The book record is successfully erased" << endl;
    }
    else
    {
        cout << "Book Record is not found" << endl;
    }
    cout<<"Do You Wish To Delete Another Book Record? Yes/No: ";
    cin>>reply;
    clearScreen();
    }
    while (reply=="Yes" || reply=="yes");
    LibrarianPortal();
}

void SearchBook()
{
    cout << "_____________________________________________________________________________________________" << endl;
    cout << "|                  HA TSOLO COMMUNITY LIBRARY MANAGEMENT SYSTEM                             |" << endl;
    cout << "|___________________________________________________________________________________________|" << endl;
    cout << "|                               >>SEARCH BOOK<<                                            |" << endl;
    cout << "|___________________________________________________________________________________________|" << endl;
       do
    {
    cout << "Enter Book ISBN to search: ";
    int isbn;
    cin >> isbn;

    bool found = false;
    for (int t = 0; t < booksNum; t++)
    {
        if (books[t].getISBN() == isbn)
        {
            books[t].getBook();
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Book record not found" << endl;
    }
    cout<<"Do You Wish To Search Another Book Record? Yes/No: ";
    cin>>reply;
    clearScreen();
    }
    while (reply=="Yes" || reply=="yes");
    LibrarianPortal();
}
void IssueBook()
{
    string id, Mid;
    int bookk, isb, isbn, price;
    string titles, edt, cat, name, eaddress;

    cout << "_____________________________________________________________________________________________" << endl;
    cout << "|                  HA TSOLO COMMUNITY LIBRARY MANAGEMENT SYSTEM                             |" << endl;
    cout << "|___________________________________________________________________________________________|" << endl;
    cout << "|                               >>Issue Book<<                                            |" << endl;
    cout << "|___________________________________________________________________________________________|" << endl;
    cout << "Issued Books this week: " << count << endl;

    do
    {
        cout << "Enter Member ID to issue a book to: ";
        cin >> Mid;
        bool memberFound = false;

        for (int t = 0; t < number; t++)
        {
            if (members[t].getID() == Mid)
            {
                memberFound = true;
                id = members[t].getID();
                name = members[t].getName();
                eaddress = members[t].getEmailAddress();
                break;
            }
        }

        if (memberFound)
        {
            bool HasIssuedBook = false;

            for (int i = 0; i < count; i++) {
                if (issued[i].getID() == Mid)
                {
                    HasIssuedBook = true;
                    cout<<"This member still owes a book";
                    break;
                }
               if (!HasIssuedBook)
               {

                    cout << "Enter the number of books you want to issue (up to 3): ";
                    cin >> bookk;

                    if (bookk >= 1 && bookk <= 3)
                    {
                        for (int f = 0; f < bookk; f++)
                        {
                            cout << "Enter Book " << f + 1 << " ISBN to Issue: ";
                            cin >> isbn;
                            bool bookFound = false;

                            for (int t = 0; t < booksNum; t++)
                            {
                                if (books[t].getISBN() == isbn)
                                {
                                    bookFound = true;
                                    titles = books[t].getTitle();
                                    isb = isbn;
                                    edt = books[t].getEdition();
                                    cat = books[t].getCategory();
                                    price = books[t].getPrice();
                                    amount = amount + price;
                                    count = count + 1;
                                    issued[count - 1].issueBook(titles, isb, edt, cat, id, name, eaddress, price);
                                    cout<<"Amount owed: "<<amount;
                                    break;
                                }
                            }

                            if (!bookFound)
                            {
                                cout << "Book record not found" << endl;
                            }
                        }
                    }
                    else
                    {
                        cout << "Invalid number of books. You can issue 1 to 3 books." << endl;
                    }
                }
            }
        }
      else
        {
            cout << "Member record not found" << endl;
        }

    cout << "Do You Wish To Issue Books To Another Member? Yes/No: ";
    cin >> reply;
    clearScreen();
    }
    while (reply == "Yes" || reply == "yes");
    LibrarianPortal();
}
void returnBook()
{
    cout << "_____________________________________________________________________________________________" << endl;
    cout << "|                  HA TSOLO COMMUNITY LIBRARY MANAGEMENT SYSTEM                             |" << endl;
    cout << "|___________________________________________________________________________________________|" << endl;
    cout << "|                               >>RETURN A BOOK <<                                          |" << endl;
    cout << "|___________________________________________________________________________________________|" << endl;

    do
    {
        cout << "Enter Book ISBN To return: ";
        int isbn;
        int index = -1;
        cin >> isbn;

        for (int t = 0; t < count; t++)
        {
            if (issued[t].getISBN() == isbn)
            {
                index = t;
                break;
            }
        }

        if (index != -1)
        {
            for (int g = index; g < count - 1; g++)
            {
                issued[g] = issued[g + 1];
            }
            cout << "Book has been successfully returned" << endl;
            count--;
        }
        else
        {
            cout << "Issued Book is not found" << endl;
        }

        cout << "Do You Wish To Return Another Book? Yes/No: ";
        cin >> reply;
        clearScreen();
    } while (reply == "Yes" || reply == "yes");

    LibrarianPortal();
}


void ViewBookList()
{

        cout<< "_____________________________________________________________________________________________"<<endl;
        cout<< "                  HA TSOLO COMMUNITY LIBRARY MANAGEMENT SYSTEM                             "<<endl;
        cout<< "___________________________________________________________________________________________"<<endl;
        cout<< "                               >>VIEW BOOKLIST<<                                            "<<endl;
        cout<< "___________________________________________________________________________________________"<<endl;
         cout<< " Book Title          Author          Category          Edition        Date of Publication  "<<endl;
         cout<< "___________________________________________________________________________________________"<<endl;
         do
         {
        for(int x=0; x<booksNum;x++)
        {
            books[x].getBook();
        }
        cout<<"Do You Wish To View The BookList Again? Yes/No: ";
        cin>>reply;
        clearScreen();
        }
        while (reply=="Yes" || reply=="yes");
        MemberPortal();
}

//members related functions
void MemberSearchBook()
{
        cout << "_____________________________________________________________________________________________" << endl;
    cout << "|                  HA TSOLO COMMUNITY LIBRARY MANAGEMENT SYSTEM                             |" << endl;
    cout << "|___________________________________________________________________________________________|" << endl;
    cout << "|                               >>SEARCH BOOK<<                                            |" << endl;
    cout << "|___________________________________________________________________________________________|" << endl;
      do
    {
    cout << "Enter Book ISBN to search: ";
    int isbn;
    cin >> isbn;

    bool found = false;
    for (int t = 0; t < booksNum; t++)
    {
        if (books[t].getISBN() == isbn)
        {
            books[t].getBook();
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Book record not found" << endl;
    }
            cout<<"Do You Wish To Search Another Book Record? Yes/No: ";
            cin>>reply;
            clearScreen();
            }
            while (reply=="Yes" || reply=="yes");
           MemberPortal();

}
void AddMembers()
{
        string address,gender,id,password,name,email;
        int identity=23082300;
        id="M"+ to_string(identity);
        do
        {
        cout<< "Enter the number of Members you wish to add: ";
        cin>>number;
        cout<< "_____________________________________________________________________________________________"<<endl;
        cout<< "|                  HA TSOLO COMMUNITY LIBRARY MANAGEMENT SYSTEM                             |"<<endl;
        cout<< "|___________________________________________________________________________________________|"<<endl;
        cout<< "|                               >>ADD NEW MEMBER<<                                          |"<<endl;
        cout<< "|___________________________________________________________________________________________|"<<endl;
        for(int y=0;y<number;y++)
        {
              cout<< "     Member ID                    : "<<id<<endl;
              cout<< "     Enter Member Name            : ";
        cin>>name;
        cout<<endl<< "     Enter Member Address         : ";
        cin>>address;
        cout<<endl<< "     Enter Member Gender          : ";
        cin>>gender;
        cout<<endl<< "     Enter Member Email Address   : ";
        cin>>email;
        cout<<endl;
        members[y].setMemberData(address,gender,id,name,email);
        identity++;
        }
        cout<<"Do You Wish To Add Another Member Record? Yes/No: ";
        cin>>reply;
        clearScreen();
        }
        while (reply=="Yes" || reply=="yes");
        LibrarianPortal();
}
void modifyMember()
{
        string address,gender,id,name,email;
        cout<< "_____________________________________________________________________________________________"<<endl;
        cout<< "|                  HA TSOLO COMMUNITY LIBRARY MANAGEMENT SYSTEM                             |"<<endl;
        cout<< "|___________________________________________________________________________________________|"<<endl;
        cout<< "|                               >>MODIFY MEMBER<<                                          |"<<endl;
        cout<< "|___________________________________________________________________________________________|"<<endl;
        do
        {
        cout<<"Enter Member ID to modify...";
        cin>>id;
        for(int k=0;k<number;k++)
        {
           if(members[k].getID() ==id)
           {
              cout<< "     Member ID                    : "<<id<<endl;
              cout<< "     Modify Member Name            : ";
              cin>>name;
        cout<<endl<< "     Modify Member Address         : ";
        cin>>address;
        cout<<endl<< "     Modify Member Gender          : ";
        cin>>gender;
        cout<<endl<< "     Modify Member Email Address   : ";
        cin>>email;
        cout<<endl;
        members[k].setMemberData(address,gender,id,name,email);
           }
           else
             {
                 cout<<"Member not found!";
             }
        }
        cout<<"Do You Wish To Modify Another Member Record? Yes/No: ";
        cin>>reply;
        clearScreen();
        }
        while (reply=="Yes" || reply=="yes");
       LibrarianPortal();
}
void deleteMember()
{
    cout << "_____________________________________________________________________________________________" << endl;
    cout << "|                  HA TSOLO COMMUNITY LIBRARY MANAGEMENT SYSTEM                             |" << endl;
    cout << "|___________________________________________________________________________________________|" << endl;
    cout << "|                               >>DELETE  MEMBER<<                                          |" << endl;
    cout << "|___________________________________________________________________________________________|" << endl;
    do
    {
    cout << "Enter Member ID: ";
    string id;
    int index = -1;
    cin >> id;

    for (int t = 0; t < number; t++)
    {
        if (members[t].getID() == id)
        {
            index = t;
            break;
        }
    }

    if (index != -1)
    {
        for (int g = index; g < number - 1; g++)
        {
            members[g] = members[g + 1];
        }
        cout << "The Member record is successfully erased" << endl;
        number--;
    }
    else
    {
        cout << "Member Record is not found";
    }
    cout<<"Do You Wish To Delete Another Member Record? Yes/No: ";
    cin>>reply;
    clearScreen();
    }
    while (reply=="Yes" || reply=="yes");
    LibrarianPortal();
}
void DisplayAllOwingMembers()
{
     cout << "_____________________________________________________________________________________________" << endl;
    cout << "|                  HA TSOLO COMMUNITY LIBRARY MANAGEMENT SYSTEM                             |" << endl;
    cout << "|___________________________________________________________________________________________|" << endl;
    cout << "|                               >>DISPLAY ALL OWING MEMBERS<<                                          |" << endl;
    cout << "|___________________________________________________________________________________________|" << endl;
    do
    {
        cout << "BOOK TITLE                 MEMBER ID           MEMBER NAME                 AMOUNT OWING" << endl;
        cout << "___________________________________________________________________________________________" << endl;
        for(int i=0; i<count; i++)
        {
             issued[i].OwingMembers();
        }
    cout<<"Do You Wish To Display All Owing Members Again? Yes/No: ";
    cin>>reply;
    clearScreen();
    }
    while (reply=="Yes" || reply=="yes");
    LibrarianPortal();
}
void LibrarianPortal()
{
   cout<< "_____________________________________________________________________________________________"<<endl;
   cout<< "|                  HA TSOLO COMMUNITY LIBRARY MANAGEMENT SYSTEM                             |"<<endl;
   cout<< "|               'WHERE QUALITY LIBRARY SERVICES CANNOT BE MATCHED'                          |"<<endl;
   cout<< "|___________________________________________________________________________________________|"<<endl;
   cout<< "|                 Welcome to Ha Tsolo Library Management System                             |"<<endl;
   cout<< "|___________________________________________________________________________________________|"<<endl;
   cout<< "|                               MAIN MENU                                                   |"<<endl;
   cout<< "|___________________________________________________________________________________________|"<<endl;
   cout<< "|                                                                                           |"<<endl;
   cout<< "|     1. Add Book Record                         7. Add a new Member                        |"<<endl;
   cout<< "|     2. Modify Book Record                      8. Modify a Member Record                  |"<<endl;
   cout<< "|     3. Delete Book Record                      9. Delete a Member Record                  |"<<endl;
   cout<< "|     4. Search Book Record                      10. Display ALL owing Members              |"<<endl;
   cout<< "|     5. Issue Book                                                                         |"<<endl;
   cout<< "|     6. Return Book                                                                        |"<<endl;
   cout<< "|                           11. Exit Application                                            |"<<endl;
   cout<< "|      Enter Your Choice:";
   cin >> choice;
   cout<< "|___________________________________________________________________________________________|"<<endl<<endl;

    switch(choice)
    {
    case 1:
        clearScreen();
        AddBook();
        break;
    case 2:
        clearScreen();
        modifyBook();
        break;
    case 3:
        clearScreen();
        deleteBook();
        break;
    case 4:
        clearScreen();
        SearchBook();
    case 5:
        clearScreen();
        IssueBook();
    case 6:
        clearScreen();
        returnBook();
    case 7:
        clearScreen();
        AddMembers();
        break;
    case 8:
        clearScreen();
        modifyMember();
        break;
    case 9:
        clearScreen();
        deleteMember();
        break;
    case 10:
        clearScreen();
        DisplayAllOwingMembers();
        break;
    case 11:
        clearScreen();
        LoginMenu();
        break;
    default:
        cout<< "Enter A Choice Between 1 and 11";
        break;
    }
}
//Member Menus
void MemberPortal()
{
    cout<<"_____________________________________________________________________________________________"<<endl;
   cout<< "|                  HA TSOLO COMMUNITY LIBRARY MANAGEMENT SYSTEM                             |"<<endl;
   cout<< "|___________________________________________________________________________________________|"<<endl;
   cout<< "|                        >>Please choose one option<<                                       |"<<endl;
   cout<< "|                               MEMBER PORTAL                                               |"<<endl;
   cout<< "|___________________________________________________________________________________________|"<<endl;
   cout<< "|                                                                                           |"<<endl;
   cout<< "|     1. View Booklist                                                                      |"<<endl;
   cout<< "|     2. Search For a Book                                                                  |"<<endl;
   cout<< "|     3. Exit                                                                               |"<<endl;
   cout<< "|                                                                                           |"<<endl;
   cout<< "|      Enter Your Choice:";
   cin >> choice;
   cout<< "|___________________________________________________________________________________________|"<<endl<<endl;

    switch(choice)
    {
    case 1:
        clearScreen();
        ViewBookList();
        break;
    case 2:
        clearScreen();
        MemberSearchBook();
        break;
    case 3:
        clearScreen();
        LoginMenu();
        break;
    default:
        cout<< "Enter A Choice Between 1 and 3";
    }
}
//login menu
void LoginMenu()
{
   cout<< "_____________________________________________________________________________________________"<<endl;
   cout<< "|                  HA TSOLO COMMUNITY LIBRARY MANAGEMENT SYSTEM                             |"<<endl;
   cout<< "|___________________________________________________________________________________________|"<<endl;
   cout<< "|                        >>Please choose any option<<                                       |"<<endl;
   cout<< "|___________________________________________________________________________________________|"<<endl;
   cout<< "|                                                                                           |"<<endl;
   cout<< "|     1. Librarian                                                                          |"<<endl;
   cout<< "|     2. Member                                                                             |"<<endl;
   cout<< "|     3. Exit Application                                                                   |"<<endl;
   cout<< "|                                                                                           |"<<endl;
   cout<< "|      Enter Your Choice:";
   cin >> choice;
   cout<< "|___________________________________________________________________________________________|"<<endl<<endl;

    switch(choice)
    {
    case 1:
        clearScreen();
        LibrarianPortal();
        break;
    case 2:
        clearScreen();
        MemberPortal();
        break;
    case 3:
        exit(0);
        break;
    default:
        cout<< "Enter A Choice Between 1 and 3";

}
}

int main()
{

    system("color 5f");
    LoginMenu();
    return 0;
}
