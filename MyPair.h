#ifndef MYPAIR_H
#define MYPAIR_H

#include <string>
#include <utility>

template<class K, class V>
class MyPair : public std::pair<K,V>
{
  public:
    MyPair(){};
    //pass constructor variables to base class
    MyPair(const K & x, const V & y) : std::pair<K, V>(x,y){}

    //customized equality operator based on pair 'key'
    friend bool operator==(const MyPair & p1, const MyPair & p2)
    {
      return p1.first == p2.first;
    }

    //customized function operator
    //used to sort MyPair in 'key' order
    bool operator()(const MyPair & p1, const MyPair & p2)
    {
      return ( p1.first < p2.first );
    }
};
#endif
