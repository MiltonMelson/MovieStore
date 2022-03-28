#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>

using namespace std;

class Movie {
public:
  Movie() = default;

  static Movie *create(string mv);
  virtual void print() = 0;
  virtual bool operator>(Movie &mv) = 0;
  virtual bool operator<(Movie &mv) = 0;
  virtual bool operator==(Movie &mv) = 0;

  virtual string getKey() const = 0;
  virtual int getStock() const = 0;
  virtual string getTitle() const = 0;
  virtual string getGenre() const = 0;
  virtual string getDirector() const = 0;
  virtual int getReleaseYear() const = 0;
  virtual void brwMovie() = 0;
  virtual void rtnMovie() = 0;
}; // end of Movie
#endif