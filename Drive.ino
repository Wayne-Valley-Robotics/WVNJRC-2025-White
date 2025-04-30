/*
    Primary movement controls scheme
*/

const int TORQUENADO_MAX_SPEED = 630; // max speed for torquenado
const int MOTORS_MAX_SPEED = 720;  // max physical speed, effectively disabling torquenado

int JOY_LX;
int JOY_LY;
int JOY_RX;
int JOY_RY;

int lf_val;
int rf_val;
int lb_val;
int rb_val;

byte range = 100;


void DriveSystem()
{
  // if you set speeds as opposed to power, the power will automatically be adjusted depending on the load (i.e. going over an obstacle will automatically supply more power)
  // prizm.setMotorSpeed(1, 630); // max speed for "torquenado" as its called
  // prizm.setMotorSpeed(1, 720); // max physical speed, effectively disabling torquenado

  // prizm.setMotorPower(1, 50);

  JOY_LX = map(ps4.Stick(LX), 0, 255, -100, 100);
  JOY_LY = map(ps4.Stick(LY), 0, 255, -100, 100);

  JOY_RX = map(ps4.Stick(RX), 0, 255, -100, 100);
  JOY_RY = map(ps4.Stick(RY), 0, 255, -100, 100);

  int lf_val = constrain(JOY_LY + JOY_LX + JOY_RX, -range, range);
  int rf_val = constrain(JOY_LY - JOY_LX - JOY_RX, -range, range);
  int lb_val = constrain(JOY_LY - JOY_LX + JOY_RX, -range, range);
  int rb_val = constrain(JOY_LY + JOY_LX - JOY_RX, -range, range);

  if (abs(JOY_LY) >= abs(JOY_LX) && JOY_LY > 0) {  // forwards
    prizm.setMotorPowers(JOY_LY, JOY_LY);
  }
  else if (abs(JOY_LY) >= abs(JOY_LX) && JOY_LY < 0) {  // backwards
    prizm.setMotorPowers(JOY_LY, JOY_LY);
  }
  else if (abs(JOY_LX) >= abs(JOY_LY) && JOY_LX < 0) { // left
    prizm.setMotorPowers(-JOY_LX, JOY_LY);
  }
  else if (abs(JOY_LX) >= abs(JOY_LY) && JOY_LX > 0) { // left
    prizm.setMotorPowers(JOY_LX, -JOY_LY);
  }

  exc.setMotorPower(1, 1, lf_val);
  exc.setMotorPower(2, 1, lb_val);
  exc.setMotorPower(1, 2, rf_val);
  exc.setMotorPower(2, 2, rb_val);
  


  if (ps4.Button(TRIANGLE) == 1) {

  }
  else if (ps4.Button(CIRCLE) == 1) {

  }
  else if (ps4.Button(CROSS) == 1) {

  }
  else if (ps4.Button(SQUARE) == 1) {

  }

  

}