/////////////////////////////////////////////////////////
// Simple Finite State Machine implementation of       //
// Blink.ino inspired by:                              //
// https://github.com/marshalltaylorSFE/state_machines //
//                                                     //
// Written for an Uno or other Arduino with LED on D13 //
//                                                     //
// State transition table:                             //
//                                                     //
//  | Num | Name    | LED | Time  | Input 0 |          //
//  |-----|---------|-----|-------|---------|          //
//  | 0   | LED_ON  | 1   | DELAY | LED_OFF |          //
//  | 1   | LED_OFF | 0   | DELAY | LED_ON  |          //
//                                                     //
/////////////////////////////////////////////////////////

const uint8_t LED_PIN = 13;
const uint16_t DELAY = 1000;
uint32_t time;    // Size of return type of millis()

typedef struct {
  uint8_t out;
  uint16_t time;  // Can't delay longer than 65,535 ms
  uint8_t next[2];
} const state_t;

enum states: uint8_t { LED_ON, LED_OFF };

state_t FSM[2] = {
  {1, DELAY, {LED_OFF}},
  {0, DELAY, {LED_ON}} 
};

uint8_t state = LED_ON;
uint8_t input = 0;  // Input is always zero since there aren't any

void setup()
{
  pinMode(LED_PIN, OUTPUT);  // Initialize LED pin as an output.
  time = millis();  // Capture rough start time
}

void loop()
{
  // Start of FSM
  // Set the LED for the current state
  digitalWrite(LED_PIN, FSM[state].out);  // Set the LED
  // If time is up, transition to next state
  if ( (millis() - time) >= FSM[state].time )
  {
    // Would read input here
    state = FSM[state].next[input];
    time = millis();  // 'Reset' timer
  }
  // End of FSM
  
  // Do other stuff here...
}
