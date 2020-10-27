#include "UIController.h"

UIController::UIController(IEvents *controller) {
	eventController = controller;
	features = new std::vector<IUIFeature*>();
	FeatureFactory::createFeatures(features);
	subscribeToEvents();
}

void UIController::subscribeToEvents() {
	for (auto const feature : *features) {
		for (auto const& sub : feature->Subscriptions())
		{
            eventController->addObserverToStateInfo(sub, feature);
		}
	}
}