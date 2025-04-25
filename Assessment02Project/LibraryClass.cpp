
#include <iostream>
#include <string>
#include <vector>
#include <exception>
// #include  "BookClass.cpp"
#include  "EBookClass.cpp"
#include  "UserClass.cpp"
#include  "TransactionClass.cpp"

#include <random>
#include <algorithm>

#include <chrono>
#include <format>
#include <iomanip>
#include <sstream>

class LibraryClass {

private:
    std::vector<UserClass> userList[20];
    std::vector<EBookClass> bookList;
    std::vector<TransactionClass> transList;


public: std::string getCurrentDate() const {
    const auto now = std::chrono::system_clock::now();
    time_t time = std::chrono::system_clock::to_time_t(now);
    tm local_tm = *localtime(&time);
    // std::cout << std::put_time(&local_tm, "%d-%m-%Y %H-%M-%S") << std::endl;
    std::ostringstream oss;
    oss << std::put_time(&local_tm, "%Y-%m-%d");
    std::string nowTxt = oss.str();
    return nowTxt;
}

public: int getTransSize() const {
    return transList.size();
}

/* Menu Display method */
public: int displayMainMenu() {
    std::cout << std::endl << "Library Main Menu.";
    std::cout << std::endl << "1. Show all books.";
    std::cout << std::endl << "2. Borrow Book.";
    std::cout << std::endl << "3. Return Book.";
    std::cout << std::endl << "4. Add a new Book.";
    std::cout << std::endl;
    std::cout << std::endl << "5. Bubber Sortting Book.";
    std::cout << std::endl << "6. Merge Sortting Book.";
    std::cout << std::endl << "7. Quick Sortting Book.";
    std::cout << std::endl;
    std::cout << std::endl << "0. Exit.";
    std::cout << std::endl;

    std::cout << std::endl << "Please select option : ";
    int option = -1;
    std::cin >> option;
    return option;
}
public: int displaySortSubMenu() {
    std::cout << std::endl << "Sort Sub Menu.";
    std::cout << std::endl << "1. Ascending order.";
    std::cout << std::endl << "2. Descending order.";
    std::cout << std::endl << "3. Mixed order.";

    std::cout << std::endl << "Please select option : ";
    int option = -1;
    std::cin >> option;
    return option;
}


/* Method */
/* User Class method */
public: void setMember(std::string inpName, std::string inpContract, std::string inpAddr) {
    MemberClass member = MemberClass(inpName, inpContract, inpAddr);
    userList->push_back((UserClass)member);
}
public: void setStaff(std::string inpName, std::string inpContract, std::string inpAddr) {
    StaffClass member = StaffClass(inpName, inpContract, inpAddr);
    userList->push_back((UserClass)member);
}
public: void displayUserList() {
    std::cout << std::endl;
    std::cout << "Show all user\n";
    for (int i = 0; i < userList->max_size(); i++) {
        try {
            // std::cout << std::endl;
            UserClass user = userList->at(i);

            std::cout << "userList [" << i << "] >> ";
            std::cout << "Name: " << user.getName() << "\t";
            std::cout << "Contract: " << user.getContract() << "\t";
            std::cout << "Position: " << user.getPosition() << "\t";
            std::cout << std::endl;

        } catch (std::exception& e) {
            break;
        };
    }
}


/* Book Class method */
public: void addBook(std::string inpTitle, std::string inpAuthor, std::string inpISBN, std::string inpAddedDate) {

    EBookClass book = EBookClass(inpTitle, inpAuthor, inpISBN, inpAddedDate, false, "");
    bookList.push_back(book);
}
public: void addBook(std::string inpTitle, std::string inpAuthor, std::string inpISBN, std::string inpAddedDate, bool inpIsEBook, std::string inpEBookUrl) {

    EBookClass book = EBookClass(inpTitle, inpAuthor, inpISBN, inpAddedDate, inpIsEBook, inpEBookUrl);
    bookList.push_back(book);
}
public: void updateBooksStatus() {
    for (int i = 0; i < bookList.size(); i++) {
        try {
            EBookClass book = bookList.at(i);
            bool isAva = isAvailabe(book.getISBN());
            book.setAvailabe(isAva);
            //
            bookList.at(i) = book;
        }
        catch (std::exception& e) {
            break;
        };
    }
}
public: void displayBookList(bool showAll) {
    std::cout << std::endl;

    std::vector<EBookClass> cBookList[20];
    std::vector<EBookClass> inBookList[20];

    // check corrent/incoorect
    for (int i = 0; i < bookList.size(); i++) {
        EBookClass book = bookList.at(i);
        // check
        if (book.getTitle().length() == 0 ||
            book.getAuthor().length() == 0 ||
            book.getISBN().length() == 0 ||
            book.getDateAdded().length() == 0 /* check-format */
        ) {
            // incorrect boobk
            inBookList->push_back(book);
        } else {
            // correct book
            cBookList->push_back(book);
        }
    }

    // Show correct book.
    std::cout << "Correct Book’s information." << std::endl << std::endl;
    for (int i = 0; i < cBookList->size(); i++) {
        EBookClass book = cBookList->at(i);
        std::cout << "Title: " << book.getTitle() << "\t\t";
    }
    std::cout << std::endl;
    for (int i = 0; i < cBookList->size(); i++) {
        EBookClass book = cBookList->at(i);
        std::cout << "Author: " << book.getAuthor() << "\t\t";
    }
    std::cout << std::endl;
    for (int i = 0; i < cBookList->size(); i++) {
        EBookClass book = cBookList->at(i);
        std::cout << "ISBN: " << book.getISBN() << "\t\t";
    }
    std::cout << std::endl;
    for (int i = 0; i < cBookList->size(); i++) {
        EBookClass book = cBookList->at(i);
        std::cout << "Availability: " << (book.getAvailabe() ? "True" : "False") << "\t";
    }
    std::cout << std::endl;
    for (int i = 0; i < cBookList->size(); i++) {
        EBookClass book = cBookList->at(i);
        std::cout << "DateAdd: " << book.getDateAdded() << "\t";
    }
    std::cout << std::endl;
    for (int i = 0; i < cBookList->size(); i++) {
        EBookClass book = cBookList->at(i);
        std::cout << "Is E-Book: " << (book.getIsEBook() ? "True" : "False") << "\t";
    }
    std::cout << std::endl;
    for (int i = 0; i < cBookList->size(); i++) {
        EBookClass book = cBookList->at(i);
        std::cout << "E-Book URL: " << (book.getEBookUrl().length() == 0 ? "\t" : book.getEBookUrl()) << "\t";
    }
    std::cout << std::endl;

    if (!showAll)
        return; 

    // Show incorrect book.
    std::cout << std::endl;
    std::cout << "Incorrect Book’s information." << std::endl << std::endl;
    for (int i = 0; i < inBookList->size(); i++) {
        EBookClass book = inBookList->at(i);
        std::cout << "Title: " << book.getTitle() << "\t\t";
    }
    std::cout << std::endl;
    for (int i = 0; i < inBookList->size(); i++) {
        EBookClass book = inBookList->at(i);
        std::cout << "Author: " << book.getAuthor() << "\t\t";
    }
    std::cout << std::endl;
    for (int i = 0; i < inBookList->size(); i++) {
        EBookClass book = inBookList->at(i);
        std::cout << "ISBN: " << book.getISBN() << "\t\t";
    }
    std::cout << std::endl;
    for (int i = 0; i < inBookList->size(); i++) {
        EBookClass book = inBookList->at(i);
        std::cout << "Availability: " << (book.getAvailabe() ? "True" : "False") << "\t";
    }
    std::cout << std::endl;
    for (int i = 0; i < inBookList->size(); i++) {
        EBookClass book = inBookList->at(i);
        std::cout << "DateAdd: " << book.getDateAdded() << "\t";
    }
    std::cout << std::endl;

/**
    for (int i = 0; i < bookList->size(); i++) {
        try {
            // std::cout << std::endl;
            EBookClass book = bookList->at(i);

            // std::cout << "bookList["    << i << "] >> " << std::endl;
            std::cout << "Title: "        << book.getTitle()        << std::endl;
            std::cout << "Author: "       << book.getAuthor()       << std::endl;
            std::cout << "ISBN: "         << book.getISBN()         << std::endl;
            std::cout << "Availability: " <<(book.getAvailabe() ? "True" : "False") << std::endl;
            std::cout << "DateAdd: "      << book.getDateAdded()    << std::endl;
            std::cout << std::endl;

        } catch (std::exception& e) {
            break;
        };
    }
*/
}
public: void displayAvailabilityBookList(bool isAva) {
    std::vector<EBookClass> showBooks;

    // check corrent/incoorect
    for (int i = 0; i < bookList.size(); i++) {
        EBookClass book = bookList.at(i);
        if (book.getAvailabe() && isAva) {
            showBooks.push_back(book);
        } else if (!book.getAvailabe() && !isAva) {
            showBooks.push_back(book);
        }
    }

    if(isAva)
        std::cout << "Book’s information, it can borrow." << std::endl << std::endl;
    else
        std::cout << "Book’s information, it can return." << std::endl << std::endl;


    for (int i = 0; i < showBooks.size(); i++) {
        EBookClass book = showBooks.at(i);
        std::cout << "Title: " << book.getTitle() << "\t\t";
    }
    std::cout << std::endl;
    for (int i = 0; i < showBooks.size(); i++) {
        EBookClass book = showBooks.at(i);
        std::cout << "Author: " << book.getAuthor() << "\t\t";
    }
    std::cout << std::endl;
    for (int i = 0; i < showBooks.size(); i++) {
        EBookClass book = showBooks.at(i);
        std::cout << "ISBN: " << book.getISBN() << "\t\t";
    }
    std::cout << std::endl;
    for (int i = 0; i < showBooks.size(); i++) {
        EBookClass book = showBooks.at(i);
        std::cout << "Availability: " << (book.getAvailabe() ? "True" : "False") << "\t";
    }
    std::cout << std::endl;
    for (int i = 0; i < showBooks.size(); i++) {
        EBookClass book = showBooks.at(i);
        std::cout << "DateAdd: " << book.getDateAdded() << "\t";
    }
    std::cout << std::endl;

}


/* Transaction Class method */
public: void addTransaction(int inpTransactionId, std::string inpISBN, std::string inpBorrowDate, std::string inpReturnDate) {
    TransactionClass trans;
    trans.setTransaction(inpTransactionId, inpISBN, inpBorrowDate, inpReturnDate);
    transList.push_back(trans);
}
public: void updateTransaction(std::string inpISBN, std::string returnDate) {
    for (int i = 0; i < transList.size(); i++) {
        try {
            TransactionClass trans = transList.at(i);
            if (trans.getISBN() == inpISBN && trans.getReturnDate().length() == 0) {
                trans.updateReturnDate(returnDate);
                transList.at(i) = trans;
            }
        } catch (std::exception& e) {
            break;
        };
    }
}
public: bool isAvailabe(std::string inpISBN) {
    for (int i = 0; i < transList.size(); i++) {
        try {
            TransactionClass trans = transList.at(i);
            bool isAva = trans.isAvailabe(inpISBN);
            if (!isAva)
                return false;
        } catch (std::exception& e) {
            break;
        };
    }
    return true;
}


/* Get correct books */
private: std::vector<EBookClass> getCorrectBooks() const {
    std::vector<EBookClass> cBookList;

    // check corrent
    for (int i = 0; i < bookList.size(); i++) {
        EBookClass book = bookList.at(i);
        // check
        if (book.getTitle().length() == 0 ||
            book.getAuthor().length() == 0 ||
            book.getISBN().length() == 0 ||
            book.getDateAdded().length() == 0 /* check-format */
            ) {
            // incorrect book -- ignore.
        }
        else {
            // correct book
            cBookList.push_back(book);
        }
    }

    return cBookList;
}

/* Sortting method */
public: void bubberSort(std::string sort) {
    bool swapped;
    std::cout << ">>> BubberSort method [" + sort + "]. <<<" << std::endl;

    std::vector<EBookClass> list;
    list = getCorrectBooks();

    // loop for each pass
    for (int i = 0; i < list.size() - 1; i++) {
        try {
            swapped = false;
            std::cout << std::endl;
            std::cout << "bubberSort()-Step[i]: " << i << std::endl;

            // Inner loop for comparing adjacent elements
            for (int j = 0; j < list.size() - i - 1; j++) {
                try {
                    // std::cout << "bubberSort()-size: " << (list.size() - i - 1);
                    std::cout << "bubberSort()-Compare[j]: " << j;
                    if (list.at(j).getISBN() > list.at(j+1).getISBN() && "asc" == sort) {
                        std::cout << "\t|-->> Swap elements";

                        // Swap elements
                        EBookClass temp = list.at(j);
                        list.at(j) = list.at(j+1);
                        list.at(j + 1) = temp;
                        swapped = true;
                    } else if (list.at(j).getISBN() < list.at(j + 1).getISBN() && "desc" == sort) {
                        std::cout << "\t|-->> Swap elements";

                        // Swap elements
                        EBookClass temp = list.at(j);
                        list.at(j) = list.at(j + 1);
                        list.at(j + 1) = temp;
                        swapped = true;
                    }
                    std::cout << std::endl;
                } catch (std::exception& e) {
                    break;
                };
            }
        } catch (std::exception& e) {
            break;
        };

        // If no elements were swapped, it's end;
        if (!swapped)
            break;
    }

    bookList = list;
}


/* MergeSort method */
public: void mergeSort(std::string sort) {
    std::cout << ">>> MergeSort method [" + sort + "]. <<<" << std::endl;
    bookList = getCorrectBooks();

    // init
    int left = 0;
    int right = bookList.size() - 1;
    std::cout << "left: " << left << std::endl;
    std::cout << "right: " << right << std::endl;

    mergeSortProcess(left, right, 1, sort);
}
// Main merge sort process
private: void mergeSortProcess(int left, int right, int step, std::string sort) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        std::cout << "step: " << step << std::endl;
        mergeSortProcess(left, mid, step + 1, sort);
        mergeSortProcess(mid + 1, right, step + 1, sort);

