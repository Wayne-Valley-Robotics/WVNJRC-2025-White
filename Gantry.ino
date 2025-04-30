void GantrySystem() {
  int S_B = A0;
  /*
if limit switch pressed, set position 0
if limit switch not pressed, move up

  */
  if (digitalRead(S_B)) {
    prizm.setMotorPower(1, 125);
  }
  else {
    prizm.setMotorPower(1, 40);
  }

}