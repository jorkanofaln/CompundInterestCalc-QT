#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "compondcalc.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
void MainWindow::calculateFutureValue(){
    double amount;
    double time;
    double interest;
    amount = std::stod(ui->lineEditAmount->text().toStdString());
    time = std::stod(ui->lineEditTime->text().toStdString());
    interest = std::stod(ui->lineEditInterest->text().toStdString());
    //Initializing compound calculator
    CompondCalc compound(interest,amount,time);
    double futureValue = compound.calculateFutureValue();
    //Converting and Displaying result
    std::ostringstream streamFutureValue;
    streamFutureValue << futureValue;
    std::string str_futureValue = "The future value is " + streamFutureValue.str();
    QMessageBox::information(this,tr("Result"), tr(str_futureValue.c_str()));
}
void MainWindow::clearFields(){
    //Clear input fields
    ui->lineEditTime->clear();
    ui->lineEditAmount->clear();
    ui->lineEditInterest->clear();
}
void MainWindow::aboutThisApp(){
    QMessageBox::about(this,"About this app","A compound interest calculator in C++ using the qt framework");
}
void MainWindow::calculateCurrentValue(){
    double amount;
    double time;
    double interest;
    amount = std::stod(ui->lineEditAmount->text().toStdString());
    time = std::stod(ui->lineEditTime->text().toStdString());
    interest = std::stod(ui->lineEditInterest->text().toStdString());
    //Initializing compound calculator
    CompondCalc compound(interest,amount,time);
    double presentValue = compound.calculatePresentValue();
    //Converting and Displaying result
    std::ostringstream streamPresentValue;
    streamPresentValue << presentValue;
    std::string str_presentValue = "The present value is " + streamPresentValue.str();
    QMessageBox::information(this,tr("Result"), tr(str_presentValue.c_str()));
}
MainWindow::~MainWindow()
{
    delete ui;
}

