#include <iostream>
#include "game.h"
std::string getString( GameData& game_data, const std::string& prompt )
{
    game_data.getOS() << prompt;
    std::string input;
    game_data.getIS() >> input;
    return input;
};
int getInteger( GameData& game_data, const std::string& prompt )
{
    game_data.getOS() << prompt;
    int input;
    game_data.getIS() >> input;
    return input;
};
double getDouble( GameData& game_data, const std::string& prompt )
{
    game_data.getOS() << prompt;
    double input;
    game_data.getIS() >> input;
    return input;
};



std::string getChoice( GameData& game_data ){
    return getString(game_data, "Choice? ");
}; //Uses getString to ask the user for a string, using “Choice? ” as the prompt. Returns the value returned by getString().
