/* @Author
* Student Name: İbrahim Taha Tüzgen
* Student ID : 150210717
*/

#include "../include/psychicPokemon.h"
#include "../include/electricPokemon.h"

PsychicPokemon::PsychicPokemon(std::string name, int fullHP, int regularDamage):Pokemon::Pokemon{name,fullHP,regularDamage,5,30,terrainTypes::Psychic} {

}

PsychicPokemon::~PsychicPokemon(){}

void PsychicPokemon::powerUp(ElectricPokemon& affectedPokemon){
    affectedPokemon.setIsConfused(true);
    this->setIsPowerUp(true);
}