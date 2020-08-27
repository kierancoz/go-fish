
#include "UIController.h"
#include "FeatureFactory.h"

UIController::UIController()
{
	FeatureFactory::createFeatures(&features);
}

void UIController::subscribeToEvents(EventController* events)
{
	for (auto const feature : features) {
		for (auto const& sub : feature->Subscriptions())
		{
			events->addObservorToStateInfo(sub, feature);
		}
	}
}