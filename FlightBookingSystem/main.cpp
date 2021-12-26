#include "mainwindow.h"
#include "flightnumgenerator.h"
#include "calendar.h"
#include "register.h"
#include "mainmenu.h"
#include "map.h"
#include "seats.h"
#include "flight.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FlightNumGenerator fng;
    MainWindow m;
    m.show();
    return a.exec();
}
