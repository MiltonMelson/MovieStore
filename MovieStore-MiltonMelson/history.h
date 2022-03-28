#ifndef HISTORY_H
#define HISTORY_H

#include "command.h"

using namespace std;

class History : public Command {
public:
  explicit History(Customer *custPtr);
  void print() override;
  void execute() override;

private:
  Customer *custPtr;
}; // end of History
#endif