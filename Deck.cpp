#include "Deck.h"

#include <algorithm>
#include <random>
#include <stdexcept>

namespace {
bool sameCard(Card& left, Card& right) {
    return left.getVal() == right.getVal() &&
           left.getType() == right.getType();
}
}

Deck::Deck() {
    for (int value = 1; value <= 128; ++value) {
        addCard(Card(value, "displacement"));
    }
    for (int value = 1; value <= 64; ++value) {
        addCard(Card(value, "velocity"));
    }
    for (int value = 1; value <= 32; ++value) {
        addCard(Card(value, "acceleration"));
    }
    for (int value = 1; value <= 16; ++value) {
        addCard(Card(value, "jerk"));
    }
    for (int value = 1; value <= 8; ++value) {
        addCard(Card(value, "snap"));
    }
    for (int value = 1; value <= 4; ++value) {
        addCard(Card(value, "crackle"));
    }
    for (int value = 1; value <= 2; ++value) {
        addCard(Card(value, "pop"));
    }
    for (int value = 1; value <= 16; ++value){
        addCard(Card(value,"draw"));
    }
    shuffle();
}

void Deck::shuffle() {
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::shuffle(m_Deck.begin(), m_Deck.end(), generator);
}

void Deck::addCard(Card card) {
    m_Deck.push_back(card);
}

void Deck::removeCard(Card card) {
    for (auto it = m_Deck.begin(); it != m_Deck.end(); ++it) {
        if (sameCard(*it, card)) {
            m_Deck.erase(it);
            return;
        }
    }
    throw std::out_of_range("card is not in the deck");
}

std::vector<Card> Deck::discard(int amount) {
    if (amount < 0) {
        throw std::invalid_argument("discard amount cannot be negative");
    }
    if (static_cast<std::size_t>(amount) > m_Hand.size()) {
        throw std::out_of_range("discard amount exceeds hand size");
    }

    std::vector<Card> discarded(m_Hand.begin(), m_Hand.begin() + amount);
    m_Discard.insert(m_Discard.end(), discarded.begin(), discarded.end());
    m_Hand.erase(m_Hand.begin(), m_Hand.begin() + amount);
    return discarded;
}

std::vector<Card> Deck::draw(int amount) {
    if (amount < 0) {
        throw std::invalid_argument("draw amount cannot be negative");
    }
    if (static_cast<std::size_t>(amount) > m_Deck.size()) {
        throw std::out_of_range("draw amount exceeds deck size");
    }

    std::vector<Card> drawn(m_Deck.begin(), m_Deck.begin() + amount);
    m_Hand.insert(m_Hand.end(), drawn.begin(), drawn.end());
    m_Deck.erase(m_Deck.begin(), m_Deck.begin() + amount);
    return drawn;
}

Card Deck::playCard(Card card) {
    for (auto it = m_Hand.begin(); it != m_Hand.end(); ++it) {
        if (sameCard(*it, card)) {
            Card playedCard = *it;
            m_Hand.erase(it);
            m_Discard.push_back(playedCard);
            return playedCard;
        }
    }
    throw std::out_of_range("card is not in the hand");
}

std::vector<Card> Deck::checkHand() {
    return m_Hand;
}
