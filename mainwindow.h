#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sstream>
#include<iostream>
#include<QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void calculateCurrentValue();
    void calculateFutureValue();
    void clearFields();
    void aboutThisApp();
    void aboutLicense();
    bool validateStringNum(std::string value);
    bool validateFields(std::string strAmount,std::string strTime, std::string strInterest);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
