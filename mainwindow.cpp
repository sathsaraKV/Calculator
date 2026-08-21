#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <qDebug>
double firstNum;
bool userIsTypingSecondNumber =  false ;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{    
    ui->setupUi(this);
    connect(ui->pushButton_00,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_01,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_02,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_03,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_04,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_05,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_06,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_07,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_08,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_09,SIGNAL(released()),this,SLOT(digit_pressed()));

    connect(ui->pushButton_plus_minus,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
    connect(ui->pushButton_percentage,SIGNAL(released()),this,SLOT(unary_operation_pressed()));

    connect(ui->pushButton_plus,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_substract,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_mul,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_devision,SIGNAL(released()),this,SLOT(binary_operation_pressed()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_substract->setCheckable(true);
    ui->pushButton_mul->setCheckable(true);
    ui->pushButton_devision->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::digit_pressed()
{
    QPushButton *button =(QPushButton *)sender ();
    double labelNumber ;
    QString newlabel;
    if ((ui->pushButton_plus->isChecked() ||ui->pushButton_substract->isChecked() || ui->pushButton_mul->isChecked() ||ui->pushButton_devision->isChecked()) && (!userIsTypingSecondNumber))
    {
       labelNumber =button->text().toDouble();
        userIsTypingSecondNumber = true;
       newlabel = QString::number(labelNumber,'g',15) ;
    }
    else
    {
        if((ui->label->text().contains("."))&& button->text() == "0")
        {
            newlabel = ui->label->text() +button->text();

        }

        else
        {
            labelNumber = (ui->label->text() + button->text()).toDouble();
            newlabel = QString::number(labelNumber,'g',15) ;

        }

    }


    ui->label->setText(newlabel);
}

void MainWindow::on_pushButton_desimal_released()
{
    ui->label->setText(ui->label->text()+".");
}

void MainWindow::unary_operation_pressed()
{
    QPushButton * button =(QPushButton *)sender ();
    double labelNumber;
    QString newlabel;
    if(button->text()== "+/-")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber =labelNumber * -1 ;
        newlabel =QString::number(labelNumber,'g',15);
        ui->label->setText(newlabel);
    }

    if(button->text()== "%")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber =labelNumber * 0.01 ;
        newlabel =QString::number(labelNumber,'g',15);
        ui->label->setText(newlabel);
    }
}

void MainWindow::on_pushButton_C_released()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_substract->setChecked(false);
    ui->pushButton_mul->setChecked(false);
    ui->pushButton_devision->setChecked(false);

    userIsTypingSecondNumber = false;
    ui->label->setText("0");

}


void MainWindow::on_pushButton_equal_released()
{
    double labelNumber ,secondNum;
    QString newlabel;

    secondNum  = ui->label->text().toDouble();
    if(ui->pushButton_plus->isChecked())
    {

        labelNumber = firstNum + secondNum;
        newlabel = QString::number(labelNumber , 'g',15);
        ui->label->setText(newlabel);
        ui->pushButton_plus->setChecked(false);

    }

    else if(ui->pushButton_substract->isChecked())
    {
        labelNumber = firstNum - secondNum;
        newlabel = QString::number(labelNumber , 'g',15);
        ui->label->setText(newlabel);
        ui->pushButton_substract->setChecked(false);

    }

    else if(ui->pushButton_mul->isChecked())
    {
        labelNumber = firstNum * secondNum;
        newlabel = QString::number(labelNumber , 'g',15);
        ui->label->setText(newlabel);
        ui->pushButton_mul->setChecked(false);

    }

    else if(ui->pushButton_devision->isChecked())
    {
        labelNumber = firstNum / secondNum;
        newlabel = QString::number(labelNumber , 'g',15);
        ui->label->setText(newlabel);
        ui->pushButton_devision->setChecked(false);

    }

    userIsTypingSecondNumber = false ;

}

void MainWindow::binary_operation_pressed()
{
    QPushButton * button =(QPushButton *)sender ();
    firstNum = ui->label->text().toDouble();
    button->setChecked(true);

}

