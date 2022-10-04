
class Flasher
{
  int ledPin;
  long OnTime;
  long OffTime;
  int ledState;
  unsigned long previousMillis;


  public:
  Flasher(int pin, long on, long off)
  {
    ledPin = pin;
    OnTime = on;
    OffTime = off;

    ledState = LOW;
    previousMillis = 0;
  }

void update(){
  unsigned long currentMillis = millis();
  
  if(( ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
  {
    ledState = LOW;  // Turn it off
    previousMillis = currentMillis;  // Remember the time
    digitalWrite(ledPin, ledState);  // Update the actual LED
  }
  else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
  {
    ledState = HIGH;  // turn it on
    previousMillis = currentMillis;   // Remember the time
    digitalWrite(ledPin, ledState);    // Update the actual LED
  }
}
};
Flasher led2(12, 800, 450);
Flasher led3(11, 900, 550);
Flasher led5(7, 850, 560);

const int A1A = 5;  // define pin 5 for A-1A (PWM Speed)
const int A1B = 6;  // define pin 6 for A-1B (direction)
unsigned long previousMillis1 = 0;
long OnTime1 = 100000; 
int Direction = HIGH;

// This is a custom function to drive Motor A
// inputs: direction (HIGH/LOW), speed (0-255)
// outputs: motor control

void motorA(byte d, int s) {
  if(d == 1){
    analogWrite(A1A, 255-s); 
    digitalWrite(A1B, HIGH); 
  } else if (d == 0){
    analogWrite(A1A, s); 
    digitalWrite(A1B, LOW);
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(A1A, OUTPUT); // specify these pins as outputs
  pinMode(A1B, OUTPUT); 
  motorA(Direction, 255);
}
void loop() {
  // put your main code here, to run repeatedly:
led2.update();
led3.update();
led5.update();

unsigned long currentMillis1 = millis();

  if(currentMillis1 - previousMillis1 >= OnTime1)
  {
    if (Direction == HIGH)
    {
      Direction = LOW;
    }
    else 
    {
      Direction = HIGH; 
    }
 
    motorA(Direction, 255); 

    previousMillis1 = currentMillis1;
  }

  }
