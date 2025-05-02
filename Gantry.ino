void GantrySystem() {
  int S_B = A0;
  // insert limit switch 2 variable name
  //insert limit switch 3 variable name
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
  /*
make front up and down move before back
precison is key :)
  */

}