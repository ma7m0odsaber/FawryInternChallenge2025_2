//
// Created by Lenovo on 7/8/2025.
//

#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <stdexcept>
#define PRINT(x) cout << x << endl;
using namespace std;

class Book {
protected:
    string isbn, title, author;
    int year;
    double price;

public:
    Book(string isbn, string title, string author, int year, double price) : isbn(isbn), title(title), author(author), year(year), price(price) {}

    virtual ~Book() {}

    string getISBN() const { return isbn; }
    int getYear() const { return year; }
    double getPrice() const { return price; }

    virtual void buy(int quantity, string email, string address) = 0;
    virtual bool isOutdated(int currentYear, int threshold) {
        return (currentYear - year) >= threshold;
    }

    virtual bool isSellable() const = 0;
    virtual void printDetails() const = 0;
};

#endif //BOOK_H
