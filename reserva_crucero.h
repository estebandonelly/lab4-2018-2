#ifndef RESERVA_CRUCERO_H
#define RESERVA_CRUCERO_H
#include <iostream>


class reserva_crucero
{
private:
    std::string nombre;
    int documentoIdentidad;
    char numeroMaletas;
    bool camaroteReservado;

public:
    reserva_crucero();
    std::string getNombre() const;
    void setNombre(const std::string &value);
    int getDocumentoIdentidad() const;
    void setDocumentoIdentidad(int value);
    char getNumeroMaletas() const;
    void setNumeroMaletas(char value);
    bool getCamaroteReservado() const;
    void setCamaroteReservado(bool value);
};


#endif // RESERVA_CRUCERO_H
