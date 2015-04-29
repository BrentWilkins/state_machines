// Currently only a test of important functionality.
// Needs a metric ton of work!
// Requires a 'real' serial terminal emulator such as putty, screen, etc.
// On OS X I'm running: $ screen /dev/cu.usbmodem1411 9600

void setup() {
  Serial.begin(9600);
  clearMenu();
  Serial.println("<Option 0> Option 1  Option 2");
}

void loop() {
  if (Serial.available()) 
  {
    int read = Serial.read();
    delay(5);  // Seems to be necessary to read control chars
    switch (read) 
    {
    case '0':
      clearMenu();
      colorRed();
      Serial.println("<Option 0> Option 1  Option 2");
      colorDefault();
      break;
    case '1':
      clearMenu();
      Serial.println(" Option 0 <Option 1> Option 2");
      break;
    case '2':
      clearMenu();
      Serial.println(" Option 0  Option 1 <Option 2>");
      break;
    case '\r':
      colorRed();
      Serial.println("Option selected!");
      colorDefault();
      break;
    case '\x1B':  // Control Sequence Introducer (ESC[)
      if (Serial.read() == '[') {
        switch (Serial.read())
        {
        case 'D':
          Serial.println("Left Arrow");
          break;
        case 'A':
          Serial.println("Up Arrow");
          break;
         case 'C':
          Serial.println("Right Arrow");
          break;
        case 'B':
          Serial.println("Down Arrow");
          break;
        }
      }
      break; 
    default:
      break;
    }
  }
}

void clearMenu() {
  Serial.write(27);       // ESC command
  Serial.print("[2J");    // clear screen command
  Serial.write(27);
  Serial.print("[H");     // cursor to home command
  Serial.println("Menu:");
}

void colorGreen() {
  Serial.write(27);
  Serial.print("[30m");
}

void colorRed() {
  Serial.write(27);
  Serial.print("[31m");
}

void colorDefault() {
  Serial.write(27);
  Serial.print("[0m");
}
