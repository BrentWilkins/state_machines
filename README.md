# *F*inite *S*tate *M*achines
Playing around with FSMs on Arduino. Inspired by Marshall's [blog post](https://www.sparkfun.com/news/1801 "State Machines: blink.ino learns to snooze") and related [GitHub repository](https://github.com/marshalltaylorSFE/state_machines "another state_machines repository").

##Current Sketches
* blink_fsm - 2 states (on/off) for flashing LED
* debounce - 4 states for debouncing a button or a switch hooked to D0 and using internal pull-up resistor of ATmega328.  Not the ideal debounce code, but a next level state machine example.
* TBD...
