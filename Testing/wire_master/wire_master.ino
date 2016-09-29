// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>
////^ Writer of the base code for this program.

//Keyboard connection test.
//



#include <Wire.h>

boolean connection;
byte x = 5;

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600);
  Serial.println("mega (master)");
}



void loop() {

  if(connection) {
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write("x is ");        // sends five bytes
  Wire.write(x);              // sends one byte
  Wire.endTransmission();    // stop transmitting

  Serial.println(x);

  x++;
  }
  else {
    Wire.requestFrom(8, 1);
    int c = Wire.read();
    if(c == 1) {
      Serial.println("Connected.");
      connection = true;
  }
  }
  delay(500);
}
