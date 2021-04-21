#include <iostream>
#include <algorithm>
#include "lands.h"
#include "player.h"

using namespace std;

enum PlayerChoice {NORTH, SOUTH, EAST, WEST};

void clearTerminal(){
    for(int i = 0; i < 100; i++){
        cout << endl;
    }
}

bool getPlayerInput(PlayerChoice &playerChoice){
    // 0 = North, 1 = South, 2 = East, 3 = West
    string input;
    cout << "Which direction will you go?" << endl;
    cout << "Enter N, S, E, or W" << endl;
    cin >> input;
    
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    
    
    if(input == "n"){
        playerChoice = NORTH;
    } else if(input == "s"){
        playerChoice = SOUTH;
    } else if(input == "e"){
        playerChoice = EAST;
    } else if(input == "w"){
        playerChoice = WEST;
    } else {
        cout << "Invalid input. " << endl;
        return false;
    }
    
    return true;
}


int main(){
    const   int MAP_SIZE = 20;
    Player player(Player::DEFAULT_HEALTH, 
                  Player::DEFAULT_HUNGER, 
                  Player::DEFAULT_THIRST, 
                  MAP_SIZE/2, MAP_SIZE/2);
    
    //Build Map
    srand(time(NULL));
    Land* map[MAP_SIZE][MAP_SIZE];
    for(int i = 0; i < MAP_SIZE; i++){
        for(int j = 0; j < MAP_SIZE; j++){
            map[i][j] = getRandomLand();
        }
    }
    
    cout << "You wake up in a " << 
        map[player.getX()][player.getY()]->getShortDescription() <<
        " with no memory of how you got there." << endl;
        
    while(player.isAlive()){
        clearTerminal();
        player.newTurn();
        
        // Give description of surroundings
          int x = player.getX();
          int y = player.getY();
        
        cout << map[x][y]->getLongDescription() << endl << endl;
        cout << map[x][y]->visit(player) << endl << endl;
        player.checkCon();
        if(!player.isAlive()){
            if(player.getHunger()==0){
                cout << "You Starved to death! Better luck next time!"<<endl;
            }else if(player.getThirst()==0){
                cout << "You died of dehydration! Better luck next time!"<<endl;
            }else{
                cout << "You were killed! Better luck next time!"<<endl;
            }
            
            return 0;
        }
        cout << player.printStats() << endl << endl;
        
        //north Look
        if(y==19){
            cout << "To the north you see a " << map[x][0]->getShortDescription() << endl;
        }else{
            cout << "To the north you see a " << map[x][y + 1]->getShortDescription() << endl;  
        }
        //south look
        if(y==0){
            cout << "To the south you see a " << map[x][19]->getShortDescription() << endl;
        }else{
            cout << "To the south you see a " << map[x][y - 1]->getShortDescription() << endl;
        }
        //east look
        if(x==19){
            cout << "To the east you see a " << map[0][y]->getShortDescription() << endl;
        }else{
           cout << "To the east you see a " << map[x + 1][y]->getShortDescription() << endl; 
        }
        //west look
    
        if(x==0){
            cout << "To the west you see a " << map[19][y]->getShortDescription() << endl;  
        }else{
           cout << "To the west you see a " << map[x - 1][y]->getShortDescription() << endl; 
        }
        
        PlayerChoice playerChoice;
        while(!getPlayerInput(playerChoice));
        
        switch(playerChoice){
            case NORTH:
                player.setY(player.getY() + 1);
                break;
            case SOUTH:
                player.setY(player.getY() - 1);
                break;
            case EAST:
                player.setX(player.getX() + 1);
                break;
            case WEST:
                player.setX(player.getX() - 1);
                break;
            default:
                cout << "Invalid input found: " << playerChoice << endl;
                break;
        }

    }
    
    return 0;
}