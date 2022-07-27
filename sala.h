#ifndef SALA_H
#define SALA_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QDir>
#include <string>


#include "compra.h"
#include "factura.h"
#include "ventanap.h"

#define IVA 12

namespace Ui {class Sala;}

class Sala : public QMainWindow
{
    Q_OBJECT

public:
    explicit Sala(QWidget *parent = nullptr);
    ~Sala();

private slots:
    void on_OutCompra_clicked();

    void on_InHorario_currentIndexChanged(int index);

    void on_actionNuevo_triggered();

    void on_btnFactura_pressed();

    void on_actionRegresar_triggered();

private:
    Ui::Sala *ui;
    QList<Compra*> m_Horarios;
    QString m_detalles;
    float m_subtotal;
    float m_iva;
    float m_total;
    int m_contador = 0;

    void cargarHorarios();
    void calcular(float stProducto);
    void enviarDatos();
    bool validarCampos();
    bool validarCI(QString num);
};

#endif // SALA_H
