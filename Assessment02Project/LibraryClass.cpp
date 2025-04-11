
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include  "BookClass.cpp"
#include  "UserClass.cpp"
#include  "TransactionClass.cpp"

class LibraryClass {

private:
    std::vector<UserClass> userList[20];
    std::vector<BookClass> bookList[20];
    std::vector<TransactionClass> transList[80];

/* Method */
/* User Class method */
public: void setMember(std::string inpName, std::string inpContract, std::string inpAddr) {
    MemberClass member = MemberClass(inpName, inpContract, inpAddr);
    userList->push_back((UserClass)member);
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
            std::cout << std::endl;
            UserClass user = userList->at(i);

            std::cout << "userList [" << i << "] >> ";
            std::cout << "Name: " << user.getName() << "\t";
            std::cout << "Contract: " << user.getContract() << "\t";
            std::cout << "Position: " << user.getPosition() << "\t";
            // std::cout << std::endl;

        } catch (std::exception& e) {
            break;
        };
    }
}


/* Book Class method */
public: void addBook(std::string inpTitle, std::string inpAuthor, std::string inpISBN, std::string inpAddedDate) {
    BookClass book = BookClass(inpTitle, inpAuthor, inpISBN, inpAddedDate);
    bookList->push_back(book);
}
public: void updateBooksStatus() {
    for (int i = 0; i < bookList->max_size(); i++) {
        try {
            BookClass book = bookList->at(i);
            bool isAva = isAvailabe(book.getISBN());
            // std::cout << "ISBN: " << book.getISBN() << "\tbook.setAvailabe: " << isAva << "\n";
            book.setAvailabe(isAva);
            //
            bookList->at(i) = book;
        }
        catch (std::exception& e) {
            break;
        };
    }
}
public: void displayBookList() {
    std::cout << std::endl;
    std::cout << "Show all books\n";
    for (int i = 0; i < bookList->max_size(); i++) {
        try {
            std::cout << std::endl;
            BookClass book = bookList->at(i);

            std::cout << "bookList[" << i << "] >> ";
            std::cout << "Title: " << book.getTitle() << "\t";
            std::cout << "ISBN: " << book.getISBN() << "\t";
            std::cout << "Date Added: " << book.getDateAdded() << "\t";
            std::cout << "Is Availabe: " << book.getAvailabe() << "\t";
            // std::cout << std::endl;

        } catch (std::exception& e) {
            break;
        };
    }
}


/* Transaction Class method */
public: void addTransaction(int inpTransactionId, std::string inpISBN, std::string inpBorrowDate, std::string inpReturnDate) {
    TransactionClass trans;
    trans.setTransaction(inpTransactionId, inpISBN, inpBorrowDate, inpReturnDate);
    transList->push_back(trans);
}

public: bool isAvailabe(std::string inpISBN) {
    for (int i = 0; i < transList->max_size(); i++) {
        try {
            TransactionClass trans = transList->at(i);
            bool isAva = trans.isAvailabe(inpISBN);
            if (!isAva)
                return false;
        } catch (std::exception& e) {
            break;
        };
    }
    return true;
}

};

