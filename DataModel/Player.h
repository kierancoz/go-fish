#pragma once
#include <vector>
#include "Card.h"
#include "Set.h"

class Player
{
public:
	Player(std::vector<Set*> *startingHand = new std::vector<Set*>())
	{
		hand = startingHand;
		sets = new std::vector<Set*>();
	}
	~Player() {};

	std::vector<Set*>* hand;
	std::vector<Set*>* sets;
};
