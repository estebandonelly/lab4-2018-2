#include <QCoreApplication>
#include <QDebug>
#include <vector>
#include "reserva_crucero.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream qtin(stdin);
    reserva_crucero *reserva;
    std::vector<reserva_crucero*> economica;
    std::vector<reserva_crucero*> turistica;
    std::vector<reserva_crucero*> premium;
    for (int var = 0; var < 50; ++var) {
        reserva = new reserva_crucero();
        economica.push_back(reserva);
        reserva = new reserva_crucero();
        turistica.push_back(reserva);
        reserva = new reserva_crucero();
        premium.push_back(reserva);
    }

    bool reservar=true;
    while (reservar) {
        qDebug() << "SISTEMA DE RESERVAS CRUCERO \n1.Realizar una reserva \n2.Consultar Reservas \n3.Salir";
        QString accion = qtin.readLine();
        if(accion.toInt()==1){
            qDebug() << "Sistema de reservas crucero esteban y andres, \n"
                        "Seleccione una opcion.\n"
                        "1: Clase Economica.\n"
                        "2: Clase Turistica.\n"
                        "3: Clase Premium.\n";
            qDebug() << "Digite el numero de la clase:";
            QString opc = qtin.readLine();
            switch (opc.toInt()) {
            case 1:
            {
                qDebug() << "Favor elija el numero del camarote (1 - 50)";
                QString camarote = qtin.readLine();
                int numeroCamarote = camarote.toInt()-1;
                while(economica[numeroCamarote]->getCamaroteReservado()){
                    qDebug() << "El camarote digitado ya se encuentra reservado, favor elegir otro.";
                    qDebug() << "Favor elija el numero del camarote (1 - 50)";
                    camarote = qtin.readLine();
                    numeroCamarote = camarote.toInt()-1;
                }
                if(!economica[numeroCamarote]->getCamaroteReservado()){
                    qDebug() << "Favor digite el nombre de quien reserva: ";
                    economica[numeroCamarote]->setNombre(qtin.readLine().toStdString());
                    qDebug() << "Favor digite el documento de identidad: ";
                    economica[numeroCamarote]->setDocumentoIdentidad(qtin.readLine().toInt());
                    qDebug() << "Favor digite la cantidad de maletas.";
                    economica[numeroCamarote]->setNumeroMaletas(QString(qtin.readLine())[0].toLatin1());
                    economica[numeroCamarote]->setCamaroteReservado(true);
                }
                break;
            }
            case 2:
            {
                qDebug() << "Favor elija el numero del camarote (1 - 50)";
                QString camarote = qtin.readLine();
                int numeroCamarote = camarote.toInt()-1;
                while(turistica[numeroCamarote]->getCamaroteReservado()){
                    qDebug() << "El camarote digitado ya se encuentra reservado, favor elegir otro.";
                    qDebug() << "Favor elija el numero del camarote (1 - 50)";
                    camarote = qtin.readLine();
                    numeroCamarote = camarote.toInt()-1;
                }
                if(!turistica[numeroCamarote]->getCamaroteReservado()){
                    qDebug() << "Favor digite el nombre de quien reserva: ";
                    turistica[numeroCamarote]->setNombre(qtin.readLine().toStdString());
                    qDebug() << "Favor digite el documento de identidad: ";
                    turistica[numeroCamarote]->setDocumentoIdentidad(qtin.readLine().toInt());
                    qDebug() << "Favor digite la cantidad de maletas.";
                    turistica[numeroCamarote]->setNumeroMaletas(QString(qtin.readLine())[0].toLatin1());
                    turistica[numeroCamarote]->setCamaroteReservado(true);
                }
                break;
            }
            case 3:
            {
                qDebug() << "Favor elija el numero del camarote (1 - 50)";
                QString camarote = qtin.readLine();
                int numeroCamarote = camarote.toInt()-1;
                while(premium[numeroCamarote]->getCamaroteReservado()){
                    qDebug() << "El camarote digitado ya se encuentra reservado, favor elegir otro.";
                    qDebug() << "Favor elija el numero del camarote (1 - 50)";
                    camarote = qtin.readLine();
                    numeroCamarote = camarote.toInt()-1;
                }
                if(!premium[numeroCamarote]->getCamaroteReservado()){
                    qDebug() << "Favor digite el nombre de quien reserva: ";
                    premium[numeroCamarote]->setNombre(qtin.readLine().toStdString());
                    qDebug() << "Favor digite el documento de identidad: ";
                    premium[numeroCamarote]->setDocumentoIdentidad(qtin.readLine().toInt());
                    qDebug() << "Favor digite la cantidad de maletas.";
                    premium[numeroCamarote]->setNumeroMaletas(QString(qtin.readLine())[0].toLatin1());
                    premium[numeroCamarote]->setCamaroteReservado(true);
                }
                break;
            }
            }
        }
        else if(accion.toInt()==2){
            qDebug() << "clave de seguriad:informatica2-2018-2 .";
            qDebug() << "Consultar informacion de reservas.";
            qDebug() << "Favor digite la clave de seguridad: ";
            QString clave = qtin.readLine();
            if ("informatica2-2018-2"==clave){
                qDebug() << "Consultando informacion de reservas.";
                int camarotesDispoEco=50,camarotesDispoTuri=50,camarotesDispoPre=50;
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 50; ++j) {
                        if (i==0){
                            if(economica[j]->getCamaroteReservado()){
                                qDebug() << "Clase Economica, Camarote Numero:" << QString::number(j+1) <<
                                            "Reservado por: " << QString::fromStdString(economica[j]->getNombre());
                                camarotesDispoEco--;
                            }

                        }else if(i==1){
                            if(turistica[j]->getCamaroteReservado()){
                                qDebug() << "Clase Turistica, Camarote Numero:" << QString::number(j+1) <<
                                            "Reservado por: " << QString::fromStdString(turistica[j]->getNombre());
                                camarotesDispoTuri--;
                            }

                        }else if(i==2){
                            if(premium[j]->getCamaroteReservado()){
                                qDebug() << "Clase Premium, Camarote Numero:" << QString::number(j+1) <<
                                            "Reservado por: " << QString::fromStdString(premium[j]->getNombre());
                                camarotesDispoPre--;
                            }
                        }

                    }

                }
                qDebug() << "Camarotes disponibles para clase economica: " << QString::number(camarotesDispoEco) <<
                            ",Camarotes disponibles para clase Turistica: " << QString::number(camarotesDispoTuri) <<
                            ",Camarotes disponibles para clase premium: " << QString::number(camarotesDispoPre);


            }
        }else if (accion.toInt()==3){
             qDebug() << "gracias por viajar con nosotros. buen viaje!!.";
             break;
             reservar=false;
        }

    }
    return a.exec();
}
