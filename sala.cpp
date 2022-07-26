#include "sala.h"

#include "ui_Sala.h"

#include <QDebug>
#include <string>
#include <QString>


Sala::Sala(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Sala)
{
    ui->setupUi(this);
    setWindowTitle("Sala de cine");
    // Lista de productos
    cargarHorarios();
    // Mostrar los productos en el combo
    foreach (Compra *p, m_Horarios){
        ui->InHorario->addItem(p->Hora()+":"+QString::number(p->minuto()));
    }
    // Configurar cabecera de la tabla
    QStringList cabecera = {"ID", "N.Personas", "Asientos", "Horario", "Subtotal"};
    ui->OutPelis->setColumnCount(5);
    ui->OutPelis->setHorizontalHeaderLabels(cabecera);
    // Establecer el subtotal a 0
    m_subtotal = 0;

}
Sala::~Sala()
{
    delete ui;
}


void Sala::cargarHorarios()
{

// Podría leerse de una base de datos, de un archivo o incluso de Internet
    QDir actual= QDir::current();
    QString archivoHorarios= actual.absolutePath()+"/debug/Horarios.csv";
    QFile archivo(archivoHorarios);

    if (archivo.open(QIODevice::ReadOnly | QIODevice::Text)){
        bool primera =true;
        QTextStream in(&archivo);
        while(!in.atEnd()){
            QString linea = in.readLine();
            if(primera){
                primera=false;
                continue;

            }
            QStringList datos = linea.split(";");
            QString minuto = datos.at(2);
            QString precio = datos.at(3);
            QString precioinfa = datos.at(4);
            int min= minuto.toInt();
            float pre = precio.toFloat();
            float preinfa = precioinfa.toFloat();
            int id= datos.at(0).toInt();
            m_Horarios.append(new Compra(id,datos.at(1),min,pre,preinfa));
        }
        archivo.close();

    }else{
        qDebug()<<"No se pudo abrir el archivo";
    }
}

void Sala::calcular(float stProducto)
{
    //calcular valores
    m_subtotal += stProducto;
    float iva = m_subtotal * IVA /100;
    float total = m_subtotal + iva;

    //Moatrar en la GUI
    ui->outSubtotal->setText("$ "+ QString::number(m_subtotal, 'f',2));
    ui->outIva->setText("$ " + QString::number(iva, 'f', 2));
    ui->outTotal->setText("$ " + QString::number(total, 'f', 2));
}


void Sala::on_OutCompra_clicked()
{
    bool A1,A2,A3,A4,B1,B2,B3,B4,C1,C2;

    // Validar que no se agrege 0 cantidad
    int AdulCAn = ui->Adultos->value();
    int NinCan=ui->NInos->value();

    //validación
    if (AdulCAn==false && NinCan==false){
       return;
    }


    // Obtener los datos de la GUI
    int i = ui->InHorario->currentIndex();
    Compra *p = m_Horarios.at(i);

    QString msg="";
    // Calcular el subrotal de la compra
    float persona = p->precio() * AdulCAn;
    float personapeque = p->precioInfa() * NinCan;
    float resultado = persona + personapeque;

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
    ui->OutPelis->setItem(fila, 1, new QTableWidgetItem(QString::number((AdulCAn+NinCan),'f',0)));
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
    ui->OutPelis->setItem(fila, 3, new QTableWidgetItem(p->Hora()+":"+QString::number(p->minuto())));
    ui->OutPelis->setItem(fila, 4, new QTableWidgetItem(QString::number(resultado,'f',2)));

    //Limpiar valores
    ui->Adultos->setValue(0);
    ui->NInos->setValue(0);
    ui->InHorario->setFocus();
    calcular(resultado);

}


void Sala::on_actionEliminar_triggered()
{
     update();
}

void Sala::on_InHorario_currentIndexChanged(int index)
{
    float precio = m_Horarios.at(index)->precio();
    ui->outPrecio->setText("$ "+QString::number(precio,'f',2));
    ui->Adultos->setValue(0);
    ui->NInos->setValue(0);
}



void Sala::on_actionNuevo_triggered()
{
    //limpiar cuadro de detalles de compra
        while(ui->OutPelis->rowCount()>0){
            ui->OutPelis->removeRow(0);
        }
    ui->Adultos->clear();
    ui->NInos->clear();
    ui->outSubtotal->clear();
    ui->outIva->clear();
    ui->outTotal->clear();
}

