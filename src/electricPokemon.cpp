/* @Author
* Student Name: İbrahim Taha Tüzgen
* Student ID : 150210717
*/
#include "../include/electricPokemon.h"

ElectricPokemon::ElectricPokemon(std::string name, int fullHP, int regularDamage):Pokemon::Pokemon{name,fullHP,regularDamage,3,20,terrainTypes::Electric} {

}

ElectricPokemon::~ElectricPokemon(){}

const bool ElectricPokemon::getIsConfused()const{
    return this->isConfused;
}

void ElectricPokemon::setIsConfused(const bool isConfused){
    this->isConfused = isConfused;
}

const int ElectricPokemon::getRemainingConfusedRound()const{
    return this->remainingConfusedRound;
}

void ElectricPokemon::setRemainingConfusedRound(int remainingConfusedRound){
    this->remainingConfusedRound = remainingConfusedRound;
}

void ElectricPokemon::powerUp(){
    this->setDamage(this->getDamage()*3);
    this->setIsPowerUp(true);
}

void ElectricPokemon::powerDown(){
    this->setDamage(this->getDamage()/3);
    this->setIsPowerUp(false);
}