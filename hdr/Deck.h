#include <vector>
#include "Card.h"

class Deck
{

    std::vector<Card> deck;
    std::vector<Card> dealtCards;

    public:

        Deck();

        void reset();

        Card get_card(int i);
        Card deal_card(int i);

        int get_deck_size();

};