# *F*inite *S*tate *M*achines
Playing around with FSMs on Arduino. Inspired by Marshall's [blog post](https://www.sparkfun.com/news/1801 "State Machines: blink.ino learns to snooze") and related [GitHub repository](https://github.com/marshalltaylorSFE/state_machines "another state_machines repository").

##Current Sketches
* blink_fsm - 2 states (on/off) for flashing LED
* debounce - 4 states for debouncing a button or a switch hooked to D0 and using internal pull-up resistor of ATmega328.  Not the ideal debounce code, but a next level state machine example.
* menu - General serial port menu system that uses the arrow keys to navigate.  Requires a 'real' serial terminal emulator, the Arduino IDE one won't work.  Use something like [PuTTY](http://www.chiark.greenend.org.uk/~sgtatham/putty/download.html) or [screen](https://www.gnu.org/software/screen/).

![Basic idea in a graph](https://raw.githubusercontent.com/BrentWilkins/state_machines/master/menu/menu_fsm.png "Basic Graph")

_Partial State Diagram_

* TBD...
