#ifndef _PAINT_H_
#define _PAINT_H_

#include <QImage>
#include <QPoint>

namespace graphic
{
    class paint
    {
    public:
        void static draw_line_bresenham(
                QImage *image,
                const QColor &color,
                const QPoint &p1,
                const QPoint &p2);

        void static draw_circle_bresenham(QImage *image, QPoint center, qreal radius);
    };
}

#endif //_PAINT_H_
