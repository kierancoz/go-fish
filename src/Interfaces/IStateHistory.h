#pragma once
#include "StateInfo.h"

class IStateHistory {
public:
    virtual StateInfo* operator[](const int &index) = 0;
    virtual int size() = 0;
};