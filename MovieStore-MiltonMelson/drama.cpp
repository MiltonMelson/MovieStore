#include "drama.h"
#include <iostream>

Drama::Drama(int stock, const string &director, const string &title, int year) {
  this->stock = stock;
  this->director = director;
  this->title = title;
  this->releaseYear = year;
  this->key = director + title;
  this->genre = "Drama";
} // end of constructor

void Drama::print() {
  cout << "D, " << this->stock << ", " << this->director << ", " << this->title
       << ", " << this->releaseYear << endl;
} // end of print

// Sort by Director then title
bool Drama::operator>(Drama &dm) {
  if (this->director > dm.director) {
    return true;
  }
  if (this->director == dm.director) {
    if (this->title > dm.title) {
      return true;
    }
  }
  return false;
} // end of > operator

bool Drama::operator==(Drama &dm) {
  return (this->director == dm.director && this->title == dm.title);
} // end of ==

// uses dynamic cast to compare movie object and drama object
bool Drama::operator>(Movie &mv) {
  // returns true if this is > movie object
  auto *ptr = dynamic_cast<Drama *>(&mv);
  return *this > *ptr;
} // end of operator >

// uses dynamic cast to compare movie object and drama object
bool Drama::operator<(Movie &mv) {
  // returns true if this is < movie object
  auto *ptr = dynamic_cast<Drama *>(&mv);
  return *ptr > *this;
} // end of <

// uses dynamic cast to compare movie object and drama object
bool Drama::operator==(Movie &mv) {
  // returns true if this is == movie object
  auto *ptr = dynamic_cast<Drama *>(&mv);
  return *this == *ptr;
} // end of ==

void Drama::brwMovie() {
  if (stock > 0) {
    stock--;
  }
} // end of borrow movie

void Drama::rtnMovie() { stock++; }

std::string Drama::getTitle() const { return title; }

std::string Drama::getGenre() const { return genre; }

std::string Drama::getDirector() const { return director; }

int Drama::getReleaseYear() const { return releaseYear; }

std::string Drama::getKey() const { return key; }

int Drama::getStock() const { return stock; }