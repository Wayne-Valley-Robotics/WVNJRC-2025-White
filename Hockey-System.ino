int r_trigger;

byte flap_pin = 3;
byte servo_pin = 4;


void HockeySystem()
{
    // flap
    r_trigger = map(ps4.Button(R2T), 0, 255, -100, 100);

    if (digitalRead(A0) == 1) {
        exc.setMotorPower(3, 2, 125);
    }
    else {
        exc.setMotorPower(3, 2, r_trigger);
    }

    // push thing (servo)
    prizm.setServoSpeed(4, 100);

    if (ps4.Button(TRIANGLE) == 1) {
        prizm.setServoPosition(servo_pin, 90);
    }
    else {
        prizm.setServoPosition(servo_pin, 0);
    }

}