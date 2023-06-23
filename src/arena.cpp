/* @Author
 * Student Name: İbrahim Taha Tüzgen
 * Student ID : 150210717
 */

#include "../include/arena.h"

Arena::Arena()
{
}

Arena::~Arena()
{
}

ElectricPokemon *Arena::getFightingElectricPokemon() const
{
    return this->fightingElectricPokemon;
}

PsychicPokemon *Arena::getFightingPsychicPokemon() const
{
    return this->fightingPsychicPokemon;
}

void Arena::addPokemon(char type, std::string name, int hp, int damage)
{
    if (type == 'p')
    {
        PsychicPokemon *psychicPokemon = new PsychicPokemon(name, hp, damage);
        this->fightingPsychicPokemon = psychicPokemon;
        std::cout << "Psychic Pokemon " + name + " has entered the arena." << std::endl;
        std::cout << "Class: Psychic" << std::endl;
    }
    else if (type == 'e')
    {
        
        this->fightingElectricPokemon = new ElectricPokemon(name, hp, damage);
        std::cout << "Electric Pokemon " + name + " has entered the arena." << std::endl;
        std::cout << "Class: Electric" << std::endl;
    }
    else
    {
        std::cout << "Undefined pokemon type" << std::endl;
    }
    std::cout << '\t' << "Name: " << name << std::endl;
    std::cout << '\t' << "HP: " << hp << std::endl;
    std::cout << '\t' << "Damage: " << damage << std::endl;
    std::cout << '\n' << std::endl;
}

const terrainTypes Arena::getTerrainType() const
{
    return this->terrainType;
}

void Arena::setTerrainType(terrainTypes terrainType)
{
    this->terrainType = terrainType;
}

const int Arena::getArenaTypeCD() const
{
    return this->arenaTypeCD;
}

void Arena::setArenaTypeCD(int newCD)
{
    this->arenaTypeCD = newCD;
}

void Arena::spawnTerrain()
{
    int randomizedNumber = rand() % 10;

    if (randomizedNumber < 2)
    {
        setTerrainType(terrainTypes::Electric);
        this->fightingElectricPokemon->setIsOwnTerrain(true);
        this->fightingPsychicPokemon->setIsOwnTerrain(false);
        arenaTypeCD = 5;
    }
    else if (randomizedNumber < 4)
    {
        setTerrainType(terrainTypes::Psychic);
        this->fightingElectricPokemon->setIsOwnTerrain(false);
        this->fightingPsychicPokemon->setIsOwnTerrain(true);
        arenaTypeCD = 5;
    }
    else
    {
        setTerrainType(terrainTypes::None);
        this->fightingElectricPokemon->setIsOwnTerrain(false);
        this->fightingPsychicPokemon->setIsOwnTerrain(false);
        arenaTypeCD = 1;
    }
}

void Arena::restartTerrain()
{
    setRoundNumber(1);
    spawnTerrain();
}

void Arena::simulateBattle()
{
    bool isElectricPowerUp, isPsychicPowerUp;
    bool firstSelector;
    restartTerrain();
    while (!this->fightingElectricPokemon->getIsFainted() && !this->fightingPsychicPokemon->getIsFainted())
    {
        isElectricPowerUp = rand() % 100 < fightingElectricPokemon->getPowerUpChance() && fightingElectricPokemon->getRemainingPowerUpCooldown() == 0;
        isPsychicPowerUp = rand() % 100 < fightingPsychicPokemon->getPowerUpChance() && fightingPsychicPokemon->getRemainingPowerUpCooldown() == 0;
        firstSelector = rand() % 2; // if first selector is 0 electric goes first, else psychic goes first.

        if (arenaTypeCD == 0)
            spawnTerrain();

        if (firstSelector)
        {
            if (isPsychicPowerUp)
            {
                if (!fightingElectricPokemon->getIsOwnTerrain())
                {
                    fightingPsychicPokemon->powerUp(*fightingElectricPokemon);
                    fightingElectricPokemon->setRemainingConfusedRound(3);
                }
                fightingPsychicPokemon->setRemainingPowerUpCooldown(fightingPsychicPokemon->getRecharge());
            }
            fightingPsychicPokemon->hit(*fightingElectricPokemon, fightingPsychicPokemon->getDamage());
            if (fightingPsychicPokemon->getIsOwnTerrain())
                fightingPsychicPokemon->hit(*fightingElectricPokemon, fightingPsychicPokemon->getDamage());
            if (fightingElectricPokemon->getIsFainted())
            {
                printRoundStats(getRoundNumber(), firstSelector);
                break;
            }
            if (isElectricPowerUp)
            {
                fightingElectricPokemon->powerUp();
                fightingElectricPokemon->setRemainingPowerUpCooldown(fightingElectricPokemon->getRecharge());
            }
            if (!fightingElectricPokemon->getIsConfused())
                fightingElectricPokemon->hit(*fightingPsychicPokemon, fightingElectricPokemon->getDamage());
            else
            {
                if (fightingElectricPokemon->getRemainingConfusedRound() > 0)
                    fightingElectricPokemon->setRemainingConfusedRound(fightingElectricPokemon->getRemainingConfusedRound() - 1);
            }
        }
        else
        {
            if (isElectricPowerUp)
            {
                fightingElectricPokemon->powerUp();
                fightingElectricPokemon->setRemainingPowerUpCooldown(fightingElectricPokemon->getRecharge());
            }
            if (!fightingElectricPokemon->getIsConfused())
                fightingElectricPokemon->hit(*fightingPsychicPokemon, fightingElectricPokemon->getDamage());
            else
            {
                if (fightingElectricPokemon->getRemainingConfusedRound() > 0)
                    fightingElectricPokemon->setRemainingConfusedRound(fightingElectricPokemon->getRemainingConfusedRound() - 1);
            }
            if (fightingPsychicPokemon->getIsFainted())
            {
                printRoundStats(getRoundNumber(), firstSelector);
                break;
            }
            if (isPsychicPowerUp)
            {
                if (!fightingElectricPokemon->getIsOwnTerrain())
                {
                    fightingPsychicPokemon->powerUp(*fightingElectricPokemon);
                    fightingElectricPokemon->setRemainingConfusedRound(3);
                }
                fightingPsychicPokemon->setRemainingPowerUpCooldown(fightingPsychicPokemon->getRecharge());
            }
            fightingPsychicPokemon->hit(*fightingElectricPokemon, fightingPsychicPokemon->getDamage());
        }
        printRoundStats(getRoundNumber(), firstSelector);
        nextRound();
    }
    printMatchResults();
    delete fightingElectricPokemon;
    delete fightingPsychicPokemon;
}

