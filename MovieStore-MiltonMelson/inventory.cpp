#include "inventory.h"
#include <iostream>

void Inventory::print() { cout << "Inventory: "; }

void Inventory::execute() { Store::printInventory(); }