        // Merge the sorted halves
        mergeLogic(left, mid, right, step, sort);
    }
}
// Merge two halves into a sorted array
private: void mergeLogic(int left, int mid, int right, int step, std::string sort) {
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid;    // Size of right subarray

    // Create temporary arrays
    std::vector<EBookClass> L;
    std::vector<EBookClass> R;

    // Copy data into temp arrays
    for (int i = 0; i < n1; i++) {
        L.reserve(i);
        L.push_back(bookList.at(left + i));
    }
    for (int j = 0; j < n2; j++) {
        R.reserve(j);
        R.push_back(bookList.at(mid + 1 + j));
    }

    // Merge the temp arrays back into arr[]
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if("asc" == sort) {
            if (L.at(i).getISBN() <= R.at(j).getISBN()) {
                std::cout << "step[" << step << "]-swap" << std::endl;
                bookList.at(k++) = L.at(i++);
            } else {
                std::cout << "step[" << step << "]-swap" << std::endl;
                bookList.at(k++) = R.at(j++);
            }
        } else if ("desc" == sort) {
            if (L.at(i).getISBN() >= R.at(j).getISBN()) {
                std::cout << "step[" << step << "]-swap" << std::endl;
                bookList.at(k++) = L.at(i++);
            } else {
                std::cout << "step[" << step << "]-swap" << std::endl;
                bookList.at(k++) = R.at(j++);
            }
        }
        //
    }

    // Copy remaining elements
    while (i < n1)
        bookList.at(k++) = L.at(i++);
    while (j < n2)
        bookList.at(k++) = R.at(j++);
}


