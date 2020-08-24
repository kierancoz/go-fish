#pragma once
#include <vector>
#include "Card.h"

class Player
{
public:
	Player() {}
	Player(std::vector<Card> startingHand)
	{
		hand = startingHand;
	}
	~Player() {};
	std::vector<Card> hand;
	std::vector<std::vector<Card>> sets;
};
