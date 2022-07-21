#ifndef VENTANAP_H
#define VENTANAP_H

#include <QMainWindow>
#include "acerca.h"
#include "sala.h"

namespace Ui {class VentanaP;}

class VentanaP : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaP(QWidget *parent = nullptr);
    ~VentanaP();

private slots:
    void on_action_Salir_triggered();

    void on_actionAcerca_de_triggered();

    void on_pushButton_clicked();

    void on_pbCompra1_clicked();

    void on_pbCompra2_clicked();

    void on_pbCompra3_clicked();

    void on_pbCompra4_clicked();

    void on_pbComprar5_clicked();

private:
    Ui::VentanaP *ui;
};

#endif // VENTANAP_H
