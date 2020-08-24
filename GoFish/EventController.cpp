#include "EventController.h"

// Public
void EventController::fireObservorUpdate(StateInfo *info)
{
	StateEvent* event = getEvent(info);
	if (event == nullptr)
		event = addNewEvent(info);

	event->Notify();
	stateController->addChange(info);
}

void EventController::addObservorToStateInfo(StateInfo* info, IObservor* observor)
{
	StateEvent* event = getEvent(info);
	if (event == nullptr)
		event = addNewEvent(info);

	event->Attach(observor);
}

// Private
StateEvent* EventController::getEvent(const StateInfo* info)
{
	auto event = std::find_if(subjects.begin(), subjects.end(), [&info](const StateEvent* f)->bool
		{ return (f->stateInfo.optionalListIndex == info->optionalListIndex &&
		f->stateInfo.propertyType == info->propertyType); });

	if (event == subjects.end())
		return nullptr;

	return *event;
}

StateEvent* EventController::addNewEvent(StateInfo* info)
{
	StateEvent* event = new StateEvent(*info);
	subjects.push_back(event);
	return event;
}