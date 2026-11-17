#include "GameData.h"

#include <sstream>
#include <stdexcept>
#include <string>

GameData::GameData(std::istream& is, std::ostream& os):
    m_input(is),
    m_output(os),
    m_quit(false),
    m_Displacement(0),
    m_Velocity(0),
    m_Acceleration(0),
    m_Jerk(0),
    m_Snap(0),
    m_Crackle(0),
    m_Pop(0)
{};

std::istream& GameData::getIS(){
    return m_input;
};
std::ostream& GameData::getOS(){
    return m_output;
};
int GameData::getDisplacement() const{
    return m_Displacement;
};
int GameData::getVelocity() const{
    return m_Velocity;
};
int GameData::getAcceleration() const{
    return m_Acceleration;
};
int GameData::getJerk() const{
    return m_Jerk;
};
int GameData::getSnap() const{
    return m_Snap;
};
int GameData::getCrackle() const{
    return m_Crackle;
};
int GameData::getPop() const{
    return m_Pop;
};
std::vector<Card> GameData::drawCards(int amount){
    return m_deck.draw(amount);
};
std::vector<Card> GameData::getHand(){
    return m_deck.checkHand();

};
Card GameData::playCard(Card card){
    return m_deck.playCard(card);
};

void GameData::cardAbility(Card card) {
    const std::string type = card.getType();
    const int value = card.getVal();
    if (type == "displacement") {
        m_Displacement += value;
    } else if (type == "velocity") {
        m_Velocity += value;
    } else if (type == "acceleration") {
        m_Acceleration += value;
    } else if (type == "jerk") {
        m_Jerk += value;
    } else if (type == "snap") {
        m_Snap += value;
    } else if (type == "crackle") {
        m_Crackle += value;
    } else if (type == "pop") {
        m_Pop += value;
    } else if (type == "draw") {
        m_deck.draw(value);
    } else {
        throw std::invalid_argument("Unsupported card type: " + type);
    }
}
void GameData::move(){
    m_Crackle += m_Pop;
    m_Snap += m_Crackle;
    m_Jerk += m_Snap;
    m_Acceleration += m_Jerk;
    m_Velocity += m_Acceleration;
    m_Displacement += m_Velocity;
};
std::string GameData::getStats() const{
    std::ostringstream stats;
    stats << "Displacement: " << m_Displacement << '\n'
          << "Velocity: " << m_Velocity << '\n'
          << "Acceleration: " << m_Acceleration << '\n'
          << "Jerk: " << m_Jerk << '\n'
          << "Snap: " << m_Snap << '\n'
          << "Crackle: " << m_Crackle << '\n'
          << "Pop: " << m_Pop << '\n';
    return stats.str();
};
