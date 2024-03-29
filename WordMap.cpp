#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "WordMap.h"

WordMap::WordMap( std::istream & an_input_stream )
{
  std::istream_iterator<std::string> start(an_input_stream), finish;
  *this = for_each(start, finish, *this);
}

void WordMap::insert(const std::string & word)
{
  std::map<std::string, int>::iterator mit;

  //determine if the word is already in the map
  mit = wmap.find( word );

  if(mit!=wmap.end())
    ++mit->second;//add one to the count
  else
    //if it doesn't exist insert it with a count of 1
    wmap.insert( std::pair<std::string, int>(word, 1) );
}

bool WordMap::remove(const std::string & word)
{
  std::map<std::string, int>::iterator mit;

  //find a matching string in the map
  mit = wmap.find( word );

  if(mit==wmap.end())
    return false; //return false if nothing found
  else
  {
    wmap.erase(mit); //erase the found element
    return true;//return true
  }
}

int WordMap::lookup(const std::string & word)
{
  std::map<std::string, int>::iterator mit;

  //find a matching string in the map
  mit = wmap.find( word );

  if(mit==wmap.end())
    return 0; //return 0 if nothing found
  else
    return mit->second; //return the matched word
}

void printPair(std::pair<std::string, int> p)
{
  //set the tab offset from the left border
  int size=0;
  if(p.second>9)
    size=2;
  else
    size=1;

  int spacing = 3 - size;

  //print out the offset
  while (spacing > 0){
    std::cout << " ";
    spacing--;
  }

  std::cout << p.second << " : " << p.first << std::endl;
}

void WordMap::print() const
{
  for_each(wmap.begin(), wmap.end(), printPair);
}

int WordMap::size() const
{
  return wmap.size();
}

int WordMap::sum_frequency_count() const
{
  int total=0;

  for_each(wmap.begin(), wmap.end(),
    //lamba that adds up all the values
    [&total](std::pair<std::string, int> p)
    ->void{
      total += p.second;
    });

  return total;
}

//function operator to insert a word into the map.
//used by the constructor
void WordMap::operator()(const std::string word)
{
  insert(word);
}
