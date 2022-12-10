// TestCard.hpp
#pragma once

#include <iostream>
#include <sstream>

#include <gtest/gtest.h>

#include "Card.hpp"


TEST(CardCreate, Simple)
{
    Card c = Card(Card::Suit::Spades, Card::Rank::Ace);
    ASSERT_NE(&c, nullptr);
}

TEST(CardCreate, Joker)
{
    Card c = Card(Card::Suit::Joker, Card::Rank::Joker);
    ASSERT_NE(&c, nullptr);
}

TEST(CardCreate, BadJoker)
{
    try
    {
        Card(Card::Suit::Spades, Card::Rank::Joker);
        ASSERT_EQ(true, false);
    }
    catch (const std::invalid_argument& e)
    {
        ;
    }

    try
    {
        Card(Card::Suit::Joker, Card::Rank::Ace);
        ASSERT_EQ(true, false);
    }
    catch (const std::invalid_argument& e)
    {
        ;
    }
}


TEST(CardCopy, Constructor)
{
    Card c1 = Card(Card::Suit::Spades, Card::Rank::Ace);
    Card c2 = Card(c1);
    ASSERT_EQ(c1, c2);
}

TEST(CardCopy, Assignment)
{
    Card c1 = Card(Card::Suit::Spades, Card::Rank::Ace);
    Card c2 = Card(Card::Suit::Clubs, Card::Rank::Ace);
    ASSERT_NE(c1, c2);
    c2 = c1;
    ASSERT_EQ(c1, c2);
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

TEST(CardOutput, Joker)
{
    Card c = Card(Card::Suit::Joker, Card::Rank::Joker);
    std::stringstream ss;
    ss << c;
    ASSERT_EQ(ss.str(), "Joker");
}
