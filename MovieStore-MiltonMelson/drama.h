#ifndef DRAMA_H
#define DRAMA_H

#include "movie.h"
#include <string>

using namespace std;

class Drama : public Movie {
public:
  Drama(int stock, const string &director, const string &title, int year);

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

  // sort by director then title
  virtual bool operator>(Drama &dm);
  virtual bool operator==(Drama &dm);

private:
  int stock;
  string director;
  string title;
  int releaseYear;
  // Title + year == key
  string key;
  string genre;
}; // end of Drama
#endif