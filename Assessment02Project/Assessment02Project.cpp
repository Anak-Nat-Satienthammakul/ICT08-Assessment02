// Assessment02Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include  "LibraryClass.cpp"
#include <ctype.h>
#include <string_view> 

int main() {
    // the Library System
    LibraryClass libCls;

    // init -- insert demo - User
    std::cout << "Init User in Library System.\n";
    libCls.setMember("Anak Satienthammakul", "14646@ait.nsw.edu.au", "VIC, AU");
    libCls.setStaff("Staff 1", "staff1@gmail.com", "VIC, AU");


    // inset - Book Class
    std::cout << "Init Book in Library System.\n";
    libCls.addBook("AAA", "AAA", "AAA", "2025-01-01");
    libCls.addBook("DDD", "DDD", "DDD", "2025-01-01");
    libCls.addBook("EEE", "EEE", "EEE", "2025-01-01");
    libCls.addBook("BBB", "BBB", "BBB", "2025-01-01");
    libCls.addBook("CCC", "CCC", "CCC", "2025-01-01");
//    libCls.addBook("FFF", "FFF", "FFF", "");
//    libCls.addBook("HHH", "", "", "2025-04-24");


    // inset - History Transaction Class
//    libCls.addTransaction(1, "BBB", "2025-04-01", "2025-04-07");
//    libCls.addTransaction(2, "BBB", "2025-04-07", "");
//
//    libCls.addTransaction(3, "CCC", "2025-04-01", "2025-04-07");
//    libCls.addTransaction(4, "CCC", "2025-04-07", "2025-04-13");

    // check status
//    libCls.updateBooksStatus();

    // show main-menu
    do {
        // show main-menu option
        int option = libCls.displayMainMenu();
        if (option == 0) {
            return 0;
        } else if (option == 1) {
            // show all books
            libCls.displayBookList(true);
        } else if (option == 2) {
            // show book list can borrow
            libCls.displayAvailabilityBookList(true);
            std::string borrowBook;
            std::cout << "Please select the book you need to borrow: ";
            std::cin >> borrowBook;
            std::cout << std::endl;

            // borrow book.  >> new Transaction
            std::string nowTxt = libCls.getCurrentDate();
            libCls.addTransaction(libCls.getTransSize() + 1, borrowBook, nowTxt, "");
            // check status
            libCls.updateBooksStatus();

        } else if (option == 3) {
            // show book list can return
            libCls.displayAvailabilityBookList(false);
            std::string returnBook;
            std::cout << "Please select the book you need to return: ";
            std::cin >> returnBook;
            std::cout << std::endl;

            // return book.  >> Update Transaction
            std::string nowTxt = libCls.getCurrentDate();
            libCls.updateTransaction(returnBook, nowTxt);
            // check status
            libCls.updateBooksStatus();
            
        } else if (option == 4) {
            // add a new book;
            std::string inpTitle;
            std::string inpAuthor;
            std::string inpISBN;
            std::string inpDateAdd;
            std::string inpIsEBook;
            bool isEBook = false;
            std::string inpEBookUrl;

            std::cout << "Please insert a new book. " << std::endl;
            
            std::cout << "Title: ";
            std::cin >> inpTitle;

            std::cout << "Author: ";
            std::cin >> inpAuthor;

            bool isPassISBN = false;
            do {
                std::cout << "ISBN(only number): ";
                std::cin >> inpISBN;
                isPassISBN = true;
                try {
                    int num_int = std::stoi(inpISBN);
                } catch (const std::invalid_argument& e) {
                    std::cout << ">> Wrong input, Please insert ISBN(only number)." << std::endl;
                    isPassISBN = false;
                }
            } while (!isPassISBN);

            bool isPassDate = false;
            do {
                std::cout << "Date Add(YYYY-MM-DD): ";
                std::cin >> inpDateAdd;
                isPassDate = true;

                // validate format
                size_t count = std::count_if(inpDateAdd.begin(), inpDateAdd.end(), [](char c) {return c == '-';});
                if (count != 2) {
                    std::cout << ">> Wrong format, Please insert Date in the format(YYYY-MM-DD)." << std::endl;
                    isPassDate = false;
                }
                
                // validate Number
                if(isPassDate)
                    try {
                        std::string year = inpDateAdd.substr(0, 4);
                        std::string month = inpDateAdd.substr(5, 2);
                        std::string date = inpDateAdd.substr(8, 2);

                        int year_int  = std::stoi(year);
                        int month_int = std::stoi(month);
                        int date_int  = std::stoi(date);
                    } catch (const std::invalid_argument& e) {
                        std::cout << ">> Wrong Format, Please insert Date in the format(YYYY-MM-DD)." << std::endl;
                        isPassDate = false;
                    }
            } while (!isPassDate);

            std::cout << "The book is EBook(Y/N): ";
            std::cin >> inpIsEBook;
            
            if (inpIsEBook == "Y" || inpIsEBook == "y" || inpIsEBook == "yes" || inpIsEBook == "YES")
                isEBook = true;
            if (isEBook) {
                bool isPassEBookUrl = false;
                do {
                    std::cout << "The E-Book URL: ";
                    std::cin >> inpEBookUrl;
                    isPassEBookUrl = true;
                
                    // validate format 'http', '://', '/'
                    // start with 'http'
                    std::string httpTxt = inpEBookUrl.substr(0, 7);
                    size_t count2 = std::count_if(inpEBookUrl.begin(), inpEBookUrl.end(), [](char c) {return c == '/';});

                    std::cout << "httpTxt: " << httpTxt << std::endl;
                    std::cout << "count2: " << count2 << std::endl;
                    if ((httpTxt == "http://" || httpTxt == "https:/") && count2 > 2) {
                        // correct
                    } else {
                        std::cout << ">> Wrong Format, Please insert E-Book URL in the website format." << std::endl;
                        isPassEBookUrl = false;
                    }

                } while (!isPassEBookUrl);
            }
            

            // insert a new book.
            if (isEBook) {
                libCls.addBook(inpTitle, inpAuthor, inpISBN, inpDateAdd, isEBook, inpEBookUrl);
            } else {
                libCls.addBook(inpTitle, inpAuthor, inpISBN, inpDateAdd);
            }

        } else if (option == 5) {
            // show sub-sort-menu option
            int subOption = libCls.displaySortSubMenu();
            std::string sort = "";
            if (subOption == 1) {
                sort = "asc";
                // sortting
                libCls.bubberSort(sort);
            } else if (subOption == 2) {
                sort = "desc";
                // sortting
                libCls.bubberSort(sort);
            } else if (subOption == 3) {
                sort = "mix";
                // suffering
                libCls.sufferingSort();
            }

            // show all book
            libCls.displayBookList(false);
            
        } else if (option == 6) {
            // show sub-sort-menu option
            int subOption = libCls.displaySortSubMenu();
            std::string sort = "";
            if (subOption == 1) {
                sort = "asc";
                // sortting
                libCls.mergeSort(sort);
            } else if (subOption == 2) {
                sort = "desc";
                // sortting
                libCls.mergeSort(sort);
            } else if (subOption == 3) {
                sort = "mix";
                // suffering
                libCls.sufferingSort();
            }

            // show all book
            libCls.displayBookList(false);
            
        } else if (option == 7) {
            // show sub-sort-menu option
            int subOption = libCls.displaySortSubMenu();
            std::string sort = "";
            if (subOption == 1) {
                sort = "asc";
                // sortting
                libCls.quickSort(sort);
            } else if (subOption == 2) {
                sort = "desc";
                // sortting
                libCls.quickSort(sort);
            } else if (subOption == 3) {
                sort = "mix";
                // suffering
                libCls.sufferingSort();
            }

            // show all book
            libCls.displayBookList(false);

        } else {
            // wrong & rerender.
            continue;
        }
        std::string inp;
        std::cout << "please input any key to back to Main Menu >> " ;
        std::cin >> inp;
        // std::getline(std::cin, inp);

    } while (true);

}

