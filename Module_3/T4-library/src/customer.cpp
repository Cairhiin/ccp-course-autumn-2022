#include "customer.hpp"

#include <iostream>
#include <algorithm>

Customer::Customer(const std::string& name, const std::string& id)
            : name_(name), id_(id) {
}

std::string Customer::GetName() const {
    return name_;
}

std::string Customer::GetID() const {
    return id_;
}

int Customer::GetLoanAmount() const {
    return (int)loaned_books_.size();
}

std::vector<Book> Customer::GetLoans() const {
    return loaned_books_;
}

bool Customer::LoanBook(Book &b) {
    bool isSuccess { b.Loan() };
    if (isSuccess) loaned_books_.push_back(b);
    return isSuccess;
}

void Customer::ReturnBook(Book &b) {
    std::vector<Book> loaned_books;
    for (std::vector<Book>::const_iterator it = loaned_books_.begin(); it != loaned_books_.end(); it++) {    
        Book book { *it };
        if (book.GetISBN() == b.GetISBN()) {
            b.Restore();
        } else {
            loaned_books.push_back(book);
        }
    }
    loaned_books_ = loaned_books;
}

void Customer::Print() const {
    int amount { GetLoanAmount() };
    std::cout << "Customer: " << name_ << ", " << id_ << ", has ";
    std::cout << amount << " books on loan:" << std::endl;
    for (auto it = loaned_books_.begin(); it != loaned_books_.end(); it++) {
        Book book = *it;
        std::cout << "- ";
        book.Print();
    }
}