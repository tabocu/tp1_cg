#ifndef _PAINT_H_
#define _PAINT_H_

#include <QImage>
#include <QPoint>

namespace graphic
{
    class paint
    {
    public:
        void static draw_line_bresenham(QImage *image, QPoint p1, QPoint p2);
        void static draw_circle_bresenham(QImage *image, QPoint center, qreal radius);
    };
}

#endif //_PAINT_H_
