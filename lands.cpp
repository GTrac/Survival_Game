#include "lands.h"

using namespace std;

Land* getRandomLand(){
    LandTypes selection = (LandTypes)(rand() % MAX_NUM_LANDS);
    
    switch(selection){
        case LAKE:
            return new Lake;
            break;
        case FOREST:
            return new Forest;
            break;
        case DESERT:
            return new Desert;
            break;
        default:
            return new Lake;
            break;
    }
    
}

string Lake::getShortDescription(){
    return "lake";
}

string Lake::getLongDescription(){
    return "You arrive at a large lake filled with clear sparkling water.";
}

string Lake::visit(Player& p){
    string description = "You drink from the lake, replenishing your thirst";
    p.setThirst(Player::DEFAULT_THIRST);
    return description;
}

string Forest::getShortDescription(){
    
    return "forest";
}

string Forest::getLongDescription(){
    return "You arrive in dense forest filled with trees and foliage.";
}

string Forest::visit(Player& p){
    string description = "You forage for berries but find nothing.";
    
    int chance = rand() % 100;
    
    // Chance to find berries
    if(chance > 50){
        description = "You foraged for berries in the forest and found some!";
        p.setHunger(p.getHunger() + 1);
        return description;
    }
    
    // Chance to get mauled by bear
    if(chance < 10 && chance > 5){
        description = "You are attacked by a hungry bear in the woods!";
        p.setHealth(p.getHealth() - 1);
    }
    
    // Chance to get double mauled
    if(chance < 5){
        description = "You are attacked by two very large bears!";
        int newHealth = (int)p.getHealth() - 2;
        newHealth = newHealth < 0 ? 0 : newHealth;
        p.setHealth(newHealth);
    }
    
    
    return description;
}

string Desert::getShortDescription(){
    
    return "desert";
}

string Desert::getLongDescription(){
    return "You arrive in a extremely hot, dry desert";
}

string Desert::visit(Player& p){
    string description = "The heat of the desert makes you dehydrated.";
    
    p.setThirst(p.getThirst() - 1);

    return description;
}