void Arena::printRoundStats(int round, int firstHit) const
{
    std::cout << "Round: ";
    std::cout << round << std::endl;
    std::cout << "Current Terrain: ";
    switch (this->getTerrainType())
    {
    case terrainTypes::Electric : std::cout << "Electric" << std::endl;
        break;
    case terrainTypes::Psychic : std::cout << "Psychic" << std::endl;
        break;
    case terrainTypes::None : std::cout << "None" << std::endl;
    
    default:
        break;
    }
    if (firstHit == 0)
        std::cout << this->fightingElectricPokemon->getName() + " goes first." << std::endl;
    else
        std::cout << this->fightingPsychicPokemon->getName() + " goes first." << std::endl;
    if (this->fightingElectricPokemon->getIsPowerUp())
        std::cout << this->fightingElectricPokemon->getName() + " has initiated a power up." << std::endl;
    if (this->fightingPsychicPokemon->getIsPowerUp())
        std::cout << this->fightingPsychicPokemon->getName() + " has initiated a power up." << std::endl;
    std::cout << this->fightingElectricPokemon->getName() << +" HP: " << this->fightingElectricPokemon->getHP() << std::endl;
    std::cout << this->fightingPsychicPokemon->getName() << +" HP: " << this->fightingPsychicPokemon->getHP() << std::endl;

    if (this->fightingElectricPokemon->getHP() > this->fightingPsychicPokemon->getHP())
        std::cout << this->fightingElectricPokemon->getName() << +" is in the lead!" << '\n'
                  << '\n'
                  << std::endl;
    else
        std::cout << this->fightingPsychicPokemon->getName() << +" is in the lead!" << '\n'
                  << '\n'
                  << std::endl;
}

void Arena::printMatchResults() const
{
    std::cout << "Match Results:" << std::endl;
    if (this->fightingElectricPokemon->getIsFainted())
        std::cout << this->fightingPsychicPokemon->getName() << +" has won the match." << std::endl
                  << std::endl
                  << std::endl;
    else
        std::cout << this->fightingElectricPokemon->getName() << +" has won the match." << std::endl
                  << std::endl
                  << std::endl;
}

const int Arena::getRoundNumber() const
{
    return this->roundNumber;
}

void Arena::setRoundNumber(int roundNumber)
{
    this->roundNumber = roundNumber;
}

void Arena::nextRound()
{
    if (fightingElectricPokemon->getRemainingConfusedRound() == 0)
        fightingElectricPokemon->setIsConfused(false);
    if (fightingPsychicPokemon->getRemainingPowerUpCooldown() > 0)
        fightingPsychicPokemon->setRemainingPowerUpCooldown(fightingPsychicPokemon->getRemainingPowerUpCooldown() - 1);
    if (fightingElectricPokemon->getIsPowerUp())
        fightingElectricPokemon->powerDown();
    if(fightingPsychicPokemon->getIsPowerUp())
        fightingPsychicPokemon->setIsPowerUp(false);
    if (arenaTypeCD > 0)
        arenaTypeCD--;

    this->roundNumber++;
}