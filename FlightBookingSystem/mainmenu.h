#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <QLabel>
#include <QDateTime>
#include <QTime>

namespace Ui {
class mainmenu;
}

class mainmenu : public QMainWindow
{
    Q_OBJECT

public:
    Ui::mainmenu *ui;
    explicit mainmenu(QWidget *parent = nullptr);
    int value, totalaccid;
    QTime timercountdown = QTime::currentTime();
    QString timeLabel = timercountdown.toString("hhmm");
    QString timecountdownlbl;
    QString username, accid, *seatselected, *gatenum, *departure, *arrival, *flightnum, *date, *time, *flightname;
    QString selectedbookid;
    QString timeofbooked, dateofbooked, time4digit, timeb4checkin, bookingid, gatecheckin;
    QDateTime datetdy = QDateTime::currentDateTime();
    QString datetdylbl = datetdy.toString("dd/MM/yyyy");
    QPixmap *ficon;
    QLabel *flightlbl, *seatlbl, *departlbl, *arrivelbl, *gatelbl, *datelbl, *timelbl, *iconlbl, *namelbl;
    QString region[10] = {"MY","SG","HK","JP","IN","US","KR","ME","UK","RU"};
    QString airlinename[10] = {"Malaysia Airlines",
                              "Singapore Airlines",
                              "Hong Kong Airlines",
                              "Japan Airlines",
                              "Air India",
                              "American Eagle",
                              "Korean Air Lines",
                              "Aeroméxico",
                              "British Airways",
                              "Aeroflot Russian Airlines"};
    QPixmap flighticon[10] ={QPixmap(":/images/my.png"),
                             QPixmap(":/images/sg.png"),
                             QPixmap(":/images/hk.png"),
                             QPixmap(":/images/jp.png"),
                             QPixmap(":/images/in.png"),
                             QPixmap(":/images/us.png"),
                             QPixmap(":/images/kr.png"),
                             QPixmap(":/images/me.png"),
                             QPixmap(":/images/uk.png"),
                             QPixmap(":/images/ru.png"),};
    ~mainmenu();

private slots:
    void currentsession();
    void on_buttonlogout_clicked();
    void on_btn_viewbook_clicked();
    void on_buttonreturn_clicked();
    void on_btn_newbook_clicked();
    void initarrayval();
    void on_btn_info_clicked();
    void on_buttonmainmenu_2_clicked();
    void on_buttonmainmenu_clicked();
    void on_btn_cancelbook_clicked();
    void on_buttonmainmenu_3_clicked();
    void on_listView_clicked(const QModelIndex &index);
    void on_btn_cancel_clicked();
    void on_btn_checkin_clicked();
    void on_buttonmainmenu_4_clicked();
    void timecountdown();
    void on_btn_checkedin_clicked();

private:
};

#endif // MAINMENU_H
