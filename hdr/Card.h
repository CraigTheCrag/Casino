#include <vector>
#include <string>
#include <map>

enum Suit { DIAMOND, HEART, CLUB, SPADE, INVALID};

enum Value { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE, INVALID };

class Card
{

    Suit suit;
    Value value;

    const std::map<Suit, std::string> SUIT_STR {
        { DIAMOND, "DIAMOND"},
        { HEART, "HEART"},
        { CLUB, "CLUB"},
        { SPADE, "SPADE"}
    };

    const std::map<Value, std::string> VALUE_STR {
        { TWO, "TWO"}, { THREE, "THREE"}, { FOUR, "FOUR"},
        { FIVE, "FIVE"}, { SIX, "SIX"}, { SEVEN, "SEVEN"},
        { EIGHT, "EIGHT"}, { NINE, "NINE"}, { TEN, "TEN"},
        { JACK, "JACK"}, { QUEEN, "QUEEN"}, { KING, "KING"},
        { ACE, "ACE"},
    };

    public:

        static const int NUM_OF_VALS = 13;
        static const int NUM_OF_SUITS = 4;

        Card(Suit suit, Value value);

        Suit get_suit();
        Value get_value();

        void set_suit(Suit suit);
        void set_value(Value value);

        std::vector<uint8_t> get_numerical_value();

        static Suit get_random_suit();
        static Value get_random_value();

        std::string toString();
        bool equals(Card card);
};