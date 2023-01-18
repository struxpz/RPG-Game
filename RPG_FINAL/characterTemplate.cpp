#ifndef characterTemplate_cpp
#define characterTemplate_cpp

using namespace std;
#include <string>

class characterTemplate
{
protected:
    string nick;
    int health;
    int strength;
    int dexterity;
    int endurance;
    int intelligence;
    int charisma;
    int level;
    float coins;
    int energy;
    int luck;
    int clas;

public:
    characterTemplate() {}
    characterTemplate(string nick, int clas, int level, int hp, int coin, int energy, int luck, int strength, int dexterity, int endurance, int intelligence, int charisma) {}
    virtual ~characterTemplate() {}

    virtual const int getStrength(){};
    virtual const int getDexterity(){};
    virtual const int getEndurance(){};
    virtual const int getIntelligence(){};
    virtual const int getCharisma(){};
    virtual const int getLevel(){};
    virtual const int getHp(){};
    virtual const int getCoins(){};
    virtual const int getLuck(){};
    virtual const int getClass(){};
    virtual const string getNick(){};

    virtual void setStats(string nick, int clas, int level, int Helh, int cois, int energ, int lucky, int stren, int dext, int endur, int intel, int charis){};
    virtual void setStrength(int strength){};
    virtual void setClass(int clase){};
    virtual void setDexterity(int dexterity){};
    virtual void setEndurance(int endurance){};
    virtual void setIntelligence(int intelligence){};
    virtual void setCharisma(int charisma){};
    virtual void setLevel(int level){};
    virtual void setNick(string nick){};
    virtual void setLuck(int luck){};
    virtual void setHp(int hp){};
    virtual void addCoins(int addCoin){};

    virtual void toPrint(){};
    virtual void getFileData(){};
    virtual void setFileData(){};
    virtual void monsterGetFileData(){};
    virtual void monsterSetFileData(){};
    virtual void save(){};
    virtual void load(){};
    virtual void boostStats(){};
    virtual void setRandomStats(){};
    virtual void monsterToPrint(){};
    virtual void charBattle(){};
};
#endif