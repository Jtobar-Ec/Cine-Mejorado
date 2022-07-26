#include "factura.h"
#include "ui_factura.h"

Factura::Factura(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Factura)
{
    ui->setupUi(this);
}

Factura::~Factura()
{
    delete ui;
}

void Factura::datosfac(QString ci, QString nombre, QString telefono, QString email, QString direccion, QString detalles)
{
    this->m_cedula = ci;
    this->m_nombre = nombre;
    this->m_telefono = telefono;
    this->m_email = email;
    this->m_direccion = direccion;
    this->m_detalles = detalles;
}

void Factura::datosPrecios(float subtotal, float iva, float total)
{
    this->m_subtotal = subtotal;
    this->m_ivafac = iva;
    this->m_totalfac = total;
}

void Factura::cargarDatos()
{
    ui->outNombre->setText(m_nombre);
    ui->outCi->setText(m_cedula);
    ui->outDireccion->setText(m_direccion);
    ui->outEmail->setText(m_email);
    ui->outTelefono->setText(m_telefono);
    ui->outDetallecompra->setPlainText(m_detalles);
    m_fecha = QDate::currentDate().toString(Qt::ISODate);
    ui->outFecha->setText(m_fecha);
    m_fechahora = QDateTime::currentDateTime().toString("ddMMyyyy_hhmmss");

}
