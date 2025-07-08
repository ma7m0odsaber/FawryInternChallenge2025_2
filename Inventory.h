//
// Created by Lenovo on 7/8/2025.
//

#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include "Book.h"

class Inventory {
    vector<shared_ptr<Book>> books;

public:
    void addBook(shared_ptr<Book> book) {
        books.push_back(book);
        PRINT("Added book with ISBN: " + book->getISBN());
    }

    shared_ptr<Book> findBook(string isbn) {
        for (auto &book : books) {
            if (book->getISBN() == isbn) return book;
        }
        PRINT("There is no book with ISBN = " + isbn + " in the inventory");
        return nullptr;
    }

    void buyBook(string isbn, int quantity, string email, string address) {
        auto book = findBook(isbn);
        if (!book || !book->isSellable()) {
            throw runtime_error("Book not available or not sellable.");
        }
        book->buy(quantity, email, address);
    }

    void removeBooks(int const thresholdYears) {
        const int currentYear = 2025;
        auto it = books.begin();
        while (it != books.end()) {
            if ((*it)->isOutdated(currentYear, thresholdYears)) {
                PRINT("Removing outdated book: " + (*it)->getISBN());
                it = books.erase(it);
            } else {
                ++it;
            }
        }
    }

    void listBooks() const {
        for (auto &book : books) {
            book->printDetails();
        }
    }
};
#endif //INVENTORY_H
