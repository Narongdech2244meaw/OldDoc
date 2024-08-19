#include "Item.cpp"
#include "Player.cpp"
using namespace std;

int main()
{
    // Set up all required things. (playr, and item)
    Player player;
    Item *rock = new Item("Rock", "A sturdy rock");
    Item *pen = new Item("Pen", "A ballpoint pen");
    Item *paper = new Item("Paper", "Sheets of paper");

    // 1. check empthy inventory
    cout << "==============================================" << endl;
    cout << "1. Empthy inventory" << endl;
    cout << "==============================================" << endl;
    player.PrintInventory();
    cout << endl;

    // 2. Add items to the player's inventory then print
    cout << "==============================================" << endl;
    cout << "2. Inventory after deleting items:" << endl;
    cout << "==============================================" << endl;
    player.Inventory["rock"] = rock;
    player.Inventory["pen"] = pen;
    player.Inventory["paper"] = paper;
    player.PrintInventory();
    cout << endl;

    // 3. Remove and delete an item directly from the player's inventory
    cout << "==============================================" << endl;
    cout << "2. Inventory after adding items:" << endl;
    cout << "==============================================" << endl;
    cout << "Before ==>" << endl;
    cout << "Inventory size: " << player.Inventory.size() << endl;
    player.PrintInventory();
    player.Inventory.erase("pen"); // erase by key - other way https://www.geeksforgeeks.org/map-erase-function-in-c-stl/

    cout << "After ==>" << endl;
    cout << "Inventory size: " << player.Inventory.size() << endl;
    player.PrintInventory();
    cout << "<End>";

    return 0;
}