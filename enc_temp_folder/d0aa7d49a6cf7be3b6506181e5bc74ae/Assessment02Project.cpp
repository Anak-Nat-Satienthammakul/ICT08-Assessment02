// Assessment02Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include  "LibraryClass.cpp"

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
    libCls.addBook("FFF", "FFF", "FFF", "");


    // inset - History Transaction Class
    libCls.addTransaction(1, "BBB", "2025-04-01", "2025-04-07");
    libCls.addTransaction(2, "BBB", "2025-04-07", "");

    libCls.addTransaction(3, "CCC", "2025-04-01", "2025-04-07");
    libCls.addTransaction(4, "CCC", "2025-04-07", "2025-04-13");

    // check status
    libCls.updateBooksStatus();

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

            // borrow book.  >> new Transaction

        } else if (option == 3) {
            // show book list can return
            libCls.displayAvailabilityBookList(false);

            // return book.  >> Update Transaction

        } else if (option == 4) {
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
            
        } else if (option == 5) {
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
            
        } else if (option == 6) {
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
/** 
    // show all book
    libCls.displayBookList();

    // show all user
    libCls.displayUserList();

    std::cout << std::endl;
    // test sort
    libCls.bubberSort();
    // libCls.mergeSort();
    // libCls.quickSort();


    // show all book
    libCls.displayBookList();

    return 0;
*/
}

