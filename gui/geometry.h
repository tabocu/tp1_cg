#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include <QColor>
#include <QImage>
#include <QPointF>

namespace graphic
{
    class geometry
    {
    public:
        virtual void paint(QImage *image, QPointF minEdge, QPointF maxEdge) const = 0;

        void setLineColor(QColor color) { m_lineColor = color; }
        QColor getLineColor() { return m_lineColor; }

    private:
        QColor m_lineColor;
    };

    class line : public geometry
    {
    public:
        line(QPointF p1, QPointF p2);

        void setP1(QPointF point) { m_p1 = point; }
        void setP2(QPointF point) { m_p2 = point; }

        /*virtual*/ void paint(QImage *image, QPointF minEdge, QPointF maxEdge) const;
    private:
        QPointF m_p1, m_p2;
    };

    class circle : public geometry
    {
    public:
        circle(QPointF center, qreal radius);

        void setCenter(QPointF center) { m_center = center; }
        void setRadius(qreal radius) { m_radius = radius; }

        /*virtual*/ void paint(QImage *image, QPointF minEdge, QPointF maxEdge) const;
    private:
        QPointF m_center;
        qreal m_radius;
    };
}

#endif // _GEOMETRY_H_
