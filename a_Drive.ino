/*
    Primary movement controls scheme
*/

const int TORQUENADO_MAX_SPEED = 630; // max speed for torquenado
const int MOTORS_MAX_SPEED = 720;  // max physical speed, effectively disabling torquenado

void DriveSystem()
{
    // if you set speeds as opposed to power, the power will automatically be adjusted depending on the load (i.e. going over an obstacle will automatically supply more power)
    // prizm.setMotorSpeed(1, 630); // max speed for "torquenado" as its called
    // prizm.setMotorSpeed(1, 720); // max physical speed, effectively disabling torquenado

    // prizm.setMotorPower(1, 50);
}