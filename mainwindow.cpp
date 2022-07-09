#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "randomwaypoint.h"
#include "QGraphicsRectItem"
#include "QTimer"
#include <cstdlib>
#include <iostream>
#include <memory>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand(400);
    ui->setupUi(this);

    QGraphicsScene* qgs_Spielfeld = new QGraphicsScene(0,0,440, 440, ui->graphicsView_Spielfeld);
    QGraphicsRectItem* block = new QGraphicsRectItem (0, 0,40, 40);
    block->setBrush(Qt::yellow);
    block->setPen(QPen(Qt::black));
    qgs_Spielfeld->addItem(block);
    ui->graphicsView_Spielfeld->setScene(qgs_Spielfeld);

    RandomWaypoint* rp = new RandomWaypoint(200,200);
    auto proceed = [=] () {
        rp->proceed();
        block->setPos(rp->getXpos(), rp->getYpos());
        ui->lcdNumber_xpos->display(rp->getXpos());
        ui->lcdNumber_ypos->display(rp->getYpos());
        qgs_Spielfeld->update();
    };


    QTimer* qtimer_ptr = new QTimer(this);
    connect(qtimer_ptr, &QTimer::timeout, proceed);
    qtimer_ptr->start(5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

