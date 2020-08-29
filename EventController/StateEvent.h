#pragma once
#include "Observor.h"

// Event fire type
enum class DMPropertyType { Player, Deck, DeckType, State };

// Generally used to subscribe to & fire events
class StateInfo
{
public:
	StateInfo(DMPropertyType type, int index = -1)
	{
		propertyType = &type;
		optionalListIndex = &index;
	};
	~StateInfo() {};

	const DMPropertyType *propertyType;
	const int *optionalListIndex;
};

// Generally unique StateInfos to be stored as the Subject in the EventController, for Observors to subscribe to
namespace Events
{
	class StateEvent : public Subject, public StateInfo
	{
	public:
		StateEvent(StateInfo *info) : StateInfo(*info->propertyType, *info->optionalListIndex) {}
		~StateEvent() {};
	};
}
