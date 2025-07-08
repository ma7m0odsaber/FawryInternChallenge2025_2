//
// Created by Lenovo on 7/8/2025.
//

#ifndef EBOOK_H
#define EBOOK_H
#include "Book.h"

class EBook : public Book {
    string fileType;

public:
    EBook(string isbn, string title, string author, int year, double price, string fileType) : Book(isbn, title, author, year, price), fileType(fileType) {}

    void buy(int quantity, string email, string address) override {
        if (quantity > 1) throw runtime_error("You can only buy 1 copy of an EBook.");
        PRINT("EBook bought: " + isbn + "\tAmount Paid: $" + to_string(price));
        PRINT("Sending to email: " + email);
    }

    bool isSellable() const override { return true; }

    void printDetails() const override {
        PRINT("EBook - ISBN: " + isbn + "\tTitle: " + title + "\tAuthor: " + author + "\tYear: " + to_string(year) + "\tPrice: $" + to_string(price) + "\tFileType: " + fileType);
    }
};
#endif //EBOOK_H
