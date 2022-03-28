#include "hashtable.h"
#include <iostream>

HashMap::HashMap() {
  table = new HashElement *[TABLE_SIZE];
  for (int i = 0; i < TABLE_SIZE; i++) {
    table[i] = nullptr;
  }
} // end of constructor

HashMap::~HashMap() { clear(); }

void HashMap::clear() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (table[i] != nullptr) {
      delete table[i]->customer; // delete customer first
      delete table[i];
    }
  }
  delete[] table;
} // end of clear

int HashMap::HashFunction(int key) {
  return key % (TABLE_SIZE - 1);
} // end of hashFunction

void HashMap::insert(int key, Customer *custPtr) {
  // get hash key
  int hash = HashFunction(key);
  // search for empty spot using linear probing
  while (table[hash] != nullptr && table[hash]->key != key) {
    hash = HashFunction(hash + 1);
  }
  // if contains a duplicate
  if (table[hash] != nullptr) {
    delete table[hash];
  }
  // insert element into table.
  table[hash] = new HashElement(key, custPtr);
} // end of insert

// searchs hashmap using key and returns customer
Customer *HashMap::search(int key) {
  int hash = HashFunction(key);
  // Search for key
  while (table[hash] != nullptr && table[hash]->key != key) {
    hash = HashFunction(hash + 1);
  }
  // if not found
  if (table[hash] == nullptr) {
    return nullptr;
  }
  // Found customer
  return table[hash]->customer;
} // end of search

void HashMap::print() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (table[i] != nullptr) {
      cout << *table[i]->customer << endl;
    }
  }
} // end of print

// removes the object from the table
void HashMap::remove(int key) {
  int hash = HashFunction(key);
  while (table[hash] != nullptr && table[hash]->key != key) {
    hash = HashFunction(hash + 1);
  }
  if (table[hash] == nullptr) {
    cerr << "No Element found at key: " << key << endl;
    return;
  }
  delete table[hash];
  cout << "Element Removed" << endl;
}