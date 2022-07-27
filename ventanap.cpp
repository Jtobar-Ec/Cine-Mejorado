#include "ventanap.h"
#include "ui_ventanap.h"

VentanaP::VentanaP(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaP)
{
    ui->setupUi(this);
    setWindowTitle("CINEMANIASALE");
}

VentanaP::~VentanaP()
{
    delete ui;
}

void VentanaP::on_action_Salir_triggered()
{
    close();
}

void VentanaP::on_actionAcerca_de_triggered()
{
 Acerca *dialog = new Acerca(this);
 dialog->exec();
}

//Funciones con las cuales pasara de una ventana a otra

void VentanaP::on_pbCompra1_clicked()
{
    Sala *ventana = new Sala;
    ventana->show();
    close();
}


void VentanaP::on_pbCompra2_clicked()
{
    Sala *ventana = new Sala;
    ventana->show();
     close();
}


void VentanaP::on_pbCompra3_clicked()
{
    Sala *ventana = new Sala;
    ventana->show();
     close();
}

void VentanaP::on_pbCompra4_clicked()
{
    Sala *ventana = new Sala;
    ventana->show();
     close();
}


void VentanaP::on_pbComprar5_clicked()
{
    Sala *ventana = new Sala;
    ventana->show();
     close();
}

