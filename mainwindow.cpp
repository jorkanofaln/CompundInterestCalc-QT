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
    QMessageBox::about(this,"About this app","A compound interest calculator in C++ using the qt framework\n "
                            "Copyright (c) 2020, Jorkano Faln\n"
                            "THIS SOFTWARE IS PROVIDED AS IS WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES");
}
void MainWindow::aboutLicense(){
    QMessageBox::about(this,"License Information", "BSD 3-Clause License\n"

                       "Copyright (c) 2020, Jorkano Faln\n"
                       "All rights reserved."
                       "Redistribution and use in source and binary forms, with or without"
                       "  modification, are permitted provided that the following conditions are met:\n"

                       "\n1. Redistributions of source code must retain the above copyright notice, this"
                       "   list of conditions and the following disclaimer.\n"

                       "\n2. Redistributions in binary form must reproduce the above copyright notice,"
                          "this list of conditions and the following disclaimer in the documentation"
                          "and/or other materials provided with the distribution.\n"

                       "\n3. Neither the name of the copyright holder nor the names of its"
                         " contributors may be used to endorse or promote products derived from"
                        "  this software without specific prior written permission.\n"

                       "\nTHIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 'AS IS'"
                       "AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE"
                       "IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE"
                       "DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE"
                       "FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL"
                       "DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR"
                       "SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER"
                       "CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,"
                       "OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE"
                       "OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."

);
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

