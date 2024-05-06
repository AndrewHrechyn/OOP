#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>

namespace Ui {
class Registration;
}

class Registration : public QWidget
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();

    QString getLogin();
    QString getPassword();

signals:
    void loginSuccesfully();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Registration *ui;

    QString login = "lox";
    QString password = "3535";
};

#endif // REGISTRATION_H
