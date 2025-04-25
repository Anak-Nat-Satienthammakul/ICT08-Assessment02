
#include <iostream>
#include <string>
#include <vector>
#include <exception>
// #include "TransactionClass.cpp"


class BookClass {
protected:
    std::string title;
    std::string author;
    std::string ISBN;
    std::string dateAdd;
    bool isAvailabe = true;
    

/* Method */
public: BookClass(std::string inpTitle, std::string inpAuthor, std::string inpISBN, std::string inpAddedDate) {
    title = inpTitle;
    author = inpAuthor;
    ISBN = inpISBN;
    dateAdd = inpAddedDate;
}

public: void setAvailabe(bool isAva) {
    isAvailabe = isAva;
}

public: std::string getTitle() {
    return title;
}
public: std::string getAuthor() {
    return author;
}
public: std::string getISBN() {
    return ISBN;
}
public: std::string getDateAdded() {
    return dateAdd;
}
public: bool getAvailabe() {
    return isAvailabe;
}

};

