#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Thing
{
private:
public:
    std::string name;
    std::string description;

    Thing();
    Thing(std::string name, std::string desc)
    {
        name = name;
        description = desc;
    }
    virtual void PrintName()
    {
        cout << name << endl;
    }
    virtual void PrintDesc()
    {
        cout << description << endl;
    }
};

class Item : virtual public Thing
{
private:
public:
    Item();
    Item(string name, string desc) : Thing(name, desc)
    {
        // Constructor implementation (if needed)
    }

    void PrintName() override
    {
        Thing::PrintName();
    }
    void PrintDesc() override
    {
        Thing::PrintDesc();
    }
};
