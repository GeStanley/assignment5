#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "WordVector.h"

WordVector::WordVector( std::istream & an_input_stream )
{
  std::istream_iterator<std::string> start(an_input_stream), finish;
  *this = for_each(start, finish, *this);
}

void WordVector::insert( const std::string & word )
{
  MyPair<std::string, int> p(word, 1);

  //find the word in the vector
  auto vit = find( wordvec.begin(), wordvec.end(), p );

  if(vit!=wordvec.end())
    ++vit->second;//increase count when found
  else
    wordvec.push_back(p);//insert at the back of the list when not
}

bool WordVector::remove( const std::string & word )
{
  MyPair<std::string, int> p(word, 1);

  //find word in the vector
  auto vit = find( wordvec.begin(), wordvec.end(), p );

  if(vit==wordvec.end())
    return false; //return false if not found
  else
  {
    wordvec.erase(vit); //erase the word
    return true;//return true when found.
  }
}

int WordVector::lookup( const std::string & word ) const
{
  MyPair<std::string, int> p(word, 1);

  //find the word in the vector
  auto vit = find( wordvec.begin(), wordvec.end(), p );

  if(vit==wordvec.end())
    return 0;//return 0 if not found
  else
    return vit->second;//return the count when found
}

void printMyPair(MyPair<std::string, int> p)
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
    //lambda that adds all the second elements
    [&total](MyPair<std::string, int> p)->void{
      total += p.second;
    });

  return total;
}

void WordVector::sort()
{//sort the vector in alphabetical order
  //using the MyPair function operator
  std::sort(wordvec.begin(), wordvec.end(), MyPair<std::string, int>());
}

//function operator to insert a word into the map.
//used by the constructor
void WordVector::operator()(const std::string word)
{
  insert(word);
}
