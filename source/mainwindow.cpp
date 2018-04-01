#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <functional>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    dbc_auto_logger("MainWindow")
{
    ui->setupUi(this);

    //Attach the logger
    dbc_auto_logger.attach(std::bind(&MainWindow::new_logs, this, std::placeholders::_1, std::placeholders::_2));

    //Initialize core
    dbc.initialize();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::new_logs(DBC::LogLevel level, const std::string & str){
    switch(level){
    case DBC::LogLevel::DEBUG: ui->textBrowser->setTextColor(QColor(0,0,200)); break;
    case DBC::LogLevel::INFO: ui->textBrowser->setTextColor(QColor(0,100,0)); break;
    case DBC::LogLevel::WARNING: ui->textBrowser->setTextColor(QColor(239, 127, 26)); break;
    case DBC::LogLevel::ERROR: ui->textBrowser->setTextColor(QColor(250,0,0)); break;
    default:
        ui->textBrowser->setTextColor(QColor(0,0,0));
    }

    ui->textBrowser->append(QString(str.c_str()));
}

void MainWindow::on_actionClose_triggered() {
    QMetaObject::invokeMethod(this, "close",
        Qt::QueuedConnection);
}
