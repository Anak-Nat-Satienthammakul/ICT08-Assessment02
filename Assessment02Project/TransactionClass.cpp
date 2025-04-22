
#include <iostream>
#include <string>

class TransactionClass {
private:
    int transactionId;
    std::string ISBN;       // FK
    std::string borrowDate;
    std::string returnDate;
    // bool isAvailabe = true; // returnDate <= borrowDate || returnDate is not null

public: std::string getISBN() {
    return ISBN;
}
public: std::string getBorrowDate() {
    return borrowDate;
}
public: std::string getReturnDate() {
    return returnDate;
}
public: bool isAvailabe(std::string inpISBN) {
    if (inpISBN != ISBN)
        return true;

    // std::cout << "inpISBN: " << inpISBN << "\tempty: " << returnDate.empty() << "\tlength: " << returnDate.length();
    if(returnDate.empty() == 0)
        return true;
    //
    return false;
}

/* Method */
public: void setTransaction(int inpTransactionId, std::string inpISBN, std::string inpBorrowDate, std::string inpReturnDate) {
        transactionId = inpTransactionId;
        ISBN = inpISBN;
        borrowDate = inpBorrowDate;
        returnDate = inpReturnDate;
    }
public: void updateReturnDate(std::string inpReturnDate) {
        returnDate = inpReturnDate;
    }
};

