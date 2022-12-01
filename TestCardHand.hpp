// TestCardHand.hpp
#pragma once

#include <iostream>
#include <sstream>
#include <string>

#include <gtest/gtest.h>

#include "Card.hpp"
#include "CardHand.hpp"


TEST(CardHandCreate, Simple)
{
    CardHand ch = CardHand();
    ASSERT_NE(&ch, nullptr);
}


TEST(CardHandManage, SimpleSize)
{
    CardHand ch = CardHand();
    ASSERT_EQ(ch.size(), 0);
}

TEST(CardHandManage, SingleAdd)
{
    CardHand ch = CardHand();
    ch.add_card(Card(Card::Suit::Spades, Card::Rank::Ace));
    ASSERT_EQ(ch.size(), 1);
}

TEST(CardHandManage, MultiAdd)
{
    CardHand ch = CardHand();
    Card c = Card(Card::Suit::Spades, Card::Rank::Ace);
    ch.add_card(c).add_card(c);
    ASSERT_EQ(ch.size(), 2);
    ch.add_card(c);
    ASSERT_EQ(ch.size(), 3);
}

TEST(CardHandManage, SingleRemove)
{
    CardHand ch = CardHand();
    Card c1 = Card(Card::Suit::Spades, Card::Rank::Ace);
    ch.add_card(c1);
    Card c2 = ch.remove_card(0);
    ASSERT_EQ(c1, c2);
    ASSERT_EQ(ch.size(), 0);
}

TEST(CardHandManage, MultiRemove)
{
    CardHand ch = CardHand();
    Card c1 = Card(Card::Suit::Spades, Card::Rank::Ace);
    ch.add_card(c1);
    Card c2 = Card(Card::Suit::Clubs, Card::Rank::Ace);
    ch.add_card(c2);
    Card c3 = ch.remove_card(0);
    ASSERT_EQ(c1, c3);
    ASSERT_EQ(ch.size(), 1);
    Card c4 = ch.remove_card(0);
    ASSERT_EQ(c2, c4);
    ASSERT_EQ(ch.size(), 0);
}


TEST(CardHandOutput, Empty)
{
    CardHand ch = CardHand();
    std::stringstream ss;
    ss << ch;
    ASSERT_EQ(ss.str(), "");
}

TEST(CardHandOutput, Simple)
{
    CardHand ch = CardHand();
    std::stringstream ss;
    ch.add_card(Card(Card::Suit::Spades, Card::Rank::Ace));
    ch.add_card(Card(Card::Suit::Clubs, Card::Rank::Ace));
    ch.add_card(Card(Card::Suit::Diamonds, Card::Rank::Ace));
    ch.add_card(Card(Card::Suit::Hearts, Card::Rank::Ace));
    std::string expected_str =
        "0: Ace of Spades\n"
        "1: Ace of Clubs\n"
        "2: Ace of Diamonds\n"
        "3: Ace of Hearts\n"; 
    ss << ch;
    ASSERT_EQ(ss.str(), expected_str);
}

