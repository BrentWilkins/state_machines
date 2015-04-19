/////////////////////////////////////////////////////////
// Simple Finite State Machine implementation of       //
// switch debounce. Requires the pin to go high or low //
// for 2 samples which span over 5 ms. Button press    //
// causes LED to light while held.                     //
//                                                     //
// State transition table (assumes pull-up):           //
//                                                     //
//  | Num | Name    | Out | Time | Input 0 | Input 1 | //
//  |-----|---------|-----|------|---------|---------| //
//  | 0   | UP      | 0   | 5 ms | PRESS   | UP      | //
//  | 1   | PRESS   | 0   | 5 ms | DOWN    | UP      | //
//  | 2   | DOWN    | 1   | 5 ms | DOWN    | RELEASE | //
//  | 3   | RELEASE | 1   | 5 ms | DOWN    | UP      | //
//                                                     //
/////////////////////////////////////////////////////////

// pinMode(pin, INPUT);           // set pin to input
// digitalWrite(pin, HIGH);       // turn on pullup resistors

const uint8_t LED_PIN = 13;
const uint8_t SWITCH = 0;
uint32_t time;    // Size of return type of millis()

typedef struct {
  uint8_t out;
  uint16_t time;    // Can't delay longer than 65,535 ms
  uint8_t next[2];  // Only two unique input states
} const state_t;

enum states: uint8_t { UP, PRESS, DOWN, RELEASE };

state_t FSM[4] = {
  {0, 5, {PRESS, UP}},
  {0, 5, {DOWN, UP}},
  {1, 5, {DOWN, RELEASE}},
  {1, 5, {DOWN, UP}}
};

uint8_t state = UP;  // Assume switch/button not pressed at power up

void setup()
{
  pinMode(LED_PIN, OUTPUT);    // Initialize LED pin
  pinMode(SWITCH, INPUT);      // Initialize switch/button pin
  digitalWrite(SWITCH, HIGH);  // Turn on internal pull-up resistor
  time = millis();             // Capture rough start time
}

void loop()
{   
  // Start of FSM
  // Set the LED for the current state
  digitalWrite(LED_PIN, FSM[state].out);  // Set the LED
  // If time is up, transition to next state
  if ( (millis() - time) >= FSM[state].time )
  {
    state = FSM[state].next[digitalRead(SWITCH)];
    time = millis();  // 'Reset' timer
  }
  // End of FSM
  
  // Do other stuff here...
}
