#ifndef battle_cpp
#define battle_cpp
#include <iostream>
#include "heroManage.cpp"
#include "monsterManage.cpp"
#include "lists.cpp"
#include "items.cpp"
#include "Inventory.cpp"
using namespace std;
float itemDropRate = 0;
TsingleList sl;
lst_el *p;
bool gamingCond = true;
bool notFighting = true;
int picklv = 0;
int quit = 1;
string monster_array[5] = {"monster1", "monster2", "monster3", "monster4", "monster5"};
template <class T>
class battleSim
{
    T statHolder[5][2];

public:
    battleSim() {}
    int battle_iter = 1;
    int sum[2] = {0, 0}, i = 0, j = 0;
    T compare(heroManage &obj, monsters &monster);
    T charBattle(int a, invent &inv, Potion &pot, heroManage &obj, mage &mag, warior &war, berserker &ber, thief &thif, monsters &mon);
};

template <class T>
T battleSim<T>::charBattle(int a, invent &inv, Potion &pot, heroManage &obj, mage &mag, warior &war, berserker &ber, thief &thif, monsters &mon)
{
    while (obj.getHp() > 0 && mon.getMonsterHp() > 0)
    {
        switch (obj.getClass())
        {
        case 1: // Class: MAGE
            cout << "\nMonster's HP: " << mon.getMonsterHp();
            cout << "\nHero's HP: " << obj.getHp() << "   Hero's energy: " << obj.getEnergy();
            in = 1;
            while (in == 1)
            {
                cout << "\nDo you want to use a potion ? Press 1 to enter inventory, or anything else to continue";
                cin >> in;
                if (in == 1)
                    inv.displayPotions(obj, pot); // Display potions and let the hero drink a potion
            }
            mag.battleAbilities(obj);                // choosing the attacking method of the hero
            if (obj.getEnergy() - neededEnergy >= 0) // if enough energy for the desired attack
            {                                        // Attack the opponent
                obj.setEnergy(obj.getEnergy() - neededEnergy);
                cout << "\nDamage = " << damage - (mon.getMonsterEndurance());
                damage = damage - (mon.getMonsterEndurance()); // estabilishing the damage
                mon.setHp(mon.getMonsterHp() - damage);        // giving damage to the monster
                cout << "\nMonster's hp = " << mon.getMonsterHp();
            }
            else
            {
                cout << "\nYou'have not enough energy for the desired attack, you have to rest!";
            }

            if (mon.getMonsterHp() > 0) // if monster is not dead
            {
                if (obj.getEnergy() + 20 < 101)          // Hero cannot gather more than 100 energy by himself, to do this he needs certain items
                    obj.setEnergy(obj.getEnergy() + 20); // Restore some energy
                else if (obj.getEnergy() + 20 > 100)
                    obj.setEnergy(100);
                if (dodge == 0) // if hero cannot dodge
                {
                    if (block == 0) // if hero cannot block
                    {
                        mon.monsterBattleAbilities(mon); // the monster gonna attack
                        cout << "\nDamage = " << damage - (obj.getEndurance());
                        damage = damage - (obj.getEndurance());
                        obj.setHp(obj.getHp() - damage); // serving damage to the hero
                        cout << "\nHero's hp = " << obj.getHp();
                    }
                    else if (block == 1)
                        cout << "\nYou blocked monster's attack";
                }
                else if (dodge == 1)
                {
                    cout << "\nMonster tried to hit you but you managed to make a dodge";
                }
                cout << "\nRestoring some energy...";
            }
            break;
        case 2: // Class: WARIOR
            cout << "\nMonster's HP: " << mon.getMonsterHp();
            cout << "\nHero's HP: " << obj.getHp() << "   Hero's energy: " << obj.getEnergy();
            in = 1;
            while (in == 1)
            {
                cout << "\nDo you want to use a potion ? Press 1 to enter inventory, or anything else to continue";
                cin >> in;
                if (in == 1)
                    inv.displayPotions(obj, pot); // Display potions and let the hero drink a potion
            }
            war.battleAbilities(obj);
            if (obj.getEnergy() - neededEnergy >= 0) // if enough energy for the desired attack
            {                                        // Attack the opponent
                obj.setEnergy(obj.getEnergy() - neededEnergy);
                cout << "\nDamage = " << damage - (mon.getMonsterEndurance());
                damage = damage - (mon.getMonsterEndurance());
                mon.setHp(mon.getMonsterHp() - damage);
                cout << "\nMonster's hp = " << mon.getMonsterHp();
            }
            else
            {
                cout << "\nYou'have not enough energy for the desired attack, you have to rest!";
            }
            if (mon.getMonsterHp() > 0)
            {
                if (obj.getEnergy() + 20 < 101)          // Hero cannot gather more than 100 energy by himself, to do this he needs certain items
                    obj.setEnergy(obj.getEnergy() + 20); // Restore some energy
                else if (obj.getEnergy() + 20 > 100)
                    obj.setEnergy(100);
                if (dodge == 0)
                {
                    if (block == 0)
                    {
                        mon.monsterBattleAbilities(mon);
                        cout << "\nDamage = " << damage;
                        damage = damage - (obj.getEndurance());
                        obj.setHp(obj.getHp() - damage);
                        cout << "\nHero's hp = " << obj.getHp();
                    }
                    else if (block == 1)
                        cout << "\nYou blocked monster's attack";
                }
                else if (dodge == 1)
                {
                    cout << "\nMonster tried to hit you but you managed to make a dodge";
                }
                cout << "\nRestoring some energy...";
            }
            break;
        case 3: // Class: BERSERKER
            cout << "\nMonster's HP: " << mon.getMonsterHp();
            cout << "\nHero's HP: " << obj.getHp() << "   Hero's energy: " << obj.getEnergy();
            in = 1;
            while (in == 1)
            {
                cout << "\nDo you want to use a potion ? Press 1 to enter inventory, or anything else to continue";
                cin >> in;
                if (in == 1)
                    inv.displayPotions(obj, pot); // Display potions and let the hero drink a potion
            }
            ber.battleAbilities(obj);
            if (obj.getEnergy() - neededEnergy >= 0) // if enough energy for the desired attack
            {                                        // Attack the opponent
                obj.setEnergy(obj.getEnergy() - neededEnergy);
                cout << "\nDamage = " << damage - (mon.getMonsterEndurance());
                damage = damage - (mon.getMonsterEndurance());
                mon.setHp(mon.getMonsterHp() - damage);
                cout << "\nMonster's hp = " << mon.getMonsterHp();
            }
            else
            {
                cout << "\nYou'have not enough energy for the desired attack, you have to rest!";
            }
            if (mon.getMonsterHp() > 0)
            {
                if (obj.getEnergy() + 20 < 101)          // Hero cannot gather more than 100 energy by himself, to do this he needs certain items
                    obj.setEnergy(obj.getEnergy() + 20); // Restore some energy
                else if (obj.getEnergy() + 20 > 100)
                    obj.setEnergy(100);
                if (dodge == 0)
                {
                    if (block == 0)
                    {
                        mon.monsterBattleAbilities(mon);
                        cout << "\nDamage = " << damage - (obj.getEndurance());
                        damage = damage - (obj.getEndurance());
                        obj.setHp(obj.getHp() - damage);
                        cout << "\nHero's hp = " << obj.getHp();
                    }
                    else if (block == 1)
                        cout << "\nYou blocked monster's attack";
                }
                else if (dodge == 1)
                {
                    cout << "\nMonster tried to hit you but you managed to make a dodge";
                }
                cout << "\nRestoring some energy...";
            }
            break;
        case 4: // Class: THIEF
            cout << "\nMonster's HP: " << mon.getMonsterHp();
            cout << "\nHero's HP: " << obj.getHp() << "   Hero's energy: " << obj.getEnergy();
            in = 1;
            while (in == 1)
            {
                cout << "\nDo you want to use a potion ? Press 1 to enter inventory, or anything else to continue";
                cin >> in;
                if (in == 1)
                    inv.displayPotions(obj, pot); // Display potions and let the hero drink a potion
            }
            thif.battleAbilities(obj);
            if (runaway == 1 && obj.getDexterity() + obj.getEndurance() + obj.getIntelligence() >= mon.getMonsterDexterity() + mon.getMonsterEndurance() + mon.getMonsterIntelligence() && rand() % 10 + 1 > 5)
            {                 // If you have enough dexterity endurance and inteligence and some luck, as a thief you are able to run away from the battlefield and therefore win the battle and get drop
                damage = 100; // You've run away, congrats
                dodge = 0;
                cout << "\nCongrats, you run away!";
                cout << "\nDamage = " << damage - (mon.getMonsterEndurance());
                mon.setHp(mon.getMonsterHp() - damage);
                cout << "\nMonster's hp = " << mon.getMonsterHp();
            }
            else if (runaway == 1)
            { // If you didn't satisfied the previous condition you are given a better chance of dodging the next attack of the monster
                runaway = 0;
                dodge = 1; // get a 75% chance to make a dodge on the next move of your opponent
                if (rand() % 4 + 1 == 1)
                    dodge = 0;
            }
            else if (runaway == 0)
            {                                            // HERO ATTACKs
                if (obj.getEnergy() - neededEnergy >= 0) // if enough energy for the desired attack
                {                                        // Attack the opponent
                    obj.setEnergy(obj.getEnergy() - neededEnergy);
                    cout << "\nDamage = " << damage - (mon.getMonsterEndurance());
                    damage = damage - (mon.getMonsterEndurance());
                    mon.setHp(mon.getMonsterHp() - damage);
                    cout << "\nMonster's hp = " << mon.getMonsterHp();
                }
                else
                {
                    cout << "\nYou'have not enough energy for the desired attack, you have to rest!";
                }
            }

            if (mon.getMonsterHp() > 0)
            {
                if (obj.getEnergy() + 20 < 101)          // Hero cannot gather more than 100 energy by himself, to do this he needs certain items
                    obj.setEnergy(obj.getEnergy() + 20); // Restore some energy
                else if (obj.getEnergy() + 20 > 100)
                    obj.setEnergy(100);
                if (runaway == 0) // If you didn't manage to escape the battlefield, the monster gonna attack
                {
                    if (dodge == 0)
                    {
                        if (block == 0)
                        {
                            mon.monsterBattleAbilities(mon);
                            cout << "\nDamage = " << damage - (obj.getEndurance());
                            damage = damage - (obj.getEndurance());
                            obj.setHp(obj.getHp() - damage);
                            cout << "\nHero's hp = " << obj.getHp();
                        }
                        else if (block == 1)
                            cout << "\nYou blocked monster's attack";
                    }
                    else if (dodge == 1)
                    {
                        cout << "\nYou made a dodge";
                    }
                }
                cout << "\nRestoring some energy...";
            }
            break;
        }
        if (obj.getHp() <= 0) // checking if hero's still alive
        {
            if (obj.getEnergy() < 100)
                obj.setEnergy(100);
            notFighting = true;
            drunk = false;
            pot.resetEffect(pot);      // if present, reset beer effect, if not it leaves the stats as they were before
            pot.drinkPotion(obj, pot); // set the previous stats
            cout << "\n/-/-/-/-/-/-/-/-Opppp you lost!/-/-/-/-/-/-/-/-/-/-/-/";
            cout << "\nYou lost " << ceil((float)obj.getLevel() / (float)mon.getMonsterLevel() * 100) << " experience";
            experience -= ceil(((float)obj.getLevel() / (float)mon.getMonsterLevel() * 100)); // subtract experience
            if (experience < 0)
                experience = 0;
            // Saving the battle result into the list carrying battle statistics
            p = new lst_el;
            p->key = battle_iter;
            p->name = "You lost against " + monster_array[picklv - 1];
            sl.push_head(p);
            obj.setHp(100);
            battle_iter++;
            break;
        }
        else if (mon.getMonsterHp() <= 0)
        {
            if (obj.getEnergy() < 100)
                obj.setEnergy(100);
            notFighting = true;
            cout << "\n----------------------Oppa you've won!-----------------------";
            cout << "\nYou won " << 100 * ((float)mon.getMonsterLevel() / (float)obj.getLevel()) << " experience";
            experience += ceil(100 * (float)(mon.getMonsterLevel() / (float)obj.getLevel())); // add experience
            obj.addCoins(ceil(150 * (float)(mon.getMonsterLevel() / (float)obj.getLevel()))); // coins dropped
            obj.setHp(100);
            //-------------ITEM DROPPING CHANCE
            // cout << "\nHey you may drop some items";
            itemDropRate = rand() % 101;
            if (obj.getLuck() == 0)
            {
                if (itemDropRate < 20)
                    cout << "\nNo drop this time :(";
                else if (itemDropRate >= 20 && itemDropRate < 30)
                {
                    dl.change_amount("Beer", 1);
                    cout << "\nBeer - a drink of luck dropped";
                }
                else if (itemDropRate >= 30 && itemDropRate < 55)
                {
                    dl.change_amount("Health_Potion", 1);
                    cout << "\nHealth_Potion dropped";
                }
                else if (itemDropRate >= 55 && itemDropRate < 75)
                {
                    // drop redbull
                    dl.change_amount("RedBull", 1);
                    cout << "\nRedBull dropped";
                }
                else if (itemDropRate >= 75 && itemDropRate < 85)
                {
                    // drop something else
                    dl.change_amount("Great_Health_Potion", 1);
                    cout << "\nGreat_Health_Potion dropped !";
                }
                else if (itemDropRate >= 85 && itemDropRate < 92)
                {
                    // drop big health potion
                    dl.change_amount("Great_RedBull", 1);
                    cout << "\nGreat_RedBull dropped";
                }
                else if (itemDropRate >= 92 && itemDropRate < 97)
                {
                    // drop big redbull
                    dl.change_amount("Shield", 1);
                    cout << "\nShield dropped";
                }
                else if (itemDropRate >= 97 && itemDropRate < 100)
                {
                    // drop rare item
                    dl.change_amount("Armour", 1);
                    cout << "\nArmour dropped";
                }
                else if (itemDropRate == 100)
                {
                    // drop legendary item
                    dl.change_amount("Shoes", 1);
                    cout << "\nShoes dropped";
                }
                cout << "\nCoins dropped " << ceil(150 * ((float)mon.getMonsterLevel() / (float)obj.getLevel()));
            }
            else
            { // You drunk a beer, you have a better dropping rate
                cout << "\nA beer gives you a greater chance to drop rare items!";
                if (itemDropRate < 2)
                    cout << "\nNo drop this time :(";
                else if (itemDropRate >= 2 && itemDropRate < 15)
                {
                    dl.change_amount("Beer", 1);
                    cout << "\nBeer - a drink of luck dropped";
                }
                else if (itemDropRate >= 15 && itemDropRate < 40)
                {
                    dl.change_amount("Health_Potion", 1);
                    cout << "\nHealth_Potion dropped";
                }
                else if (itemDropRate >= 40 && itemDropRate < 60)
                {
                    dl.change_amount("RedBull", 1);
                    cout << "\nRedBull dropped";
                }
                else if (itemDropRate >= 60 && itemDropRate < 75)
                {
                    dl.change_amount("Great_Health_Potion", 1);
                    cout << "\nGreat_Health_Potion dropped !";
                }
                else if (itemDropRate >= 75 && itemDropRate < 85)
                {
                    dl.change_amount("Great_RedBull", 1);
                    cout << "\nGreat_RedBull dropped";
                }
                else if (itemDropRate >= 85 && itemDropRate < 92)
                {
                    dl.change_amount("Shield", 1);
                    cout << "\nShield dropped";
                }
                else if (itemDropRate >= 92 && itemDropRate < 97)
                {
                    dl.change_amount("Armour", 1);
                    cout << "\nArmour dropped";
                }
                else if (itemDropRate >= 97 && itemDropRate <= 100)
                {
                    dl.change_amount("Shoes", 1);
                    cout << "\nShoes dropped";
                }
                cout << "\nCoins dropped " << ceil((150 + 50) * ((float)mon.getMonsterLevel() / (float)obj.getLevel()));
                pot.resetEffect(pot); // CANCEL BEER EFFECT
                pot.drinkPotion(obj, pot);
                cout << "\nLuck: " << obj.getLuck();
                drunk = false;
            }
            obj.levelUp(obj);
            // Saving the battle result into the list carrying battle statistics
            p = new lst_el;
            p->key = battle_iter;
            p->name = "You won against " + monster_array[picklv - 1];
            sl.push_head(p);

            battle_iter++;
            break;
        }
    }
    mon.setHp(100);
    mon.setRandomStats(mon);
}
#endif