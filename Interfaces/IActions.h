#pragma once
#include "DataModel.h"

class IActions
{
public:
	virtual ~IActions() {};

	// DataModel changes
	virtual void setupDeck(MatchType matchType = MatchType::Standard) = 0;
	virtual void dealDeck(int numCards) = 0; // will check for sets
	virtual bool deckHasCards() = 0;

	//virtual void askForCard(int& playerIndex, int& cardIndex) = 0;
	//virtual void check

	// Get DataModel values
	//virtual void getPlayer

//private:
	virtual Card* askForCard(Player *targetPlayer, Card *askingCard) = 0;
	virtual void giveCard(Player* player, Card* givingCard) = 0; // will check for sets
	virtual Card* goFish() = 0;
};