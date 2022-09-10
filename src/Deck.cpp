#include <algorithm>
#include <random>
#include "Deck.h"

Deck::Deck(void)
{
    for (int suit=0;suit<Card::NUM_OF_SUITS;suit++)
    {
        for (int val=0;val<Card::NUM_OF_VALS;val++)
        {
            this->deck.push_back(Card((Suit)suit, (Value)val));
        }
    }
    
    std::random_device rd;
    std::default_random_engine rng(rd());

    shuffle(this->deck.begin(), this->deck.end(), rng);
}

void Deck::reset(void) { this->dealtCards.clear(); }

Card Deck::get_card(int i)
{
    return this->deck.at(i);
}

Card Deck::deal_card(int i)
{
    Card current = get_card(i);

    for (int j=0;j<this->dealtCards.size();j++)
    {
        if (current == dealtCards.at(j))
        {
            return Card(Suit::INVALID, Value::INVALID);
        }
    }

    this->dealtCards.push_back(current);
    return current;
}

int Deck::get_deck_size(void)
{
    return this->deck.size();
}