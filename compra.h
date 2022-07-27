#ifndef COMPRA_H
#define COMPRA_H

#include <QObject>

class Compra : public QObject
{
private:
    int m_codigo;
    QString m_Hora;
    int m_Minuto;
    float m_Precio;
    float m_PrecioInfantil;
    int m_sala;

public:
    explicit Compra(QObject *parent = nullptr);
    Compra(int codigo, const QString &hora, int minuto,float precio,float precio_infantil,int sala, QObject *parent = nullptr);

    int codigo() const;
    void setCodigo(int newCodigo);
    const QString &Hora() const;
    void setHora(const QString &newHora);
    int minuto() const;
    void setMinuto(float newMinuto);
    float precio() const;
    void setPrecio(float newPrecio);
    float precioInfa() const;
    void setPrecioinfa(float newPrecioinfa);
    int sala() const;
    void setSala(float newSala);


signals:
};

#endif // COMPRA_H
