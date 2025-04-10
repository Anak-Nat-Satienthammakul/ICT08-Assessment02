
#include <iostream>
#include <string>

class BookClass {
private:
    std::string title;
    std::string author;
    std::string ISBN;
    bool isAvailabe = true;


/* Method */
public: BookClass(std::string inpTitle, std::string inpAuthor, std::string inpISBN) {
        title = inpTitle;
        author = inpAuthor;
        ISBN = inpISBN;
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

public: bool checkActive() {
        // check BorrowDate / ReturnDAte
        return isAvailabe;
    }

};

