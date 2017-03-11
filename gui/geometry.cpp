#include "geometry.h"
#include "paint.h"

#include <QPainter>
#include <QtMath>

graphic::line::line(QPointF p1, QPointF p2)
    : m_p1(p1)
    , m_p2(p2)
{}

void graphic::line::paint(QImage *image, QPointF, QPointF) const
{
    graphic::paint::draw_line_bresenham(image,m_lineColor,m_p1.toPoint(),m_p2.toPoint());
}

graphic::rectangle::rectangle(QPointF p1, QPointF p2)
    : l1(p1,QPointF(p1.x(),p2.y()))
    , l2(p1,QPointF(p2.x(),p1.y()))
    , l3(QPointF(p1.x(),p2.y()),p2)
    , l4(QPointF(p2.x(),p1.y()),p2)
{}

void graphic::rectangle::set(QPointF p1, QPointF p2)
{
    l1.set(p1,QPointF(p1.x(),p2.y()));
    l2.set(p1,QPointF(p2.x(),p1.y()));
    l3.set(QPointF(p1.x(),p2.y()),p2);
    l4.set(QPointF(p2.x(),p1.y()),p2);
}

void graphic::rectangle::setP1(QPointF p1)
{
    QPointF p2 = getP2();
    l1.set(p1,QPointF(p1.x(),p2.y()));
    l2.set(p1,QPointF(p2.x(),p1.y()));
    l3.set(QPointF(p1.x(),p2.y()),p2);
    l4.set(QPointF(p2.x(),p1.y()),p2);
}

void graphic::rectangle::setP2(QPointF p2)
{
    QPointF p1 = getP1();
    l1.set(p1,QPointF(p1.x(),p2.y()));
    l2.set(p1,QPointF(p2.x(),p1.y()));
    l3.set(QPointF(p1.x(),p2.y()),p2);
    l4.set(QPointF(p2.x(),p1.y()),p2);
}

void graphic::rectangle::paint(QImage *image, QPointF minEdge, QPointF maxEdge) const
{
    l1.paint(image,minEdge,maxEdge);
    l2.paint(image,minEdge,maxEdge);
    l3.paint(image,minEdge,maxEdge);
    l4.paint(image,minEdge,maxEdge);
}

graphic::circle::circle(QPointF center, qreal radius)
    : m_center(center)
    , m_radius(radius)
{}

void graphic::circle::paint(QImage *image, QPointF, QPointF) const
{
    graphic::paint::draw_circle_bresenham(image,m_lineColor,m_center.toPoint(),qRound(m_radius));
}

