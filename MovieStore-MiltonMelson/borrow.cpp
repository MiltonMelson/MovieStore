#include "borrow.h"
#include <iostream>

// Constructor
Borrow::Borrow(Customer *cust, Movie *mv) {
  mvPtr = mv;
  custPtr = cust;
  tempStock = 0;
}

// Exectues borrow command
void Borrow::execute() {
  tempStock = 0;
  if (mvPtr->getStock() > 0) {
    custPtr->addCommand(this);     // log cmd in customers history log
    custPtr->addMovie(mvPtr);      // adds movie to customers movieList
    mvPtr->brwMovie();             // removes 1 from stock
    tempStock = mvPtr->getStock(); // stock after borrow
  } else {
    cout << "Movie out of stock: ";
    mvPtr->print();
  }
}

// prints the borrowed items
void Borrow::print() {
  cout << "  Borrowed: " << mvPtr->getGenre() << ", " << tempStock << ", "
       << mvPtr->getTitle() << ", " << mvPtr->getDirector() << endl;
}