#pragma once

using namespace std;

class Object
{
public:
    Object(){}
    virtual ~Object(){}
    virtual void show() = 0;
};