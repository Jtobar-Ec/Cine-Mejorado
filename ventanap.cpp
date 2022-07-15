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

void VentanaP::on_action_Salir_triggered()
{
    close();
}

void VentanaP::on_actionAcerca_de_triggered()
{
 Acerca *dialog = new Acerca(this);
 dialog->exec();
}

void VentanaP::on_pushButton_clicked()
{

}
