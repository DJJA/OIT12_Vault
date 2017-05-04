#define PIN_SWITCH A0
#define PIN_POTMETER A1
#define PIN_LEDGREEN 2
#define PIN_LEDRED 3

byte mAccessCode[4];

void setup() {
  // Init pins
  pinMode(PIN_POTMETER, INPUT);
  pinMode(PIN_SWITCH, INPUT);
  pinMode(PIN_LEDGREEN, OUTPUT);
  pinMode(PIN_LEDRED, OUTPUT);
  
  // Init serial
  Serial.begin(9600);
  
  // Init vault
  digitalWrite(PIN_LEDRED, HIGH);
  
  // Get access code from user
  Serial.println("Please enter the 4 digit access code you would like to use:");
  getAccessCodeFromUser(mAccessCode);

  // Print the chosen access code
  Serial.print("This is the access code you've chosen: [ ");
  for(byte i=0;i<4;i++){
    Serial.print(mAccessCode[i]);
    Serial.print(" ");
  }
  Serial.println("]");
  Serial.println();
}

void loop() {
  byte enteredAccessCode[4];  // Should I put this var outside of this scope so it doesn't get recreated every time we loop through?

  // Print instructions
  Serial.println("Please enter the access code to open the vault:");
  
  // Get the access code from the user
  getAccessCodeFromUser(enteredAccessCode);
  
  // Compare access code from user to the one saved in the memory
  if(accessCodesMatch(mAccessCode, enteredAccessCode)){
    Serial.println("Vault open...");
    digitalWrite(PIN_LEDGREEN, HIGH);
    delay(3000);
    digitalWrite(PIN_LEDGREEN, LOW);
    Serial.println("Vault closed.");
  }else{
    Serial.println("You've entered the wrong access code, please try again...");
    for(byte i=0;i<3;i++){
      digitalWrite(PIN_LEDRED, LOW);
      delay(500);
      digitalWrite(PIN_LEDRED, HIGH);
      delay(500);
    }
  }

  // Print empty line for cleanliness
  Serial.println();
}
