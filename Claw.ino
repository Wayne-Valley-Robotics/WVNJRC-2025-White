void Claw() {
<<<<<<< Updated upstream
  //claw open = O;
  //claw close = C;
  int S = 1;
  prizm.setServoSpeed(S, 70);
=======
 // I am so done with this code, but code I must
  
  int O = number;
  int C = number;
  int S = 1;
  prizm.setServoSpeed(S, 60);
>>>>>>> Stashed changes

  if (ps4.Button(L2T)) {
    if (prizm.readServoPosition(S)== (O)){
    prizm.setServoPosition(S, C);
    }
    else if (prizm.readServoPosition(S)==(C)){
    prizm.setServoPosition(S, O);
    
  }
}
