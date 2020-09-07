#pragma once
#include "DMPropertyType.h"

// Non-unique event information used to subscribe to Events & fire them
class StateInfo {
public:
    // Default index of -1 so non-negative values can past index and enum values
    explicit StateInfo(DMPropertyType type, int index = -1) {
        propertyType = &type;
        optionalListIndex = &index;
    };
    ~StateInfo() = default;

    DMPropertyType *propertyType;
    int *optionalListIndex;
};