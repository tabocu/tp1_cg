#include "canvas.h"

#include <QImage>
#include <QMouseEvent>
#include <QPoint>

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

void Canvas::paintEvent(QPaintEvent *)
{
    std::clog << "Command: Repaint canvas" << std::endl;
}
