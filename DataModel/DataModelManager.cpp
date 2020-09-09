#include "DataModelManager.h"

DataModelManager::DataModelManager(IEvents *controller, MatchType matchType) {
	dataModel = new DataModel(matchType);
	eventController = controller;
}

// Public members
void DataModelManager::setupDeck() {
    setupDeck(MatchType::Standard);
}

void DataModelManager::setupDeck(MatchType matchType) {
	dataModel->gameType = &matchType;
    eventController->fireObserverUpdate(new StateInfo(DMPropertyType::DeckType));

	for (const auto inSuite : Suite::All)
	{
		for (const auto inVal : CardValue::All)
		{
			dataModel->deck.push_back(new Card(inSuite, inVal));
		};
	};
    eventController->fireObserverUpdate(new StateInfo(DMPropertyType::Deck));
}

void DataModelManager::dealDeck(int numCards, int numPlayers) {
    setupPlayers(numPlayers);
	for (const auto player : dataModel->players)
	{
		for (int i = 0; i < numCards; i++) {
			Card* fishedCard = getCardFromDeck();

			Set* set = getPlayerSetForCard(player, fishedCard);

			if (set->complete())
				moveSetFromHand(player, set);
		}
	}
    eventController->fireObserverUpdate(new StateInfo(DMPropertyType::Player));
    eventController->fireObserverUpdate(new StateInfo(DMPropertyType::Deck));
}

bool DataModelManager::deckHasCards() {
    return !dataModel->deck.empty();
}

bool DataModelManager::askForCard(int &askingPlayerIndex, int &askedPlayerIndex) {
    return askForCard(askedPlayerIndex, askedPlayerIndex, 0);
}

bool DataModelManager::askForCard(int& askingPlayerIndex, int& askedPlayerIndex, int askingCardIndex) {
    return false;
}

IStateHistory* DataModelManager::getGameHistory() {
    return eventController->getStateHistory();
}

// Private members
void DataModelManager::setupPlayers(int numPlayers) {
    for (int i = 0; i < numPlayers; i++)
    {
        dataModel->players.push_back(new Player());
        eventController->fireObserverUpdate(new StateInfo(DMPropertyType::Player, i));
    }
}

void DataModelManager::moveSetFromHand(Player *player, Set* set) {
	// get children sets and add to sets vector
	for (auto childSet : *set->children())
	{
		player->sets.push_back(childSet);
	}

	// erase past set
	auto it = std::find(player->sets.begin(), player->sets.end(), set);
	player->sets.erase(it);
}

Set* DataModelManager::getPlayerSetForCard(Player* player, Card* searchCard) {
	for (auto iter = player->hand.begin(); iter < player->hand.end(); iter++)
	{
		Set* set = player->hand[iter - player->hand.begin()];

		if (*set->value() == *searchCard->value)
		{
			set->cards->push_back(searchCard);
			return set;
		}
	}
	std::vector<Card*> inVector = { searchCard };
	auto newSet = new Set(dataModel->gameType, &inVector);
	player->hand.push_back(newSet);
	return newSet;
}

void DataModelManager::giveCard(Player* player, Card* givingCard) {

}

Card* DataModelManager::goFish() {
	Card* fishedCard = getCardFromDeck();
    eventController->fireObserverUpdate(new StateInfo(DMPropertyType::Deck));
	return fishedCard;
}

Card* DataModelManager::getCardFromDeck() {
	int index = rand() % dataModel->deck.size();
	Card* returnCard = dataModel->deck[index];
	dataModel->deck.erase(dataModel->deck.begin() + index);
    eventController->fireObserverUpdate(new StateInfo(DMPropertyType::Deck));
	return returnCard;
}
