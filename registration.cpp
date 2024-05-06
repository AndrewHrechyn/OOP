#include "registration.h"
#include "ui_registration.h"
#include <QMessageBox>
#include <QApplication>

Registration::Registration(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Registration)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &Registration::on_pushButton_clicked);
}

Registration::~Registration()
{
    delete ui;
}

//функції для подальшої зміни(передачі) даних у іншому класі
QString Registration::getLogin(){
    return login;
}
QString Registration::getPassword(){
    return password;
}


//Кнопка авторизації
void Registration::on_pushButton_clicked()
{
    QString temp_login = ui->lineEdit->text();
    QString temp_password = ui->lineEdit_2->text();

    if (temp_login == login && temp_password == password) {
        emit loginSuccesfully();
    } else {
        QMessageBox::warning(this, "Invalid data", "Invalid login or password");
    }
}

//Кнопка виходу з вікна реєстрації
void Registration::on_pushButton_2_clicked()
{
    QApplication::quit();
}

