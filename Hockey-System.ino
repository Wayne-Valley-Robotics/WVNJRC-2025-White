int r_trigger;

byte flap_pin = 3;
byte servo_pin = 2;

bool input;

void HockeySystem()
{
    // flippy floppy
    if (ps4.Button(SQUARE)) {
      exc.setMotorPower(3, 2, 15);
    }
    else if (ps4.Button(CROSS)) {
      exc.setMotorPower(3, 2, -15);
    }
    else {
      exc.setMotorPower(3, 2, 125);
    }

    // push thing (servo)
    prizm.setServoSpeed(4, 100);

    if (ps4.Button(CIRCLE) == 1) {
        prizm.setServoPosition(servo_pin, 113);
    }
    else {
        prizm.setServoPosition(servo_pin, 0);
    }
}
