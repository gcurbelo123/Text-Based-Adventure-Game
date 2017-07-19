#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

//**********************************
//Class Name:
//
//Description:
//
//**********************************
#include <fstream>
//#include "enemy.h"
class Character
{
public:
    Character(); // done
    void addLvl(); // done
    void addExp(int x);
    void addHp(int x);
    void setDamage();
    void goHome();
    void create();
    int getDamage()const{return damage;}
    void setHealth(int hp){this->hp = hp;}
    void removeHealth(int x);
    int getMaxHealth()const{return maxhp;}
    void addGold(int x); //done
    void removeGold(int amount);
    void addItem(string item); //done
    void removeItem(); //done
    void removeItemStore(int choice); //done
    int getGP()const{return gp;} //done
    void sellItem(); //done
    friend ostream& operator <<(ostream& out, const Character& p1); // done
    void setName(string name){this->name = name;} //done
    void setGen(char gender){this->gender = gender;} //done
    void setHair(string hColor){this->hColor = hColor;} //done
    void setEyes(string eColor){this->eColor = eColor;} //done
    void setSkin(string sColor){this->sColor = sColor;} //done
    string useItems();
    int getHealth()const{return hp;}
    int getCharLvl()const{return lvl;}
    string getName()const {return name;}
    string items[12] = {"Wood Sword", "Wood Shield", "Minor Health Potion", "Steel Sword", "Steel Shield", "Regular Health potion", "Fire Sword", "Fire Shield", "Large Health Potion", "Stick", "Rock", "Leaf"}; //done
    int itemVals[12] = {5,2,2,10,5,5,15,10,10,1,1,1}; //done


private:
    int lvl, exp, hp, maxhp;
    string name;
    char gender;
    string backpack[5];
    int gp;
    string hColor; //hair
    string eColor; //eye
    string sColor; //skin
    string item1, item2, item3;
    int item1val, item2val, item3val;
    int damage;
};
#endif // CHARACTER_H_INCLUDED
