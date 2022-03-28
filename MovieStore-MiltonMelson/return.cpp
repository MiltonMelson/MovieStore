#include "return.h"
#include <iostream>

Return::Return(Customer *cust, Movie *mv) {
  mvPtr = mv;
  custPtr = cust;
  tempStock = 0;
} // end of constructor

void Return::print() {
  cout << "  Returned: " << mvPtr->getGenre() << ", " << tempStock << ", "
       << mvPtr->getTitle() << ", " << mvPtr->getDirector() << endl;
} // end of print

void Return::execute() {
  tempStock = 0; // reset stock before execute
  if (custPtr->movieRented(mvPtr)) {
    // Make customer return movie
    custPtr->returnMovie(mvPtr);
    // log command in customer command history
    custPtr->addCommand(this);
    // adds 1 to movie stock
    mvPtr->rtnMovie();
    tempStock = mvPtr->getStock(); // stock after return
  }
} // end of execute