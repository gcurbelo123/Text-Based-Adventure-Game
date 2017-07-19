#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

//**********************************
//Class Name:
//
//Description:
//
//**********************************
#include <fstream>
#include "character.h"
class Enemy
{
    public:
        Enemy();
        void newEnemy(Character& c);
        void combat(Character& c);
        int getHealth();
        int getDamage();
        string getEnemy();

    private:
        int health;
        int damage;
        string dropsOne[3] = {"Stick", "Rock", "Leaf"};
        string dropsTwo[4] = {"Stick", "Rock", "Wood Sword", "Minor Health Potion"};
        string dropsThree[4] = {"Rock", "Steel Sword", "Regular Health Potion", "Wood Shield"};
        string monstersOne[2] = {"Slime", "Rat"};
        string monstersTwo[8] = {"Goblin", "Goblin", "Goblin", "Orc", "Orc", "Orc", "Zombie", "Zombie"};
        string monstersThree[8] = {"Wizard", "Wizard", "Skeleton", "Skeleton", "Skeleton", "Werewolf", "Werewolf", "Werewolf"};
        string monster;
};

#endif // ENEMY_H_INCLUDED
