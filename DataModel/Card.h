#pragma once

namespace Suite
{
	enum class Type
	{
		Clubs, Diamonds, Hearts, Spades
	};

	static const Type All[] = { Type::Clubs, Type::Diamonds, Type::Hearts, Type::Spades };
}

namespace CardValue
{
	enum class Type
	{
		One, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace
	};

	static const Type All[] = { Type::One, Type::Two, Type::Three, Type::Four, Type::Five, Type::Six,
		Type::Seven, Type::Eight, Type::Nine, Type::Ten, Type::Jack, Type::Queen, Type::King, Type::Ace };
}

class Card
{
public:
	Card(Suite::Type inSuite, CardValue::Type inVal)
	{
		suite = &inSuite;
		value = &inVal;
	};
	~Card() {};

	const Suite::Type *suite;
	const CardValue::Type *value;
};

