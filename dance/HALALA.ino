int time;
int buttonPressTime = 0;
int autoDancing = 0;
int state5 = LOW, state6 = LOW, state7 = LOW;
int bouncing5 = 1, bouncing6 = 1, bouncing7 = 1;
int double5 = 0, double6 = 0, double7 = 0;
int down5 = 0, down6 = 0, down7 = 0;
int beats = 0;
int interval = 500;
int bounceDelay = 70;
int didHalfBeat = 0, didBounce = 0;
int lastBeat = 0;

void setup() {                
  pinMode(1, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  Serial.begin(38400);
  Serial.println("Ready for input.");
  Serial.flush();
}

void loop() {
  time = millis();
  
  if ((digitalRead(1)==0) && (time-buttonPressTime > 1000)) {
    Serial.println("change");
    autoDancing = !autoDancing;
    if (!autoDancing) {
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      beats = 4;
    }
    buttonPressTime = time;
  }
  
//  if (autoDancing) autoDance();
  
  while (Serial.available() > 0) {
    int input = Serial.read();
    switch ((char)input) {
    case 'a':
      digitalWrite(5, HIGH);
      break;
    case 'q':
      digitalWrite(5, LOW);
      break;
    case 's':
      digitalWrite(6, HIGH);
      break;
    case 'w':
      digitalWrite(6, LOW);
      break;
    case 'd':
      digitalWrite(7, HIGH);
      break;
    case 'e':
      digitalWrite(7, LOW);
      break;
    }
  }
}

void autoDance() {
  if (beats > 3) {
    bouncing5 = random(0,2);
    bouncing6 = random(0,2);
    bouncing7 = random(0,2);
    double5 = random(0,2);
    double6 = random(0,2);
    double7 = random(0,2);
    down5 = random(0,2);
    down6 = random(0,2);
    down7 = random(0,2);
    beats = 0;
  }
  if (time > lastBeat+interval) {
    state5 = down5;
    state6 = down6;
    state7 = down7;
    beats++;
    lastBeat = time;
    didHalfBeat = 0;
    didBounce = 0;
  } else if ((time > lastBeat+(interval/2)+bounceDelay) && !didBounce) {
    if (bouncing5) state5 = !state5;
    if (bouncing6) state6 = !state6;
    if (bouncing7) state7 = !state7;
    didBounce = 1;
  } else if ((time > lastBeat+(interval/2)) && !didHalfBeat) {
    if (double5) state5 = !state5;
    if (double6) state6 = !state6;
    if (double7) state7 = !state7;
    didHalfBeat = 1;
    didBounce = 0;
  } else if ((time > lastBeat+bounceDelay) && !didBounce) {
    if (bouncing5) state5 = !state5;
    if (bouncing6) state6 = !state6;
    if (bouncing7) state7 = !state7;
    didBounce = 1;
  }
  digitalWrite(5, state5);
  digitalWrite(6, state6);
  digitalWrite(7, state7);
}
