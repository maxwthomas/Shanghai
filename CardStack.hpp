// CardStack.hpp
#pragma once

#include <vector>
#include <stack>
#include <random>
#include <algorithm>

#include "Card.hpp"


static const Card::Suit deck_suits[] = { Card::Suit::Spades, Card::Suit::Clubs, Card::Suit::Diamonds, Card::Suit::Hearts };
static const Card::Rank deck_ranks[] = { Card::Rank::Ace, Card::Rank::Two, Card::Rank::Three, Card::Rank::Four, Card::Rank::Five, Card::Rank::Six, Card::Rank::Seven, Card::Rank::Eight, Card::Rank::Nine, Card::Rank::Ten, Card::Rank::Jack, Card::Rank::Queen, Card::Rank::King };

class CardStack
{
private:
    // Using a vector to make shuffling easier
    std::vector<Card> cards;
    // Random Number Generator for shuffling
    std::mt19937 g;

public:
    CardStack()
    {
        std::random_device rd;
        g = std::mt19937(rd());
    }

    CardStack(unsigned int seed)
    {
        g = std::mt19937(seed);
    }

    CardStack(size_t decks, size_t jokers_per_deck):
        CardStack(decks, jokers_per_deck, 0)
    {
        std::random_device rd;
        g = std::mt19937(rd());
    }

    CardStack(size_t decks, size_t jokers_per_deck, unsigned int seed)
    {
        for (size_t i = 0; i < decks; ++i)
        {
            for (const Card::Suit& cs : deck_suits)
            {
                for (const Card::Rank& cr : deck_ranks)
                {
                    cards.push_back(Card(cs, cr));
                }
            }
            for (size_t j = 0; j < jokers_per_deck; ++j)
            {
                cards.push_back(Card(Card::Suit::Joker, Card::Rank::Joker));
            }
        }

        g = std::mt19937(seed);
    }


    size_t size ()
    {
        return cards.size();
    }

    Card pop()
    {
        Card c = cards.back();
        cards.pop_back();
        return c;
    }

    Card& top()
    {
        return cards.back();
    }

    void push(const Card& c)
    {
        cards.push_back(c);
    }

    void shuffle()
    {
        std::shuffle(cards.begin(), cards.end(), g);
    }
};
