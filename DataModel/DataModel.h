#pragma once
#include <vector>
#include "Player.h"
#include "Card.h"
#include "GameState.h"

class DataModel {
public:
	explicit DataModel(MatchType matchType = MatchType::Standard) {
		state = GameState::state1;
		gameType = &matchType;
	}
	~DataModel() = default;

	std::vector<Player*> players;
	std::vector<Card*> deck;
	const MatchType *gameType;
	GameState state;
};

