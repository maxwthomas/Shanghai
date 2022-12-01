#include <iostream>
#include <map>
#include <string>


class Card
{
    public:
        enum class Suit { Spades, Clubs, Diamonds, Hearts };
        enum class Rank { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Joker };

    private:
        Suit suit;
        Rank rank;

    public:
        Card(Suit _suit, Rank _rank):
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
