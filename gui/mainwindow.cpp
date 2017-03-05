#include "mainwindow.h"

#include <iostream>

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
    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);
    fileMenu->addAction(newAct);

    fileMenu->addSeparator();

    QAction *closeAct = new QAction(tr("&Exit"), this);
    closeAct->setShortcuts(QKeySequence::Quit);
    closeAct->setStatusTip(tr("Exit the program"));
    connect(closeAct, &QAction::triggered, this, &QWidget::close);
    fileMenu->addAction(closeAct);

    QMenu *drawMenu = menuBar()->addMenu(tr("&Draw"));
    QToolBar *drawToolBar = addToolBar(tr("Draw"));

    QActionGroup *drawActGroup = new QActionGroup(this);

    QAction *lineAct = new QAction(tr("&Line"), this);
    lineAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_L));
    lineAct->setStatusTip(tr("Draw line"));
    lineAct->setCheckable(true);
    lineAct->setChecked(true);
    connect(lineAct, &QAction::triggered, this, &MainWindow::drawLine);
    drawMenu->addAction(lineAct);
    drawToolBar->addAction(lineAct);
    drawActGroup->addAction(lineAct);

    QAction *rectangleAct = new QAction(tr("&Rectangle"), this);
    rectangleAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_R));
    rectangleAct->setStatusTip(tr("Draw rectangle"));
    rectangleAct->setCheckable(true);
    connect(rectangleAct, &QAction::triggered, this, &MainWindow::drawRectangle);
    drawMenu->addAction(rectangleAct);
    drawToolBar->addAction(rectangleAct);
    drawActGroup->addAction(rectangleAct);

    QAction *circleAct = new QAction(tr("&Circle"), this);
    circleAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_C));
    circleAct->setStatusTip(tr("Draw circle"));
    circleAct->setCheckable(true);
    connect(circleAct, &QAction::triggered, this, &MainWindow::drawCircle);
    drawMenu->addAction(circleAct);
    drawToolBar->addAction(circleAct);
    drawActGroup->addAction(circleAct);

    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));

    QAction *aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the About box"));
    connect(aboutAct, &QAction::triggered, this, &MainWindow::showAbout);
    helpMenu->addAction(aboutAct);
}

void MainWindow::closeEvent(QCloseEvent *)
{
    std::clog << "Command: Close program" << std::endl;
}

void MainWindow::newFile()
{
    std::clog << "Command: New file" << std::endl;
}

void MainWindow::drawLine()
{
    std::clog << "Command: Choose line" << std::endl;
}

void MainWindow::drawRectangle()
{
    std::clog << "Command: Choose rectangle" << std::endl;
}

void MainWindow::drawCircle()
{
    std::clog << "Command: Choose circle" << std::endl;
}

void MainWindow::chooseColor()
{

}

void MainWindow::showAbout()
{
    std::clog << "Command: Show about" << std::endl;
    QMessageBox::about(this, tr("About Application"),
            tr("This <b>Application</b> was developed by <b>Tales Bontempo Cunha</b> "
               "to <b>Graphic Computation Class</b>"));
}
