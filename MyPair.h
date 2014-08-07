#ifndef MYPAIR_H
#define MYPAIR_H

#include <string>
#include <utility>

template<class K, class V>
class MyPair : public std::pair<K,V>
{
  public:
    MyPair(){};
    MyPair(const K & x, const V & y) : std::pair<K, V>(x,y){}

    friend bool operator==(const MyPair & p1, const MyPair & p2)
    {
      return p1.first == p2.first;
    }

    bool operator()(const MyPair & p1, const MyPair & p2)
    {
      return ( p1.first < p2.first );
    }
};
#endif
