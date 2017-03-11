#include "paint.h"

using namespace graphic;

void paint::draw_line_bresenham(QImage *image,
        const QColor &color,
        const QPoint &p1,
        const QPoint &p2)
{
    QPoint dp = p2-p1;
    int Xincr, Yincr;

    if (dp.x() < 0)
    {
        dp.rx() = -dp.rx();
        Xincr = -1;
    }
    else Xincr = 1;

    if (dp.y() < 0)
    {
        dp.ry() = -dp.ry();
        Yincr = -1;
    }
    else Yincr = 1;

    QPoint pixel(p1);
    image->setPixelColor(pixel,color);

    if (dp.x() > dp.y()) // First case
    {
        int c1 = dp.y() << 1;
        int p  = c1 - dp.x();
        int c2 = (dp.y() - dp.x()) << 1;

        for (int i = 0; i < dp.x(); ++i)
        {
            pixel.rx() += Xincr;
            if (p < 0) p += c1;
            else
            {
                p += c2;
                pixel.ry() += Yincr;
            }
            image->setPixelColor(pixel,color);
        }
    }
    else // Second case
    {
        int c1 = dp.x() << 1;
        int p  = c1 - dp.y();
        int c2 = (dp.x() - dp.y()) << 1;

        for (int i = 0; i < dp.y(); ++i)
        {
            pixel.ry() += Yincr;
            if (p < 0) p += c1;
            else
            {
                p += c2;
                pixel.rx() += Xincr;
            }
            image->setPixelColor(pixel,color);
        }
    }
}

void paint::draw_circle_bresenham(QImage *image, QPoint center, qreal radius)
{

}

