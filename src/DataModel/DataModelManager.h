#pragma once
#include <algorithm>
#include "IActions.h"
#include "IEvents.h"
#include "DataModel.h"

class DataModelManager : public IActions {
public:
	explicit DataModelManager(IEvents *controller, MatchType matchType = MatchType::Standard);
	~DataModelManager() override = default;

	void setupDeck() override;
    void setupDeck(MatchType matchType) override;
    void dealDeck(int numCards, int numPlayers) override;
    bool deckHasCards() override;
    bool askForCard(int& askingPlayerIndex, int& askedPlayerIndex) override;
    bool askForCard(int& askingPlayerIndex, int& askedPlayerIndex, int askingCardIndex) override;
    IStateHistory* getGameHistory() override;

private:
	DataModel* dataModel;
	IEvents* eventController;
	Card* getCardFromDeck();
	Set* getPlayerSetForCard(Player* player, Card* searchCard);
	void setupPlayers(int numPlayers);
	static void moveSetFromHand(Player* player, Set* set);

	// might get rid of
    void giveCard(Player* player, Card* givingCard);
    Card* goFish();
};