#pragma once
#include <vector>
#include "StateController.h"
using namespace Events;

class EventController
{
public:
	EventController() 
	{
		stateController = new StateController();
	};

	~EventController() {};

	void fireObservorUpdate(StateInfo* info);
	void addObservorToStateInfo(StateInfo* info, IObservor* observor);

private:
	std::vector<StateEvent*> subjects;
	StateEvent* getEvent(const StateInfo* info);
	StateEvent* addNewEvent(StateInfo* info);
	StateController* stateController;
};
