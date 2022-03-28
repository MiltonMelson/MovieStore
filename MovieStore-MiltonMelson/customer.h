#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "command.h"
#include "movie.h"
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Command;

class Customer {
public:
  Customer();
  Customer(int id, string name);
  void setID(int id);
  void setName(string name);
  string getName();
  int getID();
  void addCommand(Command *cmd); // adds commands
  void addMovie(Movie *mv);      // adds movies
  bool movieRented(Movie *mv);   // checks if movie is rented
  void returnMovie(Movie *mv);   // returns movie

  void printCommandHistory(); // prints the command history
  void clearCommandHistory(); // clears command history
  void clearMovieList();      // clears movie list

  friend ostream &operator<<(ostream &out, const Customer &cust);

private:
  int customerID;                  // customer ID
  string customerName;             // customer name
  vector<Movie *> movieList;       // movie list
  queue<Command *> commandHistory; // command history
};                                 // end of customer
#endif