#include "reserva_crucero.h"


std::string reserva_crucero::getNombre() const
{
    return nombre;
}

void reserva_crucero::setNombre(const std::string &value)
{
    nombre = value;
}

int reserva_crucero::getDocumentoIdentidad() const
{
    return documentoIdentidad;
}

void reserva_crucero::setDocumentoIdentidad(int value)
{
    documentoIdentidad = value;
}

char reserva_crucero::getNumeroMaletas() const
{
    return numeroMaletas;
}

void reserva_crucero::setNumeroMaletas(char value)
{
    numeroMaletas = value;
}

bool reserva_crucero::getCamaroteReservado() const
{
    return camaroteReservado;
}

void reserva_crucero::setCamaroteReservado(bool value)
{
    camaroteReservado = value;
}

reserva_crucero::reserva_crucero()
{
    this->setCamaroteReservado(false);
    this->setDocumentoIdentidad(0);
    this->setNombre("");
    this->setNumeroMaletas(0);

}
