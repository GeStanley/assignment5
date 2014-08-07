#include <string>
#include <iostream>
#include "WordVector.h"

WordVector::WordVector( std::istream & inputStream )
{
  std::string currentWord="":

  while(inputStream >> currentWord)
  {
    std::cout << currentWord << std::endl;
  }
}

void WordVector::insert( const string & word )
{
  MyPair<string, int> p(word, 1);
  auto vit = find( wordvec.begin(), wordvec.end(), p);
  if(vit!=wordvec.end())
    ++vit->second;
  else
    wordvec.push_back(p);
}

bool WordVector::remove()
{
  return false;
}

int WordVector::lookup(const std::string & word) const
{
  return 0;
}

void WordVector::print() const
{}

int WordVector::size() const
{
  return 0;
}

int WordVector::sum_frequency_count() const
{
  return 0;
}

void WordVector::sort()
{
  std::sort(wordvec.begin(), wordvec.end(), MyPair<string, int>());
}
