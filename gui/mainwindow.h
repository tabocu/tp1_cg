#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

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

};

#endif // MAINWINDOW_H
