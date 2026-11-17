#include "GameData.h"

std::string getString( GameData& game_data, const std::string& prompt );
int getInteger( GameData& game_data, const std::string& prompt );
double getDouble( GameData& game_data, const std::string& prompt );
std::string getChoice( GameData& game_data ); 
bool gameLoop();