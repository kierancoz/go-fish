#pragma once
#include <vector>
#include <algorithm>
#include "StateHistory.h"
#include "StateEvent.h"
#include "IEvents.h"

using namespace Events;

class EventController : public IEvents{
public:
	EventController() {
	    stateHistory = new StateHistory();
    };
	~EventController() = default;

	void fireObserverUpdate(StateInfo* info) override;
	void addObserverToStateInfo(StateInfo* info, IObserver *observer) override;
	IStateHistory* getStateHistory() override;

private:
	// Change to map for efficiency later
	std::vector<StateEvent> subjects;

	StateEvent* getEvent(StateInfo* info);
	StateEvent* addNewEvent(StateInfo* info);
	StateHistory* stateHistory;
};
