#ifndef FACTURA_H
#define FACTURA_H

#include <QDialog>
#include <QTextStream>
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QDateTime>
#include <QDate>

namespace Ui {
class Factura;
}

class Factura : public QDialog
{
    Q_OBJECT

public:
    explicit Factura(QWidget *parent = nullptr);
    ~Factura();

    void datosfac(QString ci,QString nombre,QString telefono, QString email,QString direccion,QString detalles);
    void datosPrecios(float subtotal,float iva,float total);
    void cargarDatos();

private:
    Ui::Factura *ui;
    QString m_fechahora;
    QString m_fecha;
    QString m_detalles;
    QString m_cedula;
    QString m_nombre;
    QString m_telefono;
    QString m_email;
    QString m_direccion;
    float m_subtotal;
    float m_ivafac;
    float m_totalfac;

};

#endif // FACTURA_H
