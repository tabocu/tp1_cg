#include "mainwindow.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    createActions();
}

void MainWindow::createActions()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

    QAction *newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new canvas"));
    fileMenu->addAction(newAct);

    fileMenu->addSeparator();

    QAction *closeAct = new QAction(tr("&Exit"), this);
    closeAct->setShortcuts(QKeySequence::Quit);
    closeAct->setStatusTip(tr("Exit the program"));
    fileMenu->addAction(closeAct);

    QMenu *drawMenu = menuBar()->addMenu(tr("&Draw"));
    QToolBar *drawToolBar = addToolBar(tr("Draw"));

    QAction *lineAct = new QAction(tr("&Line"), this);
    lineAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_L));
    lineAct->setStatusTip(tr("Draw line"));
    drawMenu->addAction(lineAct);
    drawToolBar->addAction(lineAct);

    QAction *rectangleAct = new QAction(tr("&Rectangle"), this);
    rectangleAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_R));
    rectangleAct->setStatusTip(tr("Draw rectangle"));
    drawMenu->addAction(rectangleAct);
    drawToolBar->addAction(rectangleAct);

    QAction *circleAct = new QAction(tr("&Circle"), this);
    circleAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_C));
    circleAct->setStatusTip(tr("Draw circle"));
    drawMenu->addAction(circleAct);
    drawToolBar->addAction(circleAct);

    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));

    QAction *aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the About box"));
    helpMenu->addAction(aboutAct);
}

void MainWindow::newFile()
{

}

void MainWindow::drawLine()
{

}

void MainWindow::drawRectangle()
{

}

void MainWindow::drawCircle()
{

}

void MainWindow::chooseColor()
{

}

void MainWindow::showAbout()
{

}
