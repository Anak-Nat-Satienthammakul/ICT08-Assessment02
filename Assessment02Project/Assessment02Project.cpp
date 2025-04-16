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


    // inset - History Transaction Class
    libCls.addTransaction(1, "BBB", "2025-04-01", "2025-04-07");
    libCls.addTransaction(2, "BBB", "2025-04-07", "");

    libCls.addTransaction(3, "CCC", "2025-04-01", "2025-04-07");
    libCls.addTransaction(4, "CCC", "2025-04-07", "2025-04-13");

    // check status
    libCls.updateBooksStatus();

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
}

