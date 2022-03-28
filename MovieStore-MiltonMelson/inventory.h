#ifndef INVENTORY_H
#define INVENTORY_H

#include "command.h"

using namespace std;

class Inventory : public Command {
public:
  void print() override;
  void execute() override;
}; // end of Inventory
#endif