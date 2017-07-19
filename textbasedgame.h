#ifndef TEXTBASEDGAME_H_INCLUDED
#define TEXTBASEDGAME_H_INCLUDED

//**********************************
//Class Name:
//
//Description:
//
//**********************************
#include <fstream>
#include "character.h"

class Shop
{
    public:
        Shop();
        void setItem1(string item1){this->item1 = item1;}
        void setItem2(string item2){this->item2 = item2;}
        void setItem3(string item3){this->item3 = item3;}
        void setItem1Val(int item1val){this->item1val = item1val;}
        void setItem2Val(int item2val){this->item2val = item2val;}
        void setItem3Val(int item3val){this->item3val = item3val;}
        string getItem1();
        string getItem2();
        string getItem3();
        int getItem1V();
        int getItem2V();
        int getItem3V();

        void buyOrSell(Character& c);
        void shop(Character& c);
        string items[12] = {"Wood Sword", "Wood Shield", "Minor Health Potion", "Steel Sword", "Steel Shield", "Regular Health potion", "Fire Sword", "Fire Shield", "Large Health Potion", "Stick", "Rock", "Leaf"};
        int itemVals[12] = {10,10,5,20,20,10,30,30,15,1,1,1};

    private:
        string item1;
        int item1val;
        string item2;
        int item2val;
        string item3;
        int item3val;
};

#endif // TEXTBASEDGAME_H_INCLUDED
