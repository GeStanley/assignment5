#ifndef COMPAREWORDS_H
#define COMPAREWORDS_H

#include <string>

class CompareWords
{
  //Function object that takes two strings as parameters
  //it determines if one string is less then another (a comparator)
  //the desired ordering is:
  //A, B, AA, BB, AAA etc..
public:
  bool operator()(const std::string s1, const std::string s2)
  {
    if(s1.length()==s2.length())
      return s1 < s2;
    else
      return s1.length() < s2.length();
  }


};
#endif