/* QuickSort method */
public: void quickSort(std::string sort) {
    std::cout << ">>> QuickSort method [" + sort + "]. <<<" << std::endl;
    bookList = getCorrectBooks();

    quickSortProcess(0, bookList.size() - 1, 1, sort);
}
private: void quickSortProcess(int low, int high, int step, std::string sort) {
    if (low < high) {
        // pi is partitioning index
        std::cout << "step: " << step << std::endl;
        int pi = partition(low, high, sort);

        // Recursively sort elements before and after partition
        quickSortProcess(low, pi - 1, step+1, sort);
        quickSortProcess(pi + 1, high, step + 1, sort);
    }
}
// Partition function (Lomuto partition scheme)
private: int partition(int low, int high, std::string sort) {
    std::string pivot = bookList.at(high).getISBN();   // Pivot element
    int i = low - 1;                                    // Index of smaller element

    for (int j = low; j < high; ++j) {
        if (bookList.at(j).getISBN() < pivot && "asc" == sort) {
            ++i;

            // Swap
            std::cout << "swap" << std::endl;
            EBookClass temp = bookList.at(i);
            bookList.at(i) = bookList.at(j);
            bookList.at(j) = temp;
        } else if (bookList.at(j).getISBN() > pivot && "desc" == sort) {
            ++i;

            // Swap
            std::cout << "swap" << std::endl;
            EBookClass temp = bookList.at(i);
            bookList.at(i) = bookList.at(j);
            bookList.at(j) = temp;
        }
    }

    // Swap
    std::cout << "swap" << std::endl;
    EBookClass temp = bookList.at(i + 1);
    bookList.at(i + 1) = bookList.at(high);
    bookList.at(high) = temp;

    return i + 1;
}

/* Suffering */
public: void sufferingSort() {
    std::cout << ">>> SufferingSort method. <<<" << std::endl;
    // std::random_shuffle(bookList.begin(), bookList.end());


    // Initialize random number generator
    std::random_device rd;
    std::mt19937 g(rd());

    // Shuffle the vector
    std::shuffle(bookList.begin(), bookList.end(), g);

}

};

