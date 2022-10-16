#include "library.hpp"

#include <iostream>

#include "book.hpp"
#include "customer.hpp"

Library::Library(const std::string& name)
            : name_(name) {
}

std::string Library::GetName() const {
    return name_;
}

std::vector<Book>& Library::GetBooks() {
    return books_;
}

std::vector<Customer>& Library::GetCustomers() {
    return customers_;
}

Book Library::FindBookByName(const std::string& name) {
    for (auto it : books_) {
        if (it.GetName() == name) return it; 
    }
    return Book({}, {}, {});
}

std::vector<Book> Library::FindBooksByAuthor(const std::string& name) {
    std::vector<Book> booksByAuthor;
    for (auto it : books_) {
        if (it.GetAuthor() == name) booksByAuthor.push_back(it);
    }
    return booksByAuthor;
}

std::vector<Book> Library::FindAllLoanedBooks() {
    std::vector<Book> booksByStatusLoaned;
    for (auto it : books_) {
        if (it.GetStatus()) booksByStatusLoaned.push_back(it);
    }
    return booksByStatusLoaned;
}

Customer Library::FindCustomer(const std::string& id) {
    for (auto it : customers_) {
        if (it.GetID() == id) return it;
    }
    return Customer({}, {});
}
