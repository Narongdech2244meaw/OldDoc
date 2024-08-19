#pragma once
#include <iostream>
#include <string>
#include <map>
#include "Item.cpp"
using namespace std;
class Player
{
public:
    Player()
    {
    }

        std::map<std::string, Thing *> Inventory;
    void PrintInventory()
    {
        if (Inventory.size() != 0)
        {
            cout << "Your inventory contains:" << endl;
            for (map<string, Thing *>::iterator it = Inventory.begin(); it != Inventory.end(); ++it)
            {
                it->second->PrintName();
                it->second->PrintDesc();
                cout << endl;
            }
        }
        else
            cout << "Your inventory is empty\n";
    }
};