#include <vector>
#include <string>
#include <map>

enum Suit { DIAMOND, HEART, CLUB, SPADE, INVALID};

std::string suit_to_string(Suit suit)
{
    switch (suit)
    {
        case DIAMOND:   return "DIAMOND";
        case HEART:     return "HEART";
        case SPADE:     return "SPADE";
        case CLUB:      return "CLUB";
    }
}

enum Value { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE, INVALID };

std::string value_to_string(Value val)
{
    switch (val)
    {
        case TWO:   return "TWO";
        case THREE: return "THREE";
        case FOUR:  return "FOUR";
        case FIVE:  return "FIVE";
        case SIX:   return "SIX";
        case SEVEN: return "SEVEN";
        case EIGHT: return "EIGHT";
        case NINE:  return "NINE";
        case TEN:   return "TEN";
        case JACK:  return "JACK";
        case QUEEN: return "QUEEN";
        case KING:  return "KING";
        case ACE:   return "ACE";
    }
}

class Card
{

    Suit suit;
    Value value;

    public:

        static const int NUM_OF_VALS = 13;
        static const int NUM_OF_SUITS = 4;

        Card(Suit suit, Value value);

        Suit get_suit(void);
        Value get_value(void);

        void set_suit(Suit suit);
        void set_value(Value value);

        std::vector<uint8_t> get_numerical_value(void);

        static Suit get_random_suit(void);
        static Value get_random_value(void);

        std::string toString(void);
        friend bool operator==(Card lhs, Card rhs);
        friend bool operator!=(Card lhs, Card rhs);
};