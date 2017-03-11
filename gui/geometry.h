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

    protected:
        QColor m_lineColor = Qt::black;
    };

    class line : public geometry
    {
    public:
        line(QPointF p1, QPointF p2);

        void set(QPointF p1, QPointF p2) { m_p1 = p1; m_p2 = p2; }

        void setP1(QPointF point) { m_p1 = point; }
        void setP2(QPointF point) { m_p2 = point; }

        QPointF getP1() { return m_p1; }
        QPointF getP2() { return m_p2; }

        /*virtual*/ void paint(QImage *image, QPointF minEdge, QPointF maxEdge) const;
    private:
        QPointF m_p1, m_p2;
    };

    class rectangle : public geometry
    {
    public:
        rectangle(QPointF pq, QPointF p2);

        void set(QPointF p1, QPointF p2);

        void setP1(QPointF point);
        void setP2(QPointF point);

        QPointF getP1() { return l1.getP1(); }
        QPointF getP2() { return l3.getP2(); }

        /*virtual*/ void paint(QImage *image, QPointF minEdge, QPointF maxEdge) const;
    private:
        line l1, l2, l3, l4;
    };

    class circle : public geometry
    {
    public:
        circle(QPointF center, qreal radius);

        void setCenter(QPointF center) { m_center = center; }
        void setRadius(qreal radius) { m_radius = radius; }

        QPointF getCenter() { return m_center; }
        qreal   getRadius() { return m_radius; }

        /*virtual*/ void paint(QImage *image, QPointF minEdge, QPointF maxEdge) const;
    private:
        QPointF m_center;
        qreal m_radius;
    };
}

#endif // _GEOMETRY_H_
