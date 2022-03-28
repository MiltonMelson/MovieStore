#include "classic.h"
#include <iostream>

Classic::Classic(int stock, string director, string title, const string &actor,
                 int month, int year) {
  this->stock = stock;
  this->director = move(director);
  this->title = move(title);
  this->actor = actor;
  this->releaseMonth = month;
  this->releaseYear = year;
  this->key = to_string(year) + actor;
  this->genre = "Classic";
} // end of constructor

void Classic::print() {
  cout << "C, " << this->stock << ", " << this->director << ", " << this->title
       << ", " << this->actor << ", " << this->releaseMonth << " "
       << this->releaseYear << endl;
} // end of print

// Classic sorted by release date and then Major Actor
bool Classic::operator>(Classic &mv) {
  if (this->releaseYear > mv.releaseYear) {
    return true;
  }
  if (this->releaseYear == mv.releaseYear) {
    if (this->releaseMonth > mv.releaseMonth) {
      return true;
    }
    if (this->releaseMonth == mv.releaseMonth) {
      if (this->actor > mv.actor) {
        return true;
      }
    }
  }
  return false;
} // end of operator >

bool Classic::operator==(Classic &mv) {
  return (this->releaseYear == mv.releaseYear &&
          this->releaseMonth == mv.releaseMonth && this->actor == mv.actor);
} // end of ==

// uses dynamic cast to comapre movie object and drama object
bool Classic::operator>(Movie &mv) {
  // returns true if this is > movie object
  auto *ptr = dynamic_cast<Classic *>(&mv);
  return *this > *ptr;
} // end of operator > dynamic casting

// uses dynamic cast to comapre movie object and drama object
bool Classic::operator<(Movie &mv) {
  // returns true if this is < movie object
  auto *ptr = dynamic_cast<Classic *>(&mv);
  return *ptr > *this;
} // end of operator < dynamic casting

// uses dynamic cast to comapre movie object and drama object
bool Classic::operator==(Movie &mv) {
  // returns true if this is == movie object
  auto *ptr = dynamic_cast<Classic *>(&mv);
  return *this == *ptr;
} // end of == dynamic casting

string Classic::getKey() const { return key; }

int Classic::getStock() const { return stock; }

void Classic::brwMovie() {
  if (stock > 0) {
    stock--;
  }
} // end of borrow movie

void Classic::rtnMovie() { stock++; }

string Classic::getTitle() const { return title; }

string Classic::getGenre() const { return genre; }

string Classic::getDirector() const { return director; }

int Classic::getReleaseYear() const { return releaseYear; }

string Classic::getActor() const { return actor; }

int Classic::getReleaseMonth() const { return releaseMonth; }