#include <pololu/orangutan.h>

int main()
{
  clear();
  print("About to init");
  // initialize your QTR sensors
  //unsigned char qtr_rc_pins[] = {14, 15, 16};
  //qtr_rc_init(qtr_rc_pins, 3, 2000, 255);  // 800 us timeout, no emitter pin
  int qtr_analog_pins[] = {0, 1, 2};
  qtr_analog_init(qtr_analog_pins, 3, 10, 14); // 10 samples, emitter pin is PC0

  clear();
  print("waiting for top button");
  unsigned char button = wait_for_button_press(TOP_BUTTON);
  // optional: wait for some input from the user, such as  a button press
  
  clear();
  print("about to calibrate");
  // then start calibration phase and move the sensors over both
  // reflectance extremes they will encounter in your application:
  for (int i = 0; i < 250; i++)  // make the calibration take about 5 seconds
  {
    qtr_calibrate(QTR_EMITTERS_ON);
    delay(20);
  }
 
  clear();
  print("waiting for top button");
  unsigned char button2 = wait_for_button_press(TOP_BUTTON);
  // optional: signal that the calibration phase is now over and wait for further
  // input from the user, such as a button press

  while (1)
  {
    clear();
    print("getting sensor vals");

    unsigned int sensor_values[8];
	unsigned int sensor_values2[8];
	qtr_read(sensor_values, QTR_EMITTERS_ON);
	qtr_read_calibrated(sensor_values2, QTR_EMITTERS_ON);
	for(int i = 0; i<8; i++)
	{
	  print(sensor_values[i]);
	  print(sensor_values2[i]);
	  delay_ms(200);
	  clear();
	}
  }

  return 0;
}
