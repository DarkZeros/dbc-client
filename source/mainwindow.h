#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "core/source/core.h"
#include "core/source/logger.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void new_logs(DBC::LogLevel level, const std::string & str);

private slots:
    void on_actionClose_triggered();

private:
    Ui::MainWindow *ui;
    DBC::Logger dbc_auto_logger;
    DBC::Core dbc;
};

#endif // MAINWINDOW_H
