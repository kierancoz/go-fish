#pragma once
#include <vector>
#include "StateInfo.h"
#include "IStateHistory.h"

namespace Events
{
	class StateHistory : public IStateHistory {
	public:
		StateHistory() = default;
		~StateHistory() = default;

		void addChange(StateInfo* changeInfo) {
            stateChanges.push_back(changeInfo);
        }

		StateInfo* operator[](const int &index) override {
		    return stateChanges[index];
        }

		int size() override {
		    return stateChanges.size();
        }

	private:
		std::vector<StateInfo*> stateChanges;
	};
}
