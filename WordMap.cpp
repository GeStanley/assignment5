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

  mit = wmap.find( word );

  if(mit!=wmap.end())
    ++mit->second;
  else
    wmap.insert( std::pair<std::string, int>(word, 1) );
}

bool WordMap::remove(const std::string & word)
{
  std::map<std::string, int>::iterator mit;

  mit = wmap.find( word );

  if(mit==wmap.end())
    return false;
  else
  {
    wmap.erase(mit);
    return true;
  }
}

int WordMap::lookup(const std::string & word)
{
  std::map<std::string, int>::iterator mit;

  mit = wmap.find( word );

  if(mit==wmap.end())
    return 0;
  else
    return mit->second;
}

void WordMap::print() const
{
  for(std::pair<std::string, int> p : wmap)
  {
    //set the tab offset from the left border
    int size=0;
    if(p.second>9)
      size=2;
    else
      size=1;

    int spacing = 4 - size;

    //print out the offset
    while (spacing > 0){
      std::cout << " ";
      spacing--;
    }

    std::cout << p.second << " : " << p.first << std::endl;
  }
}

int WordMap::size() const
{
  return wmap.size();
}

int WordMap::sum_frequency_count() const
{
  return 0;
}

void WordMap::operator()(const std::string word)
{
  insert(word);
}
