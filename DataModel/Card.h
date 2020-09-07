#pragma once
#include "Suite.h"
#include "CardValue.h"

class Card {
public:
	Card(Suite::Type inSuite, CardValue::Type inVal) {
		suite = &inSuite;
		value = &inVal;
	};
	~Card() = default;

	const Suite::Type *suite;
	const CardValue::Type *value;
};

