#include "canvas.h"

#include <QMouseEvent>
#include <QPoint>

#include <iostream>

std::ostream& operator<<(std::ostream &os, const QPoint &point)
{
    os << "[";
    os << "x: " << point.x();
    os << " | ";
    os << "y: " << point.y();
    os << "]" << std::endl;
    return os;
}

Canvas::Canvas(QWidget *parent)
    : QWidget(parent)
    , m_drawType(DrawTypeEnum::DrawLine)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    std::clog << "Command: Mouse pressed " << event->pos() << std::endl;
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
    std::clog << "Command: Mouse released " << event->pos() << std::endl;
}
