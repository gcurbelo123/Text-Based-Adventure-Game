//Title: .cpp
//Gilbert Curbelo III
//Date Modified:
//Desc:

#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include "enemy.h"
#include "character.h"

Enemy::Enemy()
{
    int choice;
    choice = (rand() % 2);
    monster = monstersOne[choice];
    if(monster == "Slime"){
        health = 20;
        damage = 3;
    }
    if(monster == "Rat"){
        health = 15;
        damage = 2;
    }
}
void Enemy::newEnemy(Character& c)
{
    int choice;
    if(c.getCharLvl() <= 4){
        choice = (rand() % 2);
        monster = monstersOne[choice];
        if(monster == "Slime"){
            health = 20;
            damage = 3;
        }
        if(monster == "Rat"){
            health = 15;
            damage = 2;
        }
    }
    if(c.getCharLvl() > 4 && c.getCharLvl() <= 7){
        choice = (rand() % 8);
        monster = monstersTwo[choice];
        if(monster == "Goblin"){
            health = 30;
            damage = 6;
        }
        if(monster == "Orc"){
            health = 35;
            damage = 7;
        }
        if(monster == "Zombie"){
            health = 25;
            damage = 5;
        }
    }
    if(c.getCharLvl() > 7 && c.getCharLvl() <= 9){
        choice = (rand() % 8);
        monster = monstersThree[choice];
        if(monster == "Skeleton"){
            health = 40;
            damage = 6;
        }
        if(monster == "Werewolf"){
            health = 45;
            damage = 7;
        }
        if(monster == "Wizard"){
            health = 40;
            damage = 9;
        }
    }
    if(c.getCharLvl() == 10){
        monster = "Craynor";
        health = 75;
        damage = 11;
    }
}
string Enemy::getEnemy()
{
    return monster;
}
void Enemy::combat(Character& c)
{
    int item;
    char choice;
    c.setDamage();
    if(monster == "Rat"){
        while(choice != 'R'){
            cout << "*****************************" << endl;
            cout << "Would you like to: " << endl;
            cout << "A - attack" << endl;
            cout << "U - use an item" << endl;
            cout << "R - run away" << endl;
            cin >> choice;
            choice = toupper(choice);
            switch(choice)
            {
                case 'A':
                    cout << "You attack the nasty rat and deal " << c.getDamage() << " damage." << endl;
                    health-=c.getDamage();
                    if(health <= 0){
                        cout << "The rat now has 0 health." << endl;
                        cout << "You defeated the rat!" << endl;
                        c.addExp(2);
                        item = (rand() % 3);
                        cout << "You gained a " << dropsOne[item] << "!" << endl;
                        c.addItem(dropsOne[item]);
                        choice = 'R';
                    }
                    else{
                        cout << "The rat now has " << health << " health." << endl;
                        cout << "He bites your leg" << endl;
                        c.removeHealth(damage);
                        if(c.getHealth() <= 0){
                            cout << "You died! Oh no!" << endl;
                            cout << "An angel comes and takes you to your house." << endl;
                            c.setHealth(c.getMaxHealth());
                            cout << "You wake up feeling much better." << endl;
                            choice = 'R';
                        }
                    }
                    cout << "You now have " << c.getHealth() << " health." << endl;
                    cout << "*****************************" << endl;
                    break;

                case 'U':
                    c.useItems();
                    break;

                case 'R':
                    cout << "You ran away like a coward" << endl;
                    break;
                default:
                    cout << "Invalid input" << endl;
                cout << "**********************************" << endl;
                    break;
            }
        }
    }
    if(monster == "Slime"){
        while(choice != 'R'){
            cout << "*****************************" << endl;
            cout << "Would you like to: " << endl;
            cout << "A - attack" << endl;
            cout << "U - use an item" << endl;
            cout << "R - run away" << endl;
            cin >> choice;
            choice = toupper(choice);
            switch(choice)
            {
                case 'A':
                    cout << "You attack the nasty slime and deal " << c.getDamage() << " damage." << endl;
                    health-=c.getDamage();
                    if(health <= 0){
                        cout << "The slime now has 0 health." << endl;
                        cout << "You defeated the slime!" << endl;
                        c.addExp(2);
                        item = (rand() % 3);
                        cout << "You gained a " << dropsOne[item] << "!" << endl;
                        c.addItem(dropsOne[item]);
                        choice = 'R';
                    }
                    else{
                        cout << "The slime now has " << health << " health." << endl;
                        cout << "He throws slime at your face." << endl;
                        c.removeHealth(damage);
                        cout << "You lose " << damage << " health." << endl;
                        if(c.getHealth() <= 0){
                            cout << "You died! Oh no!" << endl;
                            cout << "An angel comes and takes you to your house." << endl;
                            c.setHealth(c.getMaxHealth());
                            cout << "You wake up feeling much better." << endl;
                            choice = 'R';
                        }
                    }
                    cout << "You now have " << c.getHealth() << " health." << endl;
                    cout << "*****************************" << endl;
                    break;

                case 'U':
                    c.useItems();
                    break;

                case 'R':
                    cout << "You ran away like a coward" << endl;
                    break;
                default:
                    cout << "Invalid input" << endl;
                cout << "*****************************" << endl;
                    break;
            }
        }
    }
    if(monster == "Goblin"){
        while(choice != 'R'){
            cout << "*****************************" << endl;
            cout << "Would you like to: " << endl;
            cout << "A - attack" << endl;
            cout << "U - use an item" << endl;
            cout << "R - run away" << endl;
            cin >> choice;
            choice = toupper(choice);
            switch(choice)
            {
                case 'A':
                    cout << "You attack the snarling goblin and deal " << c.getDamage() << " damage." << endl;
                    health-=c.getDamage();
                    cout << "The goblin now has " << health << " health." << endl;
                    if(health <= 0){
                        cout << "You defeated the goblin!" << endl;
                        c.addExp(3);
                        item = (rand() % 4);
                        cout << "You gained a " << dropsTwo[item] << "!" << endl;
                        c.addItem(dropsTwo[item]);
                        choice = 'R';
                    }
                    else{
                        cout << "He hits you with his sword." << endl;
                        c.removeHealth(damage);
                        cout << "You lose " << damage << " health." << endl;
                        if(c.getHealth() <= 0){
                            cout << "You died! Oh no!" << endl;
                            cout << "An angel comes and takes you to your house." << endl;
                            c.setHealth(c.getMaxHealth());
                            cout << "You wake up feeling much better." << endl;
                            choice = 'R';
                        }
                    }
                    cout << "You now have " << c.getHealth() << " health." << endl;
                    cout << "*****************************" << endl;
                    break;

                case 'U':
                    c.useItems();
                    break;

                case 'R':
                    cout << "You ran away like a coward" << endl;
                    break;
                default:
                    cout << "Invalid input" << endl;
                cout << "*****************************" << endl;
                    break;
            }
        }
    }
    if(monster == "Orc"){
        while(choice != 'R'){
            cout << "*****************************" << endl;
            cout << "Would you like to: " << endl;
            cout << "A - attack" << endl;
            cout << "U - use an item" << endl;
            cout << "R - run away" << endl;
            cin >> choice;
            choice = toupper(choice);
            switch(choice)
            {
                case 'A':
                    cout << "You attack the orc and deal " << c.getDamage() << " damage." << endl;
                    health-=c.getDamage();
                    cout << "The orc now has " << health << " health." << endl;
                    if(health <= 0){
                        cout << "You defeated the orc!" << endl;
                        c.addExp(3);
                        item = (rand() % 4);
                        cout << "You gained a " << dropsTwo[item] << "!" << endl;
                        c.addItem(dropsTwo[item]);
                        choice = 'R';
                    }
                    else{
                        cout << "He hits you with his club." << endl;
                        c.removeHealth(damage);
                        cout << "You lose " << damage << " health." << endl;
                        if(c.getHealth() <= 0){
                            cout << "You died! Oh no!" << endl;
                            cout << "An angel comes and takes you to your house." << endl;
                            c.setHealth(c.getMaxHealth());
                            cout << "You wake up feeling much better." << endl;
                            choice = 'R';
                        }
                    }
                    cout << "You now have " << c.getHealth() << " health." << endl;
                    cout << "*****************************" << endl;
                    break;

                case 'U':
                    c.useItems();
                    break;

                case 'R':
                    cout << "You ran away like a coward" << endl;
                    break;
                default:
                    cout << "Invalid input" << endl;
                cout << "*****************************" << endl;
                    break;
            }
        }
    }
    if(monster == "Zombie"){
        while(choice != 'R'){
            cout << "*****************************" << endl;
            cout << "Would you like to: " << endl;
            cout << "A - attack" << endl;
            cout << "U - use an item" << endl;
            cout << "R - run away" << endl;
            cin >> choice;
            choice = toupper(choice);
            switch(choice)
            {
                case 'A':
                    cout << "You attack the disgusting zombie and deal " << c.getDamage() << " damage." << endl;
                    health-=c.getDamage();
                    cout << "The zombie now has " << health << " health." << endl;
                    if(health <= 0){
                        cout << "You defeated the rat!" << endl;
                        c.addExp(1);
                        item = (rand() % 3);
                        cout << "You gained a " << dropsOne[item] << "!" << endl;
                        c.addItem(dropsOne[item]);
                        choice = 'R';
                    }
                    else{
                        cout << "He swings his arm at your head and bonks you." << endl;
                        c.removeHealth(damage);
                        cout << "You lose " << damage << " health." << endl;
                        if(c.getHealth() <= 0){
                            cout << "You died! Oh no!" << endl;
                            cout << "An angel comes and takes you to your house." << endl;
                            c.setHealth(c.getMaxHealth());
                            cout << "You wake up feeling much better." << endl;
                            choice = 'R';
                        }
                    }
                    cout << "You now have " << c.getHealth() << " health." << endl;
                    cout << "*****************************" << endl;
                    break;

                case 'U':
                    c.useItems();
                    break;

                case 'R':
                    cout << "You ran away like a coward" << endl;
                    break;
                default:
                    cout << "Invalid input" << endl;
                cout << "*****************************" << endl;
                    break;
            }
        }
    }
    if(monster == "Wizard"){
        while(choice != 'R'){
            cout << "*****************************" << endl;
            cout << "Would you like to: " << endl;
            cout << "A - attack" << endl;
            cout << "U - use an item" << endl;
            cout << "R - run away" << endl;
            cin >> choice;
            choice = toupper(choice);
            switch(choice)
            {
                case 'A':
                    cout << "You attack the old wizard and deal " << c.getDamage() << " damage." << endl;
                    health-=c.getDamage();
                    cout << "The wizard now has " << health << " health." << endl;
                    if(health <= 0){
                        cout << "You defeated the wizard!" << endl;
                        c.addExp(1);
                        item = (rand() % 3);
                        cout << "You gained a " << dropsOne[item] << "!" << endl;
                        c.addItem(dropsOne[item]);
                        choice = 'R';
                    }
                    else{
                        cout << "He launches a fireball at you." << endl;
                        c.removeHealth(damage);
                        cout << "You lose " << damage << " health." << endl;
                        if(c.getHealth() <= 0){
                            cout << "You died! Oh no!" << endl;
                            cout << "An angel comes and takes you to your house." << endl;
                            c.setHealth(c.getMaxHealth());
                            cout << "You wake up feeling much better." << endl;
                            choice = 'R';
                        }
                    }
                    cout << "You now have " << c.getHealth() << " health." << endl;
                    cout << "*****************************" << endl;
                    break;

                case 'U':
                    c.useItems();
                    break;

                case 'R':
                    cout << "You ran away like a coward" << endl;
                    break;
                default:
                    cout << "Invalid input" << endl;
                cout << "*****************************" << endl;
                    break;
            }
        }
    }
    if(monster == "Skeleton"){
        while(choice != 'R'){
            cout << "*****************************" << endl;
            cout << "Would you like to: " << endl;
            cout << "A - attack" << endl;
            cout << "U - use an item" << endl;
            cout << "R - run away" << endl;
            cin >> choice;
            choice = toupper(choice);
            switch(choice)
            {
                case 'A':
                    cout << "You attack the skinny skeleton and deal " << c.getDamage() << " damage." << endl;
                    health-=c.getDamage();
                    cout << "The skeleton now has " << health << " health." << endl;
                    if(health <= 0){
                        cout << "You defeated the skeleton!" << endl;
                        c.addExp(1);
                        item = (rand() % 3);
                        cout << "You gained a " << dropsOne[item] << "!" << endl;
                        c.addItem(dropsOne[item]);
                        choice = 'R';
                    }
                    else{
                        cout << "He throws a bone at you." << endl;
                        c.removeHealth(damage);
                        cout << "You lose " << damage << " health." << endl;
                        if(c.getHealth() <= 0){
                            cout << "You died! Oh no!" << endl;
                            cout << "An angel comes and takes you to your house." << endl;
                            c.setHealth(c.getMaxHealth());
                            cout << "You wake up feeling much better." << endl;
                            choice = 'R';
                        }
                    }
                    cout << "You now have " << c.getHealth() << " health." << endl;
                    cout << "*****************************" << endl;
                    break;

                case 'U':
                    c.useItems();
                    break;

                case 'R':
                    cout << "You ran away like a coward" << endl;
                    break;
                default:
                    cout << "Invalid input" << endl;
                cout << "*****************************" << endl;
                    break;
            }
        }
    }
    if(monster == "Werewolf"){
        while(choice != 'R'){
            cout << "*****************************" << endl;
            cout << "Would you like to: " << endl;
            cout << "A - attack" << endl;
            cout << "U - use an item" << endl;
            cout << "R - run away" << endl;
            cin >> choice;
            choice = toupper(choice);
            switch(choice)
            {
                case 'A':
                    cout << "You attack the growling werewolf and deal " << c.getDamage() << " damage." << endl;
                    health-=c.getDamage();
                    cout << "The werewolf now has " << health << " health." << endl;
                    if(health <= 0){
                        cout << "You defeated the werewolf!" << endl;
                        c.addExp(1);
                        item = (rand() % 3);
                        cout << "You gained a " << dropsOne[item] << "!" << endl;
                        c.addItem(dropsOne[item]);
                        choice = 'R';
                    }
                    else{
                        cout << "He scratches you." << endl;
                        c.removeHealth(damage);
                        cout << "You lose " << damage << " health." << endl;
                        if(c.getHealth() <= 0){
                            cout << "You died! Oh no!" << endl;
                            cout << "An angel comes and takes you to your house." << endl;
                            c.setHealth(c.getMaxHealth());
                            cout << "You wake up feeling much better." << endl;
                            choice = 'R';
                        }
                    }
                    cout << "You now have " << c.getHealth() << " health." << endl;
                    cout << "*****************************" << endl;
                    break;

                case 'U':
                    c.useItems();
                    break;

                case 'R':
                    cout << "You ran away like a coward" << endl;
                    break;
                default:
                    cout << "Invalid input" << endl;
                cout << "*****************************" << endl;
                    break;
            }
        }
    }
    if(monster == "Craynor"){
        cout << "This is the final boss. Good luck." << endl;
        while(choice != 'R'){
            cout << "*****************************" << endl;
            cout << "Would you like to: " << endl;
            cout << "A - attack" << endl;
            cout << "U - use an item" << endl;
            cout << "R - run away" << endl;
            cin >> choice;
            choice = toupper(choice);
            switch(choice)
            {
                case 'A':
                    cout << "You attack Craynor and deal " << c.getDamage() << " damage." << endl;
                    health-=c.getDamage();
                    cout << "Craynor now has " << health << " health." << endl;
                    if(health <= 0){
                        cout << "You defeated Craynor! Good job!" << endl;
                        c.addExp(1);
                        item = (rand() % 3);
                        cout << "You gained a " << dropsOne[item] << "!" << endl;
                        c.addItem(dropsOne[item]);
                        choice = 'R';
                    }
                    else{
                        cout << "Craynor sends lightning at you and punches you with his mighty fist." << endl;
                        c.removeHealth(damage);
                        cout << "You lose " << damage << " health." << endl;
                        if(c.getHealth() <= 0){
                            cout << "You died! Oh no!" << endl;
                            cout << "An angel comes and takes you to your house." << endl;
                            c.setHealth(c.getMaxHealth());
                            cout << "You wake up feeling much better." << endl;
                            choice = 'R';
                        }
                    }
                    cout << "You now have " << c.getHealth() << " health." << endl;
                    cout << "*****************************" << endl;
                    break;

                case 'U':
                    c.useItems();
                    break;

                case 'R':
                    cout << "You ran away like a coward" << endl;
                    break;
                default:
                    cout << "Invalid input" << endl;
                cout << "*****************************" << endl;
                    break;
            }
        }
    }
}
