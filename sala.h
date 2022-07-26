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

    void on_actionEliminar_triggered();

    void on_InHorario_currentIndexChanged(int index);

    void on_actionNuevo_triggered();

private:
    Ui::Sala *ui;
    QList<Compra*> m_Horarios;
    void cargarHorarios();
    float m_subtotal;
    void calcular(float stProducto);
};

#endif // SALA_H
