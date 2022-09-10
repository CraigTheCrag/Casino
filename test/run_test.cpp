#include "test_card.h"
#include "test_deck.h"
#include "test_hand.h"

void (*tests[])() = {
    &card_constructor_test,
    &card_value_test,
    &random_suit_test,
    &random_value_test,
    &card_string_test,
    &card_equaliy_test
};


int main()
{
    int num_of_tests = sizeof(tests)/sizeof(tests[0]);

    for (int i=0;i<num_of_tests;i++)
    {
        tests[i]();
    }
}

