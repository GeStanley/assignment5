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
  auto p = wordset.equal_range(word);

  if(p.first == p.second)
    return 0;
  else{
    wordset.erase(p.first, p.second);
    return true;
  }
}

int WordMultiSet::lookup(const std::string & word)
{
  auto p = wordset.equal_range(word);

  int count = std::distance(p.first, p.second);
  return count;
}

void printElement(const std::string word, const int wordSize)
{
  //set the tab offset from the left border
  int size=0;
  if(wordSize>9)
    size=2;
  else
    size=1;

  int spacing = 3 - size;

  //print out the offset
  while (spacing > 0){
    std::cout << " ";
    spacing--;
  }

  std::cout << wordSize << " : " << word << std::endl;
}

void WordMultiSet::print() const
{
  int wordSize = 0;

  std::multiset<std::string>::iterator it;
  it = wordset.begin();
  std::string previousWord = *it;


  for_each(wordset.begin(), wordset.end(),
    [&wordSize, &previousWord](std::string word)->void{
      if(previousWord==word)
      {
        ++wordSize;
      }
      else
      {
        printElement(previousWord, wordSize);
        previousWord = word;
        wordSize = 1;
      }
    });
  //print the last word in the list.
  printElement(previousWord, wordSize);
}

int WordMultiSet::size() const
{
  return wordset.size();
}
