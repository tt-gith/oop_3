/* @Author
* Student Name: İbrahim Taha Tüzgen
* Student ID : 150210717
*/
#pragma once
#include "./pokemon.h"

class ElectricPokemon: public Pokemon {
    public:
        ElectricPokemon(std::string, int, int);
        ~ElectricPokemon();

    private:
        bool isConfused;
        int remainingConfusedRound;

    public:
        const bool getIsConfused() const;
        void setIsConfused(const bool);

        const int getRemainingConfusedRound() const;
        void setRemainingConfusedRound(int);

        void powerUp();
        void powerDown();
};