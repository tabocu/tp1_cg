#ifndef _CANVAS_H_
#define _CANVAS_H_

#include <QWidget>

class Canvas : public QWidget
{
    Q_OBJECT

public:

    enum DrawTypeEnum {
        DrawLine,
        DrawSquare,
        DrawCircle,
        Invalid
    };

    Canvas(QWidget *parent = 0);

    void setDrawType(DrawTypeEnum drawType) { m_drawType = drawType; }
    DrawTypeEnum getDrawType() { return m_drawType; }

public slots:

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

private:
    DrawTypeEnum m_drawType;
};

#endif // _CANVAS_H_



