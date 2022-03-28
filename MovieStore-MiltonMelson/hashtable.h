#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "customer.h"

using namespace std;

class Customer;

#define TABLE_SIZE 100

class HashElement {
public:
  int key;            // key to store in the hash table
  Customer *customer; // pointer to the customer
  // constructor to initialize customer pointer and key
  HashElement(int ky, Customer *cust) {
    key = ky;
    customer = cust;
  }
};

class HashMap {
public:
  HashMap();
  ~HashMap();
  int HashFunction(int key);
  void insert(int key, Customer *custPtr);
  Customer *search(int key);
  void remove(int key);
  void print();
  void clear();

private:
  HashElement **table;
}; // end of hashtable
#endif