#include <vector>
#include "IFeature.h"

class FeatureFactory
{
public:
	FeatureFactory(EventController *controller)
	{
		eventController = controller;
	};
	~FeatureFactory() {};
	void createFeatures();
	void subscribeFeatures();

private:
	std::vector<IFeature*> features;
	EventController *eventController;
};