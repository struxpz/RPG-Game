#ifndef Inventory_cpp
#define Inventory_cpp

#include "lists.cpp"
#include "heroManage.cpp"
#include "items.cpp"

double_llist dl;
int t = 0;
string ItemName;
int in = 0;
int stop = 0;
// This class handles displaying inventory and buying items
class invent
{
public:
    void createList() // initiating the inventory
    {
        dl.create_list("start", 0);
        dl.add_begin(items[0][0], 0);
        dl.add_begin(items[0][1], 0);
        dl.add_begin(items[0][2], 0);
        dl.add_begin(items[0][3], 0);
        dl.add_begin(items[0][4], 0);
        dl.add_begin(items[0][5], 0);
        dl.add_begin(items[0][6], 0);
        dl.add_begin(items[0][7], 0);
    }
    void buyItem(heroManage &obj)
    {
        cout << "\nShop  :\n";
        stop = 0;
        while (stop != 1)
        {
            for (t = 0; t < 8; t++)
                cout << t + 1 << ") " << items[0][t] << "  -  " << items[1][t] << " coins   ";
            cout << "\nYour coins: " << obj.getCoins();
            cout << "\nType a corresponding number to buy an item, or type 0 to leave";
            cin >> in;
            switch (in)
            {
            case 0: // Leaving criterion
                stop = 1;
                break;
            case 1: // Beer
                if (obj.getCoins() >= stoi(items[1][0]))
                {
                    obj.addCoins(-stoi(items[1][0]));
                    dl.change_amount(items[0][0], 1); // save an item to the inventory and change it's amount
                    cout << "You purchased : " << items[0][0];
                }
                else
                    cout << "\nYou can't afford such an item";
                break;
            case 2: // Health pot
                if (obj.getCoins() >= stoi(items[1][1]))
                {
                    obj.addCoins(-stoi(items[1][1]));
                    dl.change_amount(items[0][1], 1);
                    cout << "You purchased : " << items[0][1];
                }
                else
                    cout << "\nYou can't afford such an item";
                break;
            case 3: // Redbull
                if (obj.getCoins() >= stoi(items[1][2]))
                {
                    obj.addCoins(-stoi(items[1][2]));
                    dl.change_amount(items[0][2], 1);
                    cout << "You purchased : " << items[0][2];
                }
                else
                    cout << "\nYou can't afford such an item";
                break;
            case 4: // Great health pot
                if (obj.getCoins() >= stoi(items[1][3]))
                {
                    obj.addCoins(-stoi(items[1][3]));
                    dl.change_amount(items[0][3], 1);
                    cout << "You purchased : " << items[0][3];
                }
                else
                    cout << "\nYou can't afford such an item";
                break;
            case 5: // Legendary redbull
                if (obj.getCoins() >= stoi(items[1][4]))
                {
                    obj.addCoins(-stoi(items[1][4]));
                    dl.change_amount(items[0][4], 1);
                    cout << "You purchased : " << items[0][4];
                }
                else
                    cout << "\nYou can't afford such an item";
                break;
            case 6: // shield
                if (obj.getCoins() >= stoi(items[1][5]))
                {
                    obj.addCoins(-stoi(items[1][5]));
                    dl.change_amount(items[0][5], 1);
                    cout << "You purchased : " << items[0][5];
                }
                else
                    cout << "\nYou can't afford such an item";
                break;
            case 7: // armour
                if (obj.getCoins() >= stoi(items[1][6]))
                {
                    obj.addCoins(-stoi(items[1][6]));
                    dl.change_amount(items[0][6], 1);
                    cout << "You purchased : " << items[0][6];
                }
                else
                    cout << "\nYou can't afford such an item";
                break;
            case 8: // shoes
                if (obj.getCoins() >= stoi(items[1][7]))
                {
                    obj.addCoins(-stoi(items[1][7]));
                    dl.change_amount(items[0][7], 1);
                    cout << "You purchased : " << items[0][7];
                }
                else
                    cout << "\nYou can't afford such an item";
                break;
            default:
                stop = 1;
                cout << "\nYou left the shop, by typing a wrong number!";
                break;
            }
            if (stop != 1)
            {
                cout << "\nPress 0 to leave the shop or anything else to order again";
                cin >> in;
                if (in == 0)
                    stop = 1;
            }
        }
    }
    void displayInventory(heroManage &obj, Potion &pot, invent &inv)
    {
        dl.display_dlist(); // Displaying inventory
        if (empty == false)
        {
            cout << "\nPlease type a name of an item to use it, or press 0 to exit inventory";
            cin >> ItemName;
            cout << "\n Your item  " << ItemName;
            dl.search_And_Use_Item(ItemName, obj, pot, dl);
        }
        else
        {
            cout << "\nYou have no items in your inventory!";
        }
    }
    void displayPotions(heroManage &obj, Potion &pot) // A method of displaying items available and allowed to use durring the battle
    {
        dl.display_potions();
        if (empty == false)
        {
            cout << "\nPlease type a name of an item to use it, or press 0 to exit inventory";
            cin >> ItemName;
            cout << "\n Your item  " << ItemName;
            dl.search_And_Use_Potion(ItemName, obj, pot, dl);
            if (ItemName == "0")
            {
                in = 0;
            }
        }
        else
        {
            cout << "\nYou have no items in your inventory!";
            in = 0;
        }
    }
};

#endif