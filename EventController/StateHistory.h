#pragma once
#include <vector>
#include "StateEvent.h"

namespace Events
{
	class StateHistory
	{
	public:
		StateHistory() {};
		~StateHistory() {};

		void addChange(StateInfo* changeInfo)
		{
			stateChanges.push_back(changeInfo);
		}

		StateInfo* latestChange()
		{
			if (!stateChanges.empty())
				return stateChanges.at(stateChanges.size());
			return nullptr;
		}

	private:
		std::vector<StateInfo*> stateChanges;
	};

}
