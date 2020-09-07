#pragma once
#include "MatchType.h"
#include "IStateHistory.h"

class IActions {
public:
	virtual ~IActions() = default;;

	// DataModel changes
    virtual void setupDeck() = 0;
	virtual void setupDeck(MatchType matchType) = 0;
	virtual void dealDeck(int numCards) = 0;
	virtual bool deckHasCards() = 0;
    virtual bool askForCard(int& askingPlayerIndex, int& askedPlayerIndex) = 0;
	virtual bool askForCard(int& askingPlayerIndex, int& askedPlayerIndex, int askingCardIndex) = 0;
	virtual const IStateHistory* getGameHistory() = 0;
};