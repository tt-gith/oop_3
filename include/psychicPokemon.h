/* @Author
* Student Name: İbrahim Taha Tüzgen
* Student ID : 150210717
*/
#pragma once
#include "./pokemon.h"
#include "./electricPokemon.h"


class PsychicPokemon: public Pokemon {
    public:
        PsychicPokemon(std::string, int, int);
        ~PsychicPokemon();

        void powerUp(ElectricPokemon&);
};