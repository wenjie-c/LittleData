#include<iostream>

using namespace std;

#ifndef COMPARATOR_HPP
#define COMPARATOR_HPP

namespace LittleData {
template<typename E>
class Comparator
{
    public:
    virtual bool operator()(const E & p, const E & q) = 0;
};

#pragma region EXAMPLES

struct Point2
{
    int x, y;
};

class LeftRight : Comparator<Point2>
{
    public:
    bool operator()(const Point2 & p, const Point2 & q) override
    {
        return p.x < q.x;
    }
};

class BottomTop : Comparator<Point2>
{
    public:
    bool operator()(const Point2 & p, const Point2 & q) override
    {
        return p.y < q.y;
    }
};

}

#pragma endregion EXAMPLES

#endif COMPARATOR_HPP