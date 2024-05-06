#include "user_info.h"
#include "ui_user_info.h"

User_Info::User_Info(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::User_Info)
{
    ui->setupUi(this);
}

User_Info::~User_Info()
{
    delete ui;
}


//in progress
void User_Info::set_name(QString name)
{
    ui->lineEdit->setText(name);
}

void User_Info::set_surname(QString surname){
    ui->lineEdit_2->setText(surname);
}

void User_Info::set_nickname(QString nickname)
{
    ui->lineEdit_3->setText(nickname);
}

void User_Info::on_pushButton_5_clicked()
{
    hide();
}



//in progress
void User_Info::on_pushButton_3_clicked()
{
    QString temp_name = ui->lineEdit->text();
    ui->lineEdit->setText(temp_name);
}
void User_Info::on_pushButton_clicked()
{
    QString temp_surname = ui->lineEdit_2->text();
    ui->lineEdit_2->setText(temp_surname);
}
void User_Info::on_pushButton_2_clicked()
{
    QString temp_nickname = ui->lineEdit_3->text();
    ui->lineEdit_3->setText(temp_nickname);
}

void User_Info::on_pushButton_4_clicked()
{
    QString imagePath = ":/images/logo.jpg";

    QPixmap newImage(imagePath);

    if (!newImage.isNull()) {
        ui->label_acc_logo->setPixmap(newImage);
        ui->label_acc_logo->setScaledContents(true);
    } else {
        ui->label_acc_logo->setText("Wrong try");
    }
}

