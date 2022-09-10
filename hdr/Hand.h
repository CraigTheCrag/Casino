#include <vector>
#include <string>
#include "Card.h"
#include "Deck.h"

class Hand
{

    std::vector<Card> hand;
    std::vector<int> aceSums;

    const int HIGH_ACE_VALUE = 11;
    const int LOW_ACE_VALUE = 1;

    int get_sum_of_card_values(std::vector<Card> cards);
    std::vector<Card> get_list_without_aces();
    void find_ace_sums();
    int get_number_of_aces();

    public:

        Hand();

        void add_card(Card c);
        int get_hand_size();

        Card get_card(int i);

        std::string show_hand();

        std::vector<int> get_numerical_value();

};