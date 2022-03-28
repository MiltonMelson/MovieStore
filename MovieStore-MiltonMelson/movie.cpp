#include "movie.h"
#include "classic.h"
#include "comedy.h"
#include "drama.h"
#include <iostream>
#include <sstream>
#include <string>

Movie *Movie::create(string mv) {
  Movie *mov = nullptr;
  char movieType = mv[0];

  switch (movieType) {
  case 'C': {
    stringstream ss(mv);
    int stock = 0;
    string junk = " ";
    getline(ss, junk, ' ');
    ss >> stock;
    getline(ss, junk, ' ');
    string director = " ";
    getline(ss, director, ',');
    ss.get();
    string title = " ";
    getline(ss, title, ',');
    getline(ss, junk, ' ');
    string actorF = " ";
    string actorL = " ";
    string actorFullName = " ";
    getline(ss, actorF, ' ');
    getline(ss, actorL, ' ');
    actorFullName = actorF + " " + actorL;
    int month = 0;
    ss >> month;
    int year = 0;
    ss >> year;
    mov = new Classic(stock, director, title, actorFullName, month, year);
    break;
  }
  case 'D': {
    stringstream ss(mv);
    int stock = 0;
    string junk = " ";
    getline(ss, junk, ' ');
    ss >> stock;
    getline(ss, junk, ' ');
    string director = " ";
    getline(ss, director, ',');
    ss.get();
    string title = " ";
    getline(ss, title, ',');
    getline(ss, junk, ' ');
    int year = 0;
    ss >> year;

    mov = new Drama(stock, director, title, year);
    break;
  }
  case 'F': {
    stringstream ss(mv);
    int stock = 0;
    string junk = " ";
    getline(ss, junk, ' ');
    ss >> stock;
    getline(ss, junk, ' ');
    string director = " ";
    getline(ss, director, ',');
    ss.get();
    string title = " ";
    getline(ss, title, ',');
    getline(ss, junk, ' ');
    int year = 0;
    ss >> year;

    mov = new Comedy(stock, director, title, year);
    break;
  }
  default:
    return mov;
  }
  return mov;
}
