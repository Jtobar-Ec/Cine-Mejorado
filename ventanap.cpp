#include "ventanap.h"
#include "ui_ventanap.h"

VentanaP::VentanaP(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaP)
{
    ui->setupUi(this);
}

VentanaP::~VentanaP()
{
    delete ui;
}
