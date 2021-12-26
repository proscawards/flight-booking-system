#include "seats.h"
#include "ui_seats.h"
#include "mainwindow.h"
#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QMessageBox>
#include <QtSql>
#include <QTextStream>
#include <QDebug>

Seats::Seats(QWidget *parent) :QMainWindow(parent), ui(new Ui::Seats)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(currentsession()));
    connect(timer, SIGNAL(timeout()), this, SLOT(datafromprev()));
    timer->start();
    QPixmap exitup, exitdown;
    exitup.load(":/images/arrow_up.png");
    exitdown.load(":/images/arrow_down.png");
    ui->exit1->setPixmap(exitup);
    ui->exit2->setPixmap(exitup);
    ui->exit3->setPixmap(exitup);
    ui->exit4->setPixmap(exitup);
    ui->exit9->setPixmap(exitup);
    ui->exit5->setPixmap(exitdown);
    ui->exit6->setPixmap(exitdown);
    ui->exit7->setPixmap(exitdown);
    ui->exit8->setPixmap(exitdown);
    ui->exit10->setPixmap(exitdown);


}

void Seats::currentsession(){
    QFile currentuser("G:/Degree/Sem3(1910)/TCP1201 - OOPDS/Assignment/FlightBookingSystem/currentuser.txt");
    currentuser.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&currentuser);
    in>>username>>accid;
    ui->currentuser_lbl->setText(username);
    currentuser.flush();
    currentuser.close();
}

void Seats::datafromprev(){
    QFile selectseat("G:/Degree/Sem3(1910)/TCP1201 - OOPDS/Assignment/FlightBookingSystem/b4selectseat.txt");
    selectseat.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&selectseat);
    in>>departure>>arrival>>distance>>ticketprice>>flightnum>>gatenum>>date>>time>>flightstatus;
    selectseat.flush();
    selectseat.close();
}

Seats::~Seats()
{
    delete ui;
}

void Seats::on_confirm_btn_clicked()
{
    if (seatclass == "BUSINESS"){
        int ticketpriceint = ticketprice.split(" ")[0].toInt();
        ticketpriceint = ticketpriceint + 200;
        ticketprice = QString::number(ticketpriceint);
    }
    else{}
    MainWindow m;
    m.dbopened();
    QString initstatus = "PENDING";
    QSqlQuery qry;
    qry.prepare("insert into bookingdata (acc_id,flightnum,seat,seatclass,date,time,gate,departure,arrival,distance,flightstatus,ticketstatus,price)" "values ('"+accid+"','"+flightnum+"','"+seatselected+"','"+seatclass+"','"+date+"','"+time+"','"+gatenum+"','"+departure+"','"+arrival+"','"+distance+"','"+flightstatus+"','"+initstatus+"','"+ticketprice+"')");
    if(qry.exec()){
           QMessageBox::information(this,"Redirecting...","Registered Sucessfully!");
           m.dbclosed();
           hide();
           MainWindow *m;
           m = new MainWindow(this);
           m->show();
    }
    else{QMessageBox::information(this,"Redirecting...","ERROR!");}
}

