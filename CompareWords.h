#ifndef COMPAREWORDS_H
#define COMPAREWORDS_H

#include <string>

class CompareWords
{
public:

  bool operator()(const std::string s1, const std::string s2);

};
#endif
