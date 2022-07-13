#ifndef VENTANAP_H
#define VENTANAP_H

#include <QMainWindow>

namespace Ui {
class VentanaP;
}

class VentanaP : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaP(QWidget *parent = nullptr);
    ~VentanaP();

private:
    Ui::VentanaP *ui;
};

#endif // VENTANAP_H
