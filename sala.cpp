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
    QStringList cabecera = {"ID", "N.Personas", "Asientos", "Horario"};
    ui->OutPelis->setColumnCount(4);
    ui->OutPelis->setHorizontalHeaderLabels(cabecera);
    // Establecer el subtotal a 0
    m_subtotal = 0;

}
Sala::~Sala()
{
    delete ui;
}

void Sala::cargarProductos()
{
    // Crear productos "quemados" en el código
    m_productos.append(new Compra(1, "14:00", 0.80));
    m_productos.append(new Compra(2, "16:00", 0.15));
    m_productos.append(new Compra(3, "18:00", 2.50));
// Podría leerse de una base de datos, de un archivo o incluso de Internet
    QDir actual= QDir::current();
    QString archivoProductos= actual.absolutePath()+"/debug/Productos.csv";
    QFile archivo(archivoProductos);

    if (archivo.open(QIODevice::ReadOnly | QIODevice::Text)){
        bool primera =true;
        QTextStream in (&archivo);
        while(in.atEnd()){
            if(primera){
                primera=false;
                continue;

            }
            QString linea= in.readLine();
            QStringList datos= linea.split(":");
            QString precio = datos.at(2);
            float p= precio.toFloat();
            int id= datos.at(0).toInt();
            m_productos.append(new Compra(id,datos.at(1),p));
        }
        archivo.close();

    }else{
        qDebug()<<"No se pudo abrir el archivo";
    }
}




void Sala::on_OutCompra_clicked()
{

    bool A1,A2,A3,A4,B1,B2,B3,B4,C1,C2;

    // Validar que no se agregen productos cpn 0 cantidad
    int AdulCAn = ui->Adultos->value();
    int NinCan=ui->NInos->value();
    if (AdulCAn == 0 || NinCan==0){
        return;
    }
    // Obtener los datos de la GUI
    int i = ui->InHorario->currentIndex();
    Compra *p = m_productos.at(i);
    QString msg="";
    // Calcular el subrotal del producto
    float persona = ui->Adultos->value()+ui->NInos->value();


    A1=ui->A1->isChecked();
    A2=ui->A2->isChecked();
    A3=ui->A3->isChecked();
    A4=ui->A4->isChecked();
    B1=ui->B1->isChecked();
    B2=ui->B2->isChecked();
    B3=ui->B3->isChecked();
    B4=ui->B4->isChecked();
    C1=ui->C1->isChecked();
    C2=ui->C2->isChecked();

    // Agregar los datos a la tabla
    int fila = ui->OutPelis->rowCount();
    ui->OutPelis->insertRow(fila);
    ui->OutPelis->setItem(fila, 0, new QTableWidgetItem(QString::number(1)));
    ui->OutPelis->setItem(fila, 1, new QTableWidgetItem(QString::number(persona,'f',0)));
    msg="";

    if (A1){
        msg+="A1  ";
    }
    if (A2){
        msg+="A2  ";
    }
    if (A3){
        msg+="A3  ";
    }
    if (A4){
        msg+="A4  ";
    }
    if (B1){
        msg+="B1  ";
    }
    if (B2){
        msg+="B2  ";
    }
    if (B3){
        msg+="B3  ";
    }
    if (B4){
        msg+="B4  ";
    }
    if (C1){
        msg+="C1  ";
    }
    if (C2){
        msg+="C2  ";
    }


    ui->OutPelis->setItem(fila,2,new QTableWidgetItem(msg));
    ui->OutPelis->setItem(fila, 3, new QTableWidgetItem(p->nombre()));







}


void Sala::on_actionEliminar_triggered()
{
     update();
}

