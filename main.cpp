#include "game.h"

int main(){
    bool endGameState = gameLoop();
    if(endGameState){
        std::cout << "YOU WIN"<< std::endl;
        return 0;
    } else {
        std::cout << "GAME OVER"<< std::endl;
        return 0;
    };
};