
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include  "BookClass.cpp"
#include  "UserClass.cpp"
#include  "TransactionClass.cpp"

class LibraryClass {

private:
    std::vector<UserClass> userList[20];
    std::vector<BookClass> bookList[20];
    std::vector<TransactionClass> transList[80];

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
    BookClass book = BookClass(inpTitle, inpAuthor, inpISBN, inpAddedDate);
    bookList->push_back(book);
}
public: void updateBooksStatus() {
    for (int i = 0; i < bookList->size(); i++) {
        try {
            BookClass book = bookList->at(i);
            bool isAva = isAvailabe(book.getISBN());
            // std::cout << "ISBN: " << book.getISBN() << "\tbook.setAvailabe: " << isAva << "\n";
            book.setAvailabe(isAva);
            //
            bookList->at(i) = book;
        }
        catch (std::exception& e) {
            break;
        };
    }
}
public: void displayBookList() {
    std::cout << std::endl;
    std::cout << "Show all books\n";
    for (int i = 0; i < bookList->size(); i++) {
        try {
            // std::cout << std::endl;
            BookClass book = bookList->at(i);

            std::cout << "bookList[" << i << "] >> ";
            std::cout << "Title: " << book.getTitle() << "\t";
            std::cout << "ISBN: " << book.getISBN() << "\t";
            std::cout << "Date Added: " << book.getDateAdded() << "\t";
            std::cout << "Is Availabe: " << book.getAvailabe() << "\t";
            std::cout << std::endl;

        } catch (std::exception& e) {
            break;
        };
    }
}


/* Transaction Class method */
public: void addTransaction(int inpTransactionId, std::string inpISBN, std::string inpBorrowDate, std::string inpReturnDate) {
    TransactionClass trans;
    trans.setTransaction(inpTransactionId, inpISBN, inpBorrowDate, inpReturnDate);
    transList->push_back(trans);
}
public: bool isAvailabe(std::string inpISBN) {
    for (int i = 0; i < transList->max_size(); i++) {
        try {
            TransactionClass trans = transList->at(i);
            bool isAva = trans.isAvailabe(inpISBN);
            if (!isAva)
                return false;
        } catch (std::exception& e) {
            break;
        };
    }
    return true;
}


/* Sortting method */
public: void bubberSort() {
    bool swapped;
    std::cout << ">>> BubberSort method. <<<" << std::endl;

    // loop for each pass
    for (int i = 0; i < bookList->size() - 1; i++) {
        try {
            swapped = false;
            std::cout << std::endl;
            std::cout << "bubberSort()-Step[i]: " << i << std::endl;

            // Inner loop for comparing adjacent elements
            for (int j = 0; j < bookList->size() - i - 1; j++) {
                try {
                    std::cout << "bubberSort()-Compare[j]: " << j;
                    if (bookList->at(j).getISBN() > bookList->at(j+1).getISBN()) {
                        std::cout << "\t|-->> Swap elements";

                        // Swap elements
                        BookClass temp = bookList->at(j);
                        bookList->at(j) = bookList->at(j+1);
                        bookList->at(j + 1) = temp;
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
}


/* MergeSort method */
public: void mergeSort() {
    std::cout << ">>> MergeSort method. <<<" << std::endl;
    // init
    int left = 0;
    int right = bookList->size() - 1;
    std::cout << "left: " << left << std::endl;
    std::cout << "right: " << right << std::endl;

    mergeSortProcess(left, right, 1);
}
// Main merge sort process
private: void mergeSortProcess(int left, int right, int step) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        std::cout << "step: " << step << std::endl;
        mergeSortProcess(left, mid, step + 1);
        mergeSortProcess(mid + 1, right, step + 1);

        // Merge the sorted halves
        mergeLogic(left, mid, right, step);

    }
}
// Merge two halves into a sorted array
private: void mergeLogic(int left, int mid, int right, int step) {
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid;    // Size of right subarray

    // Create temporary arrays
    std::vector<BookClass> L;
    std::vector<BookClass> R;

    // Copy data into temp arrays
    for (int i = 0; i < n1; i++) {
        L.reserve(i);
        L.push_back(bookList->at(left + i));
    }
    for (int j = 0; j < n2; j++) {
        R.reserve(j);
        R.push_back(bookList->at(mid + 1 + j));
    }

    // Merge the temp arrays back into arr[]
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L.at(i).getISBN() <= R.at(j).getISBN()) {
            std::cout << "step[" << step << "]-swap" << std::endl;
            bookList->at(k++) = L.at(i++);
        } else {
            std::cout << "step[" << step << "]-swap" << std::endl;
            bookList->at(k++) = R.at(j++);
        }
    }

    // Copy remaining elements
    while (i < n1)
        bookList->at(k++) = L.at(i++);
    while (j < n2)
        bookList->at(k++) = R.at(j++);
}


/* QuickSort method */
public: void quickSort() {
    std::cout << ">>> QuickSort method. <<<" << std::endl;
    quickSortProcess(0, bookList->size() - 1, 1);
}
private: void quickSortProcess(int low, int high, int step) {
    if (low < high) {
        // pi is partitioning index
        std::cout << "step: " << step << std::endl;
        int pi = partition(low, high);

        // Recursively sort elements before and after partition
        quickSortProcess(low, pi - 1, step+1);
        quickSortProcess(pi + 1, high, step + 1);
    }
}
// Partition function (Lomuto partition scheme)
private: int partition(int low, int high) {
    std::string pivot = bookList->at(high).getISBN();   // Pivot element
    int i = low - 1;                                    // Index of smaller element

    for (int j = low; j < high; ++j) {
        if (bookList->at(j).getISBN() < pivot) {
            ++i;

            // Swap
            std::cout << "swap" << std::endl;
            BookClass temp = bookList->at(i);
            bookList->at(i) = bookList->at(j);
            bookList->at(j) = temp;
        }
    }

    // Swap
    std::cout << "swap" << std::endl;
    BookClass temp = bookList->at(i + 1);
    bookList->at(i + 1) = bookList->at(high);
    bookList->at(high) = temp;

    return i + 1;
}

};

