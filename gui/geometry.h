#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include <QPointF>
#include <QImage>

namespace graphic
{
    class geometry
    {
        virtual void paint(QImage &image, QPointF minEdge, QPointF maxEdge) = 0;
    };

    class line : public geometry
    {
    public:
        line(QPointF p1, QPointF p2);

        /*virtual*/ void paint(QImage &image, QPointF minEdge, QPointF maxEdge);
    private:
        QPointF m_p1, m_p2;
    };

    class circle : public geometry
    {
    public:
        circle(QPointF p1, QPointF p2);

        /*virtual*/ void paint(QImage &image, QPointF minEdge, QPointF maxEdge);
    private:
        QPointF m_center;
        qreal m_radius;
    };
}

#endif // _GEOMETRY_H_
