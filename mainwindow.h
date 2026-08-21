#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculator;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

 private slots:
    void digit_pressed();

     void on_pushButton_desimal_released();
    void unary_operation_pressed();

     void on_pushButton_C_released();

    void on_pushButton_equal_released();
     void binary_operation_pressed();

private:
    Ui::Calculator *ui;


};
#endif // MAINWINDOW_H
