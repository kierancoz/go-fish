#pragma once
#include "IActions.h"
#include "EventController.h"

class DataModelManager : public IActions
{
public:
	DataModelManager(EventController *controller, MatchType matchType = MatchType::Standard);
	~DataModelManager() {};

	void setupDeck(MatchType matchType);
	void dealDeck(int &numCards);
	bool deckHasCards();

	Card* askForCard(Player* targetPlayer, Card* askingCard);
	void giveCard(Player* player, Card* givingCard);
	Card* goFish();

private:
	DataModel* dataModel;
	EventController* eventController;
	Card* getCardFromDeck();
	Set* getPlayerSetForCard(Player* player, Card* searchCard);
	void moveSetFromHand(Player* player, Set* set);
};