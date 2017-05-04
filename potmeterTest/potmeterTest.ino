const int mPinPotmeter = A1;
int mLastSafeDialNumber = -1;

//int getSafeDialNumber();

void setup() {
  // put your setup code here, to run once:
  pinMode(mPinPotmeter, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int number = getSafeDialNumber();
  if(number != mLastSafeDialNumber){
    mLastSafeDialNumber = number;
    Serial.print("Current dial number: ");
    Serial.println(number);
  }
  delay(50);
}

int getSafeDialNumber(){
  return map(analogRead(mPinPotmeter), 0, 1023, 0, 25);
}

