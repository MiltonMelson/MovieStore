#include "command.h"
#include "borrow.h"
#include "history.h"
#include "inventory.h"
#include "return.h"
#include "store.h"
#include <iostream>
#include <sstream>
#include <string>

Command *Command::create(const string &identifier) {
  int custNum = 0;
  char actionCode = ' ';
  string movieCode = " ";
  string mediaCode = " ";
  int month = 0;
  int year = 0;
  string title = " ";
  string actor = " ";
  string actFirst = " ";
  string actLast = " ";
  string director = " ";
  stringstream ss(identifier);
  Command *cmd = nullptr;

  ss >> actionCode;

  // if inventory action code
  if (actionCode == 'I') {
    return make(actionCode, nullptr, nullptr);
  }

  // check customer
  ss >> custNum;
  Customer *customer = Store::customerList.search(custNum);
  if (customer == nullptr) {
    cerr << "Customer ID: " << custNum << " is not valid" << endl;
    return nullptr; // return error if customer does not exist
  }

  // if history action code
  if (actionCode == 'H') {
    return make(actionCode, customer, nullptr);
  }

  // if return or borrow action codes
  if (actionCode == 'B' || actionCode == 'R') {
    ss >> mediaCode; // check mediaType exists
    if (Store::mediaCodes.count(mediaCode) == 1) {
      ss >> movieCode;
      ss.get(); // get space after movieCode
      if (movieCode == "C") {
        ss >> month >> year;
        ss.get(); // get space after year
        getline(ss, actFirst, ' ');
        getline(ss, actLast, '\r');
        ss.get(); // get carrige return
        actor = actFirst + " " + actLast;
        string yr = to_string(year);

        bool test = false;
        for (auto &m : Store::inventory[mediaCode][movieCode]) {
          if (m->getKey() == (yr + actor)) {
            cmd = make(actionCode, customer, m);
            test = true;
          }
        }
        if (!test) {
          cerr << "The movie, " << actor;
          cerr << ", " << yr << " does not exist" << endl;
        }
      } else if (movieCode == "D") {
        getline(ss, director, ',');
        ss.get(); // remove comma from ss
        getline(ss, title, ',');

        bool test = false;
        for (auto &m : Store::inventory[mediaCode][movieCode]) {
          if (m->getKey() == (director + title)) {
            cmd = make(actionCode, customer, m);
            test = true;
          }
        }
        if (!test) {
          cerr << "The movie, " << movieCode << ": " << title;
          cerr << " " << director << " does not exist" << endl;
        }
      } else if (movieCode == "F") {
        getline(ss, title, ',');
        ss >> year;
        string yr = to_string(year);

        bool test = false;
        for (auto &m : Store::inventory[mediaCode][movieCode]) {
          if (m->getKey() == (title + yr)) {
            cmd = make(actionCode, customer, m);
            test = true;
          }
        }
        if (!test) {
          cerr << "The movie, " << movieCode << ": " << title;
          cerr << " " << yr << " does not exist" << endl;
        }
      } else {
        cerr << movieCode << " is an invalid genre" << endl;
      }
    } else {
      cerr << mediaCode << " is an invalid mediaType" << endl;
    }
  } else {
    cerr << actionCode << " is an invalid command code" << endl;
  }
  return cmd;
}

// Makes commands
Command *Command::make(char actionType, Customer *cust, Movie *mv) {
  Command *cmd = nullptr;
  // switch statement to see the type of command
  switch (actionType) {
  case 'B': {
    cmd = new Borrow(cust, mv);
    cmd->execute();
    break;
  }
  case 'R': {
    cmd = new Return(cust, mv);
    cmd->execute();
    break;
  }
  case 'I': {
    cmd = new Inventory();
    cmd->execute();
    break;
  }
  case 'H': {
    cmd = new History(cust);
    cmd->execute();
    break;
  }
  default:
    cout << "Invalid Action Code" << endl;
  }
  return cmd;
} // end of make
