
#include <iostream>
#include <string>

class BookClass {
public:
    int transactionId;
    std::string ISBN;       // FK
    std::string borrowDate;
    std::string returnDate;
    bool isAvailabe = true; // returnDate <= borrowDate || returnDate is not null


/* Method */
public: void setBook(int inpTransactionId, std::string inpISBN, std::string inpBorrowDate, std::string inpReturnDate) {
        transactionId = inpTransactionId;
        ISBN = inpISBN;
        borrowDate = inpBorrowDate;
        returnDate = inpReturnDate;
    }
public: bool checkActive() {
        if (returnDate._Equal(NULL) || returnDate.length() == 0) {
            return false;
        }
        return true;
    }

};
