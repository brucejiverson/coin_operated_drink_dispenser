/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products
*/

const int coin_sensor_pin 1;

// peristaltic pump NEMA 17 set up
const int pump_step_pin = 2;
const int pump_dir_pin = 3;
const int pump_steps_per_rev = 200;
const int microstepping = 1;
const int pump_revs_per_ml = 2;
const int pump_dispense_speed_ml_per_sec = 1.75;
const int drink_volume_ml = 1.25;


const int steps_per_drink = (int) (drink_volume_ml * pump_revs_per_ml * pump_steps_per_rev);
const double pump_dispense_speed_steps_per_sec = pump_dispense_speed_ml_per_sec * pump_revs_per_ml * pump_steps_per_rev 

const int LED_pin 4;

Stepper DrinkPump(pump_steps_per_rev, 8, 9, 10, 11);


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize the serial port:
  Serial.begin(9600);
}


void dispense_drink(){
  // executes the process of dispense a shot, with all the bells and whistles

  Serial.println("Dispensing a drink.")
  // do the lights
  
  // note: we may want a distance sensor to make sure that the shot dispenser didn't mess up. 
  myStepper.step(steps_per_drink);
  Serial.println("Drink is pouring. Sleeping during process");
  delay(500);
}


// the loop function runs over and over again forever
void blink_example() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}

void rapid_test_dispense_systems(){
  while(1){
    dispense_drink();
  }
}

void loop() {
  blink_example();
  // rapid_test_dispense_systems();
  
// this really should be an interrupt but its ok
  while(analogRead(coing_sensor_pin) == 0){
    delay(50);
  }
  Serial.print("Detected a coin!");
  dispense_drink();
}
