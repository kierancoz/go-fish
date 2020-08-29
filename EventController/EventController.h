#pragma once
#include <vector>
#include "StateHistory.h"
using namespace Events;

class EventController
{
public:
	EventController() {};
	~EventController() {};

	void fireObservorUpdate(StateInfo* info);
	void addObservorToStateInfo(StateInfo* info, IObservor* observor);

private:
	// Change to map for efficiency later
	std::vector<StateEvent*> subjects;

	StateEvent* getEvent(const StateInfo* info);
	StateEvent* addNewEvent(StateInfo* info);
	StateHistory stateHistory;
};
