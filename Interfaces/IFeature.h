#pragma once
#include <list>
#include "EventController.h"

class IFeature : public IObservor
{
public:
	virtual ~IFeature() {};
	virtual void Update() = 0;
	virtual std::list<StateInfo*> Subscriptions() = 0;
};