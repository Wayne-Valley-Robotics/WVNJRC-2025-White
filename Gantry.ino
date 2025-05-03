void GantrySystem() {
<<<<<<< Updated upstream
  int S_T = A0;
=======
  int S_T = A1;
>>>>>>> Stashed changes
  int M_S = 40;
  int S_B = A1;

 /* 
 right is right, NOT LEFT
  */
  
  if (ps4.Button(RIGHT)) {
    exc.setMotorPower(3, 1, M_S);
  }
  else {
    exc.setMotorPower(3, 1, 125);
  }
  
  /*
left better not move anywhere except left
  */
 if (ps4.Button(LEFT)) {
    exc.setMotorPower(3, 1, -M_S);
  }
  else {
    exc.setMotorPower(3, 1, 125);
  }
  
  /*
 now the hard part, two consecutive ha ha ha :,)
   */
  /*
 up up and away!!!
   */
// no switch
 if ((ps4.Button(UP))&&(!digitalRead(S_T))) {
    prizm.setMotorPower(1, M_S);
  }
//with switch
  else if ((ps4.Button(UP))&&(digitalRead(S_T))){
    prizm.setMotorPower(2, M_S);
    prizm.setMotorPower(1, 125);
  }
 //stop
  else {
    prizm.setMotorPower(1, 125);
    prizm.setMotorPower(2, 125);
  }
  /*
 down time is frown time :(
   */
  // no switch
 if ((ps4.Button(DOWN))&&(!digitalRead(S_B))) {
    prizm.setMotorPower(1, -M_S);
  }
//with switch
  else if ((ps4.Button(DOWN))&&(digitalRead(S_B))){
    prizm.setMotorPower(2, -M_S);
    prizm.setMotorPower(1, 125);
  }
 //stop
  else {
    prizm.setMotorPower(1, 125);
    prizm.setMotorPower(2, 125);
  }
}
<<<<<<< Updated upstream
=======
/* 
 *  Finally!!!!!!!!
 */
>>>>>>> Stashed changes
