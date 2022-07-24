#include "sala.h"

#include "ui_Sala.h"

#include <QDebug>

Sala::Sala(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Sala)
{
    ui->setupUi(this);
    // Lista de productos
    cargarProductos();
    // Mostrar los productos en el combo
    foreach (Compra *p, m_productos){
        ui->InHorario->addItem(p->nombre());
    }
    // Configurar cabecera de la tabla
    QStringList cabecera = {"Cantidad", "Producto", "P. unitario", "Subtotal"};
    ui->OutPelis->setColumnCount(4);
    ui->OutPelis->setHorizontalHeaderLabels(cabecera);
    // Establecer el subtotal a 0
    m_subtotal = 0;

}
Sala::~Sala()
{
    delete ui;
}

void Sala::on_OutBoletos_valueChanged(int arg1)
{

}


void Sala::on_Adultos_valueChanged(int arg1)
{

}


void Sala::on_NInos_valueChanged(int arg1)
{

}


void Sala::on_groupBox_2_clicked()
{

}


void Sala::on_pushButton_clicked()
{

}

