#ifndef COMPRA_H
#define COMPRA_H

#include <QObject>

class Compra : public QObject
{
private:
    int m_codigo;
    QString m_nombre;
    float m_precio;

public:
    explicit Compra(QObject *parent = nullptr);
    Compra(int codigo, const QString &nombre, float horario, QObject *parent = nullptr);

    int codigo() const;
    void setCodigo(int newCodigo);
    const QString &nombre() const;
    void setNombre(const QString &newNombre);
    float precio() const;
    void setPrecio(float newPrecio);

signals:
};

#endif // COMPRA_H
