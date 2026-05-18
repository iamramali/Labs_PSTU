#pragma once
#include "Event.h"

class Object {
public:
    Object() {
    }

    virtual ~Object() {
    }

    virtual void Show() const = 0;
    virtual void Input() = 0;
    virtual void HandleEvent(const TEvent& event) = 0;
    virtual const char* GetName() const = 0;
};