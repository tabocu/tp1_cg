#include "canvas.h"

#include <QImage>
#include <QMouseEvent>
#include <QPoint>
#include <QSize>

#include <iostream>
#include <string>

static const std::string DRAW_TYPE[Canvas::DrawTypeEnum::Invalid] = {
    "Line",
    "Rectangle",
    "Circle"};

std::ostream& operator<<(std::ostream &os, const QPoint &point)
{
    os << "[";
    os << "x: " << point.x();
    os << " | ";
    os << "y: " << point.y();
    os << "]";
    return os;
}

std::ostream& operator<<(std::ostream &os, const QPointF &point)
{
    os << "[";
    os << "x: " << point.x();
    os << " | ";
    os << "y: " << point.y();
    os << "]";
    return os;
}

std::ostream& operator<<(std::ostream &os, const QSize &size)
{
    os << "[";
    os << "w: " << size.width();
    os << " | ";
    os << "h: " << size.height();
    os << "]";
    return os;
}


Canvas::Canvas(QWidget *parent)
    : QWidget(parent)
    , m_drawType(DrawTypeEnum::DrawLine)
    , m_scale(1.0)
    , m_minEdge(0.0,0.0)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

qreal Canvas::getScale()
{
    return m_scale;
}

QPointF Canvas::getMinEdge()
{
    return m_minEdge;
}

QPointF Canvas::getMaxEdge()
{
    QPointF maxEdge(size().width(),size().height());
    return maxEdge*m_scale;
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    std::clog << "Command: Mouse pressed " << event->pos() << std::endl;
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
    std::clog << "Command: Mouse released " << event->pos() << std::endl;
}

void Canvas::paintEvent(QPaintEvent *)
{
    std::clog << "Command: Repaint canvas" << std::endl;
}

