#include "store.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

// initialize static variables in store
set<string> Store::commandCodes = {"B", "R", "I", "H"}; // NOLINT
set<string> Store::mediaCodes = {"D"};                  // NOLINT
set<string> Store::movieCodes = {"C", "D", "F"};        // NOLINT
queue<Command *> Store::commandPtrs;                    // NOLINT
HashMap Store::customerList;                            // NOLINT
map<string, map<string, vector<Movie *>, greater<string>>>
    Store::inventory; // NOLINT

Store::~Store() {
  while (!commandPtrs.empty()) {
    delete commandPtrs.front();
    commandPtrs.pop();
  }
} // end of destructor

// reads movies
void Store::readMovies(const string &filename) {
  ifstream fs(filename);
  string input = " ";
  if (fs.is_open()) {
    while (getline(fs, input)) {
      Movie *mvPtr = Movie::create(input);
      if (mvPtr != nullptr) {
        string code = input.substr(0, 1);
        inventory["D"][code].push_back(mvPtr);
      }
      input = " ";
    }
  } else {
    cerr << "Could not open file: " << filename;
  }
  fs.close();
}

// reads customers from file, adds customers to hashtable
void Store::readCustomers(const string &filename) {
  ifstream fs(filename);
  string input;
  stringstream ss;
  int custId = 0;
  string custName = " ";

  if (fs.is_open()) {
    while (getline(fs, input)) {
      ss << input;
      ss >> custId;
      ss.get(); // get space before name
      getline(ss, custName);
      // check if customer is in list
      if (customerList.search(custId) == nullptr) {
        Customer *cust = nullptr;
        cust = new Customer(custId, custName);
        customerList.insert(custId, cust);
        input = " ";
        custId = 0;
        custName = " ";
        ss.clear();
      }
    }
  } else {
    cerr << "Could not open file: " << filename;
  }
  fs.close();
}

// reads commands
void Store::readCommands(const string &filename) {
  ifstream fs(filename);
  string input;

  if (fs.is_open()) {
    while (getline(fs, input)) {
      Command *cmd = Command::create(input);
      if (cmd != nullptr) {
        commandPtrs.push(cmd);
      }
    }
    input = "";
  } else {
    cerr << "Could not open file: " << filename;
  }
  fs.close();
}

void Store::printInventory() {
  sort(inventory["D"]["F"].begin(), inventory["D"]["F"].end(), ComedySort());
  sort(inventory["D"]["D"].begin(), inventory["D"]["D"].end(), DramaSort());
  sort(inventory["D"]["C"].begin(), inventory["D"]["C"].end(), ClassicSort());
  cout << "Inventory: " << endl;
  for (auto &media : inventory) {
    cout << "\nMedia Type: " << media.first << endl;
    for (auto &type : media.second) {
      cout << "\n          ";
      cout << "Movie Genre: " << type.first << endl;
      for (auto &mv : type.second) {
        cout << "               ";
        mv->print();
      }
    }
  }
  cout << endl;
} // end of printInventory