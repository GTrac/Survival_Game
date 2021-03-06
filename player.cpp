#include "player.h"

Player::Player(  int health,   int hunger,   int thirst,
          int x,   int y){
    this->health = health;
    this->hunger = hunger;
    this->thirst = thirst;
    this->x = x;
    this->y = y;
}

  int Player::getX() const{
    return x;
}

  int Player::getY() const{
    return y;
}

void Player::setX(  int newX){
    if(newX>19){
        x = 0;
    }else if(newX<0){
        x = 19;
    }else{
        x = newX;  
    }
    
}

void Player::setY(  int newY){
    if(newY>19){
        y = 0;
    }else if(newY<0){
        y = 19;
    }else{
        y = newY;  
    }
}

  int Player::getHunger() const{
    return hunger;
}

  int Player::getThirst() const{
    return thirst;
}

  int Player::getHealth() const{
    return health;
}

void Player::setThirst(  int t){
    thirst = t;
}

void Player::setHunger(  int h){
    hunger = h;
}

void Player::setHealth(  int h){
    health = h;
}

void Player::newTurn(){
    hunger--;
    if(hunger < 0) hunger = 0;
    thirst--;
    if(thirst < 0) thirst = 0;
    
    if(hunger == 0 || thirst == 0){
        health--;
    }
}

void Player::checkCon(){
    if(hunger < 0) hunger = 0;
    if(thirst < 0) thirst = 0;
    if(health < 0) health = 0;
}

string Player::printStats(){
    ostringstream ss;
    ss << "health: " << health << " ";
    ss << "hunger: " << hunger << " ";
    ss << "thirst: " << thirst;
    return ss.str();
}

bool Player::isAlive() const{
    return health > 0;
}