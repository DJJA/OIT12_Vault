byte mLastVaultDialNumber = -1;

bool accessCodesMatch(const byte *code1, const byte *code2){  // Made the parameters constant, because we do not want to change it. Does this save memory? Or is it just security?
  for(byte i=0;i<4;i++)
    if(code1[i] != code2[i])
      return false;
  return true;
}

void getAccessCodeFromUser(byte *accessCode){
  Serial.println("Turn the dial to select the number, and press the button to confirm.");
  for(byte i=0;i<4;i++){ // Byte vs int? Does it matter here?
    accessCode[i] = getDialInputFromUser();
    // Print current entered access code
    Serial.print("[ ");
    for(byte j=0;j<4;j++){
      if(j <= i)
        Serial.print(accessCode[j]);
      else
        Serial.print("..");
      Serial.print(" ");
    }
    Serial.println("]");
  }
}

byte getDialInputFromUser(){
  for(;;){  // Returning out of infinite loop bad? Breaking out of one was, but I don't know why.
    // Keep updating the current dial number in the serial console
    byte number = map(analogRead(PIN_POTMETER), 0, 1023, 0, 25);
    if(number != mLastVaultDialNumber){
      mLastVaultDialNumber = number;
      //Serial.print("Current dial number: ");
      //Serial.println(number);
      Serial.print("Dial => (");
      Serial.print(number);
      Serial.println(")");
    }
    // When the butten is pressed, return the current dial number
    if(getButtonState())
      return mLastVaultDialNumber;
    delay(50);
  }
}
