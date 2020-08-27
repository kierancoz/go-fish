#pragma once

enum class Suite { Clubs, Diamonds, Hearts, Spades };
enum class CardValue { One, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

class Card
{
public:
	Card(Suite inSuite, CardValue inVal)
	{
		suite = inSuite;
		value = inVal;
	};
	~Card() {};
	Suite suite;
	CardValue value;
};

