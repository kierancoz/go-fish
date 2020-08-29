
#include "UIController.h"
#include "FeatureFactory.h"

UIController::UIController(EventController *controller)
{
	eventController = controller;
	features = new std::vector<IFeature*>();
	FeatureFactory::createFeatures(features);
	subscribeToEvents();
}

void UIController::subscribeToEvents()
{
	for (auto const feature : *features) {
		for (auto const& sub : feature->Subscriptions())
		{
			eventController->addObservorToStateInfo(sub, feature);
		}
	}
}