void Seats::on_A30_clicked()
{
    seatselected = "A30";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A29_clicked()
{
    seatselected = "A29";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A28_clicked()
{
    seatselected = "A28";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A27_clicked()
{
    seatselected = "A27";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A26_clicked()
{
    seatselected = "A26";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A25_clicked()
{
    seatselected = "A25";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}
void Seats::on_A24_clicked()
{
    seatselected = "A24";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A23_clicked()
{
    seatselected = "A23";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A22_clicked()
{
    seatselected = "A22";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A21_clicked()
{
    seatselected = "A21";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A20_clicked()
{
    seatselected = "A20";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A19_clicked()
{
    seatselected = "A19";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A18_clicked()
{
    seatselected = "A18";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A17_clicked()
{
    seatselected = "A17";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A16_clicked()
{
    seatselected = "A16";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A15_clicked()
{
    seatselected = "A15";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A14_clicked()
{
    seatselected = "A14";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A13_clicked()
{
    seatselected = "A13";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A12_clicked()
{
    seatselected = "A12";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A11_clicked()
{
    seatselected = "A11";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A10_clicked()
{
    seatselected = "A10";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A09_clicked()
{
    seatselected = "A09";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A08_clicked()
{
    seatselected = "A08";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A07_clicked()
{
    seatselected = "A07";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A06_clicked()
{
    seatselected = "A06";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A05_clicked()
{
    seatselected = "A05";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A04_clicked()
{
    seatselected = "A04";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A03_clicked()
{
    seatselected = "A03";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A02_clicked()
{
    seatselected = "A02";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_A01_clicked()
{
    seatselected = "A01";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B30_clicked()
{
    seatselected = "B30";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B29_clicked()
{
    seatselected = "B29";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B28_clicked()
{
    seatselected = "B28";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B27_clicked()
{
    seatselected = "B27";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B26_clicked()
{
    seatselected = "B26";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B25_clicked()
{
    seatselected = "B25";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}
void Seats::on_B24_clicked()
{
    seatselected = "B24";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B23_clicked()
{
    seatselected = "B23";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B22_clicked()
{
    seatselected = "B22";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B21_clicked()
{
    seatselected = "B21";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B20_clicked()
{
    seatselected = "B20";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B19_clicked()
{
    seatselected = "B19";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B18_clicked()
{
    seatselected = "B18";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B17_clicked()
{
    seatselected = "B17";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B16_clicked()
{
    seatselected = "B16";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B15_clicked()
{
    seatselected = "B15";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B14_clicked()
{
    seatselected = "B14";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B13_clicked()
{
    seatselected = "B13";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B12_clicked()
{
    seatselected = "B12";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B11_clicked()
{
    seatselected = "B11";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B10_clicked()
{
    seatselected = "B10";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B09_clicked()
{
    seatselected = "B09";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B08_clicked()
{
    seatselected = "B08";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B07_clicked()
{
    seatselected = "B07";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B06_clicked()
{
    seatselected = "B06";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B05_clicked()
{
    seatselected = "B05";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B04_clicked()
{
    seatselected = "B04";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B03_clicked()
{
    seatselected = "B03";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B02_clicked()
{
    seatselected = "B02";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_B01_clicked()
{
    seatselected = "B01";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C30_clicked()
{
    seatselected = "C30";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C29_clicked()
{
    seatselected = "C29";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C28_clicked()
{
    seatselected = "C28";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C27_clicked()
{
    seatselected = "C27";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C26_clicked()
{
    seatselected = "C26";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C25_clicked()
{
    seatselected = "C25";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}
void Seats::on_C24_clicked()
{
    seatselected = "C24";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C23_clicked()
{
    seatselected = "C23";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C22_clicked()
{
    seatselected = "C22";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C21_clicked()
{
    seatselected = "C21";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C20_clicked()
{
    seatselected = "C20";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C19_clicked()
{
    seatselected = "C19";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C18_clicked()
{
    seatselected = "C18";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C17_clicked()
{
    seatselected = "C17";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C16_clicked()
{
    seatselected = "C16";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C15_clicked()
{
    seatselected = "C15";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C14_clicked()
{
    seatselected = "C14";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C13_clicked()
{
    seatselected = "C13";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C12_clicked()
{
    seatselected = "C12";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C11_clicked()
{
    seatselected = "C11";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C10_clicked()
{
    seatselected = "C10";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C09_clicked()
{
    seatselected = "C09";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C08_clicked()
{
    seatselected = "C08";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C07_clicked()
{
    seatselected = "C07";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C06_clicked()
{
    seatselected = "C06";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C05_clicked()
{
    seatselected = "C05";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C04_clicked()
{
    seatselected = "C04";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C03_clicked()
{
    seatselected = "C03";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C02_clicked()
{
    seatselected = "C02";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_C01_clicked()
{
    seatselected = "C01";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D30_clicked()
{
    seatselected = "D30";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D29_clicked()
{
    seatselected = "D29";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D28_clicked()
{
    seatselected = "D28";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D27_clicked()
{
    seatselected = "D27";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D26_clicked()
{
    seatselected = "D26";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D25_clicked()
{
    seatselected = "D25";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}
void Seats::on_D24_clicked()
{
    seatselected = "D24";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D23_clicked()
{
    seatselected = "D23";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D22_clicked()
{
    seatselected = "D22";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D21_clicked()
{
    seatselected = "D21";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D20_clicked()
{
    seatselected = "D20";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D19_clicked()
{
    seatselected = "D19";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D18_clicked()
{
    seatselected = "D18";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D17_clicked()
{
    seatselected = "D17";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D16_clicked()
{
    seatselected = "D16";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D15_clicked()
{
    seatselected = "D15";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D14_clicked()
{
    seatselected = "D14";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D13_clicked()
{
    seatselected = "D13";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D12_clicked()
{
    seatselected = "D12";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D11_clicked()
{
    seatselected = "D11";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D10_clicked()
{
    seatselected = "D10";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D09_clicked()
{
    seatselected = "D09";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D08_clicked()
{
    seatselected = "D08";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D07_clicked()
{
    seatselected = "D07";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D06_clicked()
{
    seatselected = "D06";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D05_clicked()
{
    seatselected = "D05";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D04_clicked()
{
    seatselected = "D04";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D03_clicked()
{
    seatselected = "D03";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D02_clicked()
{
    seatselected = "D02";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_D01_clicked()
{
    seatselected = "D01";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E30_clicked()
{
    seatselected = "E30";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E29_clicked()
{
    seatselected = "E29";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E28_clicked()
{
    seatselected = "E28";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E27_clicked()
{
    seatselected = "E27";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E26_clicked()
{
    seatselected = "E26";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E25_clicked()
{
    seatselected = "E25";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}
void Seats::on_E24_clicked()
{
    seatselected = "E24";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E23_clicked()
{
    seatselected = "E23";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E22_clicked()
{
    seatselected = "E22";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E21_clicked()
{
    seatselected = "E21";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E20_clicked()
{
    seatselected = "E20";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E19_clicked()
{
    seatselected = "E19";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E18_clicked()
{
    seatselected = "E18";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E17_clicked()
{
    seatselected = "E17";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E16_clicked()
{
    seatselected = "E16";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E15_clicked()
{
    seatselected = "E15";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E14_clicked()
{
    seatselected = "E14";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E13_clicked()
{
    seatselected = "E13";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E12_clicked()
{
    seatselected = "E12";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E11_clicked()
{
    seatselected = "E11";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E10_clicked()
{
    seatselected = "E10";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E09_clicked()
{
    seatselected = "E09";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E08_clicked()
{
    seatselected = "E08";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E07_clicked()
{
    seatselected = "E07";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E06_clicked()
{
    seatselected = "E06";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E05_clicked()
{
    seatselected = "E05";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E04_clicked()
{
    seatselected = "E04";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E03_clicked()
{
    seatselected = "E03";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E02_clicked()
{
    seatselected = "E02";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_E01_clicked()
{
    seatselected = "E01";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F30_clicked()
{
    seatselected = "F30";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F29_clicked()
{
    seatselected = "F29";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F28_clicked()
{
    seatselected = "F28";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F27_clicked()
{
    seatselected = "F27";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F26_clicked()
{
    seatselected = "F26";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F25_clicked()
{
    seatselected = "F25";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}
void Seats::on_F24_clicked()
{
    seatselected = "F24";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F23_clicked()
{
    seatselected = "F23";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F22_clicked()
{
    seatselected = "F22";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F21_clicked()
{
    seatselected = "F21";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F20_clicked()
{
    seatselected = "F20";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F19_clicked()
{
    seatselected = "F19";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F18_clicked()
{
    seatselected = "F18";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F17_clicked()
{
    seatselected = "F17";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F16_clicked()
{
    seatselected = "F16";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F15_clicked()
{
    seatselected = "F15";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F14_clicked()
{
    seatselected = "F14";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F13_clicked()
{
    seatselected = "F13";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F12_clicked()
{
    seatselected = "F12";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F11_clicked()
{
    seatselected = "F11";
    seatclass = "ECONOMY";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F10_clicked()
{
    seatselected = "F10";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F09_clicked()
{
    seatselected = "F09";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F08_clicked()
{
    seatselected = "F08";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F07_clicked()
{
    seatselected = "F07";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F06_clicked()
{
    seatselected = "F06";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F05_clicked()
{
    seatselected = "F05";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F04_clicked()
{
    seatselected = "F04";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F03_clicked()
{
    seatselected = "F03";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F02_clicked()
{
    seatselected = "F02";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_F01_clicked()
{
    seatselected = "F01";
    seatclass = "BUSINESS";
    ui->seattype->setText(seatclass);
    ui->seatselectedlbl->setText(seatselected);
}

void Seats::on_buttonreturn_clicked()
{
    hide();
    Calendar *c;
    c = new Calendar(this);
    c->show();
}

void Seats::on_buttonmainmenu_clicked()
{
    hide();
    mainmenu *menu;
    menu = new mainmenu(this);
    menu->show();
}
