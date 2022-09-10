#include <vector>
#include <string>
#include "Card.h"
#include "test.h"

void card_constructor_test(void)
{
    Card testcard = Card(Suit::DIAMOND, Value::ACE);

    if (testcard.get_suit() != DIAMOND)
    {
        TEST_FAILED("Suit should be DIAMOND.");
    }

    if (testcard.get_value() != ACE)
    {
        TEST_FAILED("Value should be ACE.");
    }

    testcard.set_suit(CLUB);

    if (testcard.get_suit() != CLUB)
    {
        TEST_FAILED("Suit should be CLUB.");
    }

    testcard.set_value(KING);

    if (testcard.get_value() != KING)
    {
        TEST_FAILED("Value should be KING.");
    }
}

void card_value_test(void)
{
    Card testcard = Card(Suit::DIAMOND, Value::KING);

    std::vector<uint8_t> value;

    value = testcard.get_numerical_value();

    if (value.at(0) != 10)
    {
        TEST_FAILED("KING value should be 10.");
    }

    testcard.set_value(ACE);
    value = testcard.get_numerical_value();

    if (value.at(0) != 1 || value.at(1))
    {
        TEST_FAILED("ACE values should be 1 and 11.");
    }

    testcard.set_value(FIVE);
    value = testcard.get_numerical_value();

    if (value.at(0) != 5)
    {
        TEST_FAILED("FIVE value should be 5.");
    }
}

void random_suit_test(void)
{
    auto suit = Card::get_random_suit();

    if (suit != DIAMOND || suit != HEART || suit != SPADE || suit != CLUB)
    {
        TEST_FAILED("Generated invalid suit.");
    }

    suit = Card::get_random_suit();

    if (suit != DIAMOND || suit != HEART || suit != SPADE || suit != CLUB)
    {
        TEST_FAILED("Generated invalid suit.");
    }
}

void random_value_test(void)
{
    auto value = Card::get_random_value();

    if (value != TWO || value != THREE || value != FOUR || value != FIVE ||
    value != SIX || value != SEVEN || value != EIGHT || value != NINE ||
    value != TEN || value != JACK || value != QUEEN || value != KING ||
    value != ACE)
    {
        TEST_FAILED("Generated invalid value.");
    }

    value = Card::get_random_value();

    if (value != TWO || value != THREE || value != FOUR || value != FIVE ||
    value != SIX || value != SEVEN || value != EIGHT || value != NINE ||
    value != TEN || value != JACK || value != QUEEN || value != KING ||
    value != ACE)
    {
        TEST_FAILED("Generated invalid value.");
    }
}

void card_string_test(void)
{
    Card testcard = Card(Suit::SPADE, Value::ACE);

    if (testcard.toString() != "ACE SPADES")
    {
        TEST_FAILED("String should be 'ACE SPADES'.");
    }
}

void card_equaliy_test(void)
{
    Card testcard = Card(Suit::DIAMOND, Value::ACE);
    Card othercard = Card(Suit::DIAMOND, Value::ACE);

    if (testcard != othercard)
    {
        TEST_FAILED("Cards should be equal.");
    }

    othercard.set_suit(SPADE);

    if (testcard == othercard)
    {
        TEST_FAILED("Cards should not be equal.");
    }
}