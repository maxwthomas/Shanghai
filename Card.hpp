#include <iostream>
#include <map>
#include <string>

enum Card_Suit
{
    CS_Spades,
    CS_Clubs,
    CS_Diamonds,
    CS_Hearts
};

enum Card_Rank
{
    CR_Ace,
    CR_Two,
    CR_Three,
    CR_Four,
    CR_Five,
    CR_Six,
    CR_Seven,
    CR_Eight,
    CR_Nine,
    CR_Ten,
    CR_Jack,
    CR_Queen,
    CR_King,
    CR_Joker
};


class Card
{
    private:
        enum Card_Suit suit;
        enum Card_Rank rank;

    public:
        Card(enum Card_Suit _suit, enum Card_Rank _rank):
            suit(_suit),
            rank(_rank)
        {}

        friend bool operator==(const Card& lhs, const Card& rhs)
        {
            return lhs.suit == rhs.suit && lhs.rank == rhs.rank;
        }

        friend bool operator!=(const Card& lhs, const Card& rhs)
        {
            return !(lhs == rhs);
        }

        friend std::ostream& operator<<(std::ostream& os, const Card& c)
        {
            if (c.rank == CR_Joker)
                return os << c.rank_str();
            return os << c.rank_str() << " of " << c.suit_str();
        }

    private:
        const char* suit_str() const
        {
            switch (this->suit)
            {
                case CS_Spades: return "Spades";
                case CS_Clubs: return "Clubs";
                case CS_Diamonds: return "Diamonds";
                case CS_Hearts: return "Hearts";
                default: return "";
            }
        }

        const char* rank_str() const
        {
            switch (this->rank)
            {
                case CR_Ace: return "Ace";
                case CR_Two: return "Two";
                case CR_Three: return "Three";
                case CR_Four: return "Four";
                case CR_Five: return "Five";
                case CR_Six: return "Six";
                case CR_Seven: return "Seven";
                case CR_Eight: return "Eight";
                case CR_Nine: return "Nine";
                case CR_Ten: return "Ten";
                case CR_Jack: return "Jack";
                case CR_Queen: return "Queen";
                case CR_King: return "King";
                case CR_Joker: return "Joker";
                default: return "";
            }
        }
};
