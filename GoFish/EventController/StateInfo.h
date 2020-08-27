#pragma once

enum class DMPropertyType { Player, Deck, DeckType, State };

struct StateInfo
{
	DMPropertyType propertyType;
	int optionalListIndex;
};
