int r_trigger;
prizm.setServoSpeed(4, 100);

void HockeySystem()
{
    // flap
    r_trigger = map(ps4.Button(R2T), 0, 255, -100, 100);

    if (digitalRead(A0) == 1) {
        prizm.setMotorPower(3, 125);
    }
    else {
        prizm.setMotorPower(3, r_trigger);
    }

    // push thing (servo)
    if (ps4.Button(TRIANGLE) == 1) {
        prizm.setServoPosition(4, 90);
    }
    else {
        prizm.setServoPosition(4, 0);
    }

}