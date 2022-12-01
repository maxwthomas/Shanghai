#include <gtest/gtest.h>

#include "Card.hpp"

TEST(CardCreateTest, Simple)
{
    Card c = Card(CS_Spades, CR_Ace);
    ASSERT_NE(&c, nullptr);
}
