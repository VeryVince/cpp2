
// This program displays the contents of the inventory file.
#include <iostream>
#include <fstream>
using namespace std;
const int DESC_SIZE = 31; // Description size
// Declaration of InventoryItem structure
struct InventoryItem
{
    char desc[DESC_SIZE];
    int qty;
    double price;
};

int main()
{
    system("explorer C:\\");

    return 0;
}
