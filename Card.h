#pragma once
#include <string>

// a class that contains 2 main things the card type and the value of the card and functions to obtian that information.
class Card {
private:
    int m_value;
    std::string m_type;
public:
    Card();
    Card(int value, std::string type);
    int getVal();
    std::string getType();
};