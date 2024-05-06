#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDateTime>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    struct MenuItem {
        QString name;
        double price; // Змінивши тип даних на double
    };


signals:
    void clickedSuccesfully();

private slots:
    void on_user_btn_clicked();

    void on_home_btn_1_clicked();
    void on_home_btn_2_clicked();

    void on_restaurants_btn_1_clicked();
    void on_restaurants_btn_2_clicked();

    void on_order_btn_1_clicked();
    void on_order_btn_2_clicked();

    void on_chat_btn_1_clicked();
    void on_chat_btn_2_clicked();

    void on_bonuse_btn_1_clicked();
    void on_bonuse_btn_2_clicked();

    void on_rate_btn_1_clicked();
    void on_rate_btn_2_clicked();

    void on_history_btn_1_clicked();
    void on_history_btn_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    //void on_pushButton_8_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    QString count_bonuses = "123312";

    // Структура для ресторану
    struct Restaurant {
        QString name;
        QString number;
        QString address;
        QString email;
        QString hours;
        QString info;
        QVector<MenuItem> menu;
    };

    QVector<Restaurant> restaurants = {
                                       {"PizzaPlace", "123-456-7890", "123 Main St", "pizzaplace@gmail.com", "9am - 9pm","One of the best pizza places in the world. Also have bonuses for new clients and gifts. Not only pizzam but also drinks", {{"Cheese pizza", 119}, {"Chicken pizza", 109}, {"Meat pizza", 129},
                                                                                                   {"Vegan pizza", 99}, {"Veggie pizza", 109}, {"Pepperoni pizza", 99},
                                                                                                   {"Mozarrella pizza", 109}, {"Hawaiian pizza", 109}, {"Buffalo pizza", 109},
                                                                                                   {"Cola", 30}, {"Fanta", 30}, {"Sprite", 30}, {"Water", 30}}},

                                       {"BurgerPlace", "987-654-3210", "456 Elm St", "burgerplace@gmail.com", "10am - 10pm", "One of the best burger places in the world. Also have bonuses for new clients and gifts. Not only pizzam but also drinks", {{"Hamburger", 69}, {"Cheese burger", 70}, {"Burger", 58}, {"Meat burger", 79},
                                                                                                      {"Vegan burger", 59}, {"Veggie burger", 69}, {"Pepperoni burger", 59},
                                                                                                      {"Cola", 30}, {"Fanta", 30}, {"Sprite", 30}, {"Water", 30}}}};
};
#endif // MAINWINDOW_H
