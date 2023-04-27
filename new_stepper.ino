#define stp 9
#define dir 3
//Declare variables for functions
char user_input;
int x;
int y;
int state;
const int KL15Pin = 7;
const int buttonPin = 2;  
volatile int buttonState = 0;   
const int ledPin =  13; 
void setup() {
 pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
    pinMode(ledPin, OUTPUT);
   pinMode(buttonPin, INPUT);
   Serial.begin(9600); //Open Serial connection for debugging
  Serial.println("Begin motor control");
 digitalWrite(KL15Pin, HIGH); 
  digitalWrite(5, HIGH);   
    attachInterrupt(0, pin_ISR, CHANGE);
}

void loop() {
 buttonState = digitalRead(buttonPin);
do
{
    digitalWrite(stp,HIGH); //Trigger one step forward
    delayMicroseconds(300);
    digitalWrite(10,LOW); //Pull step pin low so it can be triggered again
    delayMicroseconds(300);
    digitalWrite(stp,LOW); //Trigger one step forward
    delayMicroseconds(300);
    digitalWrite(10,HIGH); //Pull step pin low so it can be triggered again
    delayMicroseconds(300);
} while (buttonState == HIGH);


do
{
    digitalWrite(stp,HIGH); //Trigger one step
     delayMicroseconds(500);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
   delayMicroseconds(500);
   

   } while (buttonState == LOW);

 
}
void pin_ISR() {
  buttonState = digitalRead(buttonPin);
  digitalWrite(ledPin, buttonState);
 if (buttonState == HIGH) {
 
  StepForwardDefault();
  }
  else {
 
    ReverseStepDefault();
  }
}
void StepForwardDefault()
{
  Serial.println("Moving forward at default step mode.");
  
  digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
 
  Serial.println("Enter new option");
  Serial.println();
}

void ReverseStepDefault()
{
  Serial.println("Moving in reverse at default step mode.");
  digitalWrite(dir, HIGH); //Pull direction pin high to move in "reverse"
 


  Serial.println("Enter new option");
  Serial.println();
}

