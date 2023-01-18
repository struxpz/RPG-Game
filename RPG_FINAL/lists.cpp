#ifndef lists_cpp
#define lists_cpp

#include <sstream>
#include <iostream>
#include <string>
#include "heroManage.cpp"
#include "items.cpp"
bool empty;
using namespace std;
string Item;
bool drunk = false;
bool potionek = false;
int RbIter = 0;
int iterat = 0;
struct lst_el
{
    lst_el *next;
    int key;
    string name;
};

class TsingleList
{
    lst_el *head, *tail;
    int cnt;

public:
    TsingleList()
    {
        head = tail = NULL;
        cnt = 0;
    }
    ~TsingleList()
    {
        lst_el *el;
        while (head)
        {
            el = head->next;
            delete head;
            head = el;
        }
    }
    // Method returning list size
    unsigned size()
    {
        return cnt;
    }
    // Method adding an element at the front of the list
    lst_el *push_head(lst_el *el)
    {
        el->next = head;
        head = el;
        if (!tail)
            tail = head;
        cnt++;
        return head;
    }
    // Method adding an element at the end of the list
    lst_el *push_tail(lst_el *el)
    {
        if (tail)
            tail->next = el;
        el->next = NULL;
        tail = el;
        if (!head)
            head = tail;
        cnt++;
        return tail;
    }
    // Method adding an element (el1) after an element (el2)
    lst_el *insert(lst_el *el1, lst_el *el2)
    {
        el1->next = el2->next;
        el2->next = el1;
        if (!(el1->next))
            tail = el1;
        cnt++;
        return el1;
    }
    // Method deleting the first element of the list
    lst_el *rmHead()
    {
        lst_el *el;
        if (head)
        {
            el = head;
            head = head->next;
            if (!head)
                tail = NULL;
            cnt--;
            return el;
        }
        else
            return NULL;
    }
    // Method deleting the last element of the list
    lst_el *rmTail()
    {
        lst_el *el;
        if (tail)
        {
            el = tail;
            if (el == head)
                head = tail = NULL;
            else
            {
                tail = head;
                while (tail->next != el)
                    tail = tail->next;
                tail->next = NULL;
            }
            cnt--;
            return el;
        }
        else
            return NULL;
    }
    // Method deleting the el element of the list
    lst_el *erase(lst_el *el)
    {
        lst_el *el1;
        if (el == head)
            return rmHead();
        else
        {
            el1 = head;
            while (el1->next != el)
                el1 = el1->next;
            el1->next = el->next;
            if (!(el1->next))
                tail = el1;
            cnt--;
            return el;
        }
    }
    // Method returns nth element of the list
    lst_el *index(int n)
    {
        lst_el *el;
        if ((!n) || (n > cnt))
            return NULL;
        else if (n == cnt)
            return tail;
        else
        {
            el = head;
            while (--n)
                el = el->next;
            return el;
        }
    }
    // Methods used to display data stored in the list
    void showKeys()
    {
        lst_el *el;
        if (!head)
            cout << "List is empty." << endl;
        else
        {
            el = head;
            while (el)
            {
                cout << el->key << " ";
                el = el->next;
            }
            cout << endl;
        }
    }
    void showNames()
    {
        lst_el *el;
        if (!head)
            cout << "List is empty." << endl;
        else
        {
            el = head;
            while (el)
            {
                cout << el->name << " ";
                el = el->next;
            }
            cout << endl;
        }
    }
    void showElements()
    {
        lst_el *el;
        if (!head)
            cout << "List is empty." << endl;
        else
        {
            el = head;
            while (el)
            {
                cout << "\nBattle: " << el->key << "    " << el->name;
                el = el->next;
            }
            cout << endl;
        }
    }
};

struct node//node def
{   //let all the nodes carry two pieces of information; nick(info), amount(amount_info)
    string info;
    int amount_info;
    struct node *next;
    struct node *prev;
} * start;

