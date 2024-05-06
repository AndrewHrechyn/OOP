#include "mainwindow.h"
#include "registration.h"
#include "user_info.h"

#include <QApplication>
#include <QMessageBox>
#include <QVector>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    Registration r;
    User_Info user;
    r.show();



    //якщо авторизація успішна я пускаю далі користувача
    QObject::connect(&r, &Registration::loginSuccesfully, [&](){
        r.hide();
        w.show();
    });

    //якщо натиснута кнопка на мейн віндов то висвічуються дані користувача
    QObject::connect(&w, &MainWindow::clickedSuccesfully, [&](){
        user.show();
    });

    user.set_name("Andrew");
    user.set_surname("Hrechyn");
    user.set_nickname("hr4ka");

    return a.exec();
}
