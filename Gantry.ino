void GantrySystem() {
  int motor_speed = 60; // motor speed

 // right is right, NOT LEFT
  if (ps4.Button(LEFT)) {
    exc.setMotorPower(3, 1, motor_speed);
    prizm.setMotorPower(1, 125);
    prizm.setMotorPower(2, 125);
  }

// left better not move anywhere except left
  else if (ps4.Button(RIGHT)) {
    exc.setMotorPower(3, 1, -motor_speed);
    prizm.setMotorPower(1, 125);
    prizm.setMotorPower(2, 125);
  }

// now the hard part, two consecutive ha ha ha :,)

/* the two vertical motors DO NOT USE EXC they use PRIZM 
  Motor 1: smaller vertical one
  Motor 2: main one (bigger) */

  // up up and away!!!
  else if (ps4.Button(UP)) { // front up
      exc.setMotorPower(3, 1, 125);
      prizm.setMotorPower(1, motor_speed);
      prizm.setMotorPower(2, 125);
    }
  else if (ps4.Button(L1)){ // back up
      exc.setMotorPower(3, 1, 125);
      prizm.setMotorPower(1, 125);
      prizm.setMotorPower(2, motor_speed);
    }
  

  else if (ps4.Button(DOWN)) { // front down
      exc.setMotorPower(3, 1, 125);
      prizm.setMotorPower(1, -motor_speed);
      prizm.setMotorPower(2, 125);
    }
  else if (ps4.Button(R1)) { // back down
      exc.setMotorPower(3, 1, 125);
      prizm.setMotorPower(1, 125);
      prizm.setMotorPower(2, -motor_speed);
    }
  

  else { // stop
    exc.setMotorPower(3, 1, 125);
    prizm.setMotorPower(1, 125);
    prizm.setMotorPower(2, 125);
  }
}