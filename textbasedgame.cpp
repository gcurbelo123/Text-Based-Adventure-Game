//Title: .cpp
//Gilbert Curbelo III
//Date Modified:
//Desc:

#include <iostream>
using namespace std;
#include "textbasedgame.h"
#include "character.h"

Shop::Shop()
{
    item1 = "Wood Sword";
    item1val = 10;
    item2 = "Wood Shield";
    item2val = 10;
    item3 = "Minor Health Potion";
    item3val = 5;
}
string Shop::getItem1()
{
    return item1;
}
string Shop::getItem2()
{
    return item2;
}
string Shop::getItem3()
{
    return item3;
}
int Shop::getItem1V()
{
    return item1val;
}
int Shop::getItem2V()
{
    return item2val;
}
int Shop::getItem3V()
{
    return item3val;
}
void Shop::buyOrSell(Character& c)
{
    char choice = 'N';
    int cho, amount;
    string item;
    if(c.getCharLvl() > 4 && c.getCharLvl() <= 7){
        item1 = items[3];
        item2 = items[4];
        item3 = items[5];
        item1val = itemVals[3];
        item2val = itemVals[4];
        item3val = itemVals[5];
    }
    if(c.getCharLvl() > 7 && c.getCharLvl() <= 10){
        item1 = items[6];
        item2 = items[7];
        item3 = items[8];
        item1val = itemVals[6];
        item2val = itemVals[7];
        item3val = itemVals[8];
    }
    while(choice != 'Q'){
        cout << "B - buy, S - sell, or Q to leave the shop: ";
        cin >> choice;
        choice = toupper(choice);
        if(choice == 'B'){
            cout << "What would you like to buy?" << endl;
            cout << "1. " << item1 << " " << item1val << "gp" << endl;
            cout << "2. " << item2 << " " << item2val << "gp" << endl;
            cout << "3. " << item3 << " " << item3val << "gp" << endl;
            cout << "Enter the number of the corresponding item you would like to purchase: ";
            cin >> cho;
            if(cho == 1){
                item = item1;
                if(c.getGP() < item1val)
                    cout << "Not enough gold. Sorry!" << endl;
                else{
                    c.addItem(item);
                    amount = item1val;
                    c.removeGold(amount);
                }
            }
            if(cho == 2){
                item = item2;
                if(c.getGP() < item2val)
                    cout << "Not enough gold. Sorry!" << endl;
                else{
                    c.addItem(item);
                    amount = item2val;
                    c.removeGold(amount);
                }
            }
            if(cho == 3){
                item = item3;
                if(c.getGP() < item3val)
                    cout << "Not enough gold. Sorry!" << endl;
                else{
                    c.addItem(item);
                    amount = item1val;
                    c.removeGold(amount);
                }
            }
            cout << "Thank you!" << endl;
        }
        if(choice == 'S'){
            c.sellItem();
            cout << "Thank you!" << endl;
        }
    }
    cout << endl << endl << "Thank you for coming!" << endl;
}
void Shop::shop(Character& c)
{
    char choice;
    cout << endl;
    cout << "**********************************************" << endl;
    cout << "Welcome to the adventurer's shop of Craynor!" << endl;
    cout << "Would you like to buy? Or sell?               " << endl;
    buyOrSell(c);
    cout << "**********************************************" << endl;
    cout << endl;
}
