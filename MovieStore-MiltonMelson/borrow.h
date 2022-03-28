#ifndef BORROW_H
#define BORROW_H

#include "command.h"

using namespace std;

class Borrow : public Command {
public:
  Borrow(Customer *custPtr, Movie *mvPtr);

  void print() override;
  void execute() override;

private:
  Movie *mvPtr;      // pointer for movie
  Customer *custPtr; // pointer for customer
  int tempStock;     // to capture stock at time of borrow
};                   // end of borrow
#endif