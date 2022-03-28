#include "customer.h"
#include <iostream>

Customer::Customer() {
  customerID = 0;
  customerName = "";
} // end of constructor

Customer::Customer(int id, string name) {
  customerID = id;
  customerName = move(name);
} // end of constructor

// adds command (borrow or return) to customer command history
void Customer::addCommand(Command *cmd) { commandHistory.push(cmd); }

// adds movie to movie queue
void Customer::addMovie(Movie *mv) { movieList.push_back(mv); }

void Customer::setID(int id) { customerID = id; }

void Customer::setName(string name) { customerName = move(name); }

int Customer::getID() { return customerID; }

string Customer::getName() { return customerName; }

// prints command history
void Customer::printCommandHistory() {
  cout << *this << endl;
  queue<Command *> temp;
  while (!commandHistory.empty()) {
    commandHistory.front()->print();
    temp.push(commandHistory.front());
    commandHistory.pop();
  }
  cout << endl;
  commandHistory = temp;
} // end of printCommandHistory

// Checks if movie is rented or not
bool Customer::movieRented(Movie *mv) {
  for (auto &m : movieList) {
    if (m == mv) {
      return true;
    }
  }
  return false;
} // end of movieRented

// Returns movie and updates customers movie list
void Customer::returnMovie(Movie *mv) {
  for (auto it = movieList.begin(); it != movieList.end(); it++) {
    if (*it == mv) {
      movieList.erase(it);
      break;
    }
  }
} // end of returnMovie

// clears the command history
void Customer::clearCommandHistory() {
  while (!commandHistory.empty()) {
    commandHistory.pop();
  }
} // end of clearCommandHistory

// clears the movie list
void Customer::clearMovieList() { movieList.clear(); }

// << overload using friend class
std::ostream &operator<<(std::ostream &out, const Customer &cust) {
  out << cust.customerID << " " << cust.customerName;
  return out;
} // end of << operator