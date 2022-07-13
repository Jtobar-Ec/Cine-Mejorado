#ifndef VENTANAP_H
#define VENTANAP_H

#include <QMainWindow>
#include "acerca.h"

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

private:
    Ui::VentanaP *ui;
};

#endif // VENTANAP_H
