#include <DFRobot_BMX160.h>
#include "BFC_SENO052.h"
unsigned long simdiki_zaman = 0;
unsigned long onceki_zaman = 0;
unsigned long aralik = 500;
void setup()
{
  Serial.begin(9600);
  BFC_Sensor_Init_BMX160();
}
void loop()
{

  simdiki_zaman = millis();
  if (simdiki_zaman - onceki_zaman >= aralik)
  {

    BFC_Sensor_Read_BMX160();
    BFC_Sensor_Print_BMX160();
 
    onceki_zaman = simdiki_zaman;
    
  }
}
