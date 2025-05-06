int servo = 1;
int l_trigger;
int close_deg = 0;
int open_deg = 180;

void Claw() {
  //prizm.setServoSpeed(servo, 70);
  // I am so done with this code, but code I must
  l_trigger = map(ps4.Servo(L2T), 0, 180, open_deg, close_deg);

  prizm.setServoPosition(servo, l_trigger);
  // if (ps4.Servo(L2T)) {
  //   if (prizm.readServoPosition(servo) == (open_deg)) {
  //     Serial.println("close");
  //     prizm.setServoPosition(servo, close_deg);
  //   } 
  //   else if (prizm.readServoPosition(servo) == (close_deg)) {
  //     Serial.println("open");
  //     prizm.setServoPosition(servo, open_deg);
  //   }
  // }
}
