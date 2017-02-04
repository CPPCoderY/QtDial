#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->dial, SIGNAL(valueChanged(int)),
            SLOT(setValue()));
    connect(ui->slider, SIGNAL(valueChanged(int)),
            SLOT(setValue()));
    connect(ui->sliderB, SIGNAL(toggled(bool)),
            SLOT(setValue()));
    connect(ui->dialB, SIGNAL(toggled(bool)),
            SLOT(setValue()));
    ui->dial->setEnabled(false);
    ui->slider->setEnabled(false);
}

void MainWindow::setValue(){
    if(ui->sliderB->isChecked()){
        ui->slider->setEnabled(true);
        displayValue(ui->slider->value());
        ui->dial->setValue(0);
        ui->dial->setEnabled(false);
    } if (ui->dialB->isChecked()) {
        ui->dial->setEnabled(true);
        displayValue(ui->dial->value());
        ui->slider->setValue(0);
        ui->slider->setEnabled(false);
    }
}

void MainWindow::displayValue(int value){
    ui->lcdHex->display(value);
    ui->lcdBin->display(value);
    ui->lcdDec->display(value);
    ui->lcdOct->display(value);
}

MainWindow::~MainWindow()
{
    delete ui;
}
