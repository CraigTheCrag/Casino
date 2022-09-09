#include "Card.h"
#include <stdlib.h>

Card::Card(Suit suit, Value value)
{
    this->suit = suit;
    this->value = value;
}

Suit Card::get_suit()
{
    return this->suit;
}

Value Card::get_value()
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

std::vector<uint8_t> Card::get_numerical_value()
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

Suit Card::get_random_suit()
{
    return (Suit)(rand() % NUM_OF_SUITS);
}

Value Card::get_random_value()
{
    return (Value)(rand() % NUM_OF_VALS);
}

std::string Card::toString()
{
    auto valstr = this->VALUE_STR.find(this->value)->second;
    auto suitstr = this->SUIT_STR.find(this->suit)->second;
    return (valstr + " " + suitstr);
}

bool Card::equals(Card card)
{
    return (this->get_value() == card.get_value() && this->get_suit() == card.get_suit());
}