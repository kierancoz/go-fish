#pragma once
#include "IStateHistory.h"
#include "Observer.h"

class IEvents
{
public:
    virtual void fireObserverUpdate(StateInfo* info) = 0;
    virtual void addObserverToStateInfo(StateInfo* info, IObserver *observer) = 0;
    virtual IStateHistory* getStateHistory() = 0;
};
