#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "WordMultiSet.h"

WordMultiSet::WordMultiSet( std::istream & an_input_stream )
{
  std::string currentWord="";

  while(an_input_stream >> currentWord)
  {
    insert(currentWord);
  }
}

void WordMultiSet::insert(const std::string & word)
{

    wordset.insert( word );
}

bool WordMultiSet::remove(const std::string & word)
{
  return 0;
}

int WordMultiSet::lookup(const std::string & word)
{
  auto p = wordset.equal_range(word);

  int count = std::distance(p.first, p.second);
  return count;
}

void printString(const std::string word)
{
  //set the tab offset from the left border
  int size=0;


  int spacing = 4 - size;

  //print out the offset
  while (spacing > 0){
    std::cout << " ";
    spacing--;
  }

  std::cout << " : " << word << std::endl;
}

void WordMultiSet::print() const
{
  for_each(wordset.begin(), wordset.end(), printString);
}

int WordMultiSet::size() const
{
  return wordset.size();
}

int WordMultiSet::sum_frequency_count() const
{
  return 0;
}
