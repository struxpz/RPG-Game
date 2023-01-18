#ifndef heroManage_cpp
#define heroManage_cpp
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>
#include "characterTemplate.cpp"
//#include "Inventory.cpp"
//#include "lists.cpp"
//#include "monsterManage.cpp"
using namespace std;
int neededEnergy = 0;
int action;
int runaway = 0, block = 0;
int a = 0, points = 0, b = 0;
int i = 0, j = 0, aux = 0, k = 0;
int aux_stats[5];
bool newaux = true;
string stats[12];
string nickname;
string tempo[12], expression[2]; // auxiliary strings
istringstream iss;
float experience = 0, levAdd = 0, newLev = 0;
int attack = 0, damage = 0, dodge = 0;
string previousNick, prevnick;
class heroManage : public characterTemplate
{
public:
    heroManage() // Default constructor
    {
        nick = "";
        level = 0;
        health = 0;
        coins = 0;
        energy = 0;
        strength = 0;
        dexterity = 0;
        endurance = 0;
        intelligence = 0;
        charisma = 0;
        luck = 0;
        clas = 0;
    }
    heroManage(string nic, int clasa, int lev, int hp, /*float*/ int coin, int ener, int lucka, int stren, int dext, int endur, int intel, int charis) // Constructor
    {
        nick = nic;
        energy = ener;
        health = hp;
        level = lev;
        coins = coin;
        strength = stren;
        dexterity = dext;
        endurance = endur;
        intelligence = intel;
        charisma = charis;
        luck = lucka;
        clas = clasa;
    }
    ~heroManage() // destructor
    {
    }

    // Getters
    const int getEnergy() const
    {
        return energy;
    }
    const int getStrength() const
    {
        return strength;
    }
    const int getDexterity() const
    {
        return dexterity;
    }
    const int getEndurance() const
    {
        return endurance;
    }
    const int getIntelligence() const
    {
        return intelligence;
    }
    const int getCharisma() const
    {
        return charisma;
    }
    const int getLuck() const
    {
        return luck;
    }
    const int getLevel() const
    {
        return level;
    }
    const int getHp() const
    {
        return health;
    }
    const string getNick() const
    {
        return nick;
    }
    const int getCoins() const
    {
        return coins;
    }
    const int getClass() const
    {
        return clas;
    }

    // Setters
    void setStats(string nic, int clasa, int levl, int helh, int cois, int energ, int lucky, int stren, int dext, int endur, int intel, int charis)
    {
        nick = nic;
        luck = lucky;
        clas = clas;
        health = helh;
        coins = cois;
        energy = energ;
        strength = stren;
        dexterity = dext;
        endurance = endur;
        intelligence = intel;
        charisma = charis;
    }
    void setEnergy(int ener)
    {
        energy = ener;
    }
    void setClass(int Clas)
    {
        clas = Clas;
    }
    void setLuck(int luk)
    {
        luck = luk;
    }
    void setStrength(int stren)
    {
        strength = stren;
    }
    void setDexterity(int dext)
    {
        dexterity = dext;
    }
    void setEndurance(int endur)
    {
        endurance = endur;
    }
    void setIntelligence(int intel)
    {
        intelligence = intel;
    }
    void setCharisma(int charis)
    {
        charisma = charis;
    }
    void setLevel(int lev)
    {
        level = lev;
    }
    void setHp(int hp)
    {
        health = hp;
    }
    void addCoins(float addCoin)
    {
        coins += addCoin;
    }
    void setNick(string nic)
    {
        nick = nic;
    }

    // methods
    void toPrint() // Printing stats
    {
        cout << "\nYour nick is: " << nick;
        cout << "\nCharacter's stats:   "
             << "level: " << level << "   Health: " << health << "   Energy: " << energy << "   Coins: " << coins << "   Luck: " << luck << "   Strength: " << strength << "   Dexterity: " << dexterity << "   Endurance: " << endurance << "   Intelligence: " << intelligence << "   Charisma: " << charisma;
    }
    void getFileData() // Loading the data from a file
    {
        ifstream file_obj;
        cout << "\nType your previous nick\n";
        // string previousNick;
        cin >> previousNick;
        prevnick = previousNick;
        previousNick = previousNick + ".txt";
        string file_path = "C:/Users/strup/Desktop/NewWork/savedCharacters/";
        previousNick = file_path + previousNick; // Estabilishing the path of the saved file
        file_obj.open(previousNick, ios::in);    // Openning the file
        if (file_obj.good())                     // if connected properly continue
        {
            cout << "\nLoading your character...";
            for (i = 0; i < 11; i++)
            {
                getline(file_obj, tempo[i]); // get each of 11 lines one by one
                iss.clear();
                iss.str(tempo[i]);
                while (iss.good())
                { // read a line word by word, and save each word into a string
                    iss >> expression[aux];
                    if (aux == 1)
                    {
                        stats[j] = expression[aux];
                        j++;
                    }
                    aux++;
                }
                aux = 0;
            }
            file_obj.close();
        }
        else
        {
            cout << "\nThere is no such character saved!\n";
            action = 1;
        }
    }

