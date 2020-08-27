#pragma once
#include "EventController.h"
#include "FeatureFactory.h"

class UIController
{
public:
	UIController();
	~UIController() {};
	void subscribeToEvents(EventController* events);

private:
	std::vector<IFeature*> features;
};