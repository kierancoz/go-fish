
#include "DataModelManager.h"

DataModelManager::DataModelManager(EventController *controller, MatchType matchType)
{
	dataModel = new DataModel(matchType);
	eventController = controller;
}

void DataModelManager::setupDeck(MatchType matchType)
{
	dataModel->gameType = &matchType;
	eventController->fireObservorUpdate(new StateInfo(DMPropertyType::DeckType));

	for (const auto inSuite : Suite::All)
	{
		for (const auto inVal : CardValue::All)
		{
			dataModel->deck->push_back(new Card(inSuite, inVal));
		};
	};
	eventController->fireObservorUpdate(new StateInfo(DMPropertyType::Deck));
}

void DataModelManager::dealDeck(int &numCards)
{
	for (const auto player : *dataModel->players)
	{
		for (int i = 0; i < numCards; i++) {
			Card* fishedCard = getCardFromDeck();

			Set* set = getPlayerSetForCard(player, fishedCard);

			if (set->complete())
				moveSetFromHand(player, set);
		}
	}
	eventController->fireObservorUpdate(new StateInfo(DMPropertyType::Player));
	eventController->fireObservorUpdate(new StateInfo(DMPropertyType::Deck));
}

void DataModelManager::moveSetFromHand(Player *player, Set* set)
{
	// get children sets and add to sets vector
	for (auto set : *set->children())
	{
		player->sets->push_back(set);
	}

	// erase past set
	auto it = std::find(player->sets->begin(), player->sets->end(), set);
	player->sets->erase(it);
}

Set* DataModelManager::getPlayerSetForCard(Player* player, Card* searchCard)
{
	for (auto iter = player->hand->begin(); iter < player->hand->end(); iter++)
	{
		Set* set = player->hand->at(iter - player->hand->begin());

		if (*set->value() == *searchCard->value)
		{
			set->cards->push_back(searchCard);
			return set;
		}
	}
	std::vector<Card*> inVector = { searchCard };
	auto newSet = new Set(dataModel->gameType, &inVector);
	player->hand->push_back(newSet);
	return newSet;
}

bool DataModelManager::deckHasCards()
{
	return true;
}

Card* DataModelManager::askForCard(Player* targetPlayer, Card* askingCard)
{
	return NULL;
}

void DataModelManager::giveCard(Player* player, Card* givingCard)
{

}

Card* DataModelManager::goFish()
{
	Card* fishedCard = getCardFromDeck();
	eventController->fireObservorUpdate(new StateInfo(DMPropertyType::Deck));
	return fishedCard;
}

Card* DataModelManager::getCardFromDeck()
{
	int index = rand() % dataModel->deck->size();
	Card* returnCard = dataModel->deck->at(index);
	dataModel->deck->erase(dataModel->deck->begin() + index);
	eventController->fireObservorUpdate(new StateInfo(DMPropertyType::Deck));
	return returnCard;
}