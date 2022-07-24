#ifndef SALA_H
#define SALA_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QDir>

#include <compra.h>>

namespace Ui {class Sala;}

class Sala : public QMainWindow
{
    Q_OBJECT

public:
    explicit Sala(QWidget *parent = nullptr);
    ~Sala();

private slots:
    void on_OutBoletos_valueChanged(int arg1);

    void on_Adultos_valueChanged(int arg1);

    void on_NInos_valueChanged(int arg1);

    void on_groupBox_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Sala *ui;

    QList<Compra*> m_productos;
    void cargarProductos();
    float m_subtotal;

    void calcular(float stProducto);
};

#endif // SALA_H
