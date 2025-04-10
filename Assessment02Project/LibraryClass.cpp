
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include  "BookClass.cpp"
#include  "UserClass.cpp"

class LibraryClass {

private:
    std::vector<UserClass> userList[20];
    std::vector<BookClass> bookList[20];

/* Method */
/* User Class method */
public: void setMember(std::string inpName, std::string inpContract, std::string inpAddr) {
    MemberClass member = MemberClass(inpName, inpContract, inpAddr);
    userList->push_back((UserClass) member);
}
public: void setStaff(std::string inpName, std::string inpContract, std::string inpAddr) {
    StaffClass member = StaffClass(inpName, inpContract, inpAddr);
    userList->push_back((UserClass)member);
}
public: void displayUserList() {
    std::cout << std::endl;
    std::cout << "Show all user\n";
    for (int i = 0; i < userList->max_size(); i++) {
        try {
            std::cout << "userList [" << i << "] >> ";

            UserClass user = userList->at(i);
            std::cout << "Name: " << user.getName() << "\t";
            std::cout << "Contract: " << user.getContract() << "\t";
            std::cout << "Position: " << user.getPosition() << "\t";
            std::cout << std::endl;

        }
        catch (std::exception& e) {
            break;
        };
    }
}


/* Book Class method */
public: void addBook(std::string inpTitle, std::string inpAuthor, std::string inpISBN) {
    BookClass book = BookClass(inpTitle, inpAuthor, inpISBN);
    bookList->push_back(book);
}
public: void displayBookList() {
    std::cout << std::endl;
    std::cout << "Show all books\n";
    for (int i = 0; i < bookList->max_size(); i++) {
        try {
            std::cout << "bookList[" << i << "] >> ";

            BookClass book = bookList->at(i);
            std::cout << "Title: " << book.getTitle() << "\t";
            std::cout << "ISBN: " << book.getISBN() << "\t";
            std::cout << std::endl;

        }
        catch (std::exception& e) {
            break;
        };
    }
}

};

