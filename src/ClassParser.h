#ifndef ClassParser_H
#define ClassParser_H

#include <vector>
#include <array>
#include <string>

//v1.2

template<typename T>
std::string ParseToStream(const T& pclass)
{
    std::string r;
    r.reserve(sizeof(T));
    char* ptr = (char*)&pclass;
    for(int i = 0;i < sizeof(T);i++)
    {
        r.push_back(ptr[i]);
    }
    return r;
}

//Class or Struct has to have a default constructor
template<typename T>
T ParseToClass(std::string::iterator it)
{
    T rClass;
    char* ptr = (char*)&rClass;
    for(int i = 0;i < sizeof(T);i++,it++)
    {
        ptr[i] = *it;
    }
    return rClass;
}

template<typename T>
std::string ParseVectorToStream(std::vector<T> pvector)
{
    std::string r;
    r.reserve(pvector.size() * sizeof(T));
    for(T& pclass : pvector)
    {
        std::string rc = ParseToStream(pclass);
        r.append(rc);
    }
    return r;
}

//Class or Struct has to have a default constructor
template<typename T>
std::vector<T> ParseToClassVector(std::string::iterator Beginit,int vsize)
{
    std::vector<T> vec;
    vec.reserve(vsize);
    auto last = Beginit + (vsize * sizeof(T));
    for(auto it = Beginit;it < last;it+= sizeof(T))
    {
        vec.push_back(ParseToClass<T>(it));
    }
    return vec;
}

#endif