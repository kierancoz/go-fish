#pragma once
#include "Observer.h"
#include "StateInfo.h"

// Unique Events to be stored as the Subject in the EventController - for Observers subscription
namespace Events
{
	class StateEvent : public Subject, public StateInfo {
	public:
		explicit StateEvent(StateInfo &info) : StateInfo(*info.propertyType, *info.optionalListIndex) {};
		~StateEvent() override = default;
	};
}
