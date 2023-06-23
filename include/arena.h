/* @Author
* Student Name: İbrahim Taha Tüzgen
* Student ID : 150210717
*/
#pragma once
#include "./electricPokemon.h"
#include "./psychicPokemon.h"

class Arena{
    public:
        Arena();
        ~Arena();
    
    private:
        ElectricPokemon* fightingElectricPokemon;
        PsychicPokemon* fightingPsychicPokemon;
    
    public:
        ElectricPokemon* getFightingElectricPokemon() const;
        PsychicPokemon* getFightingPsychicPokemon() const;

        void addPokemon(char, std::string, int, int);

    private:
        terrainTypes terrainType;
        int arenaTypeCD;
    
    public:
        const terrainTypes getTerrainType() const;
        void setTerrainType(terrainTypes);

        const int getArenaTypeCD() const;
        void setArenaTypeCD(int);

        void spawnTerrain();
        void restartTerrain();

        void simulateBattle();

        void printRoundStats(int, int) const;
        void printMatchResults() const;

    private:
        int roundNumber;
    
    public:
        const int getRoundNumber() const;
        void setRoundNumber(int);

        void nextRound();
};