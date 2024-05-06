#ifndef USER_INFO_H
#define USER_INFO_H

#include <QWidget>
#include <QPixmap>

namespace Ui {
class User_Info;
}

class User_Info : public QWidget
{
    Q_OBJECT

public:
    explicit User_Info(QWidget *parent = nullptr);
    ~User_Info();

    //in progress
    void set_name(QString name);
    void set_surname(QString surname);
    void set_nickname(QString nickname);

private slots:
    void on_pushButton_5_clicked();

    // void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::User_Info *ui;

};

#endif // USER_INFO_H
