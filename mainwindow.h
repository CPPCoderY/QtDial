#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    void displayValue(int value);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void setValue();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
