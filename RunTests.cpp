// RunTests.cpp

#include <gtest/gtest.h>

#include "TestCard.hpp"
#include "TestCardHand.hpp"
#include "TestCardStack.hpp"

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
