//
// Created by kieran on 10/26/20.
//

#define BOOST_TEST_MODULE GoFishTests
#include <boost/test/unit_test.hpp>

#include "Enums/DMPropertyType.h"

BOOST_AUTO_TEST_CASE(CheckLibraryLinkage)
{
    BOOST_CHECK_EQUAL((int)DMPropertyType::DeckType, (int)DMPropertyType::DeckType);
    BOOST_CHECK_EQUAL(1, (int)DMPropertyType::Deck);
}