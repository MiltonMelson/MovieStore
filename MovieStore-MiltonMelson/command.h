#ifndef COMMAND_H
#define COMMAND_H

#include "movie.h"
#include "store.h"
#include <set>
#include <string>

using namespace std;

class Customer;

class Command {
public:
  // To access store class
  friend class Store;
  Command() = default;
  virtual ~Command() = default;

  virtual void print() = 0;
  virtual void execute() = 0;
  static Command *create(const string &identifier);

private:
  // Makes commands
  static Command *make(char actionType, Customer *cust, Movie *mv);
}; // end of command
#endif