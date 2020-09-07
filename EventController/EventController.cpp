#include "EventController.h"

// Public methods
void EventController::fireObserverUpdate(StateInfo *info) {
	StateEvent* event = getEvent(info);
	event->Notify();
    stateHistory->addChange(info);
}

void EventController::addObserverToStateInfo(StateInfo* info, IObserver* observer) {
	StateEvent* event = getEvent(info);
	event->Attach(observer);
}

// Private methods
StateEvent* EventController::getEvent(StateInfo* info) {
	auto event = std::find_if(subjects.begin(), subjects.end(), [info](const StateEvent &f)->bool
		{ return (*f.optionalListIndex == *info->optionalListIndex && *f.propertyType == *info->propertyType); });

	// if the event doesn't exist, create it
	if (event == subjects.end())
		return addNewEvent(info);

	return &*event;
}

StateEvent* EventController::addNewEvent(StateInfo* info) {
	subjects.push_back((StateEvent)*info);
	return &subjects.back();
}

IStateHistory* EventController::getStateHistory() {
    return stateHistory;
}