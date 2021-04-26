#ifndef ADRUINO_H
#define ADRUINO_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class Arduino
{
public:
    Arduino();
    int connect_arduino(); // connecter le PC à arduino
    int close_arduino(); // Fermer la connexion
    int write_to_arduino( QByteArray );
    QByteArray rerad_from_arduino ();
    QSerialPort* getserial();
    QString getarduino_port_name ();

private:
    QSerialPort * serial;
    static const quint16 arduino_uno_vendor_id=9025;
    static const quint16 arduino_uno_producy_id=67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data;
};

#endif // ADRUINO_HS
