#pragma once
#include "Object.h"
#include <string>

using namespace std;

class Print : public Object {
public:
    Print();
    Print(const string& name, const string& author);
    Print(const Print& other);
    ~Print() override {}

    void Show() const override;
    void Input() override;
    void HandleEvent(const TEvent& event) override;
    const char* GetName() const override;

    string get_name() const;
    string get_author() const;

    void set_name(string name);
    void set_author(string author);

    Print& operator=(const Print& other);

protected:
    string name;
    string author;
};