#ifndef BOLETO_H
#define BOLETO_H

#include <QDialog>
#include <QDate>

namespace Ui {
class Boleto;
}

class Boleto : public QDialog
{
    Q_OBJECT

public:
    explicit Boleto(QWidget *parent = nullptr);
    ~Boleto();
    void datosboleto(QString dato);
    void cargarBoleto();


private:
    Ui::Boleto *ui;
    QString m_boleto;

};

#endif // BOLETO_H
