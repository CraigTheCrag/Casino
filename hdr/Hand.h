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
    std::vector<Card> get_list_without_aces(void);
    void find_ace_sums(void);
    int get_number_of_aces(void);

    public:

        Hand(void);

        void add_card(Card c);
        int get_hand_size(void);

        Card get_card(int i);

        std::string show_hand(void);

        std::vector<int> get_numerical_value(void);

};