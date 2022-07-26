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

void Sala::enviarDatos()
{
    int filas = ui->OutPelis->rowCount();
    QString detalles = "";
    while (m_contador!=filas) {
        detalles+="\t"+ui->OutPelis->item(m_contador,0)->text()+"\t   " +
                ui->OutPelis->item(m_contador,1)->text()+"\t          " +
                ui->OutPelis->item(m_contador,2)->text()+"\t                    " +
                ui->OutPelis->item(m_contador,3)->text()+"\t                " +
                ui->OutPelis->item(m_contador,4)->text()+"\t\t\n";
        m_contador++;
    }
    m_detalles = detalles;
}

bool Sala::validarCampos()
{
    if(validarCI(ui->inCi->text())==true && ui->inCi->text()!="9999999999"){

            ui->inCi->setStyleSheet("QLineEdit{ background-color: green}");

            if(ui->inNombre->text()==""){
                ui->inNombre->setStyleSheet("QLineEdit{ background-color: orange}");
            }else{
                ui->inNombre->setStyleSheet("QLineEdit{ background-color: green}");
            }
            if(ui->inTelefono->text()==""){
                ui->inTelefono->setStyleSheet("QLineEdit{ background-color: orange}");
            }else{
                ui->inTelefono->setStyleSheet("QLineEdit{ background-color: green}");
            }
            if(ui->inEmail->text()==""){
                ui->inEmail->setStyleSheet("QLineEdit{ background-color: orange}");
            }else{
                ui->inEmail->setStyleSheet("QLineEdit{ background-color: green}");
            }
            if(ui->inDireccion->toPlainText()==""){
                ui->inDireccion->setStyleSheet("QPlainTextEdit {background-color: orange}");
            }else{
                ui->inDireccion->setStyleSheet("QPlainTextEdit {background-color: green}");
            }
            if(ui->inCi->text()=="" || ui->inNombre->text()=="" || ui->inTelefono->text()=="" || ui->inEmail->text()==""||ui->inDireccion->toPlainText()==""){
                return false;
            }
            if(ui->inCi->text()!="" && ui->inNombre->text()!="" && ui->inTelefono->text()!="" && ui->inEmail->text()!="" && ui->inDireccion->toPlainText()!=""){
                return true;
            }
        }else if(ui->inCi->text()=="9999999999"){
            return true;
        }else{
            if(validarCI(ui->inCi->text())==false){
                ui->inCi->setStyleSheet("QLineEdit{ background-color: orange}");
                return false;
            }
        }
        return true;
}

bool Sala::validarCI(QString num)
{
    bool est = true;
        int vcedula[10];
        int vPar[4];
        int vImpar[5]={0};
        int sumaPar=0;
        int sumaImpar=0;
        int total;
        int nveri;

        double nu;

        if(num=="9999999999"){
            return true;
        }

        do
        {
            nu=num.toInt();
            if(nu<100000000 || nu>9999999999)
            {

                est=false;
                break;
            }


            //Separar string
            QString p1=num.mid(0,1);
            QString p2=num.mid(1,1);
            QString p3=num.mid(2,1);
            QString p4=num.mid(3,1);
            QString p5=num.mid(4,1);
            QString p6=num.mid(5,1);
            QString p7=num.mid(6,1);
            QString p8=num.mid(7,1);
            QString p9=num.mid(8,1);
            QString p10=num.mid(9,1);

            //Transformar string
            vcedula[0]=p1.toInt();
            vcedula[1]=p2.toInt();
            vcedula[2]=p3.toInt();
            vcedula[3]=p4.toInt();
            vcedula[4]=p5.toInt();
            vcedula[5]=p6.toInt();
            vcedula[6]=p7.toInt();
            vcedula[7]=p8.toInt();
            vcedula[8]=p9.toInt();
            vcedula[9]=p10.toInt();

            if(vcedula[0]>2)
            {

                est = false;
                break;
            }

            //Pares
            vPar[0]=vcedula[1];
            vPar[1]=vcedula[3];
            vPar[2]=vcedula[5];
            vPar[3]=vcedula[7];
            //Impares
            vImpar[0]=vcedula[0];
            vImpar[1]=vcedula[2];
            vImpar[2]=vcedula[4];
            vImpar[3]=vcedula[6];
            vImpar[4]=vcedula[8];


            //Multiplicacion impar
            for(int i=0; i<5; i++)
            {
                vImpar[i]=vImpar[i]*2;
                if(vImpar[i]>9)
                {
                    vImpar[i]=vImpar[i]-9;
                }
                sumaImpar += vImpar[i];
            }
            //Sumar los pares
            for(int i=0; i<4; i++)
            {
                sumaPar += vPar[i];
            }

            total = sumaPar + sumaImpar;

            //Se obtiene el modulo

            nveri = total%10;


            //Numero verificador
            if(nveri==0)
            {
                if(nveri==vcedula[9])
                {
                    est=true;
                    break;
                }else
                {
                    est=false;
                    break;
                }
            }else if(nveri !=0)
            {
                nveri=10-nveri;

                if(nveri==vcedula[9])
                {
                    est=true;
                    break;
                }else
                {

                    est=false;
                    break;
                }
            }

        }while(nu<100000000 || nu>9999999999 || vcedula[0]>2);
        return est;

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
        ui->inNombre->clear();
        ui->inCi->clear();
        ui->inDireccion->clear();
        ui->inEmail->clear();
        ui->inTelefono->clear();

        m_subtotal=0;

        ui->outSubtotal->setText("$ 0.00");
        ui->outIva->setText("$ 0.00");
        ui->outTotal->setText("$ 0.00");
        ui->inCi->setStyleSheet("QLineEdit{ background-color: white}");
        ui->inNombre->setStyleSheet("QLineEdit{ background-color: white}");
        ui->inTelefono->setStyleSheet("QLineEdit{ background-color: white}");
        ui->inEmail->setStyleSheet("QLineEdit{ background-color: white}");
        ui->inDireccion->setStyleSheet("QPlainTextEdit {background-color: white}");
        m_detalles="";
        m_contador=0;

}





void Sala::on_btnFactura_pressed()
{
    if(validarCampos()==true){
    Factura *factura = new Factura(this);
    enviarDatos();
    if(ui->inCi->text()!="9999999999"){
                factura->datosfac(ui->inCi->text(),ui->inNombre->text(),
                                      ui->inTelefono->text(),ui->inEmail->text(),
                                      ui->inDireccion->toPlainText(),m_detalles);
            }else{
                QString nombre= "Consumidor Final";
                QString telefono="**********";
                QString email="***********@gmail.com";
                QString direccion="***************";
                factura->datosfac(ui->inCi->text(),nombre,
                                      telefono,email,
                                      direccion,m_detalles);
            }


            factura->datosPrecios(m_subtotal,m_iva,m_total);
            if(m_contador !=0){
                factura->cargarDatos();
                factura->exec();
                on_actionNuevo_triggered();
            }
    }
 }
