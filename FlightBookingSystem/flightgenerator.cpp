#include "flightgenerator.h"
#include "mainwindow.h"
#include <QtSql>

FlightGenerator::FlightGenerator()
{

}

void FlightGenerator::flightnumgenerator(){
    MainWindow m;
    m.dbopened();
    QSqlQueryModel readflightdata;
    QSqlQuery randomgenerator;
    readflightdata.setQuery("select * from flight");
    for (int i = 0; i< readflightdata.rowCount(); i++){
        QString no = readflightdata.record(i).value("no").toString();
        int randomnum = qrand() % (9999 - 1000 + 1) + 1000;
        QString randomnumstr = QString::number(randomnum);
        flightnum = airlineiata[i] + randomnumstr;
        randomgenerator.prepare("update flight set flightnum = '"+flightnum+"' where no = '"+no+"'");
        if (randomgenerator.exec()){qDebug()<<"success";}
        else{qDebug()<<"failed";}}
    m.dbclosed();
}
