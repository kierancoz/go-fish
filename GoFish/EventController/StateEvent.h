#pragma once
#include "Observor.h"
#include "StateInfo.h"

namespace Events
{
	class StateEvent : public Subject
	{
	public:
		~StateEvent() {};
		StateEvent(StateInfo *info)
		{
			stateInfo = info;
		}
		StateEvent(DMPropertyType type, int index = 0)
		{
			stateInfo->propertyType = type;
			stateInfo->optionalListIndex = index;
		};

		StateInfo *stateInfo;
	};
}