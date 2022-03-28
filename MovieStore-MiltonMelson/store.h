#ifndef STORE_H
#define STORE_H

#include "classic.h"
#include "comedy.h"
#include "customer.h"
#include "drama.h"
#include "hashtable.h"
#include "movie.h"
#include <map>
#include <queue>
#include <set>
#include <string>

using namespace std;

class Command;
class HashMap;
class Store {
public:
  Store() = default;
  ~Store();

  friend class Command; // so commands can access movie and customer list

  void readMovies(const string &filename);    // reads movies
  void readCustomers(const string &filename); // reads customers
  void readCommands(const string &filename);  // reads commands
  static void printInventory();               // prints the inventory

private:
  static map<string, map<string, vector<Movie *>, greater<string>>> inventory;
  static HashMap customerList;
  static set<string> commandCodes;
  static set<string> mediaCodes;
  static set<string> movieCodes;
  static queue<Command *> commandPtrs;

  struct ComedySort {
    inline bool operator()(const Movie *mv1, const Movie *mv2) {
      if (mv1->getTitle() < mv2->getTitle()) {
        return true;
      }
      // if title is ==,compares the releaseYears
      if (mv1->getTitle() == mv2->getTitle()) {
        if (mv1->getReleaseYear() < mv2->getReleaseYear()) {
          return true;
        }
      }
      return false;
    }
  };

  struct DramaSort {
    inline bool operator()(const Movie *mv1, const Movie *mv2) {
      if (mv1->getDirector() < mv2->getDirector()) {
        return true;
      }
      if (mv1->getDirector() == mv2->getDirector()) {
        if (mv1->getTitle() < mv2->getTitle()) {
          return true;
        }
      }
      return false;
    }
  };

  struct ClassicSort {
    inline bool operator()(Movie *temp1, Movie *temp2) {
      auto *mv1 = dynamic_cast<Classic *>(temp1);
      auto *mv2 = dynamic_cast<Classic *>(temp2);
      if (mv1->getReleaseYear() < mv2->getReleaseYear()) {
        return true;
      }
      if (mv1->getReleaseYear() == mv2->getReleaseYear()) {
        if (mv1->getReleaseMonth() < mv2->getReleaseMonth()) {
          return true;
        }
        if (mv1->getReleaseMonth() == mv2->getReleaseMonth()) {
          if (mv1->getActor() < mv2->getActor()) {
            return true;
          }
        }
      }
      return false;
    }
  };

}; // end of store
#endif