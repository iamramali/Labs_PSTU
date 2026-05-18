#pragma once
#include "Vector.h"

class Dialog : public Vector {
public:
    Dialog();
    ~Dialog() override {}

    void GetEvent(TEvent& event);
    int Execute();
    int Valid() const;
    void ClearEvent(TEvent& event);
    void EndExec();
    void HandleEvent(TEvent& event);

protected:
    int EndState;
};