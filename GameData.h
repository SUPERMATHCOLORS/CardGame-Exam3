#pragma once
#include <iostream>
#include <string>
#include "Deck.h"
class GameData
{
private:
    std::istream& m_input;
    std::ostream& m_output;
    bool m_quit;
    Deck m_deck;
    int m_Displacement,m_Velocity,m_Acceleration,m_Jerk,m_Snap,m_Crackle,m_Pop;

public:
    GameData(std::istream& is, std::ostream& os); 
    std::istream& getIS(); 
    std::ostream& getOS(); 
    int getDisplacement() const;
    int getVelocity() const;
    int getAcceleration() const;
    int getJerk() const;
    int getSnap() const;
    int getCrackle() const;
    int getPop() const;
    std::vector<Card> drawCards(int amount);
    std::vector<Card> getHand();
    Card playCard(Card card);
    void cardAbility(Card card);
    void move();
    std::string getStats() const;
};
