#include "boleto.h"
#include "ui_boleto.h"

Boleto::Boleto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Boleto)
{
    ui->setupUi(this);
}

Boleto::~Boleto()
{
    delete ui;
}

void Boleto::datosboleto(QString dato)
{
    this->m_boleto = dato;
}

void Boleto::cargarBoleto()
{

    ui->outImprebole->setPlainText(m_boleto);
}

