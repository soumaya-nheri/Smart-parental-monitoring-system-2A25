#include "arduino.h"

Arduino::connect_arduino()
{
  foreach (const QSerialPortInfo &serial_port_info , QSerialPortInfo::availablePorts())
  {
      if (serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier())
      {
          if (serial_port_info.hasVendorIdentifier()== arduino_uno_vendor_id && serial_port_info.productIdentifier() == arduino_uno_producy_id )
          {
              arduino_is_available = true ;
              arduino_port_name=serial_port_info.portName();
          }
      }
  }
  qDebug() << "arduino_port_name is :" << arduino_port_name;
  if (arduino_is_available)
  {

  }
}
