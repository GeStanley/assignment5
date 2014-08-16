#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "WordMultiSet.h"

WordMultiSet::WordMultiSet( std::istream & an_input_stream )
{
  std::istream_iterator<std::string> start(an_input_stream), finish;
  *this = for_each(start, finish, *this);
}

void WordMultiSet::insert(const std::string & word)
{
    wordset.insert( word );
}

bool WordMultiSet::remove(const std::string & word)
{
  //find the range equal to word
  auto p = wordset.equal_range(word);

  if(p.first == p.second)
    return 0; //nothing found
  else{
    wordset.erase(p.first, p.second); //remove the entire range
    return true;
  }
}

int WordMultiSet::lookup(const std::string & word)
{
  //find the range equal to word
  auto p = wordset.equal_range(word);

  //count the amount of elements
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
      { //the words are equals. increase count.
        ++wordSize;
      }
      else
      { //the word changed. print the previous word
        //and it's size
        printElement(previousWord, wordSize);
        //change previous word
        previousWord = word;
        //restart the count
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

//function operator to insert a word into the map.
//used by the constructor
void WordMultiSet::operator()(const std::string word)
{
  insert(word);
}
