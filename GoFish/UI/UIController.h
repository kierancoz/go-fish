#pragma once
#include "EventController.h"
#include "FeatureFactory.h"

class UIController
{
public:
	UIController(EventController *controller);
	~UIController() {};

private:
	std::vector<IFeature*> *features;
	EventController* eventController;
	void subscribeToEvents();
};