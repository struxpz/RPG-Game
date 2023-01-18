#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "heroManage.cpp"
#include "monsterManage.cpp"
#include "battle.cpp"
#include "Inventory.cpp"
#include "items.cpp"
using namespace std;

/*

Hello Proffesor!
This game has rather complicated mechanics, that's why I am going to briefly introduce you to what it has to offer.
Apart from the obligatory features:
1) You have a shop with plenty of items, each giving unique bonus. At one time you can buy as much items as you want (if you have enough coins) 
2) During battle you can choose 1 of 2 attacking method, each attacking method requires a sufficient amount of energy
    if you do not have sufficient energy, you miss your turn. You restore 20 energy points each round.
3) If you are low on HP, or energy you can always use health or energy potions if you have previously dropped them or bought at the shop
    during 1 round you can use as many potions as you have.
4) I introduced Beer as a potion of luck :) It means you will have a better chance of dropping items, but at the cost of decreasing your stats
5) Monsters also have 2 attacking methods, they use them randomly, but be careful sometimes they hit realy hard
6) Also I tried to implement saving items which you wear (armour etc.) in a separate double linked list, so that you can take off what you wear
    but for some reason when I created a second double linked list object (with a different name), the program didn't differetiate them
    So when an item was to be saved in a list object handling inventory, it was also saved in the other list object.

 I hope you'll be having fun while trying the various features

*/
int iteratione = 0;
int main()
{
    srand((unsigned int)time(NULL));
    invent inv;
    mage mag;
    Potion pot; // Health_Potion, RedBull, Beer, Great_Health_Potion, Great_RedBull;
    warior war;
    berserker ber;
    thief thif;
    heroManage obj("", 1, 1, /*hp*/ 100, /*coins*/ 10000, /*energy*/ 100, /*luck*/ 0, 10, 10, 10, 10, 10);
    inv.createList();
    monsters monster1, monster2, monster3, monster4, monster5;
    battleSim<int> battle;
    cout << "\nHello! Please type a number to perform an action : 1)New game,   2) Load game,  Press anything else to quit\n";
    cin >> action;
    if (action == 1 || action == 2) // Security condition
    {
        if (action == 2)
        {
            //---------------LOAD A CHARACTER
            obj.getFileData();
            monster1.monsterGetFileData(prevnick);
            monster2.monsterGetFileData(prevnick);
            monster3.monsterGetFileData(prevnick);
            monster4.monsterGetFileData(prevnick);
            monster5.monsterGetFileData(prevnick);
            if (action == 2)
            {
                obj.setStats(stats[0] /*nick*/, stoi(stats[1]) /*Class*/, stoi(stats[2]) /*Level*/, stoi(stats[3]) /*Health*/, stoi(stats[4]) /*Coins*/, stoi(stats[5]) /*Energy*/, stoi(stats[6]) /*luck*/, stoi(stats[7]) /*Strength*/, stoi(stats[7]) /*Dexterity*/, stoi(stats[8]) /*Endurance*/, stoi(stats[9]) /*Intelligence*/, stoi(stats[10]) /*charisma*/);
                monster1.setStats(monsterStats[0][0], 1, 100, stoi(monsterStats[0][1]), stoi(monsterStats[0][2]), stoi(monsterStats[0][3]), stoi(monsterStats[0][4]), stoi(monsterStats[0][5]));
                monster2.setStats(monsterStats[1][0], 2, 100, stoi(monsterStats[1][1]), stoi(monsterStats[1][2]), stoi(monsterStats[1][3]), stoi(monsterStats[1][4]), stoi(monsterStats[1][5]));
                monster3.setStats(monsterStats[2][0], 3, 100, stoi(monsterStats[2][1]), stoi(monsterStats[2][2]), stoi(monsterStats[2][3]), stoi(monsterStats[2][4]), stoi(monsterStats[2][5]));
                monster4.setStats(monsterStats[3][0], 4, 100, stoi(monsterStats[3][1]), stoi(monsterStats[3][2]), stoi(monsterStats[3][3]), stoi(monsterStats[3][4]), stoi(monsterStats[3][5]));
                monster5.setStats(monsterStats[4][0], 5, 100, stoi(monsterStats[4][1]), stoi(monsterStats[4][2]), stoi(monsterStats[4][3]), stoi(monsterStats[4][4]), stoi(monsterStats[4][5]));
            }
        }
        if (action == 1)
        {
            //--------------CREATE A CHARACTER
            cout << "Choose a class of the character\n"
                 << "1) Mage,     2) Warior,          3) Berserker,      4)Thief\n";
            newaux = true;
            while (newaux) // repeat till the correct class is chosen
            {
                cin >> a;
                switch (a)
                {
                case 1:
                    mag.setInitialStats(obj);
                    newaux = false;
                    obj.setClass(1);
                    break;
                case 2:
                    war.setInitialStats(obj);
                    newaux = false;
                    obj.setClass(2);
                    break;
                case 3:
                    ber.setInitialStats(obj);
                    newaux = false;
                    obj.setClass(3);
                    break;
                case 4:
                    thif.setInitialStats(obj);
                    newaux = false;
                    obj.setClass(4);
                    break;
                default:
                    cout << "\nTyped a wrong number, please choose namber from 1 to 4";
                    break;
                }
            }
            cout << "Set your nick\n";
            cin >> nickname;
            obj.setNick(nickname);
            obj.toPrint();
            cout << "\n\nYou have 5 points to spread over yur character skills";
            cout << "\nChoose a statistic:   1) Strength   2)Dexterity   3) Endurance   4) Intelligence   5) Charisma";
            points = 5;
            while (points > 0) // let the user boost stats
            {
                newaux = true;
                while (newaux) // repeat till a point is spent
                {
                    cout << "\nYou have " << points << " points, choose a statistic\n";
                    cin >> b;
                    if (b == 1 || b == 2 || b == 3 || b == 4 || b == 5)
                    {
                        newaux = false;
                    }
                    else
                    {
                        cout << "\nTyped a wrong number, pleaase enter a number from 1 to 5";
                    }
                }
                obj.boostStats(b);
                points--;
            }
        }
        if (action == 1) // If you have just created new game initiate monsters
        {
            monster1.setNick("monster1");
            monster2.setNick("monster2");
            monster3.setNick("monster3");
            monster4.setNick("monster4");
            monster5.setNick("monster5");
            monster1.setLv(1);
            monster1.setRandomStats(monster1);
            monster2.setLv(2);
            monster2.setRandomStats(monster2);
            monster3.setLv(3);
            monster3.setRandomStats(monster3);
            monster4.setLv(4);
            monster4.setRandomStats(monster4);
            monster5.setLv(5);
            monster5.setRandomStats(monster5);
        }
        obj.toPrint();
        while (gamingCond == true)
        {
            while (notFighting)
            {
                cout << "\nPress 1 to view the inventory, press 2 to go shopping, press 3 to display your stats, press anything else to fight";
                cin >> in;
                switch (in)
                {
                case 1:
                    inv.displayInventory(obj, pot, inv);
                    break;
                case 2:
                    inv.buyItem(obj);
                    break;
                case 3:
                    obj.toPrint();
                    break;
                default:
                    notFighting = false;
                    break;
                }
            }

            cout << "\nPress 1-5 to choose monster level or press 0 to quit\t";
            cin >> picklv;
            switch (picklv)
            {
            case 0: // Quit the game
                gamingCond = false;
                cout << "\nEnjoy your battle stats";
                sl.showElements();
                break;
            case 1: // Fight with monster of level 1
                monster1.monsterToPrint();
                battle.charBattle(a, inv, pot, obj, mag, war, ber, thif, monster1);
                break;
            case 2: // Fight with monster of level 2
                monster2.monsterToPrint();
                battle.charBattle(a, inv, pot, obj, mag, war, ber, thif, monster2);
                break;
            case 3: // Fight with monster of level 3
                monster3.monsterToPrint();
                battle.charBattle(a, inv, pot, obj, mag, war, ber, thif, monster3);
            case 4: // Fight with monster of level 4
                monster4.monsterToPrint();
                battle.charBattle(a, inv, pot, obj, mag, war, ber, thif, monster4);
                break;
            case 5: // Fight with monster of level 5
                monster5.monsterToPrint();
                battle.charBattle(a, inv, pot, obj, mag, war, ber, thif, monster5);
                break;
            }
            if (picklv != 0) // after the battle you may wuit or continue
            {
                cout << "\nDo you wish to quit the game ? Press 0 to quit";
                cin >> quit;
                if (quit == 0)
                    gamingCond = false;
                cout << "\nEnjoy your battle stats";
                sl.showElements();
            }
        }
        cout << "\nEnjoy your battle stats";
        sl.showElements();
        monster1.monsterSetFileData(monster1, obj);
        monster2.monsterSetFileData(monster2, obj);
        monster3.monsterSetFileData(monster3, obj);
        monster4.monsterSetFileData(monster4, obj);
        monster5.monsterSetFileData(monster5, obj);
        obj.setFileData(obj);
    }
}