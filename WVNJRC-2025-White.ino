// TETRIX libraries
#include <PRIZM.h>
#include <TELEOP.h>
PRIZM prizm;
PS4 ps4;

// ino files are automatically included and their members prototyped (forward declared)
// https://arduino.github.io/arduino-cli/0.19/sketch-build-process/

void setup() {
  // put your setup code here, to run once:
  prizm.PrizmBegin();
  Serial.begin(115200);

  BatteryCheck();  // ensure battery is properly charged before operation
}

void loop() {
  ps4.getPS4();  // poll teleop for ps4 button inputs
  Connectivity();
  DriveSystem();  // primary drive controls
}
