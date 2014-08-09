#include <string>
#include "CompareWords.h"

bool WordMap::operator()(const std::string s1, const std::string s2)
{
  if(s1.length()==s2.length())
    return s1 < s2;
  else
    return s1.length() < s2.length();
}
