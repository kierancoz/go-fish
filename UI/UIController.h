#pragma once
#include "IEvents.h"
#include "FeatureFactory.h"

class UIController {
public:
	explicit UIController(IEvents *controller);
	~UIController() = default;

private:
	std::vector<IUIFeature*> *features;
	IEvents* eventController;
	void subscribeToEvents();
};