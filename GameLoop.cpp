#include "game.h"

bool gameLoop(){
    GameData gameData = GameData(std::cin, std::cout);
    gameData.getOS() << "get to 2500 displacement in 10 turns to win" << '\n';
    gameData.drawCards(5);
    for(int i = 0; i < 10;i++){
        gameData.move();
        gameData.getOS() << "Turn " << i + 1 << " of 10\n"
                         << gameData.getStats() << '\n';
        
        //any of the main values alter the value right below it like this Pop->Crackle->Snap->Jerk->Acceleration->Velocity->Displacement (this is done I think at start of turn or end of turn I am not sure yet though)
        //has player draw 1 card at start of turn
        //they can then play 1-3 cards
        //those cards do their effects (each of those main card types previosly mentioned that were tied to a value will directly increase that the other cards like draw and look are somewhat self explanatory)
        gameData.drawCards(1);
        for(int j = 0; j < 3; j++){
            auto hand = gameData.getHand();

            for (std::size_t i = 0; i < hand.size(); ++i) {
                gameData.getOS() << i + 1 << ") "
                    << hand[i].getType() << " "
                    << hand[i].getVal() << '\n';
            };
            int pickedCard = getInteger(gameData, "Pick a card, or enter 0 to end your turn: ");
            while (pickedCard < 0 || pickedCard > static_cast<int>(hand.size())) {
                gameData.getOS() << "Card index not in hand\n";
                pickedCard = getInteger(gameData, "Pick a card, or enter 0 to end your turn: ");
            }

            if (pickedCard == 0) {
                break;
            }
            
            Card cardInHand = hand[pickedCard - 1];
            Card playedCard = gameData.playCard(cardInHand);
            gameData.cardAbility(playedCard);
            hand = gameData.getHand();
            gameData.getOS() << gameData.getStats() << '\n';
            if (hand.empty()) {
                break;
            }
            
        };

    };
    //one final movement
    gameData.move();
    //a final stat check
    gameData.getOS() << "Final stat check" << std::endl;
    gameData.getOS() << gameData.getStats() << '\n';

    if(gameData.getDisplacement()>=2500){
        return true;
    }else{
        return false;
    };
};

// changes after the game is finished that I might make
// maybe make it so that each card has a cost to play (this could also make it so I can remove the max cap on cards played in a turn and add a whole new resource to keep track of)
// add multiple game modes like a multiplayer mode which would add a mode to see who can get to a specfic value first
// make the main 7 card types no longer use a set value and use like a dice roll that has a chance of going horribly wrong (crashing would be the term for that)
// in that previous thing to get that to work replace the value thing in the card with expression which could include expressions (these expressions could have 1-3 different input values (X+Y would have two X! would have one X{Y^}Z (that being the operation thing for up arrow notation for hyperoperations) would have 3)) like XDY (ex:1d4), X+Y, etc and potentially the X or Y could be an expression themselve or an int (any expression that would result in a non whole number would be floored, rounded or ceilinged? is that what that is called?).
// make the discard function let the player pick which cards to discard
// add a settings menu to pick different settings 
// one of those could be when during the turn movement happens if movement happens a few times after the last round but before the game ends
// another could be if the chain of movement Pop->Crackle->Snap->Jerk->Acceleration->Velocity->Displacement does its changes in order from Pop to Displacement(Pop changing Crackle first then Crackle changing pop next etc.) or the other way around (Velocity changing Displacement then Acceleration effecting Velocity etc.)