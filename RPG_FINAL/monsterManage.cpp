#include "characterTemplate.cpp"
#include "heroManage.cpp"
#ifndef monsterManage_cpp
#define monsterManage_cpp
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <direct.h>

int iter = 0, iteration = 0, att = 0;
using namespace std;
string monsterStats[5][6];
string tempor [7];
string monsterExpression[2];
int monsterAux = 0;
class monsters : characterTemplate
{
    int i = 0;
    int j = 0;

public:
//setters
    void setStats(string nic, int lev, int hp, int stren, int dext, int endur, int intel, int charis)
    {
        nick = nic;
        health = hp;
        level = lev;
        strength = stren;
        dexterity = dext;
        endurance = endur;
        intelligence = intel;
        charisma = charis;
    }
    void setNick(string nic)
    {
        nick = nic;
    }
    void setHp(int hp)
    {
        health = hp;
    }
    void setLv(int lv){
        level = lv;
    }
    //Getters
    const int getMonsterStrength() const
    {
        return this->strength;
    }
    const int getMonsterDexterity() const
    {
        return this->dexterity;
    }
    const int getMonsterEndurance() const
    {
        return this->endurance;
    }
    const int getMonsterIntelligence() const
    {
        return this->intelligence;
    }
    const int getMonsterCharisma() const
    {
        return this->charisma;
    }
    const string getMonsterNick() const
    {
        return this->nick;
    }
    const int getMonsterHp() const
    {
        return this->health;
    }
    const int getMonsterLevel() const{
        return level;
    }
    const string getNick() const
    {
        return nick;
    }
    //Methods
    void monsterGetFileData(string nickN)//Load monsters from a file
    {
        ifstream file_obj;
        string monsterki[5];
        string file_path = "C:/Users/strup/Desktop/NewWork/Monsters/";
        monsterki[0] = "_monster1";
        monsterki[1] = "_monster2";
        monsterki[2] = "_monster3";
        monsterki[3] = "_monster4";
        monsterki[4] = "_monster5";

        monsterki[iter] = nickN + monsterki[iter] + ".txt";
        monsterki[iter] = file_path + monsterki[iter];//estabilish files paths
        file_obj.open(monsterki[iter], ios::in);
        if (file_obj.good())
        {
            cout << "\nLoading monsters...";
            action = 2;
            for (k = 0; k < 7; k++)
            {
                getline(file_obj, tempor[k]);
                iss.clear();
                iss.str(tempor[k]);
                while (iss.good())
                { // read a line word by word
                    iss >> monsterExpression[monsterAux];
                    if (monsterAux == 1)
                    {
                        monsterStats[iter][j] = monsterExpression[monsterAux];
                        j++;
                    }
                    monsterAux++;
                }
                monsterAux = 0;
            }
        }
        else
        {
            cout << "\nThere are no monsters saved!\n";
            action = 1;
        }
        file_obj.close();
        iter++;
    }
    void monsterSetFileData(monsters &monster, heroManage &obj)//Saving monsters
    {
        cout << "\ngonna save some mosters now";
        ofstream file;
        string filename, objname;
        string file_path = "C:/Users/strup/Desktop/NewWork/Monsters/";
        objname = obj.getNick() + "_";
        filename = monster.getNick() + ".txt"; // = nick_monster + ".txt";
        filename = file_path + objname + filename;//Setting the full file path
        file.open(filename, ios::trunc | ios::out);
        file << "Nick " << monster.getMonsterNick() << "\n";
        file << "Level " << monster.getMonsterLevel() << "\n";
        file << "Strength " << monster.getMonsterStrength() << "\n";
        file << "Dexterity " << monster.getMonsterDexterity() << "\n";
        file << "Endurance " << monster.getMonsterEndurance() << "\n";
        file << "Intelligence " << monster.getMonsterIntelligence() << "\n";
        file << "Charisma " << monster.getMonsterCharisma() << "\n";
        file.close();
    }
    void monsterBattleAbilities(monsters &mon)//Attack generator for monsters
    {
        att = rand() % 2 + 1;
        switch (att)
        {
        case 1:
            damage = mon.getMonsterStrength() + 20; // KICK
            cout << "\nYou've been kicked by the monster";
            break;
        case 2:
            damage = mon.getMonsterStrength() + 60; // BITE THE OPPONENT
            cout << "\nThe monster has taken a bite of you";
            break;
        }
    }
    void setRandomStats(monsters & mon)//Setting randoms stats for the monsters
    {
        this->health = 100;
        this->strength = rand() % 10 + 1 + ((rand() % 5 +1) * mon.getMonsterLevel());
        this->dexterity = rand() % 10 + 1 + ((rand() % 5 +1) * mon.getMonsterLevel());
        this->endurance = rand() % 10 + 1 + ((rand() % 5 +1) * mon.getMonsterLevel());
        this->intelligence = rand() % 10 + 1 + ((rand() % 5 +1) * mon.getMonsterLevel());
        this->charisma = rand() % 10 + 1 + ((rand() % 5 +1) * mon.getMonsterLevel());
        iteration++;
    }
    void monsterToPrint()
    {
        cout << "\nA monster appears!";
        cout << "\nThese are his stats: "
             << "Level: " << this->level << "   Health: " << this->health << "   Strength: " << this->strength << "   Dexterity: " << this->dexterity << "   Endurance: " << this->endurance << "   Intelligence: " << this->intelligence << "    Charisma: " << this->charisma;
    }
    friend class thief;
};
#endif