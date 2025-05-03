/*
    Primary movement controls scheme
*/

const int TORQUENADO_MAX_SPEED = 630; // max speed for torquenado
const int MOTORS_MAX_SPEED = 720;     // max physical speed, effectively disabling torquenado

int JOY_LX;
int JOY_LY;
int JOY_RX;
int JOY_RY;

int lf_val;
int rf_val;
int lb_val;
int rb_val;

int deadzone = 10; // bruh

byte range = 100;


void DriveSystem()
{
  // if you set speeds as opposed to power, the power will automatically be adjusted depending on the load (i.e. going over an obstacle will automatically supply more power)
  // prizm.setMotorSpeed(1, 630); // max speed for "torquenado" as its called
  // prizm.setMotorSpeed(1, 720); // max physical speed, effectively disabling torquenado

  // prizm.setMotorPower(1, 50);

  // plz work
  // i dont want to redo this

  JOY_LX = map(ps4.Stick(LX), 0, 255, -100, 100);
  JOY_LX = JOY_LX * (abs(JOY_LX) > deadzone);
  JOY_LY = map(ps4.Stick(LY), 0, 255, -100, 100);
  JOY_LY = JOY_LY * (abs(JOY_LY) > deadzone);

  JOY_RX = map(ps4.Stick(RX), 0, 255, -100, 100);
  JOY_RX = JOY_RX * (abs(JOY_RX) > deadzone);
  JOY_RY = map(ps4.Stick(RY), 0, 255, -100, 100);
  JOY_RY = JOY_RY * (abs(JOY_RY) > deadzone);

  lf_val = constrain(JOY_LY + JOY_LX + JOY_RX, -range, range);
  lf_val = lf_val * (abs(lf_val) > deadzone);
  rf_val = constrain(JOY_LY - JOY_LX - JOY_RX, -range, range);
  rf_val = rf_val * (abs(rf_val) > deadzone);
  lb_val = constrain(JOY_LY - JOY_LX + JOY_RX, -range, range);
  lb_val = lb_val * (abs(lb_val) > deadzone);
  rb_val = constrain(JOY_LY + JOY_LX - JOY_RX, -range, range); 
  rb_val = rb_val * (abs(rb_val) > deadzone); 

  /*
  2, 2 br
  fr: 1, 2
  */

  if (abs(JOY_LY) >= abs(JOY_LX) && JOY_LY > 0) {  // forwards
    exc.setMotorPower(1, 1, JOY_LY); // fl
    exc.setMotorPower(1, 2, JOY_LY); // fr
  }
  else if (abs(JOY_LY) >= abs(JOY_LX) && JOY_LY < 0) {  // backwards
    exc.setMotorPower(2, 1, JOY_LY); // bl
    exc.setMotorPower(2, 2, JOY_LY); // br
  }
  else if (abs(JOY_LX) >= abs(JOY_LY) && JOY_LX < 0) { // left
    exc.setMotorPower(1, 2, -JOY_LX);
    exc.setMotorPower(2, 1, JOY_LX);
  }
  else if (abs(JOY_LX) >= abs(JOY_LY) && JOY_LX > 0) { // reverse left
    exc.setMotorPower(1, 1, -JOY_LX);
    exc.setMotorPower(2, 2, -JOY_LX);
  }
  else {
    exc.setMotorPower(1, 1, 0); // fl
    exc.setMotorPower(1, 2, 0); // fr
    exc.setMotorPower(2, 1, 0); // bl
    exc.setMotorPower(2, 2, 0); // br
  }

//   exc.setMotorPower(1, 1, lf_val);
//   exc.setMotorPower(2, 1, lb_val);
//   exc.setMotorPower(1, 2, rf_val);
//   exc.setMotorPower(2, 2, rb_val);


  if (abs(JOY_RY) > deadzone || abs(JOY_RX) > deadzone) {
    prizm.setMotorPower(1, lf_val);
    prizm.setMotorPower(2, rf_val);
    prizm.setMotorPower(1, lb_val);
    prizm.setMotorPower(2, rb_val);
  }
}