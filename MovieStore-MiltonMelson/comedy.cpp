#include "comedy.h"
#include <iostream>

Comedy::Comedy(int stock, string director, const string &title, int year) {
  this->stock = stock;
  this->director = move(director);
  this->title = title;
  this->releaseYear = year;
  this->key = title + to_string(year);
  this->genre = "Comedy";
} // end of constructor

// prints the object
void Comedy::print() {
  cout << "F, " << this->stock << ", " << this->director << ", " << this->title
       << ", " << this->releaseYear << endl;
} // end of print

// Sort by Title, then year it released
bool Comedy::operator>(Comedy &cm) {
  // compares the titles
  if (this->title > cm.title) {
    return true;
  }
  // if title is ==,compares the releaseYears
  if (this->title == cm.title) {
    if (this->releaseYear > cm.releaseYear) {
      return true;
    }
  }
  return false;
} // end of > operator

// returns true if the title and the releaseYear are same
bool Comedy::operator==(Comedy &cm) {
  return (this->title == cm.title && this->releaseYear == cm.releaseYear);
} // end of == operator

// uses dynamic cast to comapre movie object and drama object
bool Comedy::operator>(Movie &mv) {
  // returns true if this is > movie object
  auto *ptr = dynamic_cast<Comedy *>(&mv);
  return *this > *ptr;
} // end of > dynamic casting

// uses dynamic cast to comapre movie object and drama object
bool Comedy::operator<(Movie &mv) {
  // returns true if this is < movie object
  auto *ptr = dynamic_cast<Comedy *>(&mv);
  return *ptr > *this;
} // end of < dynamic casting

// uses dynamic cast to comapre movie object and drama object
bool Comedy::operator==(Movie &mv) {
  // returns true if this is = movie object
  auto *ptr = dynamic_cast<Comedy *>(&mv);
  return *this == *ptr;
} // end of == dynamic casting

std::string Comedy::getKey() const { return key; }

int Comedy::getStock() const { return stock; }

// borrows movie and decreases stock
void Comedy::brwMovie() {
  if (stock > 0) {
    stock--;
  }
} // end of borrow movie

// returns movie and increases stock
void Comedy::rtnMovie() { stock++; } // end of return movie

std::string Comedy::getTitle() const { return title; }

std::string Comedy::getGenre() const { return genre; }

std::string Comedy::getDirector() const { return director; }

int Comedy::getReleaseYear() const { return releaseYear; }