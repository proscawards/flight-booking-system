#ifndef CALENDAR_H
#define CALENDAR_H

#include <QMainWindow>
#include <QCalendarWidget>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "flight.h"
#include "ui_flight.h"
#include "map.h"
#include "ui_map.h"
#include "seats.h"
#include "ui_seats.h"

namespace Ui {
class Calendar;
}

class Calendar : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calendar(QWidget *parent = nullptr);
    QString departloc, arrivalloc, distance, ticketprice, username, timecompare, gatenum, timeselected, flightselected, flightcurstatus;
    QString day, month, year, daytdy, monthtdy, yeartdy;
    QString dateselectLabel, timeselectedLabel;
    QDateTime datetdy = QDateTime::currentDateTime();
    QString datetdylbl = datetdy.toString("dd/MM/yyyy");
    int selected;
    QString departure[90], arrival[90], flighttime[90], flightstatus[90];
    QString flightnum[90], flightdestination[90], flightairport[90], flightairline[90], flightgate[90];
    QPixmap flighticon[90] =
    {QPixmap(":/images/ru.png"), QPixmap(":/images/hk.png"),QPixmap(":/images/my.png"),QPixmap(":/images/sg.png"), QPixmap(":/images/jp.png"), QPixmap(":/images/in.png"),QPixmap(":/images/us.png"),QPixmap(":/images/kr.png"), QPixmap(":/images/me.png"), QPixmap(":/images/uk.png"),
     QPixmap(":/images/me.png"),QPixmap(":/images/ru.png"), QPixmap(":/images/my.png"), QPixmap(":/images/sg.png"),QPixmap(":/images/hk.png"),QPixmap(":/images/jp.png"),QPixmap(":/images/in.png"), QPixmap(":/images/us.png"),QPixmap(":/images/kr.png"),QPixmap(":/images/me.png"),
     QPixmap(":/images/uk.png"), QPixmap(":/images/ru.png"),QPixmap(":/images/ru.png"),QPixmap(":/images/my.png"),QPixmap(":/images/sg.png"), QPixmap(":/images/hk.png"),QPixmap(":/images/jp.png"),QPixmap(":/images/in.png"),QPixmap(":/images/us.png"), QPixmap(":/images/kr.png"),
     QPixmap(":/images/me.png"),QPixmap(":/images/uk.png"),QPixmap(":/images/ru.png"), QPixmap(":/images/ru.png"),QPixmap(":/images/my.png"),QPixmap(":/images/sg.png"),QPixmap(":/images/hk.png"), QPixmap(":/images/jp.png"),QPixmap(":/images/in.png"),QPixmap(":/images/us.png"),
     QPixmap(":/images/kr.png"), QPixmap(":/images/me.png"),QPixmap(":/images/uk.png"),QPixmap(":/images/ru.png"),QPixmap(":/images/ru.png"), QPixmap(":/images/my.png"),QPixmap(":/images/sg.png"),QPixmap(":/images/hk.png"),QPixmap(":/images/jp.png"), QPixmap(":/images/in.png"),
     QPixmap(":/images/us.png"),QPixmap(":/images/kr.png"),QPixmap(":/images/me.png"), QPixmap(":/images/uk.png"),QPixmap(":/images/ru.png"),QPixmap(":/images/ru.png"),QPixmap(":/images/my.png"), QPixmap(":/images/sg.png"),QPixmap(":/images/hk.png"),QPixmap(":/images/jp.png"),
     QPixmap(":/images/in.png"), QPixmap(":/images/us.png"),QPixmap(":/images/kr.png"),QPixmap(":/images/me.png"), QPixmap(":/images/uk.png"), QPixmap(":/images/ru.png"),QPixmap(":/images/me.png"),QPixmap(":/images/my.png"),QPixmap(":/images/sg.png"), QPixmap(":/images/hk.png"),
     QPixmap(":/images/hk.png"),QPixmap(":/images/jp.png"),QPixmap(":/images/in.png"), QPixmap(":/images/us.png"),QPixmap(":/images/kr.png"),QPixmap(":/images/uk.png"),QPixmap(":/images/ru.png"), QPixmap(":/images/ru.png"),QPixmap(":/images/my.png"),QPixmap(":/images/sg.png"),
     QPixmap(":/images/sg.png"), QPixmap(":/images/hk.png"),QPixmap(":/images/jp.png"),QPixmap(":/images/in.png"),QPixmap(":/images/us.png"), QPixmap(":/images/kr.png"),QPixmap(":/images/me.png"),QPixmap(":/images/uk.png"),QPixmap(":/images/ru.png"), QPixmap(":/images/my.png")};
    ~Calendar();

private slots:
    void displaytime();
    void on_buttonmainmenu_clicked();
    void on_calendarWidget_clicked(const QDate &date);
    void on_pushButton_clicked();
    void on_buttonconfirm_clicked();
    void displayflightonbtn();
    void currentsession();
    void selectedloc();
    void on_buttonreturn_clicked();
    void on_btnflight_clicked();

private:
    Ui::Calendar *ui;


};

#endif // CALENDAR_H
