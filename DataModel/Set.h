#pragma once
#include "Card.h"

enum class MatchType { Standard = 2, FullMatch = 4 };

class Set
{
public:
	Set(const MatchType *type, std::vector<Card*>* inCards = new std::vector<Card*>())
	{
		gameType = type;
		cards = inCards;
	};
	~Set() {};

	bool complete()
	{
		int size = cards->size();
		switch (*gameType)
		{
		case MatchType::FullMatch:
			return size == 4;
		case MatchType::Standard:
			return size > 1;
		}
	}

	std::vector<Set*>* children()
	{
		if (!complete())
			return nullptr;

		std::vector<Set*>* returnSet = new std::vector<Set*>();

		switch (*gameType)
		{
		case MatchType::FullMatch:
			returnSet->push_back(this);
			break;
		case MatchType::Standard:
			std::vector<Card*> newSet = { cards->at(0), cards->at(1) };
			returnSet->push_back(new Set(gameType, &newSet));

			int size = cards->size();
			if (size > 2)
			{
				std::vector<Card*> secondSet = { cards->at(2) };
				if (size == 3)
					secondSet.push_back(cards->at(3));
				returnSet->push_back(new Set(gameType, &secondSet));
			}
			break;
		}
		return returnSet;
	}

	const CardValue::Type* value()
	{
		return cards->at(0)->value;
	}

	const MatchType *gameType;
	std::vector<Card*> *cards;
};