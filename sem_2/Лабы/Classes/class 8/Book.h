#pragma once
#include "Print.h"

class Book : public Print {
public:
    Book();
    Book(const string& name, const string& author, int pages, const string& publisher);
    Book(const Book& other);
    ~Book() override {}

    void Show() const override;
    void Input() override;

    int get_pages() const;
    string get_publisher() const;

    void set_pages(int pages);
    void set_publisher(string publisher);

    Book& operator=(const Book& other);

protected:
    int pages;
    string publisher;
};