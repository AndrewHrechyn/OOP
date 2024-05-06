#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user_info.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    connect(ui->user_btn, &QPushButton::clicked, this, &MainWindow::on_user_btn_clicked);

    // Сховати віджет icon_only_widget
    ui->icon_only_widget->hide();

    // Встановити початковий індекс для stackedWidget
    ui->stackedWidget->setCurrentIndex(0);

    // Встановити кнопці home_btn_2 стан натиснуто
    ui->home_btn_2->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_user_btn_clicked(){
    emit clickedSuccesfully();
}

void MainWindow::on_home_btn_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_home_btn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_restaurants_btn_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}
void MainWindow::on_restaurants_btn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_order_btn_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_order_btn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_chat_btn_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::on_chat_btn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_bonuse_btn_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_bonuse_btn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_rate_btn_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
void MainWindow::on_rate_btn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_history_btn_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}
void MainWindow::on_history_btn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit->setText(count_bonuses);
}

void MainWindow::on_pushButton_2_clicked()
{

    for (auto& restaurant : restaurants)
    {
        ui->show_rest->append("Restaurant name: " + restaurant.name);
        ui->show_rest->append("Number: " + restaurant.number);
        ui->show_rest->append("Address: " + restaurant.address);
        ui->show_rest->append("Email: " + restaurant.email);
        ui->show_rest->append("Work hours: " + restaurant.hours);
        ui->show_rest->append("Info about: " + restaurant.info);
        ui->show_rest->append("");
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    int count = 1;
    for (auto& restaurant : restaurants)
    {
        ui->show_menu->append(QString::number(count) + ". " + "Restaurant name: " + restaurant.name);
        count++;
        ui->show_menu->append("Work hours: " + restaurant.hours);
        ui->show_menu->append("Menu:");
        int index = 1;
        for (auto& item : restaurant.menu)
        {
            ui->show_menu->append(QString::number(index) + ". " + item.name + "  " + QString::number(item.price, 'f', 2) + "$");
            index++;
        }
        ui->show_menu->append("");
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    QString temp_index = ui->rest_name_input->text();

    int index = temp_index.toInt() - 1;
    int dish_index = 0;
    int count = 0;

    dish_index = ui->add_number_input->text().toInt() - 1;

    count = ui->quantity_input->text().toInt();

    double price = restaurants[index].menu[dish_index].price * count;

    QString res_price = QString::number(price);

    QString currentDateTimeString = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss");

    ui->current_show_box->append(currentDateTimeString);
    ui->current_show_box->append("Restaurant name: " + restaurants[index].name);
    ui->current_show_box->append("Your order");
    ui->current_show_box->append("Dish: " + restaurants[index].menu[dish_index].name);
    ui->current_show_box->append("Price: " + QString::number(restaurants[index].menu[dish_index].price) + "$" + "  x" + QString::number(count));
    ui->current_show_box->append("Your fee: " + res_price);

    ui->rest_name_input->clear();
    ui->add_number_input->clear();
    ui->quantity_input->clear();
}


//у майбутньому тут дописати щоб замовлення відправлялось доставщику у чат і він міг це бачити
void MainWindow::on_pushButton_7_clicked()
{
    ui->show_history->append("");
    QString temp = ui->current_show_box->toPlainText();
    ui->show_history->append(temp);
    ui->current_show_box->clear();
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->current_show_box->clear();
}