    void setFileData(heroManage &obj) // Save the game
    {
        ofstream file;
        string file_path = "C:/Users/strup/Desktop/NewWork/savedCharacters/";
        string filename = obj.getNick() + ".txt";
        filename = file_path + filename;            // set the path of the file
        file.open(filename, ios::trunc | ios::out); // If there was already a file with such name, over-write it
        file << "Nick " << obj.getNick() << "\n";
        file << "Class " << a << "\n";
        file << "Level " << obj.getLevel() << "\n";
        file << "Health " << obj.getHp() << "\n";
        file << "Coins " << obj.getCoins() << "\n";
        file << "Energy " << obj.getEnergy() << "\n";
        file << "Luck " << obj.getLuck() << "\n";
        file << "Strength " << obj.getStrength() << "\n";
        file << "Dexterity " << obj.getDexterity() << "\n";
        file << "Endurance " << obj.getEndurance() << "\n";
        file << "Intelligence " << obj.getIntelligence() << "\n";
        file << "Charisma " << obj.getCharisma() << "\n";
        file.close();
        cout << "\ngonna save hero now";
    }

    void levelUp(heroManage &obj) // Handling level upping
    {
        if (experience >= (obj.getLevel() * obj.getLevel()) * 100) // if gathered enough experience
        {
            levAdd = 0;
            for (i = 0; i < 4; i++)
            {
                if (floor(experience / (((obj.getLevel() + i) * (obj.getLevel()) + i) * 100)) > levAdd) // Find out how many levels should be added
                {
                    levAdd++;
                }
                else
                {
                    i = 5; // Leave for loop
                }
            }
            newLev = obj.getLevel() + levAdd; // Save the new level
            obj.setLevel(newLev);             // and set it to the hero
            points = 2 * levAdd;              // Allow boosting the stats of the hero
            cout << "\nYou've leveled up!\nYour current level " << newLev << "\nBoost your hero's skills";
            while (points > 0) // Boosting stats procedure
            {
                newaux = true;
                while (newaux) // Auxiliary security while
                {
                    cout << "\nYou've got " << points << " points, choose corresponding number to boost a skill";
                    cout << "\n1) Strength,   2) Dexterity,   3) Endurance,   4) Intelligence,   5) Charisma";
                    cin >> b;
                    if (b == 1 || b == 2 || b == 3 || b == 4 || b == 5) // if Security condition satisfied
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
    }
    void boostStats(int a)
    {
        switch (a)
        {
        case 1:
            setStrength(this->strength + 1);
            newaux = false;
            break;
        case 2:
            setDexterity(this->dexterity + 1);
            newaux = false;
            break;
        case 3:
            setEndurance(this->endurance + 1);
            newaux = false;
            break;
        case 4:
            setIntelligence(this->intelligence + 1);
            newaux = false;
            break;
        case 5:
            setCharisma(this->charisma + 1);
            newaux = false;
            break;
        default:
            cout << "\nTyped a wrong number, pleaase enter a number from 1 to 5";
            break;
        }
    }
    friend class mage;
    friend class warior;
    friend class berserker;
    friend class thief;
};

// Creating classes of the hero
class mage
{
public:
    void setInitialStats(heroManage &ch)
    {
        ch.setLevel(1);
        ch.setStrength(2);
        ch.setDexterity(3);
        ch.setEndurance(5);
        ch.setIntelligence(15);
        ch.setCharisma(15);
    }
    void battleAbilities(heroManage &ch) // Here all the fighting possibilites are set
    {
        newaux = true;
        neededEnergy = 0;
        while (newaux)
        {
            cout << "\nType a number from 1-2 to choose attacking method:\n1) Hit enemy with a fork (20 Energy)   2)Use a spell (60 Energy)";
            cin >> attack;
            switch (attack)
            {
            case 1:
                neededEnergy = 20;
                damage = ch.getStrength() + 10;
                // ch.setEnergy(ch.getEnergy() - (10 - ch.getEndurance())); // TRZEBA DODAĆ SPRAWDZANIE CZY WYSTARCZY ENERGIII
                dodge = 0;
                block = 0;
                newaux = false;
                if (rand() % 100 + 1 <= 1 + ch.getDexterity()) // Give a chance to dodge the next attack of the monster
                    dodge = 1;
                if (rand() % 100 + 1 <= 1 + ch.getEndurance()) // give a chance to block the next attack of the monster
                    block = 1;
                break;
            case 2:
                neededEnergy = 60;
                damage = ch.getIntelligence() + ch.getCharisma() + 50;
                // ch.setEnergy(ch.getEnergy() - (60 - ch.getCharisma() - ch.getEndurance())); // TRZEBA DODAĆ SPRAWDZANIE CZY WYSTARCZY ENERGIII
                dodge = 0;
                block = 0;
                newaux = false;
                if (rand() % 100 + 1 <= 1 + ch.getDexterity())
                    dodge = 1;
                if (rand() % 100 + 1 <= 1 + ch.getEndurance())
                    block = 1;
                break;
            default:
                cout << "\nWrong attacking method!";
                break;
            }
        }
    }
};
class warior
{
public:
    void setInitialStats(heroManage &ch)
    {
        ch.setLevel(1);
        ch.setStrength(15);
        ch.setDexterity(5);
        ch.setEndurance(7);
        ch.setIntelligence(2);
        ch.setCharisma(2);
    }
    void battleAbilities(heroManage &ch)
    {
        newaux = true;
        neededEnergy = 0;
        while (newaux)
        {
            cout << "\nType a number from 1-2 to choose attacking method:\n1) Hit enemy with bare hands (20 Energy)   2)Hit enemy with a sword (60 Energy)";
            cin >> attack;
            switch (attack)
            {
            case 1:
                neededEnergy = 20;
                damage = ch.getStrength() + 20;
                // ch.setEnergy(ch.getEnergy() - (10 - ch.getEndurance()));
                dodge = 0;
                block = 0;
                newaux = false;
                if (rand() % 100 + 1 <= 1 + ch.getDexterity())
                    dodge = 1;
                if (rand() % 100 + 1 <= 1 + ch.getEndurance())
                    block = 1;
                break;
            case 2:
                neededEnergy = 60;
                damage = ch.getStrength() + 60;
                dodge = 0;
                block = 0;
                newaux = false;
                if (rand() % 100 + 1 <= 1 + ch.getDexterity())
                    dodge = 1;
                if (rand() % 100 + 1 <= 1 + ch.getEndurance())
                    block = 1;
                break;
            default:
                cout << "\nWrong attacking method!";
                break;
            }
            dodge = 0;
            if (rand() % 100 + 1 <= 1 + ch.getDexterity())
                dodge = 1;
        }
    }
};
class berserker
{
public:
    void setInitialStats(heroManage &ch)
    {
        ch.setLevel(1);
        ch.setStrength(20);
        ch.setDexterity(4);
        ch.setEndurance(2);
        ch.setIntelligence(4);
        ch.setCharisma(2);
    }
    void battleAbilities(heroManage &ch)
    {
        newaux = true;
        neededEnergy = 0;
        while (newaux)
        {
            cout << "\nType a number from 1-2 to choose attacking method:\n1) Hit enemy with bare hands (20 Energy)    2)Berserker mode (60 Energy)";
            cin >> attack;
            switch (attack)
            {
            case 1:
                neededEnergy = 20;
                damage = ch.getStrength() + 10 + ch.getDexterity();
                dodge = 0;
                block = 0;
                newaux = false;
                if (rand() % 100 + 1 <= 1 + ch.getDexterity())
                    dodge = 1;
                if (rand() % 100 + 1 <= 1 + ch.getEndurance())
                    block = 1;
                break;
            case 2:
                neededEnergy = 60;
                damage = ch.getStrength() + 60;
                dodge = 0;
                block = 0;
                newaux = false;
                if (rand() % 100 + 1 <= 1 + ch.getDexterity())
                    dodge = 1;
                if (rand() % 100 + 1 <= 1 + ch.getEndurance())
                    block = 1;
                break;
            default:
                cout << "\nWrong attacking method!";
                break;
            }
            dodge = 0;
            if (rand() % 100 + 1 <= 1 + ch.getDexterity())
                dodge = 1;
        }
    }
};
class thief
{
public:
    void setInitialStats(heroManage &ch)
    {
        ch.setLevel(1);
        ch.setStrength(5);
        ch.setDexterity(13);
        ch.setEndurance(10);
        ch.setIntelligence(6);
        ch.setCharisma(2);
    }
    void battleAbilities(heroManage &ch)
    {
        neededEnergy = 0;
        newaux = true;
        while (newaux)
        {
            cout << "\nType a number from 1-2 to choose attacking method:\n1) Run away    2)Knife him (20 Energy)";
            cin >> attack;
            switch (attack)
            {
            case 1:
                // 0 energy needed
                runaway = 1; // An interesting method of winning a battle, covered further in the battle.cpp
                newaux = false;
                break;
            case 2:
                neededEnergy = 20;
                damage = ch.getStrength() + ch.getDexterity() + 30;
                runaway = 0;
                dodge = 0;
                block = 0;
                newaux = false;
                if (rand() % 100 + 1 <= 1 + ch.getDexterity())
                    dodge = 1;
                if (rand() % 100 + 1 <= 1 + ch.getEndurance())
                    block = 1;
                break;
            default:
                cout << "\nWrong attacking method!";
                break;
            }
        }
    }
};

#endif