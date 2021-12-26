#ifndef MAP_H
#define MAP_H

#include <QMainWindow>
#include "calendar.h"
#include "ui_calendar.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace Ui {
class Map;
}

class Map : public QMainWindow
{
    Q_OBJECT


public:
    Ui::Map *ui;
    explicit Map(QWidget *parent = nullptr);
    int datecheckint;
    QString username,departure,arrival;
    QString departloc_lbl, arrivalloc_lbl, estimatedis_lbl, estimatedprice;
    bool getdepartselected(){return departselected;}
    ~Map();

private slots:
    void on_jp_btn_clicked();
    void on_us_btn_clicked();
    void on_me_btn_clicked();
    void on_ru_btn_clicked();
    void on_uk_btn_clicked();
    void on_sg_btn_clicked();
    void on_in_btn_clicked();
    void on_hk_btn_clicked();
    void on_my_btn_clicked();
    void on_kr_btn_clicked();
    void on_reset_btn_clicked();
    void on_confirm_btn_clicked();
    void displayestimateddistance();
    void currentsession();
    void on_buttonmainmenu_clicked();

private:
    bool departselected = false;
};

#endif // MAP_H
