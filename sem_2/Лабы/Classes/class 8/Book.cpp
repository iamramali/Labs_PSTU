#include "Book.h"
#include <iostream>

using namespace std;

Book::Book() : Print() {
    pages = 0;
    publisher = "";
}

Book::Book(const string& name, const string& author, int pages, const string& publisher) : Print(name, author) {
    this->pages = pages;
    this->publisher = publisher;
}

Book::Book(const Book& other) : Print(other) {
    pages = other.pages;
    publisher = other.publisher;
}

void Book::Show() const {
    Print::Show();
    cout << "Количество страниц: " << pages << endl;
    cout << "Издательство: " << publisher << endl;
}

void Book::Input() {
    Print::Input();

    cout << "Количество страниц: ";
    cin >> pages;

    cout << "Издательство: ";
    getline(cin >> ws, publisher);
}

int Book::get_pages() const {
    return pages;
}

string Book::get_publisher() const {
    return publisher;
}

void Book::set_pages(int pages) {
    this->pages = pages;
}

void Book::set_publisher(string publisher) {
    this->publisher = publisher;
}

Book& Book::operator=(const Book& other) {
    if (this == &other) return *this;

    Print::operator=(other);
    pages = other.pages;
    publisher = other.publisher;

    return *this;
}