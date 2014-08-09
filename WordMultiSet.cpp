#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "WordMultiSet.h"

WordMultiSet::WordMultiSet( std::istream & an_input_stream )
{
  std::istream_iterator<std::string> start(an_input_stream), finish;
  for_each(start, finish, insert);
}

void WordMultiSet::insert(const std::string & word)
{

    wordset.insert( word );
}

int WordMultiSet::lookup(const std::string & word)
{
  auto p = wordset.equal_range(word);

  int count = std::distance(p.first, p.second);
  return count;
}
