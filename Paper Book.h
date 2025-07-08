//
// Created by Lenovo on 7/8/2025.
//

#ifndef PAPERBOOK_H
#define PAPERBOOK_H
#include "Book.h"

class PaperBook : public Book {
    int stock;

public:
    PaperBook(string isbn, string title, string author, int year, double price, int stock) : Book(isbn, title, author, year, price), stock(stock) {}

    void buy(int quantity, string email, string address) override {
        if (quantity > stock) {
            PRINT("PaperBook: " + isbn + "\tRequested: " + to_string(quantity) + "\tAvailable:" + to_string(stock));
            throw runtime_error("Not enough stock available!");
        }

        stock -= quantity;
        double total = price * quantity;
        PRINT("PaperBook bought: " + isbn + "\tQuantity: " + to_string(quantity) + "\tAmount Paid: $" + to_string(total));
        PRINT("Shipping to address: " + address);
    }

    bool isSellable() const override { return true; }

    void printDetails() const override {
        PRINT("PaperBook - ISBN: " + isbn + "\tTitle: " + title + "\tAuthor: " + author + "\tYear: " + to_string(year) + "\tPrice: $" + to_string(price) + "\tStock: " + to_string(stock));
    }
};
#endif //PAPERBOOK_H
