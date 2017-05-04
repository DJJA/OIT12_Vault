#define DEBOUNCE_TIME 50

bool mLastState = false;
unsigned long mLastDebounceTime;

bool getButtonState(){
  bool stateChanged = false;
  bool reading = digitalRead(PIN_SWITCH);
  Serial.println(reading);

  // Current reading is different from the current buttonState(in software), and last time a debounce occured is more the the length of a debounce away
  if(reading != mLastState && (millis() - DEBOUNCE_TIME) > mLastDebounceTime){
    // Only change buttonstate when button is pressed down - Otherwise when you hold it down long enough, it will change states again because debounce time is over
    if(mLastState == HIGH){ // Register when button is released
      stateChanged = true;
    }
  }
  
  // If the state of the pin changed, change the var and memorize the last time it's changed
  if(reading != mLastState){
    mLastDebounceTime = millis();
    mLastState = reading;
  }
  return stateChanged;
}

