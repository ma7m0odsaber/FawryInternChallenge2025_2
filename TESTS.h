//
// Created by Lenovo on 7/8/2025.
//

#ifndef TESTS_H
#define TESTS_H
#include <memory>
#include "EBook.h"
#include "Paper Book.h"
#include "ShowcaseBook.h"
#include "Inventory.h"

class BookStore {
public:
    static void run() {
        Inventory inventory;

        inventory.addBook(make_shared<PaperBook>("P123", "C++ Basics", "Mahmoud", 2015, 30, 10));
        inventory.addBook(make_shared<EBook>("E456", "Learn AI", "Mohamed", 2021, 15, "PDF"));
        inventory.addBook(make_shared<ShowcaseBook>("S789", "Ancient Code", "Ali", 2000));

        PRINT("Initial Inventory:");
        inventory.listBooks();

        PRINT("=======================================================================================================");
        PRINT("\nBuying Paper Book:");
        try {
            inventory.buyBook("P123", 2, "test@example.com", "123 Minia");
        } catch (exception &e) {
            PRINT("Error: " + string(e.what()));
        }
        PRINT("\nFailing to Buy Paper Book (OUT OF STOCK):");
        try {
            inventory.buyBook("P123", 10, "test@example.com", "123 Minia");
        } catch (exception &e) {
            PRINT("Error: " + string(e.what()));
        }
        PRINT("\nFailing to Buy Paper Book (NO MATCHING ISBN):");
        try {
            inventory.buyBook("M123", 10, "test@example.com", "123 Minia");
        } catch (exception &e) {
            PRINT("Error: " + string(e.what()));
        }

        PRINT("=======================================================================================================");
        PRINT("\nBuying EBook:");
        try {
            inventory.buyBook("E456", 1, "reader@mail.com", "");
        } catch (exception &e) {
            PRINT("Error: " + string(e.what()));
        }
        PRINT("\nFailing to Buy EBook (CAN NOT BUY MORE THAN ONE FOR THE SAME EMAIL):");
        try {
            inventory.buyBook("E456", 2, "reader@mail.com", "");
        } catch (exception &e) {
            PRINT("Error: " + string(e.what()));
        }
        PRINT("\nFailing to Buy EBook (NO MATCHING ISBN):");
        try {
            inventory.buyBook("R456", 1, "reader@mail.com", "");
        } catch (exception &e) {
            PRINT("Error: " + string(e.what()));
        }

        PRINT("=======================================================================================================");
        PRINT("\nBuying Showcase Book:");
        try {
            inventory.buyBook("S789", 1, "", "");
        } catch (exception &e) {
            PRINT("Error: " + string(e.what()));
        }

        PRINT("=======================================================================================================");
        PRINT("\nRemoving outdated books (threshold: 10 years)");
        inventory.removeBooks(10);

        PRINT("=======================================================================================================");
        PRINT("\nFinal Inventory:");
        inventory.listBooks();
    }
};
#endif //TESTS_H
