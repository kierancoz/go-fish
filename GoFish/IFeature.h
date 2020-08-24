#pragma once
#include "Observor.h"

class IFeature : public IObservor
{
public:
	virtual ~IFeature() {};
	virtual void Update() {};
};