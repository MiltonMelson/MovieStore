/**
 * Driver for starting movie store tests
 */

#include "store.h"
#include <iostream>

using namespace std;

// forward declaration, implementation in store_test.cpp
void testAll();

int main() {
  testAll();
  Store st;
  st.readCustomers("data4customers.txt");
  st.readMovies("data4movies.txt");
  st.readCommands("data4commands.txt");

  return 0;
}
