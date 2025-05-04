int servo = 1;
int l_trigger;

void Claw() {
  prizm.setServoSpeed(servo, 70);
  // I am so done with this code, but code I must
  l_trigger = map(ps4.Button(L2T), 0, 255, 90, 0);

  prizm.setServoPosition(servo, l_trigger);
  // if (ps4.Button(L2T)) {
  //   if (prizm.readServoPosition(servo)== (open_deg)){
  //   prizm.setServoPosition(servo, close_deg);
  //   }
  //   else if (prizm.readServoPosition(servo)==(close_deg)){
  //   prizm.setServoPosition(servo, open_deg);
  // }
}
