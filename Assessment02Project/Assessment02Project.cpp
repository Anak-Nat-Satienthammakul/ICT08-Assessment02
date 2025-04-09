// Assessment01Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include  "BookClass.cpp"
#include  "UserClass.cpp"
// #include  "MemberClass.cpp"
// #include  "StaffClass.cpp"

int main() {

    // insert - User
    std::cout << "Input User Data\n";
    std::vector<UserClass> userList[2];
    MemberClass member1 = MemberClass("Anak Satienthammakul", "14646@ait.nsw.edu.au", "VIC, AU");
    userList->push_back((UserClass)member1);

    StaffClass staff1 = StaffClass("Staff 1", "staff1@gmail.com", "VIC, AU");
    userList->push_back((UserClass)staff1);


    // inset - Book Class
    std::cout << "Input Book Data\n";
    std::vector<BookClass> bookList[5];

    BookClass bookCls1;
    bookCls1.setBook("AAA", "AAA", "AAA");
    bookList->push_back(bookCls1);

    BookClass bookCls2;
    bookCls2.setBook("BBB", "BBB", "BBB");
    bookList->push_back(bookCls2);

    // inset - History Transaction Class

    for (int i = 0; i < bookList->max_size(); i++) {
        try {
            std::cout << "i[" << i << "] >> ";

            BookClass book = bookList->at(i);
            std::cout << book.getTitle();
            std::cout << std::endl;

        }
        catch (std::exception& e) {
            break;
        };
    }

}

