﻿#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mapboard = new MapBoard;
    ui->MapArea->setWidget(mapboard);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete  this->mapboard;
}


void MainWindow::on_Route_clicked()
{
    mapboard->updateBoard();
}


void MainWindow::on_Clear_clicked()
{
    mapboard->clear();
}
