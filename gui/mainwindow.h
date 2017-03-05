#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "canvas.h"

class Canvas;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

protected:
    void closeEvent(QCloseEvent * event) Q_DECL_OVERRIDE;

private:
    void createActions();

private slots:
    // File actions
    void newFile();

    // Draw action
    void drawLine();
    void drawRectangle();
    void drawCircle();
    void chooseColor();

    // Help action
    void showAbout();

private:
    Canvas *m_canvas;

};

#endif // MAINWINDOW_H
