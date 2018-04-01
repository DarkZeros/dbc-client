#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <functional>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    DBC::Logger::add();

    std::function<void(const std::string &)> a = std::bind(&MainWindow::new_logs, this, std::placeholders::_1);
    DBC::Logger::add(a);

    //Create DBC
    //dbc.checkPoW();
    //Link log of DBC to us
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::new_logs(const std::string & str){
    ui->textBrowser->append(QString(str.c_str()));
}
