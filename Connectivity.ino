void Connectivity() {
  /*
  if connected, do nothing
  else prizm.PrizmEnd();
*/
  if (!ps4.Connected) {
    prizm.PrizmEnd();
  }

  Range();
}

/*
  if out of connectivity range, vibrate controller
  */
void Range() {
  ps4.inRange;
  if (!ps4.inRange) {
    ps4.setRumble(FAST);
  } else {
    ps4.setRumble(STOP);
  }
}