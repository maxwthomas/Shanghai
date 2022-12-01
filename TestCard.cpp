#include <iostream>
#include <sstream>

#include <gtest/gtest.h>

#include "Card.hpp"


TEST(CardCreate, Simple)
{
    Card c = Card(Card::Suit::Spades, Card::Rank::Ace);
    ASSERT_NE(&c, nullptr);
}


TEST(CardComparision, Equal)
{
    Card c1 = Card(Card::Suit::Spades, Card::Rank::Ace);
    Card c2 = Card(Card::Suit::Spades, Card::Rank::Ace);
    ASSERT_EQ(c1, c2);
}

TEST(CardComparision, NotEqual)
{
    Card c1 = Card(Card::Suit::Spades, Card::Rank::Ace);
    Card c2 = Card(Card::Suit::Clubs, Card::Rank::Ace);
    ASSERT_NE(c1, c2);
}


TEST(CardOutput, Simple)
{
    Card c = Card(Card::Suit::Spades, Card::Rank::Ace);
    std::stringstream ss;
    ss << c;
    ASSERT_EQ(ss.str(), "Ace of Spades");
}
