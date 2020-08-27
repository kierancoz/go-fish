#pragma once
#include "DataModel.h"

class IActions
{
public:
	virtual void setupDeck(MatchType matchType = MatchType::Standard) {};
	virtual void dealDeck(int numCards) {};
	virtual bool deckHasCards() {};
	virtual Card goFish() {};
	virtual Card askForCard(Player targetPlayer, Card askingCard) {};
};