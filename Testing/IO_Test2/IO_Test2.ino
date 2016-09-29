// the setup function runs once when you press reset or power the board
#define led 28
#define in 26

int buttonState = 0;

void setup() {
  // initialize digital pin led as an output.
  pinMode(led, OUTPUT);
  pinMode(53, OUTPUT);
  pinMode(in, INPUT);

  digitalWrite(in, HIGH);
  digitalWrite(53, HIGH);
}

// the loop function runs over and over again forever
void loop() {
  buttonState = digitalRead(in);
if(buttonState == LOW) {
  digitalWrite(led, HIGH);
}
  else {
    digitalWrite(led, LOW);// wait for a second
  }

}
