#pragma once
#include <vector>
#include "Card.h"
#include "IActions.h"

class Set {
public:
	explicit Set(const MatchType *type, std::vector<Card*>* inCards = new std::vector<Card*>()) {
		gameType = type;
		cards = inCards;
	};
	~Set() = default;

	[[nodiscard]] bool complete() const {
		int size = cards->size();
		switch (*gameType)
		{
		case MatchType::FullMatch:
			return size == 4;
		case MatchType::Standard:
			return size > 1;
		}
		return false;
	}

	std::vector<Set*>* children() {
		if (!complete())
			return nullptr;

		auto* returnSet = new std::vector<Set*>();

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

	[[nodiscard]] const CardValue::Type* value() const {
		return cards->at(0)->value;
	}

	const MatchType *gameType;
	std::vector<Card*> *cards{};
};