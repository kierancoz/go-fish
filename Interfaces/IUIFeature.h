#pragma once
#include <list>
#include "StateInfo.h"

class IUIFeature : public IObserver {
public:
	~IUIFeature() override = default;
	void Update() override = 0;
	virtual std::list<StateInfo*> Subscriptions() = 0;
};