class double_llist
{
public:
    void create_list(string item_name, int item_amount) // create a list by adding the first element, and its amount
    {
        struct node *s, *temp;
        temp = new (struct node);
        temp->info = item_name; //using pointer to save the item information
        temp->amount_info = item_amount;
        temp->next = NULL;
        if (start == NULL)
        {
            temp->prev = NULL;
            start = temp;
        }
        else
        {
            s = start;
            while (s->next != NULL)
                s = s->next;
            s->next = temp;
            temp->prev = s;
        }
    }

    void add_begin(string item_name, int item_amount)//Add an element at the beginning of the list
    {
        if (start == NULL)
        {
            cout << "First Create the list." << endl;
            return;
        }
        struct node *temp;
        temp = new (struct node);//Create new node
        temp->prev = NULL;
        temp->info = item_name;//Set the name
        temp->amount_info = item_amount;//Set amount
        temp->next = start;
        start->prev = temp;
        start = temp;//Set the node as the beginning of the list
    }
    void add_after(string item_name, int item_amount, int pos)//Adding a node just after a certaing node
    {
        if (start == NULL)
        {
            cout << "First Create the list." << endl;
            return;
        }
        struct node *tmp, *q;
        int i;
        q = start;
        for (i = 0; i < pos - 1; i++)//checking if the inserted number is smaller or equal to the number of nodes in the list
        {
            q = q->next;
            if (q == NULL)
            {
                cout << "There are less than ";
                cout << pos << " elements." << endl;
                return;
            }
        }
        tmp = new (struct node);
        tmp->info = item_name;
        tmp->amount_info = item_amount;
        if (q->next == NULL)//if the element after the inputed node is empty, set a new node
        {
            q->next = tmp;
            tmp->next = NULL;
            tmp->prev = q;
        }
        else//if not, insert a new node between the two nodes
        {
            tmp->next = q->next;
            tmp->next->prev = tmp;
            q->next = tmp;
            tmp->prev = q;
        }
    }
    void change_amount(string item_name, int add)
    {
        struct node *tmp, *q;
        /*Changing amount of the first element*/
        if (start->info == item_name)
        {
            tmp = start;
            tmp->amount_info += add;
            return;
        }
        q = start;
        while (q->next->next != NULL)
        {
            /*Changing amount of an item in between*/
            if (q->next->info == item_name)
            {
                tmp = q->next;

                tmp->amount_info += add;
                return;
            }
            q = q->next;
        }
        /*Changing amount of the last element*/
        if (q->next->info == item_name)
        {
            tmp = q->next;
            tmp->amount_info += add;
            // cout << "Item added to inventory" << endl;
            return;
        }
        cout << "Element " << item_name << " not found" << endl;
    }

