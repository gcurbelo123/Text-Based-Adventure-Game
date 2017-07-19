//Title: .cpp
//Gilbert Curbelo III
//Date Modified:
//Desc:

#include <iostream>
using namespace std;
#include "character.h"
#include <iomanip>
#include "textbasedgame.h"

Character::Character()
{
    lvl = 1;
    exp = 0;
    maxhp = 30;
    hp = 30;
    damage = 4;
    name = "";
    gender = ' ';
    for(int i = 0; i < 5; i++)
        backpack[i] = "";
    gp = 0;
    hColor = "";
    eColor = "";
    sColor = "";
    item1 = items[0];
    item2 = items[1];
    item3 = items[2];
    item1val = itemVals[0];
    item2val = itemVals[1];
    item3val = itemVals[2];
}
ostream& operator <<(ostream& out, const Character& p1)
{
    int j=0, k=1;
    out << endl << "********CHARACTER INFORMATION*********" << endl;
    out << "Name: " << p1.name << endl;
    out << "Health: " << p1.hp << endl;
    out << "Items in backpack:" << endl;
    for(int i = 0; i < 5; i++){
        if(p1.backpack[i] != ""){
            out << j+1 << "." << " " << p1.backpack[i] << endl;
            j++;
        }
        else
            k++;
        if(k == 6)
            out << "Nothing in your inventory. Get out there and adventure!" << endl;
    }
    out << p1.gp << " gp" << endl;
    out << "Level: " << p1.lvl << endl;
    if(p1.lvl == 1)
        out << "Exp: " << p1.exp << "/10" << endl;
    if(p1.lvl == 2)
        out << "Exp: " << p1.exp << "/20" << endl;
    if(p1.lvl == 3)
        out << "Exp: " << p1.exp << "/30" << endl;
    if(p1.lvl == 4)
        out << "Exp: " << p1.exp << "/40" << endl;
    if(p1.lvl == 5)
        out << "Exp: " << p1.exp << "/50" << endl;
    if(p1.lvl == 6)
        out << "Exp: " << p1.exp << "/60" << endl;
    if(p1.lvl == 7)
        out << "Exp: " << p1.exp << "/70" << endl;
    if(p1.lvl == 8)
        out << "Exp: " << p1.exp << "/80" << endl;
    if(p1.lvl == 9)
        out << "Exp: " << p1.exp << "/90" << endl;
    if(p1.lvl == 10)
        out << "Exp: MAX/MAX" << endl;
    cout << "**************************************" << endl << endl;
    return out;
}
void Character::create()
{
    char uChoice = 'N', gender, choice = 'N';
    string sChoice, cName, cEye, cHair, cSkin;
    cout << "*****************************************************" << endl;
    cout << "WELCOME TO THE WORLD OF CRAYNOR. THE LAND OF CRAYNOR" << endl;
    cout << "IS RULED BY AN ANCIENT WARRIOR KNOWN AS CRAYNOR." << endl;
    cout << "CRAYNOR HAS RULED THROUGH TERROR FOR A THOUSAND YEARS." << endl;
    cout << "NO ONE HAS BEEN ABLE TO CHALLENGE HIM, LET ALONE BEAT" << endl;
    cout << "HIM. THE PEOPLE OF CRAYNOR HAVE BEEN TRYING TO FIND A" << endl;
    cout << "WARRIOR THAT CAN DEFEAT HIM EVER SINCE HE TOOK RULE." << endl;
    cout << "DO THEY FINALLY HAVE THAT WARRIOR?" << endl;
    cout << "*****************************************************" << endl;
    cout << endl << endl;
    cout << "*****************************************************" << endl;
	cout << "****************CHARACTER CREATION*******************" << endl;
	cout << "*****************************************************" << endl;
	while(uChoice == 'N'){
        choice = 'N';
        while(choice != 'Y'){
            cout << "Enter your name: ";
            getline(cin,cName);
            cout << cName << ", is that correct? (Y/N)" << endl;
            cin >> choice;
            cin.ignore();
            choice = toupper(choice);
        }
        choice = 'N';
        setName(cName);
        while(choice == 'N'){
            cout << "What is your eye color? It can be anything you want!" << endl;
            cout << "Desired eye color: ";
            cin >> cEye;
            cout << "So, you want " << cEye << " eyes? (Y/N)" << endl;
            cin >> choice;
            choice = toupper(choice);
        }
        cEye[0] = tolower(cEye[0]);
        choice = 'N';
        setEyes(cEye);
        while(choice == 'N'){
            cout << "Enter hair color: ";
            cin >> cHair;
            cout << "You hair color will be " << cHair << ". Is that correct? (Y/N)" << endl;
            cin >> choice;
            choice = toupper(choice);
        }
        cHair[0] = tolower(cHair[0]);
        choice = 'N';
        setHair(cHair);
        while(choice == 'N'){
            cout << "Enter skin color: ";
            cin >> cSkin;
            cout << "You skin is " << cSkin << ". Right? (Y/N)" << endl;
            cin >> choice;
            choice = toupper(choice);
        }
        cSkin[0] = tolower(cSkin[0]);
        choice = 'N';
        setSkin(cSkin);
        while(choice == 'N'){
            cout << "Now for the most important question of all." << endl;
            cout << "Are you a boy or a girl?" << endl;
            cout << "Enter gender (M/F): ";
            cin >> gender;
            if(gender == 'm' || gender == 'M'){
                cout << "You're a male, is that right? (Y/N)" << endl;
                cin >> choice;
                choice = toupper(choice);
            }
            else if(gender == 'f' || gender == 'F'){
                cout << "You're a female, is that right? (Y/N)" << endl;
                cin >> choice;
                choice = toupper(choice);
            }
            else
                cout << "Incorrect choice, enter M/F or m/f" << endl;
        }
        setGen(gender);
        cout << "******CURRENT BUILD*******" << endl;
        cout << "Character name: " << name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Hair color: " << hColor << endl;
        cout << "Eye color: " << eColor << endl;
        cout << "Skin color: " << sColor << endl;
        cout << "Are you happy with your character build? (N - to restart)" << endl;
        cout << "*any other entered letter will continue with current build" << endl;
        cin >> uChoice;
        cin.ignore();
        uChoice = toupper(uChoice);
	}
}
void Character::addExp(int x)
{
    if(lvl == 1){
        exp+=x;
        if(exp >= 10){
            addLvl();
            exp = 0;
        }
    }
    if(lvl == 2){
        exp+=x;
        if(exp >= 20){
            addLvl();
            exp = 0;
        }
    }
    if(lvl == 3){
        exp+=x;
        if(exp >= 30){
            addLvl();
            exp = 0;
        }
    }
    if(lvl == 4){
        exp+=x;
        if(exp >= 40){
            addLvl();
            exp = 0;
        }
    }
    if(lvl == 5){
        exp+=x;
        if(exp >= 50){
            addLvl();
            exp = 0;
        }
    }
    if(lvl == 6){
        exp+=x;
        if(exp >= 60){
            addLvl();
            exp = 0;
        }
    }
    if(lvl == 7){
        exp+=x;
        if(exp >= 70){
            addLvl();
            exp = 0;
        }
    }
    if(lvl == 8){
        exp+=x;
        if(exp >= 80){
            addLvl();
            exp = 0;
        }
    }
    if(lvl == 9){
        exp+=x;
        if(exp >= 90){
            addLvl();
            exp = 0;
        }
    }
    if(lvl == 10){
        cout << "You have reached the max level. There was no experience granted. But good job!" << endl;
    }
}
void Character::addLvl()
{
    cout << "Congratulations! You leveled up!" << endl;
    lvl++;
    if(lvl == 2)
        maxhp=35;
    if(lvl == 3)
        maxhp=40;
    if(lvl == 4)
        maxhp=45;
    if(lvl == 5)
        maxhp=50;
    if(lvl == 6)
        maxhp=55;
    if(lvl == 7)
        maxhp=60;
    if(lvl == 8)
        maxhp=65;
    if(lvl == 9)
        maxhp=70;
    if(lvl == 10)
        maxhp=75;
    cout << "Your health has been restored, and your max hp is now " << maxhp << "!" << endl;
    hp = maxhp;

    if(lvl > 4 && lvl <= 7){
        item1 = items[3];
        item2 = items[4];
        item3 = items[5];
        item1val = itemVals[3];
        item2val = itemVals[4];
        item3val = itemVals[5];
    }
    if(lvl > 7 && lvl <= 10){
        item1 = items[6];
        item2 = items[7];
        item3 = items[8];
        item1val = itemVals[6];
        item2val = itemVals[7];
        item3val = itemVals[8];
    }
}
void Character::setDamage()
{
    bool wood = false, steel = false, fire = false;
    if(lvl <= 4){
        damage = 5;
         for(int i = 0; i < 5; i++){
            if(backpack[i] == "Wood Sword"){
                wood = true;
                i = 4;
            }
        }
        if(wood == true)
            damage+=4;
    }
    if(lvl > 4 && lvl <= 7){
        damage = 10;
         for(int i = 0; i < 5; i++){
            if(backpack[i] == "Wood Sword"){
                wood = true;
            }
            if(backpack[i] == "Steel Sword"){
                steel = true;
                wood = false;
                i = 4;
            }
        }
        if(steel == true)
            damage+=7;
        else if(wood == true)
            damage+=4;
    }
    if(lvl > 7){
        damage = 15;
         for(int i = 0; i < 5; i++){
            if(backpack[i] == "Wood Sword"){
                wood = true;
            }
            if(backpack[i] == "Steel Sword"){
                steel = true;
                wood = false;
                i = 4;
            }
            if(backpack[i] == "Fire Sword"){
                fire = true;
                steel = false;
                wood = false;
                i = 4;

            }
        }
        if(fire == true)
            damage+=10;
        else if(steel == true)
            damage+=7;
        else if(wood == true)
            damage+=4;
    }

}
void Character::addGold(int x)
{
    this->gp+=x;
}
void Character::addItem(string item)
{
    char choice;
    int cho;
    for(int i = 0; i < 5; i++){
        if(backpack[i] == ""){
            backpack[i] = item;
            break;
        }
        if(i == 4){
            cout << "No more space in your backpack" << endl;
            cout << "Would you like to remove something form your inventory? (Y/N)" << endl;
            cin >> choice;
            if(choice == 'y' || choice == 'Y'){
                cout << "Which item would you like to get rid of? Enter the number of the corresponding item." << endl;
                for(int i = 0; i < 5; i++){
                    cout << i << " " << backpack[i] << endl;
                }
                cin >> cho;
                cout << "You want to get rid of " << backpack[cho] << "? (Y/N)" << endl;
                cin >> choice;
                if(choice == 'y' || choice == 'Y'){
                    cout << "You have replaced " << backpack[cho] << " with " << item << endl;
                    backpack[cho] = item;
                }
                if(choice == 'n' || choice == 'N')
                    cout << "You didn't get rid of an item." << endl;
            }
            else
                cout << "Unable to add item due to full inventory." << endl;
        }
    }
}
void Character::sellItem()
{
    int cho, op=1, counter=1;
    string temp;
    bool sell = true;
    for(int i = 0; i < 5; i++){
        if(backpack[i] == "")
            counter++;
        if(counter == 6)
            sell = false;
    }
    if(sell == true){
        cout << "Which item would you like to sell?" << endl;
        for(int i = 0; i < 5; i++){
            cout << op << ". " << backpack[i] << endl;
            op++;
        }
        cin >> cho;
        cho--;
        temp = backpack[cho];
        for(int i = 0; i < 12; i++){
            if(temp == items[i]){
                addGold(itemVals[i]);
            }
        }
        removeItemStore(cho);
    }
    if(sell == false){
        cout << "You have no items in your inventory. Go out and get some stuff to sell!" << endl;
    }

}
void Character::removeGold(int amount)
{
    gp = gp - amount;
}
void Character::removeItem()
{
    int cho;
    cout << "Which item would you like to get rid of?" << endl;
    for(int i = 0; i < 5; i++){
        cout << i+1 << ". " << backpack[i] << endl;
    }
    cin >> cho;
    backpack[cho] = "";
}
void Character::removeItemStore(int choice)
{
    backpack[choice] = "";
}
void Character::removeHealth(int x)
{
    bool wood = false, steel = false, fire = false;
    int dam = x;
    if(lvl <= 4){
        for(int i = 0; i < 5; i++){
            if(backpack[i] == "Wood Shield"){
                wood = true;
                i = 4;
            }
        }
        if(wood == true){
            dam-=2;
            cout << "You blocked 2 damage and took " << dam << " damage!" << endl;
        }
    }
    if(lvl > 4 && lvl <= 7){
         for(int i = 0; i < 5; i++){
            if(backpack[i] == "Wood Shield"){
                wood = true;
            }
            if(backpack[i] == "Steel Shield"){
                steel = true;
                wood = false;
                i = 4;
            }
        }
        if(steel == true){
            dam-=4;
            cout << "You blocked 4 damage and took " << dam << " damage!" << endl;
        }
        else if(wood == true){
            dam-=2;
            cout << "You blocked 2 damage and took " << dam << " damage!" << endl;
        }
    }
    if(lvl > 7){
         for(int i = 0; i < 5; i++){
            if(backpack[i] == "Wood Shield"){
                wood = true;
            }
            if(backpack[i] == "Steel Shield"){
                steel = true;
                wood = false;
                i = 4;
            }
            if(backpack[i] == "Fire Shield"){
                fire = true;
                steel = false;
                wood = false;
                i = 4;

            }
        }
        if(fire == true){
            dam-=6;
            cout << "You blocked 6 damage and took " << dam << " damage!" << endl;
        }
        else if(steel == true){
            dam-=4;
            cout << "You blocked 4 damage and took " << dam << " damage!" << endl;
        }
        else if(wood == true){
            dam-=2;
            cout << "You blocked 2 damage and took " << dam << " damage!" << endl;
        }
    }
    hp-=dam;
}
string Character::useItems()
{
    int cho;
    cout << "Which item would you like to use?" << endl;
    for(int i = 0; i < 5; i++){
        cout << i+1 << ". " << backpack[i] << endl;
    }
    cin >> cho;
    if(backpack[cho] == "Minor Health Potion" || backpack[cho] == "Regular Health Potion" || backpack[cho] == "Large Health Potion"){
        cout << "After using your " << backpack[cho] << " ";
        if(backpack[cho] == "Minor Health Potion"){
            cout << "you gained 10 health" << endl;
            addHp(10);
        }
        if(backpack[cho] == "Regular Health Potion"){
            cout << "you gained 15 health" << endl;
            addHp(15);
        }
        if(backpack[cho] == "Large Health Potion"){
            cout << "you gained 20 health" << endl;
            addHp(20);
        }
    }
    if(backpack[cho] == "")
        cout << "There is no item at this spot." << endl;
    else{
        cout << "That is a non-usable item." << endl;
    }
}
void Character::addHp(int x)
{
    hp+=x;
    if(hp + x > maxhp)
        hp = maxhp;
}
void Character::goHome()
{
    cout << endl;
    cout << "***************************************************************" << endl;
    cout << "You decide to take a nice nap at home, and heal your wounds" << endl;
    setHealth(getMaxHealth());
    cout << "Zzzzz" << endl;
    cout << "zzzzz" << endl;
    cout << "zzzzz" << endl;
    cout << "After a long nap, you wake up rested and healed" << endl;
    cout << "***************************************************************" << endl;
    cout << endl;
}
