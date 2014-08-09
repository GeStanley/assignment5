#ifndef WORDMAP_H
#define WORDMAP_H

#include <iostream>
#include <string>
#include <map>

class WordMap
{
public:
  //**** constructors ****//
  WordMap(std::istream & inputStream);


  //**** functions    ****//
  void insert(const std::string & word);
  bool remove(const std::string & word);
  int lookup(const std::string & word);
  void print() const;
  int size() const;
  int sum_frequency_count() const;

  //**** operators    ****//
  void operator()(const std::string word);

private:
  std::map<std::string, int> wmap;
};
#endif
