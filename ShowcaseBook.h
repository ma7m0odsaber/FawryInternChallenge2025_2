//
// Created by Lenovo on 7/8/2025.
//

#ifndef SHOWCASEBOOK_H
#define SHOWCASEBOOK_H
#include "Book.h"

class ShowcaseBook : public Book {
public:
    ShowcaseBook(string isbn, string title, string author, int year) : Book(isbn, title, author, year, 0.0) {}

    void buy(int quantity, string email, string address) override {
        throw runtime_error("Showcase books are not for sale!");
    }

    bool isSellable() const override { return false; }

    void printDetails() const override {
        PRINT("ShowcaseBook - ISBN: " + isbn + "\tTitle: " + title + "\tAuthor: " + author + "\tYear: " + to_string(year) + " (Not for sale)");

    }
};
#endif //SHOWCASEBOOK_H