    //display inventory
    void display_dlist()
    {
        struct node *q;
        cout << "\nYour inventory :   ";
        if (start == NULL)
        {
            cout << "is empty !\n";
            empty = true;
            return;
        }
        q = start;
        int iterat = 0;
        while (q != NULL)//while a node is not empty
        {
            if (q->info != "start" && q->amount_info != 0)//Do not display the starting node, and do not display an element if its amount is 0
            {
                iterat++;
                cout << iterat << ")  " << q->info << "   " << q->amount_info << ",   ";
                empty = false;
            }
            q = q->next;//point to the next element
        }
        if (iterat == 0)//if the list is empty
        {
            cout << "is empty !";
            empty = true;
        }
    }
    void display_potions()//Display items available to use durring battle
    {
        struct node *q;
        cout << "\nYour potions :   ";
        if (start == NULL)
        {
            empty = true;//No items available
            return;
        }
        q = start;//Point to the start of the list
        int iterat = 0;
        while (q != NULL)//while node is not empty
        {
            if (q->info != "start" && q->amount_info != 0)//if node isn't a starting node , and the saved amount is not 0
            {
                if (q->info == "Health_Potion" || q->info == "RedBull" || q->info == "Great_Health_Potion" || q->info == "Great_RedBull")//Look only for potions
                {
                    iterat++;
                    cout << iterat << ")  " << q->info << "   " << q->amount_info << ",   ";
                    empty = false;
                }
            }
            q = q->next;
        }
        if (iterat == 0)
            empty = true;//Empty list of potions
    }
    void getAmount(string name)//Find how many pieces of an item you have
    {
        struct node *q;
        if (start == NULL)
        {
            cout << "unavailable" << endl;
            return;
        }
        q = start;
        iterat = 0;
        if (name == "Shield" || name == "Armour" || name == "Shoes")
        {
            while (q != NULL)
            {
                if (q->info == name && iterat == 0)
                {
                    cout << "\nItem: " << name << "   amount: " << q->amount_info;
                    iterat++;
                }
                q = q->next;
            }
        }
    }
    void search_And_Use_Item(string name, heroManage &obj, Potion &pot, double_llist &dl)//USE ITEM WHEN NOT FIGHTING (potions cannot be used, except beer)
    {
        struct node *q;
        if (start == NULL)
        {
            cout << "unavailable" << endl;
            return;
        }
        q = start;
        iterat = 0;
        if (name == "Shield" || name == "Armour" || name == "Shoes")
        {
            while (q != NULL)
            {
                if (q->info != "start" && q->amount_info != 0)
                {
                    if (q->info == name)
                    {
                        iterat++;
                        pot.setPotionStats(name, pot, obj);
                        pot.drinkPotion(obj, pot);
                        dl.change_amount(name, -1);
                        cout << "\nUsing " << name;
                        obj.toPrint();
                    }
                }
                q = q->next;
            }
        }
        else if (name == "Beer" && drunk == false)//If item = Beer, then we need to check if the hero has already drunk 1 beer, because we allow only 1 beer per battle, so that the hero is not to lucky :)
        {
            while (q != NULL)
            {
                if (q->info != "start" && q->amount_info != 0)
                {
                    if (q->info == name)
                    {
                        iterat++;
                        pot.setPotionStats(name, pot, obj);
                        pot.drinkPotion(obj, pot);
                        dl.change_amount(name, -1);
                        cout << "\nUsing " << name;
                        drunk = true;
                        obj.toPrint();
                    }
                }
                q = q->next;
            }
        }
        else if (name == "Beer" && drunk == true)
        {
            cout << "\nYou can't drink more than 1 beer!";
            potionek = true;
        }
        else if (name == "Health_Potion" || name == "Great_Health_Potion" || name == "RedBull" || name == "Great_RedBull")
        {
            cout << "\nYou can't drink health potions or energy drinks when not fighting";
            potionek = true;
        }
        if (iterat == 0 && potionek == false)
            cout << "unavailable";//You have typed a wrong item name, or simply you do not have it
    }
    void search_And_Use_Potion(string name, heroManage &obj, Potion &pot, double_llist &dl)//USE ITEM WHEN FIGHTING (Only potions may be used)
    {
        struct node *q;
        if (start == NULL)
        {
            cout << "unavailable" << endl;
            return;
        }
        q = start;
        int iterat = 0;
        if (name == "Health_Potion" || name == "RedBull" || name == "Great_Health_Potion" || name == "Great_RedBull")//If item is a potion, let it be drunk
        {
            while (q != NULL)
            {
                if (q->info != "start" && q->amount_info != 0)
                {
                    if (q->info == name)
                    {
                        iterat++;
                        pot.setPotionStats(name, pot, obj);
                        pot.drinkPotion(obj, pot);
                        dl.change_amount(name, -1);
                    }
                }
                q = q->next;
            }
        }
        if (iterat == 0)
            cout << "unavailable";
    }
    double_llist()
    {
        start = NULL;
    }
};

#endif