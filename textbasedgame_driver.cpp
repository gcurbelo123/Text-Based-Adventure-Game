//Title: .cpp
//Gilbert Curbelo III, Raymond Esteybar, Irais Gopar
//Date Modified:
//Desc:

#include <iostream>
using namespace std;
#include "textbasedgame.h"
#include <cmath>
#include "character.h"
#include "enemy.h"

int main()
{
    Character character;
    char choice ='N', uChoice = 'N', gender, fight;
    int counter = 0;
	Shop shop;
	Enemy enemy;
	character.create();
	cout << "*******************************************************" << endl;
	cout << endl;
	cout << "Born from a poor family, you have never had the luxury others in life may enjoy." << endl;
	cout << "You have had to fight for everything you've wanted, and no one has helped you on the way." << endl;
	cout << "You always heard great tales of fearless warriors who have fallen at the hands of Craynor."<< endl;
    cout << "When you were a kid, you dreamed of growing up and being an adventurer." << endl;
	cout << "However, your parents worried about you. They feared that Craynor was too powerful for one" << endl;
	cout << "person to face on their own. That never stopped you. You were relentless in your training." << endl;
	cout << "The day has finally come where you can be your own person and become a great warrior." << endl;
	cout << endl << endl;
	cout << "In the town that you were born, there aren't many things to do. You can either go on an adventure(fight and lvl up), go to the shop(buy/sell items), or go home and rest(heal)" << endl;
    while(choice != 'Q')
    {
        cout << "What would you like to do?" << endl;
        cout << "A - adventure" << endl;
        cout << "S - shop" << endl;
        cout << "H - home" << endl;
        cout << "V - view character info" << endl;
        cout << "Q - quit the game :(" << endl;
        cin >> choice;
        choice = toupper(choice);
        switch(choice)
        {
            case 'A':
                cout << "You walk along the lovely forest path." << endl;
                cout << "Then out of nowhere, a " << enemy.getEnemy() << " appears!" << endl;
                cout << "Do you wish to fight it?(Y/N)" << endl;
                cin >> fight;
                fight = toupper(fight);
                if(fight == 'Y')
                    enemy.combat(character);
                enemy.newEnemy(character);
                break;
            case 'S':
                shop.shop(character);
                break;
            case 'H':
                character.goHome();
                break;
            case 'V':
                cout << character;
                break;
        }
    }
	return 0;
}
