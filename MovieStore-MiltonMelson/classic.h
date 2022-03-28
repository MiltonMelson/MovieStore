#ifndef CLASSIC_H
#define CLASSIC_H

#include "movie.h"
#include <string>

using namespace std;

class Classic : public Movie {
public:
  Classic(int stock, string director, string title, const string &actor,
          int month,
          int year); // constructor

  void print() override;
  string getKey() const override;
  int getStock() const override;
  string getTitle() const override;
  string getGenre() const override;
  string getDirector() const override;
  int getReleaseYear() const override;
  void brwMovie() override;
  void rtnMovie() override;

  string getActor() const;
  int getReleaseMonth() const;

  // sort by Release date then major actor
  virtual bool operator>(Classic &mv);
  virtual bool operator==(Classic &mv);

  bool operator<(Movie &mv) override;
  bool operator>(Movie &mv) override;
  bool operator==(Movie &mv) override;

private:
  int stock;
  string genre;
  string director;
  string title;
  string actor;
  int releaseMonth;
  int releaseYear;
  // Title + year to store in BST and we can check
  // key match rather than check random properties
  string key;
}; // end of Classic
#endif