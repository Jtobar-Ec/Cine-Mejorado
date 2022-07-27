#include "compra.h"

Compra::Compra(int codigo, const QString &hora, int minuto,float precio,float precio_infantil,int sala, QObject *parent) : QObject(parent),
        m_codigo(codigo),
        m_Hora(hora),
        m_Minuto(minuto),
        m_Precio(precio),
        m_PrecioInfantil(precio_infantil),
        m_sala(sala)
{}

int Compra::codigo() const
{
    return m_codigo;
}

void Compra::setCodigo(int newCodigo)
{
      m_codigo = newCodigo;
}

const QString &Compra::Hora() const
{
    return m_Hora;
}

void Compra::setHora(const QString &newHora)
{
    m_Hora = newHora;
}

int Compra::minuto() const
{
    return m_Minuto;
}

void Compra::setMinuto(float newMinuto)
{
    m_Minuto = newMinuto;
}

float Compra::precio() const
{
    return m_Precio;
}

void Compra::setPrecio(float newPrecio)
{
    m_Precio = newPrecio;
}

float Compra::precioInfa() const
{
    return m_PrecioInfantil;
}

void Compra::setPrecioinfa(float newPrecioinfa)
{
    m_PrecioInfantil = newPrecioinfa;
}

int Compra::sala() const
{
    return m_sala;
}

void Compra::setSala(float newSala)
{
    m_sala = newSala;
}
