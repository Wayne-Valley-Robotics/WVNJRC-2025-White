int r_trigger;

byte flap_pin = 3;
byte servo_pin = 4;


void HockeySystem()
{
    // flap
    r_trigger = map(ps4.Button(R2T), 0, 255, -100, 100);

    if (digitalRead(A0) == 0) {
        exc.setMotorPower(3, 2, 125);
        Serial.println("read a0 true");
    }
    else {
        exc.setMotorPower(3, 2, r_trigger);
        Serial.println("read a0 false");
    }

    // push thing (servo)
    prizm.setServoSpeed(4, 100);

    if (ps4.Button(TRIANGLE) == 1) {
        prizm.setServoPosition(servo_pin, 90);
        Serial.println("read triangle button true");
    }
    else {
        prizm.setServoPosition(servo_pin, 0);
        Serial.println("else triangle");
    }

}