#include "compra.h"

Compra::Compra(int codigo, const QString &nombre, float precio, QObject *parent) : QObject(parent),
        m_codigo(codigo),
        m_nombre(nombre),
        m_precio(precio)
{}

int Compra::codigo() const
{
    return m_codigo;
}

void Compra::setCodigo(int newCodigo)
{
      m_codigo = newCodigo;
}

const QString &Compra::nombre() const
{
    return m_nombre;
}

void Compra::setNombre(const QString &newNombre)
{
    m_nombre = newNombre;
}

float Compra::precio() const
{
    return m_precio;
}

void Compra::setPrecio(float newPrecio)
{
     m_precio = newPrecio;
}
