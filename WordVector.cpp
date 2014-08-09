#include <string>
#include <iostream>
#include <algorithm>
#include "WordVector.h"

WordVector::WordVector( std::istream & inputStream )
{
  std::string currentWord="";

  while(inputStream >> currentWord)
  {
    insert(currentWord);
  }
}

void WordVector::insert( const std::string & word )
{
  MyPair<std::string, int> p(word, 1);

  auto vit = find( wordvec.begin(), wordvec.end(), p );

  if(vit!=wordvec.end())
    ++vit->second;
  else
    wordvec.push_back(p);
}

bool WordVector::remove( const std::string & word )
{
  MyPair<std::string, int> p(word, 1);

  auto vit = find( wordvec.begin(), wordvec.end(), p );

  if(vit==wordvec.end())
    return false;
  else
  {
    wordvec.erase(vit);
    return true;
  }
}

int WordVector::lookup( const std::string & word ) const
{
  MyPair<std::string, int> p(word, 1);

  auto vit = find( wordvec.begin(), wordvec.end(), p );

  if(vit==wordvec.end())
    return 0;
  else
    return vit->second;
}

void printMyPair(MyPair<std::string, int> p)
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

void WordVector::print() const
{
  for_each(wordvec.begin(), wordvec.end(), printMyPair);
}

int WordVector::size() const
{
  return wordvec.size();
}

int WordVector::sum_frequency_count() const
{
  int total=0;

  for_each(wordvec.begin(), wordvec.end(),
    [&total](MyPair<std::string, int> p)->void{
      total += p.second;
    });

  return total;
}

void WordVector::sort()
{
  std::sort(wordvec.begin(), wordvec.end(), MyPair<std::string, int>());
}
