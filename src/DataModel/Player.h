#pragma once
#include <vector>
#include "Card.h"
#include "Set.h"

class Player {
public:
	explicit Player(std::vector<Set*> *startingHand = nullptr) {
	    if (startingHand != nullptr)
		    hand = *startingHand;
	}
	~Player() = default;

	std::vector<Set*> hand;
	std::vector<Set*> sets;
};
