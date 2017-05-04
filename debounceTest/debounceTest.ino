const int mPinSwitch = A0;

bool mLastState = false;
unsigned long mLastDebounceTime;
bool mButtonState = false;
int count = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(mPinSwitch, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool reading = digitalRead(mPinSwitch);

  // Current reading is different from the current buttonState(in software), and last time a debounce occured is more the the length of a debounce away
  if(reading != mLastState && (millis() - 50) > mLastDebounceTime){
    // Only change buttonstate when button is pressed down - Otherwise when you hold it down long enough, it will change states again because debounce time is over
    if(mLastState == LOW){ 
      mButtonState = !mButtonState;
      Serial.print("button state changed");
      Serial.println(++count);
    }
  }
  
  // If the state of the pin changed, change the var and memorize the last time it's changed
  if(reading != mLastState){
    mLastDebounceTime = millis();
    mLastState = reading;
  }

  digitalWrite(LED_BUILTIN, mButtonState);
  delay(50);
}
