#ifndef _CANVAS_H_
#define _CANVAS_H_

#include <QWidget>

class Canvas : public QWidget
{
    Q_OBJECT

public:

    enum DrawType {
        DrawLine,
        DrawSquare,
        DrawCircle,
    };

    Canvas(QWidget *parent = 0);
public slots:

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

private:

};

#endif // _CANVAS_H_



