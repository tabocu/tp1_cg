#ifndef _CANVAS_H_
#define _CANVAS_H_

#include "geometry.h"

#include <stack>

#include <QColor>
#include <QPointF>
#include <QWidget>

class Canvas : public QWidget
{
    Q_OBJECT

public:

    enum DrawTypeEnum {
        DrawLine,
        DrawRectangle,
        DrawCircle,
        Invalid
    };

    Canvas(QWidget *parent = 0);

    void setDrawType(DrawTypeEnum drawType) { m_drawType = drawType; }
    DrawTypeEnum getDrawType() { return m_drawType; }

    qreal getScale();
    QPointF getMinEdge();
    QPointF getMaxEdge();

public slots:

protected:
    virtual void mousePressEvent   (QMouseEvent *event) Q_DECL_OVERRIDE;
    virtual void mouseReleaseEvent (QMouseEvent *event) Q_DECL_OVERRIDE;
    virtual void paintEvent        (QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    DrawTypeEnum m_drawType;
    qreal m_scale;
    QPointF m_minEdge;

    std::list<graphic::geometry*> m_geometry;
    QColor m_bgColor;
};

#endif // _CANVAS_H_



