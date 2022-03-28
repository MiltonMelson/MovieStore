#include "history.h"
#include <iostream>

History::History(Customer *cust) { custPtr = cust; }

void History::print() { cout << "History: " << custPtr->getName(); }

void History::execute() { custPtr->printCommandHistory(); }