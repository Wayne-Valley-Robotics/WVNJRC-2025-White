void GantrySystem() {
  int top_sensor = A1; // top sensor
  int motor_speed = 40; // motor speed
  int bottom_sensor = A2; // bottom

  // right is right, NOT LEFT
  if (ps4.Button(RIGHT)) {
    exc.setMotorPower(3, 1, motor_speed);
  }
  else {
    exc.setMotorPower(3, 1, 125);
  }
  
  // left better not move anywhere except left
  if (ps4.Button(LEFT)) {
    exc.setMotorPower(3, 1, -motor_speed);
  }
  else {
    exc.setMotorPower(3, 1, 125);
  }
  
  // now the hard part, two consecutive ha ha ha :,)
  // up up and away!!!

  /* the two vertical motors DO NOT USE EXC they use PRIZM 
  Motor 1: smaller vertical one
  Motor 2: main one (bigger) */

  if ((ps4.Button(UP)) && (!digitalRead(top_sensor))) {  // no switch
    prizm.setMotorPower(1, motor_speed);
  }
  else if ((ps4.Button(UP)) && (digitalRead(top_sensor))) { // with switch
    prizm.setMotorPower(2, motor_speed);
    prizm.setMotorPower(1, 125);
  }
  else { // stop
    prizm.setMotorPower(1, 125);
    prizm.setMotorPower(2, 125);
  }

  // down time is frown time :(
  if ((ps4.Button(DOWN)) && (!digitalRead(bottom_sensor))) {  // no switch
    prizm.setMotorPower(1, -motor_speed);
  }
  else if ((ps4.Button(DOWN)) && (digitalRead(bottom_sensor))){ //with switch
    prizm.setMotorPower(2, -motor_speed);
    prizm.setMotorPower(1, 125);
  }
  else { //stop
    prizm.setMotorPower(1, 125);
    prizm.setMotorPower(2, 125);
  }
}
