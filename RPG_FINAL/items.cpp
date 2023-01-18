#ifndef items_cpp
#define items_cpp
#include <string>
#include <iostream>
#include "heroManage.cpp"
using namespace std;
string items[2][8] = {{"Beer", "Health_Potion", "RedBull", "Great_Health_Potion", "Great_RedBull", "Shield", "Armour", "Shoes"}, {"100", "100", "120", "300", "400", "1000", "8000", "15000"}};

// This class handles setting stats of all the items, don't be fooled with its name
class Potion
{
private:
    int item_hp;
    int item_strength;
    int item_dexterity;
    int item_endurance;
    int item_intelligence;
    int item_charisma;
    int item_energy;
    int item_luck;

public:
    Potion() // Condtructor
    {
        item_hp = 0;
        item_strength = 0;
        item_dexterity = 0;
        item_endurance = 0;
        item_intelligence = 0;
        item_charisma = 0;
        item_energy = 0;
        item_luck = 0;
    }
    ~Potion() // destructor
    {
        // cout << "\nPotion used";
    }
    // Setters
    void setStreng(int str)
    {
        item_strength = str;
    }
    void setEndur(int endura)
    {
        item_endurance = endura;
    }
    void setDext(int dextr)
    {
        item_dexterity = dextr;
    }
    void setInte(int intl)
    {
        item_intelligence = intl;
    }
    void setChari(int chr)
    {
        item_charisma = chr;
    }
    void setHp(int hp)
    {
        item_hp = hp;
    }
    void setEner(int ener)
    {
        item_energy = ener;
    }
    void setLuck(int luck)
    {
        item_luck = luck;
    }
    // Getters
    const int getEner() const
    {
        return item_energy;
    }
    const int getStreng() const
    {
        return item_strength;
    }
    const int getEndur() const
    {
        return item_endurance;
    }
    const int getDext() const
    {
        return item_dexterity;
    }
    const int getInte() const
    {
        return item_intelligence;
    }
    const int getHp() const
    {
        return item_hp;
    }
    const int getChar() const
    {
        return item_charisma;
    }
    const int getLuck() const
    {
        return item_luck;
    }
    void toPrint()
    {
        cout << "\nPotion stats:   "
             << "   Health: " << item_hp << "   Strength: " << item_strength << "   Dexterity: " << item_dexterity << "   Endurance: " << item_endurance << "   Intelligence: " << item_intelligence << "   Charisma: " << item_charisma;
    }
    void resetEffect(Potion &pot) // the method handes reseting the effect of a beer after a battle
    {
        pot.setHp(0);
        pot.setEndur(1);
        pot.setStreng(1);
        pot.setInte(1);
        pot.setDext(1);
        pot.setChari(1);
        pot.setEner(10);
        pot.setLuck(0);
    }
    void setPotionStats(string PotionName, Potion &pot, heroManage &obj) // Don't be fooled with the name, the method handles statistics of all the items
    {
        if (PotionName == items[0][0]) // Beer - increase your chance to get an item; gives between 1 - 2 times greater chance to drop each item comparing to the state without the effect of beer 
        {//At the same time beer reduces your battle abilities
            pot.setHp(0);
            pot.setInte(-1);
            pot.setStreng(-1);
            pot.setEndur(-1);
            pot.setDext(-1);
            pot.setChari(-1);
            pot.setEner(-10);
            pot.setLuck(50);
        }
        else if (PotionName == items[0][1]) // Health potion- gives 20HP
        {
            pot.setHp(20);
            pot.setEndur(0);
            pot.setStreng(0);
            pot.setInte(0);
            pot.setDext(0);
            pot.setChari(0);
            pot.setEner(0);
            pot.setLuck(0);
        }
        else if (PotionName == items[0][2]) // RedBull - restores 40 energy points 
        {
            pot.setHp(0);
            pot.setEndur(0);
            pot.setStreng(0);
            pot.setInte(0);
            pot.setDext(0);
            pot.setChari(0);
            pot.setEner(40);
            pot.setLuck(0);
        }
        else if (PotionName == items[0][3]) // Great health potion - restores 50HP
        {
            pot.setHp(50);
            pot.setEndur(0);
            pot.setStreng(0);
            pot.setInte(0);
            pot.setDext(0);
            pot.setChari(0);
            pot.setEner(0);
            pot.setLuck(0);
        }
        else if (PotionName == items[0][4]) // Redbull - restores all energy
        {
            pot.setHp(0);
            pot.setEndur(0);
            pot.setStreng(0);
            pot.setInte(0);
            pot.setDext(0);
            pot.setChari(0);
            pot.setEner(100);
            pot.setLuck(0);
        }
        else if (PotionName == items[0][5]) // Shield- reduces obtained damage
        {
            pot.setHp(0);
            pot.setEndur(15);
            pot.setStreng(0);
            pot.setInte(0);
            pot.setDext(0);
            pot.setChari(0);
            pot.setEner(0);
            pot.setLuck(0);
        }
        else if (PotionName == items[0][6]) // Armour - reduces obtained damage, and boosts some other battle abilities
        {
            pot.setHp(0);
            pot.setEndur(20);
            pot.setStreng(3);
            pot.setInte(3);
            pot.setDext(3);
            pot.setChari(0);
            pot.setEner(0);
            pot.setLuck(0);
        }
        else if (PotionName == items[0][7]) // Shoes - gives basicaly unlimited energy, boosts ability of dodging and other stats
        {
            pot.setHp(0);
            pot.setEndur(5);
            pot.setStreng(5);
            pot.setInte(10);
            pot.setDext(30);
            pot.setChari(5);
            pot.setEner(10000);
            pot.setLuck(0);
        }
    }
    void drinkPotion(heroManage &obj, Potion &pot) // Once again, the method is responsible for using all the items
    {
        obj.setStrength(obj.getStrength() + pot.getStreng());
        obj.setIntelligence(obj.getIntelligence() + pot.getInte());
        obj.setDexterity(obj.getDexterity() + pot.getDext());
        obj.setEndurance(obj.getEndurance() + pot.getEndur());
        obj.setCharisma(obj.getCharisma() + pot.getChar());
        // obj.setEnergy(obj.getEnergy() + pot.getEner());
        if (pot.getHp() > 0)
        {
            if (obj.getHp() + pot.getHp() > 100 && pot.getHp() > 0)
            {//Max healh points = 100
                obj.setHp(100);
                cout << "\nHero's HP" << obj.getHp();
            }
            else if (obj.getHp() + pot.getHp() <= 100 && pot.getHp() > 0)
            {
                obj.setHp(obj.getHp() + pot.getHp());
                cout << "\nHero's HP" << obj.getHp();
            }
        }
        if (pot.getEner() > 0)
        {//We allow hero to have more than 100 energy points
                obj.setEnergy(obj.getEnergy() + pot.getEner());
                cout << "\nHero's energy: " << obj.getEnergy();
        }
        obj.setLuck(pot.getLuck());
    }
};
#endif