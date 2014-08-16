#ifndef WORDMULTISET_H
#define WORDMULTISET_H

#include <iostream>
#include <string>
#include <set>
#include "CompareWords.h"

class WordMultiSet
{
public:
  //**** constructors ****//
  WordMultiSet(std::istream & inputStream);


  //**** functions    ****//
  void insert(const std::string & word);
  bool remove(const std::string & word);
  int lookup(const std::string & word);
  void print() const;
  int size() const;

  void operator()(const std::string word);
private:
  std::multiset<std::string, CompareWords> wordset;
};
#endif
