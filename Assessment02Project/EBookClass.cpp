#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "BookClass.cpp"


class EBookClass : public BookClass {
private:
    /* EBook */
    bool isEBook = false;
    std::string eBookUrl = "";


/* Method */
public: EBookClass(std::string inpTitle, std::string inpAuthor, std::string inpISBN, std::string inpAddedDate, bool inpIsEBook, std::string inpEBookUrl) 
    : BookClass(inpTitle, inpAuthor, inpISBN, inpAddedDate)
{
    isEBook = inpIsEBook;
    eBookUrl = inpEBookUrl;
}

public: bool getIsEBook() {
    return isEBook;
}
public: std::string getEBookUrl() {
    return eBookUrl;
}

};