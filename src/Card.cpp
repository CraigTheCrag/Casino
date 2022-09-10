#include "Card.h"
#include <stdlib.h>

Card::Card(Suit suit, Value value)
{
    this->suit = suit;
    this->value = value;
}

Suit Card::get_suit(void)
{
    return this->suit;
}

Value Card::get_value(void)
{
    return this->value;
}

void Card::set_suit(Suit suit)
{
    this->suit = suit;
}

void Card::set_value(Value value)
{
    this->value = value;
}

std::vector<uint8_t> Card::get_numerical_value(void)
{
    switch (this->value)
    {
        case ACE:
            return std::vector<uint8_t> {1, 11};
        case TEN:
        case JACK:
        case QUEEN:
        case KING:
            return std::vector<uint8_t> {10};
        default:
            uint8_t val = (uint8_t)this->value + 2;
            return std::vector<uint8_t> {val};
    }
}

Suit Card::get_random_suit(void)
{
    return (Suit)(rand() % NUM_OF_SUITS);
}

Value Card::get_random_value(void)
{
    return (Value)(rand() % NUM_OF_VALS);
}

std::string Card::toString(void)
{
    auto valstr = value_to_string(this->value);
    auto suitstr = suit_to_string(this->suit);
    return (valstr + " " + suitstr);
}

bool operator==(Card lhs, Card rhs)
{
    return (lhs.get_value() == rhs.get_value() && lhs.get_suit() == rhs.get_suit());
}

bool operator!=(Card lhs, Card rhs)
{
    return !(lhs == rhs);
}