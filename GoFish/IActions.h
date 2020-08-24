#pragma once
#include "DataModel.h"

class IActions
{
public:
	void setupDeck(MatchType matchType = MatchType::Standard) {};
	void dealDeck(int numCards) {};
	bool deckHasCards() {};
	Card goFish() {};
	Card askForCard(Player targetPlayer, Card askingCard) {};
};