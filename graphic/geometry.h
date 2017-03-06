#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include <utility>

namespace graphic
{
    class geometry
    {
    };

    class line : public geometry
    {
    public:
        line(std::pair<int, int> p1, std::pair<int, int> p2);
    private:
        std::pair<int, int> m_p1, m_p2;
    };

    class rectangle : public geometry
    {
    public:
        rectangle(std::pair<int, int> p1, std::pair<int, int> p2);
    private:
        line m_line1, m_line2, m_line3, m_line4;
    };

    class circle : public geometry
    {
    public:
        circle(int x, int y, int r);
        circle(int x1, int y1, int x2, int y2);

    private:
        std::pair<int, int> m_center;
        int m_radius;
    };
}

#endif // _GEOMETRY_H_
