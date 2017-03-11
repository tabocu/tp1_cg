#include "canvas.h"

#include <QImage>
#include <QMouseEvent>
#include <QPainter>
#include <QPoint>
#include <QSize>
#include <QtMath>

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
    , m_bgColor(Qt::white)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    m_geometry.push_back(new graphic::line(QPointF(5.0,5.0),QPointF(20.0,20.0)));
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
    if (event->button() == Qt::LeftButton)
    {
        QPointF pos = event->localPos();
        std::clog << "Command: Mouse pressed " << pos << std::endl;
        switch (m_drawType)
        {
            case Canvas::DrawLine:
            {
                graphic::line *new_line = new graphic::line(pos,pos);
                m_geometry.push_back(new_line);
                break;
            }
            case Canvas::DrawCircle:
            {
                graphic::circle *new_circle = new graphic::circle(pos,0);
                m_geometry.push_back(new_circle);
                break;
            }
            default:
                break;
        }
        repaint();
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    QPointF pos = event->localPos();
    switch (m_drawType)
    {
        case Canvas::DrawLine:
        {
            graphic::line *new_line = (graphic::line*) m_geometry.back();
            new_line->setP2(pos);
            break;
        }
        case Canvas::DrawCircle:
        {
            graphic::circle *new_circle = (graphic::circle*) m_geometry.back();
            QPointF diff = new_circle->getCenter()-pos;
            qreal radius = qSqrt(diff.x()*diff.x()+diff.y()*diff.y());
            new_circle->setRadius(radius);
            break;
        }
        default:
            break;
    }
    repaint();
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
    std::clog << "Command: Mouse released " << event->pos() << std::endl;
}

void Canvas::paintEvent(QPaintEvent *)
{
    std::clog << "Command: Repaint canvas" << std::endl;

    QPainter painter(this);

    QImage *image = new QImage(size(), QImage::Format_RGB32);
    image->fill(m_bgColor);
    for(std::list<graphic::geometry*>::const_iterator it = m_geometry.begin();
            it != m_geometry.end(); ++it)
        if(*it != NULL)
            (*it)->paint(image,getMinEdge(),getMaxEdge());

    painter.drawImage(QPoint(),*image);
    delete image;
}

