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
    libCls.addBook("AAA", "AAA", "AAA");
    libCls.addBook("BBB", "BBB", "BBB");


    // inset - History Transaction Class

    // show all book
    libCls.displayBookList();

    // show all user
    libCls.displayUserList();

    return 0;
}

