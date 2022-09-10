#include "Hand.h"

Hand::Hand()
{
    this->hand.clear();
}

void Hand::add_card(Card c)
{
    this->hand.push_back(c);
}

int Hand::get_hand_size()
{
    return this->hand.size();
}

Card Hand::get_card(int i)
{
    return this->hand.at(i);
}

std::string Hand::show_hand()
{
    std::string handString;

    for (int i=0;i<this->hand.size();i++)
    {
        handString += this->hand.at(i).toString() + ",";
    }

    return handString.substr(0, handString.length()-2);
}

std::vector<int> Hand::get_numerical_value()
{
    std::vector<int> sums;
    std::vector<Card> sub_hand = get_list_without_aces();
    int sub_hand_sum = get_sum_of_card_values(sub_hand);

    find_ace_sums();

    for (int i=0;i < this->aceSums.size();i++)
    {
        sums.push_back(this->aceSums.at(i) + sub_hand_sum);
    }

    return sums;
}

int Hand::get_sum_of_card_values(std::vector<Card> cards)
{
    int sum = 0;

    for (int i=0;i<cards.size();i++)
    {
        sum += cards.at(i).get_numerical_value().at(0);
    }
    return sum;
}

std::vector<Card> Hand::get_list_without_aces()
{
    std::vector<Card> without_aces;

    for (int i=0;i<this->hand.size();i++)
    {
        if (this->hand.at(i).get_value() != Value::ACE)
        {
            without_aces.push_back(this->hand.at(i));
        }
    }
    return without_aces;
}

void Hand::find_ace_sums()
{
    this->aceSums.clear();
    int aces = get_number_of_aces();
    int sum_to_store;

    for (int i=0;i<aces + 1;i++)
    {
        sum_to_store = 0;

        sum_to_store += (aces-i) * HIGH_ACE_VALUE;
        sum_to_store += i * LOW_ACE_VALUE;

        this->aceSums.push_back(sum_to_store);
    }
}

int Hand::get_number_of_aces()
{
    int count = 0;

    for (int i=0;i<this->hand.size();i++)
    {
        if (this->hand.at(i).get_value() == Value::ACE)
        {
            count++;
        }
    }
    return count;
}