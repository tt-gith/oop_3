/* @Author
* Student Name: İbrahim Taha Tüzgen
* Student ID : 150210717
*/
#include "../include/pokemon.h"

Pokemon::Pokemon(std::string name, int fullHP, int regularDamage, int recharge, float powerUpChance, terrainTypes terrain):name{name}, HP{fullHP}, damage{regularDamage},recharge{recharge},powerUpChance{powerUpChance}, terrain{terrain} {
    this->isFainted = false;
    this->isOnOwnTerrain = false;
    this->isPowerUp = false;
    this->remainingPowerUpCooldown = 0;
}

Pokemon::~Pokemon(){

}
    // getters
const std::string Pokemon::getName() const{
    return this->name;
}

int Pokemon::getDamage() const{
    return this->damage;
}

int Pokemon::getHP() const{
    return this->HP;
}

const int Pokemon::getRecharge() const{
    return this->recharge;
}

const float Pokemon::getPowerUpChance() const{
    return this->powerUpChance;
}

const terrainTypes Pokemon::getTerrain() const{
    return this->terrain;
}

bool Pokemon::getIsFainted() const {
    return this->isFainted;
}

bool Pokemon::getIsPowerUp() const {
    return this->isPowerUp;
}

bool Pokemon::getIsOwnTerrain() const {
    return this->isOnOwnTerrain;
}

const int Pokemon::getRemainingPowerUpCooldown() const{
    return this->remainingPowerUpCooldown;
}

    //setters

void Pokemon::setHP(int HP){
    this->HP = HP;
}

void Pokemon::setDamage(int damage){
    this->damage = damage;
}

void Pokemon::setIsFainted(bool isFainted){
    this->isFainted = isFainted;
}

void Pokemon::setIsPowerUp(bool isPowerUp){
    this->isPowerUp = isPowerUp;
}

void Pokemon::setIsOwnTerrain(bool isOwnTerrain){
    this->isOnOwnTerrain = isOnOwnTerrain;
}

void Pokemon::setRemainingPowerUpCooldown(int remainingPUCD){
    this->remainingPowerUpCooldown = remainingPUCD;
}

void Pokemon::hit(Pokemon& hittedPokemon, int hittedDamage){
    hittedPokemon.setHP(hittedPokemon.getHP() - hittedDamage);
    if(hittedPokemon.getHP() <= 0)
    {    
        hittedPokemon.setHP(0);
        hittedPokemon.setIsFainted(true);
    }
}