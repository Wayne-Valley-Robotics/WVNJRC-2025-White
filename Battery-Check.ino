/*
    Ensure the battery is suitably charged before operation
*/

void BatteryCheck() {
  /*
    pseudo code:
    read battery voltage:
        if below 11 volts, turn on red light
        if 900 volts or below prizm.PrizmEnd();
    */
  int batteryVoltage = prizm.readBatteryVoltage();

  if (batteryVoltage <= 1100) {
    prizm.setRedLED(HIGH);
  }
  if (batteryVoltage < 900) {
    prizm.PrizmEnd();
  }
}