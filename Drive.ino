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

  lf_val = constrain(JOY_LY + JOY_LX + JOY_RX, -range, range);
  rf_val = constrain(JOY_LY - JOY_LX - JOY_RX, -range, range);
  lb_val = constrain(JOY_LY - JOY_LX + JOY_RX, -range, range);
  rb_val = constrain(JOY_LY + JOY_LX - JOY_RX, -range, range); 

  /*
  2, 2 br
  fr: 1, 2
  */
  exc.setMotorPower(1, 1, -lf_val);
  exc.setMotorPower(2, 1, -lb_val);
  exc.setMotorPower(1, 2, rf_val);
  exc.setMotorPower(2, 2, rb_val);
}