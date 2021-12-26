#ifndef FLIGHTNUMGENERATOR_H
#define FLIGHTNUMGENERATOR_H

#include <QMainWindow>

namespace Ui {
class FlightNumGenerator;
}

class FlightNumGenerator : public QMainWindow
{
    Q_OBJECT

public:
    explicit FlightNumGenerator(QWidget *parent = nullptr);
    QString airlineiata[90] = {"SU","HX","MH","SQ","JL","AI","CP","KE","AM","BA",
                               "AM","SU","MH","SQ","HX","JL","AI","CP","KE","AM",
                               "BA","SU","SU","MH","SQ","HX","JL","AI","CP","KE",
                               "AM","BA","SU","SU","MH","SQ","HX","JL","AI","CP",
                               "KE","AM","BA","SU","SU","MH","SQ","HX","JL","AI",
                               "CP","KE","AM","BA","SU","SU","MH","SQ","HX","JL",
                               "AI","CP","KE","AM","BA","SU","AM","MH","SQ","HX",
                               "HX","JL","AI","CP","KE","BA","SU","SU","MH","SQ",
                               "SQ","HX","JL","AI","CP","KE","AM","BA","SU","MH"};
    QString flightnum;
    void flightnumgenerator();
    ~FlightNumGenerator();

private:
    Ui::FlightNumGenerator *ui;
};

#endif // FLIGHTNUMGENERATOR_H
