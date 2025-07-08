# 📚 Book Store

Welcome to **Book Store System**, a C++ console application that simulates an extensible online bookstore using Object-Oriented Programming (OOP) concepts. This project demonstrates how to manage different types of books and handle various actions like adding, removing, and purchasing books with proper abstraction, encapsulation, inheritance, and polymorphism.

---

## 🚀 Features

- Manage a dynamic inventory of different types of books:
  - **PaperBook** – Physical books with stock and shipping
  - **EBook** – Digital books sent via email
  - **ShowcaseBook** – Demo books not for sale
- Add books to the inventory with details like ISBN, title, author, year, and price
- Remove outdated books based on publication year
- Buy books using ISBN, quantity, email, and address
- Automatic error handling for unavailable books or invalid operations
- Services like **ShippingService** and **MailService** are mocked via print statements
- Easily extensible to support new book types without changing existing code

---

## 🛠 Technologies Used

- **Language**: C++
- **OOP Concepts**: Inheritance, Polymorphism, Abstraction, Encapsulation
- **Standard Libraries**: `<iostream>`, `<vector>`, `<string>`, `<memory>`, `<ctime>`

---

## 📂 Project Structure

### 🔹 `Book` (Abstract Base Class)

Represents the common properties and behaviors of all books in the store.

#### Key Attributes:

* `isbn`: Unique identifier for the book
* `title`: Book title
* `author`: Author name
* `year`: Year of publication
* `price`: Price of the book

#### Key Methods:

* `buy(...)`: Abstract method for purchasing a book (must be overridden)
* `isOutdated(...)`: Checks if a book is outdated based on a threshold
* `isSellable()`: Abstract method indicating whether the book is for sale
* `printDetails()`: Abstract method for displaying book details

---

### 🔹 `PaperBook` (Derived from `Book`)

Represents a physical book that is stocked and can be shipped.

#### Additional Attribute:

* `stock`: Quantity available in inventory

#### Overridden Methods:

* `buy(...)`: Decreases stock, simulates shipping, prints transaction info
* `isSellable()`: Returns `true`
* `printDetails()`: Displays all book information including stock

---

### 🔹 `EBook` (Derived from `Book`)

Represents a digital book that is delivered via email.

#### Additional Attribute:

* `fileType`: The format of the ebook (e.g., PDF, EPUB)

#### Overridden Methods:

* `buy(...)`: Allows buying only 1 copy, simulates email delivery
* `isSellable()`: Returns `true`
* `printDetails()`: Displays all book information including file type

---

### 🔹 `ShowcaseBook` (Derived from `Book`)

Represents a demo or display-only book that is **not for sale**.

#### Overridden Methods:

* `buy(...)`: Throws an error if an attempt is made to buy it
* `isSellable()`: Returns `false`
* `printDetails()`: Displays book details and marks as not for sale

---

### 🔹 `Inventory`

Manages a collection of books in the store.

#### Key Methods:

* `addBook(...)`: Adds a book to the inventory
* `findBook(...)`: Retrieves a book by ISBN
* `buyBook(...)`: Facilitates the purchase of a book using ISBN, quantity, email, and address
* `removeBooks(...)`: Removes books older than a given threshold
* `listBooks()`: Prints details of all books in the inventory

---

### 🔹 `TESTS`

Acts as the **test class** to demonstrate and verify all functionalities.

#### Key Method:

* `run()`: Adds sample books, performs purchases, handles errors, removes outdated books, and displays inventory status

---

## 🧪 How It Works

The entry point of the program is the `TESTS` class. It demonstrates:

1. **Adding books** to the inventory
2. **Listing all books**
3. **Buying** a PaperBook and an EBook
4. **Handling errors** (e.g., trying to buy a showcase book)
5. **Removing outdated books**
6. **Listing final inventory**

---

## 📦 How to Compile and Run

1. Make sure you have a C++ compiler installed (e.g., `g++`)
2. Compile the code:

```bash
g++ -o bookstore main.cpp
````

3. Run the executable:

```bash
./bookstore
```

---

## 📈 Extending the Project

To add a new book type (e.g., `AudioBook`):

* Inherit from the `Book` abstract class
* Implement:

  * `buy()`
  * `isSellable()`
  * `printDetails()`
* Add the new book to the inventory via `addBook()`

---

## 👤 Author

**Mahmoud Saber Tantawy**

---

## 📝 License

This project is for educational purposes. You are free to use, modify, and distribute it.
