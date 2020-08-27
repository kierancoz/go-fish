#pragma once
#include <vector>
#include "Player.h"
#include "Card.h"

enum class GameState { state1 = 1, state2 = 2, state3 = 3 }; // to complete
enum class MatchType { Standard = 2, FullMatch = 4 };

class DataModel
{
public:
	DataModel()
	{
		state = GameState::state1;
		deckType = MatchType::Standard;
	}

	DataModel(MatchType matchType)
	{
		state = GameState::state1;
		deckType = matchType;
	}
	~DataModel() {};
	std::vector<Player*> players;
	std::vector<Card*> deck;
	MatchType deckType;
	GameState state;
};

