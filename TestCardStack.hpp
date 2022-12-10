// TestCardStack.hpp
#pragma once

#include <iostream>
#include <sstream>
#include <string>

#include <gtest/gtest.h>

#include "Card.hpp"
#include "CardStack.hpp"


TEST(CardStackCreate, Simple)
{
    CardStack cs = CardStack();
    ASSERT_NE(&cs, nullptr);
}

TEST(CardStackCreate, Decks)
{
    CardStack cs = CardStack(2, 0);
    ASSERT_NE(&cs, nullptr);
}

TEST(CardStackCreate, Jokers)
{
    CardStack cs = CardStack(2, 2);
    ASSERT_NE(&cs, nullptr);
}

TEST(CardStackCreate, Seed)
{
    CardStack cs1 = CardStack(0);
    ASSERT_NE(&cs1, nullptr);
    CardStack cs2 = CardStack(1, 1, 0);
    ASSERT_NE(&cs2, nullptr);
}


TEST(CardStackManage, SimpleSize)
{
    CardStack cs = CardStack(0, 0);
    ASSERT_EQ(cs.size(), 0);
    cs = CardStack(1, 0);
    ASSERT_EQ(cs.size(), 52);
    cs = CardStack(1, 2);
    ASSERT_EQ(cs.size(), 54);
    cs = CardStack(2, 2);
    ASSERT_EQ(cs.size(), 108);
}

TEST(CardStackManage, Push)
{
    CardStack cs = CardStack(0, 0);
    cs.push(Card(Card::Suit::Spades, Card::Rank::Ace));
    ASSERT_EQ(cs.size(), 1);
    cs.push(Card(Card::Suit::Clubs, Card::Rank::Ace));
    ASSERT_EQ(cs.size(), 2);
}

TEST(CardStackManage, Pop)
{
    CardStack cs = CardStack(0, 0);
    Card c1 = Card(Card::Suit::Spades, Card::Rank::Ace);
    Card c2 = Card(Card::Suit::Clubs, Card::Rank::Ace);
    cs.push(c1);
    cs.push(c2);
    ASSERT_EQ(cs.pop(), c2);
    ASSERT_EQ(cs.size(), 1);
    ASSERT_EQ(cs.pop(), c1);
    ASSERT_EQ(cs.size(), 0);
}

TEST(CardStackManage, Top)
{
    CardStack cs = CardStack(0, 0);
    Card c1 = Card(Card::Suit::Spades, Card::Rank::Ace);
    cs.push(c1);
    ASSERT_EQ(cs.top(), c1);
    ASSERT_EQ(cs.size(), 1);
    ASSERT_EQ(cs.top(), c1);
    ASSERT_EQ(cs.size(), 1);
}


TEST(CardStackShuffle, Simple)
{
    CardStack cs = CardStack(1, 0, 0);
    ASSERT_EQ(cs.top(), Card(Card::Suit::Hearts, Card::Rank::King));
    cs.shuffle();
    ASSERT_EQ(cs.pop(), Card(Card::Suit::Diamonds, Card::Rank::Five));
    ASSERT_EQ(cs.pop(), Card(Card::Suit::Clubs, Card::Rank::Jack));
    ASSERT_EQ(cs.pop(), Card(Card::Suit::Diamonds, Card::Rank::Ten));
}
