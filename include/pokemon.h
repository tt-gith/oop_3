/* @Author
* Student Name: İbrahim Taha Tüzgen
* Student ID : 150210717
*/
#pragma once
#include <iostream>

enum terrainTypes{
    Psychic, Electric, None
};

class Pokemon{
    public:
        Pokemon(std::string, int, int, int, float, terrainTypes);
        ~Pokemon();

    private:
        const std::string name;
        int HP;
        int damage;
        const int recharge; 
        const float powerUpChance; 
        const terrainTypes terrain;

    public:
        const std::string getName() const;
        // there is no setters for the constant variables.
        
        int getHP() const;
        void setHP(int);

        int getDamage() const;
        void setDamage(int);

        const float getPowerUpChance() const;

        const int getRecharge() const;

        const terrainTypes getTerrain() const;

    private:
        bool isFainted;
        bool isPowerUp;
        bool isOnOwnTerrain;

    public:
        bool getIsFainted() const;
        void setIsFainted(bool);

        bool getIsPowerUp() const;
        void setIsPowerUp(bool);

        bool getIsOwnTerrain() const;
        void setIsOwnTerrain(bool);


    private:
        int remainingPowerUpCooldown;
        
    public:
        const int getRemainingPowerUpCooldown() const;
        void setRemainingPowerUpCooldown(int);

        void hit(Pokemon&, int); // Pokemon to be hit, and an integer value for damage.
};
