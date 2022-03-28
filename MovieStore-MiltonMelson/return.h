#ifndef RETURN_H
#define RETURN_H

#include "command.h"

using namespace std;

class Return : public Command {
public:
  Return(Customer *custPtr, Movie *mvPtr);

  void print() override;
  void execute() override;

private:
  Movie *mvPtr;
  Customer *custPtr;
  int tempStock;
}; // end of Return
#endif