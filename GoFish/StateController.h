#pragma once
#include <vector>
#include "StateEvent.h"

namespace Events
{
	class StateController
	{
	public:
		StateController() {};
		~StateController() {};

		void addChange(StateInfo* changeInfo)
		{
			stateChanges.push_back(changeInfo);
		}

		StateInfo* latestChange()
		{
			if (!stateChanges.empty())
				return stateChanges[stateChanges.size()];
		}

	private:
		std::vector<StateInfo*> stateChanges;
	};

}
