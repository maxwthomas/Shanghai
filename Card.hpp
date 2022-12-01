// Card.hpp
#pragma once

#include <iostream>
#include <map>
#include <string>
#include <stdexcept>


class Card
{
public:
    enum class Suit { Spades, Clubs, Diamonds, Hearts, Joker };
    enum class Rank { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Joker };

private:
    Suit suit;
    Rank rank;

public:
    Card(Suit _suit, Rank _rank):
        suit(_suit),
        rank(_rank)
    {
        if ((suit == Suit::Joker && rank != Rank::Joker) || (suit != Suit::Joker && rank == Rank::Joker))
            throw std::invalid_argument("Joker Suit can only go with Joker Rank.");
    }

    // Need to explicitly define bc of member variables not standard copyable
    Card(const Card& c):
        suit(c.suit),
        rank(c.rank)
    {}

    // Need to explicitly define bc of member variables not standard copyable
    Card& operator=(const Card& c)
    {
        suit = c.suit;
        rank = c.rank;
        return *this;
    }

    inline bool operator==(const Card& rhs) const
    {
        return suit == rhs.suit && rank == rhs.rank;
    }

    inline bool operator!=(const Card& rhs) const
    {
        return !operator==(rhs);
    }

    friend std::ostream& operator<<(std::ostream& os, const Card& c)
    {
        if (c.rank == Rank::Joker)
            return os << c.rank_str();
        return os << c.rank_str() << " of " << c.suit_str();
    }

private:
    const char* suit_str() const
    {
        switch (suit)
        {
            case Suit::Spades: return "Spades";
            case Suit::Clubs: return "Clubs";
            case Suit::Diamonds: return "Diamonds";
            case Suit::Hearts: return "Hearts";
            default: return "";
        }
    }

    const char* rank_str() const
    {
        switch (rank)
        {
            case Rank::Ace: return "Ace";
            case Rank::Two: return "Two";
            case Rank::Three: return "Three";
            case Rank::Four: return "Four";
            case Rank::Five: return "Five";
            case Rank::Six: return "Six";
            case Rank::Seven: return "Seven";
            case Rank::Eight: return "Eight";
            case Rank::Nine: return "Nine";
            case Rank::Ten: return "Ten";
            case Rank::Jack: return "Jack";
            case Rank::Queen: return "Queen";
            case Rank::King: return "King";
            case Rank::Joker: return "Joker";
            default: return "";
        }
    }
};
