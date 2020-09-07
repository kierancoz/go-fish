// GoFish.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "EventController.h"
#include "UIController.h"
#include "DataModelManager.h"

int main()
{
    std::cout << "Hello World!" << std::endl;

    // Create EventController and UIController
    auto eventController = new EventController();

    // DataModelManager fires events for pickup by UI
    auto dataModelManager = new DataModelManager(eventController);

    // UI Depends on Events fired from DataModelManager
    auto uiController = new UIController(eventController);

    // Create desk
    dataModelManager->setupDeck();
    dataModelManager->dealDeck(5);

    // Testing ~~ Checking Game History Size
    std::cout << dataModelManager->getGameHistory()->size() << std::endl;

    std::cout << "Goodbye World!" << std::endl;
}