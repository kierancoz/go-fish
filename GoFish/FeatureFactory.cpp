#include "FeatureFactory.h"


void FeatureFactory::createFeatures()
{
	// Add features to std::vector for features
	// Then, add their subscriptions
	subscribeFeatures();
}

void FeatureFactory::subscribeFeatures()
{
	for (auto const& feature : features) {
		for (auto const& sub : feature->Subscriptions())
		{
			eventController->addObservorToStateInfo(sub, feature);
		}
	}
}
