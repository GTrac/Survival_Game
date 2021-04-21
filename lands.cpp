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
        case CAVE:
            return new Cave;
            break;
        case TOWER:
            return new Tower;
            break;
        case FIELD:
            return new Field;
            break;
        case SWAMP:
            return new Swamp;
            break;
        case MOUNTAIN:
            return new Mountain;
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
string Cave::getShortDescription(){
    return "cave";
}

string Cave::getLongDescription(){
    return "You enter into small crack in a hill. When you get inside you see a larger space underground with some mushrooms growing in the corner.";
}

string Cave::visit(Player& p){
    
   int chance = rand() % 100;
    string description;
    
    // Chance to find a good mushroom
    if(chance >= 90){
        description = "You eat a mushroom, greatly replenishing your hunger!";
        p.setHunger(p.getHunger() + 2);
        return description;
    }
    
    //chance to find an ok mushroom
     if(chance < 90 && chance >= 40){
        description = "You eat a mushroom, replenishing your hunger!";
        p.setHealth(p.getHealth() + 1);
    }
    
    // Chance to get mauled by bear
    if(chance < 40 && chance >= 10){
        description = "You eat a mushroom, then become violently ill!";
        p.setHunger(p.getHunger() - 2);
    }
    
    // Chance to get super poisoned
    if(chance < 10){
        description = "you eat a mushroom and and pass out. You feel weak when you awaken.";
        int newHealth = (int)p.getHealth() - 2;
        newHealth = newHealth < 0 ? 0 : newHealth;
        p.setHealth(newHealth);
    }
    return description;
}



string Tower::getShortDescription(){
    return "tower";
}

string Tower::getLongDescription(){
    return "You arrive before a strange black tower towering over the land. The door opens before you and you see light within.";
}

string Tower::visit(Player& p){
    string description ;
    int chance = rand() % 25;
    
    //chance does nothing vs get teleported somewhere random
    if(chance != 1){
        description = "The inside of the tower is lit by a strange floating sphere. As you approach it the sphere vanishes.";
        
    }else{
        description = "The inside of the tower is lit by a strange floating sphere. As you approach it the sphere flashes a blinding light and you when you open your eyes you realize you are somewhere else.";
        p.setX(rand()%20);
        p.setY(rand()%20);
    }

    return description;
}

string Field::getShortDescription(){
    return "field";
}

string Field::getLongDescription(){
    return "You arrive at a large open field";
}


string Field::visit(Player& p){
    string description ;
    int chance = rand() % 300;
    
    //chance does nothing vs get teleported somewhere random
    if(chance >= 200){
        description = "You find a patch of wild carrots.";
        p.setHunger(p.getHunger() + 1);
    }else if(chance >= 100){
        description = "You find a small stream to drink from.";
        p.setThirst(p.getThirst()+ 1);
    }else if(chance >= 1){
        description = "You find patch of wild echinacea and use it to heal your wounds.";
        p.setHealth(p.getHealth()+ 1);
    }else{
        description = "A massive flying saucer appears above your head. The last thing you see is a bright light shine down on you.";
        p.setHealth(0); 
    }

    return description;
}

string Swamp::getShortDescription(){
    return "swamp";
}

string Swamp::getLongDescription(){
    return "You see a marshland infront of you. There is plenty of teaming plantlife but all the water you see is stagnant.";
}

string Swamp::visit(Player& p){
    string description;
    int chance = rand() % 10;
    if(chance==3){
        description = "You find a crazy witch-doctor in the swamp, he casts a spell to return you to when you first awoke.";
        p.setHealth(5);
    }else{
        description = "You are able to find plenty of berry bushes in the swamp and are able to eat your fill, but all the muck has made you thirsty.";
        p.setHunger(p.getHunger() + 3);
        p.setThirst(p.getThirst() - 1);
    }
    return description;
}

string Mountain::getShortDescription(){
    return "mountain";
}

string Mountain::getLongDescription(){
    return "You see a tall Mountain rising into the sky infront of you";
}

string Mountain::visit(Player& p){\
    string description = "You find a clear mountain stream.";
    p.setHunger(p.getHunger() - 1);
    p.setThirst(p.getThirst() + 3);
    int chance = rand() % 10;
    if(chance <= 3){
        description = "You get attacked by an eagle.";
        p.setHealth(p.getHealth() - 1);
    }
    
    return description;
}
