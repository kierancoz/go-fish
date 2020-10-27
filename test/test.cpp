//
// Created by kieran on 10/26/20.
//

#define BOOST_TEST_MODULE SqrTests
#include <boost/test/unit_test.hpp>

#include "Enums/DMPropertyType.h"

BOOST_AUTO_TEST_CASE(FailTest)
{
    BOOST_CHECK_EQUAL(1, (int)DMPropertyType::Deck);
}

BOOST_AUTO_TEST_CASE(PassTest)
{
    BOOST_CHECK_EQUAL(1, (int)DMPropertyType::DeckType);
}