#pragma once
#include <vector>
#include "Player.h"
#include "Card.h"

enum class GameState { state1 = 1, state2 = 2, state3 = 3 }; // to complete

class DataModel
{
public:
	DataModel(MatchType matchType = MatchType::Standard)
	{
		state = GameState::state1;
		gameType = &matchType;
		players = new std::vector<Player*>();
		deck = new std::vector<Card*>();
	}
	~DataModel() {};

	std::vector<Player*>* players;
	std::vector<Card*>* deck;
	const MatchType *gameType;
	GameState state;
};

