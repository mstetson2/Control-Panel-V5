#include <Wire.h>
#include <Keyboard.h>

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Wire.onRequest(requestEvent); // register
  Serial.begin(9600);           // start serial for output
  Serial.println("Connected print");
  Serial.write("Connected write");
  Keyboard.begin();
}

void loop() {
  //digitalWrite(13, LOW);
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  digitalWrite(13, HIGH);
  //Keyboard.write(48);
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  int x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer
}

void requestEvent() {
  int connection = 1;
  Wire.beginTransmission(8);
  Wire.write(connection);
  Wire.endTransmission();
  Serial.println("connected");
  
}


