#include <Card.h>
Card::Card(){
    m_value = 1;
    m_type = "displacement";

};
Card::Card(int value, std::string type){
    m_value = value;
    m_type = type;
};
int Card::getVal(){
    return m_value;

};
std::string Card::getType(){
    return m_type;

};