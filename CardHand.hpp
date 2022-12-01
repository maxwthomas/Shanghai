// CardHand.hpp
#pragma once

#include <vector>

#include "Card.hpp"


class CardHand
{
private:
    std::vector<Card> cards;

public:
    size_t size ()
    {
        return cards.size();
    }

    CardHand& add_card(const Card& rhs)
    {
        cards.push_back(rhs);
        return *this;
    }

    Card remove_card(size_t g)
    {
        // NOTE: This isn't perfect, would prefer to do a move rather than copy
        Card c = cards.at(g);
        cards.erase(cards.begin() + g);
        return c;
    }

    friend std::ostream& operator<<(std::ostream& os, const CardHand& ch)
    {
        // index based looping because index is printed
        for (size_t i = 0; i < ch.cards.size(); ++i)
            os << i << ": " << ch.cards.at(i) << "\n";
        return os;
    }
};
