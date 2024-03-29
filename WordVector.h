#ifndef WORDVECTOR_H
#define WORDVECTOR_H

#include <iostream>
#include <string>
#include <vector>
#include "MyPair.h"

class WordVector
{
public:
  //**** constructors ****//
  WordVector(std::istream & inputStream);


  //**** functions    ****//
  void insert(const std::string & word);
  bool remove(const std::string & word);
  int lookup(const std::string & word) const;
  void print() const;
  int size() const;
  int sum_frequency_count() const;
  void sort();

  void operator()(const std::string word);
private:
  std::vector<MyPair<std::string, int>> wordvec;
};
#endif
