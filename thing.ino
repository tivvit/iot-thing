const int yellowPin = 14;
const int redPin = 5;
const int greenPin = 13;
const int buttonPin = 4;

int timer = 0;
int timeout = 1000 * 60 * 5;

bool yellowOn = false;
int freq = 1000;
const int sleepStep = 10;

bool done = false;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
}

// the loop function runs over and over again forever
void loop() {   
  if (digitalRead(buttonPin)) {
    timer = 0;
    done = false;
    freq = 1000;
  }

  if (timer > timeout) {
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
    done = true;
    digitalWrite(yellowPin, LOW);
  } else {
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, HIGH);
  }

  if(!done) {
    // blink change?
    if (timer % freq == 0) {
      if (yellowOn) {
        digitalWrite(yellowPin, HIGH);
        yellowOn = false;
      } else {
        digitalWrite(yellowPin, LOW);
        yellowOn = true;
      }

      if (timer > (1000 * 60 * 2)) {
        freq = 750;
      }
      if (timer > (1000 * 60 * 3)) {
        freq = 500;
      }
      if (timer > (1000 * 60 * 4)) {
        freq = 250;
      }
    }
  }
  
  delay(sleepStep);
  timer += sleepStep;
}
