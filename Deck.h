#include "Card.h"
#include <vector>
#include <math.h>
#include <random>
#pragma once


class Deck{
private:
    std::vector<Card> m_Deck;
    std::vector<Card> m_Hand;
    std::vector<Card> m_Discard;
public:
    Deck();
    void shuffle();
    void addCard(Card card);
    void removeCard(Card card);
    std::vector<Card> discard(int amount);
    std::vector<Card> draw(int amount);
    Card playCard(Card card);
    std::vector<Card> checkHand();
    
};