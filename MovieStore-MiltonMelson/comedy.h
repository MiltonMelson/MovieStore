#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"
#include <string>

using namespace std;

class Comedy : public Movie {

public:
  Comedy(int stock, string director, const string &title, int year);

  void print() override;
  string getKey() const override;
  int getStock() const override;
  string getTitle() const override;
  string getGenre() const override;
  string getDirector() const override;
  int getReleaseYear() const override;
  void brwMovie() override;
  void rtnMovie() override;
  bool operator<(Movie &mv) override;
  bool operator>(Movie &mv) override;
  bool operator==(Movie &mv) override;

  virtual bool operator>(Comedy &cm);
  virtual bool operator==(Comedy &cm);

private:
  int stock;
  string director;
  string title;
  int releaseYear;
  // Title + year
  string key;
  string genre;
}; // end of comedy
#endif