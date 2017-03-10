#include "geometry.h"

graphic::line::line(QPointF p1, QPointF p2)
    : m_p1(p1)
    , m_p2(p2)
{}

void graphic::line::paint(QImage &image, QPointF minEdge, QPointF maxEdge) const
{
    QPainter painter(image);
    painter.drawLine(m_p1,m_p2);
}

graphic::circle::circle(QPointF p1, QPointF)
    : m_center(p1)
    , m_radius(0)
{}

void graphic::circle::paint(QImage &image, QPointF minEdge, QPointF maxEdge) const
{
    QPainter painter(image);
    painter.drawEllipse(m_center,m_radius,m_radius);
}

