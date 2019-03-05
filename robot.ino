int led = 2;
int buzzer = 3;

int trigger = 12;
int echo = 13;
long duration;
int distance;

const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;

//Define Pins
//Motor A
int enableA = 4;
int MotorA1 = 5;
int MotorA2 = 6 ;
 
//Motor B
int enableB = 8;
int MotorB1 = 9;
int MotorB2 = 10;

//variables
char command = 'h';
char velocity = '2';

void setup() {
  
  Serial.begin (9600);
  //configure pin modes
  pinMode (enableA, OUTPUT);
  pinMode (MotorA1, OUTPUT);
  pinMode (MotorA2, OUTPUT);  
  
  pinMode (enableB, OUTPUT);
  pinMode (MotorB1, OUTPUT);
  pinMode (MotorB2, OUTPUT);  
  
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

}

void loop() {
  //For forward 1:low 2:high
  //For backward 1:high 2:low
  //Right motor is B
  //Left motor is A
  
  
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger, LOW);
  
  duration = pulseIn(echo, HIGH);
  
  distance = microsecondsToCentimeters(duration);
  //Serial.print(distance);
  //Serial.print("\n");
  
  if (Serial.available() > 0)
  {
    command = Serial.read();
    
    //enabling motor A
    Serial.println ("Enabling Motors");
    digitalWrite (enableA, HIGH);
    digitalWrite (enableB, HIGH);
    //do something
    
    switch(command)
    {
      case '1':
      velocity = '1';
      break;
      
      case '2':
      velocity = '2';
      break;
      
      case 'w':
        digitalWrite(led, HIGH);
        
        switch(velocity)
        {
          case '1':
            analogWrite (MotorA1, 0);
            analogWrite (MotorA2, 130);
          
            analogWrite (MotorB1, 0);
            analogWrite (MotorB2, 150);
          break;
          
          case '2':
            analogWrite (MotorA1, 0);
            analogWrite (MotorA2, 200);
          
            analogWrite (MotorB1, 0);
            analogWrite (MotorB2, 235);
          break;
        }

     
      break;

      case 's':
        digitalWrite(led, HIGH);

        switch(velocity)
        {
          case '1':
            analogWrite (MotorA1, 130);
            analogWrite (MotorA2, 0);
          
            analogWrite (MotorB1, 150);                                           
            analogWrite (MotorB2, 0);
          break;
          
          case '2':
            analogWrite (MotorA1, 200);
            analogWrite (MotorA2, 0);
          
            analogWrite (MotorB1, 235);                                           
            analogWrite (MotorB2, 0);
          break;
        }        
        
      break;
      
      case 'a':
        digitalWrite(led, HIGH);
        
        switch(velocity)
        {
          case '1':
            analogWrite (MotorA1, 150);
            analogWrite (MotorA2, 0);
            
            analogWrite (MotorB1, 0);
            analogWrite (MotorB2, 150);
          break;
          
          case '2':
            analogWrite (MotorA1, 230);
            analogWrite (MotorA2, 0);
            
            analogWrite (MotorB1, 0);
            analogWrite (MotorB2, 240);
          break;
        }
        
      break;
      
      case 'd':
        digitalWrite(led, HIGH);

        switch(velocity)
        {
          case '1':
            analogWrite (MotorA1, 0);
            analogWrite (MotorA2, 150);
            
            analogWrite (MotorB1, 150);                                           
            analogWrite (MotorB2, 0);
          break;
          
          case '2':
            analogWrite (MotorA1, 0);
            analogWrite (MotorA2, 210);
            
            analogWrite (MotorB1, 240);                                           
            analogWrite (MotorB2, 0);
          break;
        }          
        
      break;
      
      case 'l':
        digitalWrite(led, HIGH);
      break;
      
      case 'b':
        tone(buzzer, 1000);
      break;
      
      case 'i':
        //Play first section
        beep(a, 500);
        beep(a, 500);
        if (Serial.available() > 0)break;  
        beep(a, 500);
        beep(f, 350);
        if (Serial.available() > 0)break;
        beep(cH, 150);  
        beep(a, 500);
        beep(f, 350);
        if (Serial.available() > 0)break;
        beep(cH, 150);
        beep(a, 650);
        if (Serial.available() > 0)break;
       
        delay(500);
       
        beep(eH, 500);
        if (Serial.available() > 0)break;
        beep(eH, 500);
        beep(eH, 500);  
        if (Serial.available() > 0)break;
        beep(fH, 350);
        beep(cH, 150);
        beep(gS, 500);
        if (Serial.available() > 0)break;
        beep(f, 350);
        beep(cH, 150);
        beep(a, 650);
        if (Serial.available() > 0)break;
        delay(500);
        
        //Play second section
        beep(aH, 500);
        beep(a, 300);
        if (Serial.available() > 0)break;
        beep(a, 150);
        beep(aH, 500);
        beep(gSH, 325);
        if (Serial.available() > 0)break;
        beep(gH, 175);
        beep(fSH, 125);
        beep(fH, 125);    
        beep(fSH, 250);
       
        delay(325);
        if (Serial.available() > 0)break;
       
        beep(aS, 250);
        beep(dSH, 500);
        beep(dH, 325);
        if (Serial.available() > 0)break;  
        beep(cSH, 175);  
        beep(cH, 125);  
        beep(b, 125);
        if (Serial.available() > 0)break;  
        beep(cH, 250);  
       
        delay(350);
        if (Serial.available() > 0)break;
       
        //Variant 1
        beep(f, 250);  
        beep(gS, 500);  
        beep(f, 350);
        if (Serial.available() > 0)break;  
        beep(a, 125);
        beep(cH, 500);
        beep(a, 375);  
        beep(cH, 125);
        if (Serial.available() > 0)break;
        beep(eH, 650);
       
        delay(500);
        if (Serial.available() > 0)break;
       
        //Repeat second section
        beep(aH, 500);
        beep(a, 300);
        beep(a, 150);
        if (Serial.available() > 0)break;
        beep(aH, 500);
        beep(gSH, 325);
        if (Serial.available() > 0)break;
        beep(gH, 175);
        beep(fSH, 125);
        beep(fH, 125);    
        beep(fSH, 250);
       
        delay(325);
        if (Serial.available() > 0)break;
       
        beep(aS, 250);
        beep(dSH, 500);
        beep(dH, 325);
        if (Serial.available() > 0)break;  
        beep(cSH, 175);  
        beep(cH, 125);  
        beep(b, 125);
        if (Serial.available() > 0)break;  
        beep(cH, 250);  
       
        delay(350);
        if (Serial.available() > 0)break;
       
        //Variant 2
        beep(f, 250);  
        beep(gS, 500);  
        beep(f, 375);
        if (Serial.available() > 0)break;  
        beep(cH, 125);
        beep(a, 500);  
        beep(f, 375);
        if (Serial.available() > 0)break;  
        beep(cH, 125);
        beep(a, 650);
        if (Serial.available() > 0)break;  
       
        delay(650);
      break;

      
      case 'h':
        Serial.println ("Stoping motors");
      
        digitalWrite (MotorA1,LOW);
        digitalWrite (MotorA2,LOW);  
        
        digitalWrite (MotorB1,LOW);
        digitalWrite (MotorB2,LOW); 
        
        digitalWrite(led, LOW);
        noTone(buzzer); 
        
        //stop
        digitalWrite (enableA, LOW);
        digitalWrite (enableB, LOW);
      break;
    }
  }
  if(distance < 15 && command=='w')
  {
      command='h';
      Serial.println ("Stoping motors");
      
      digitalWrite (MotorA1,LOW);
      digitalWrite (MotorA2,LOW);  
      
      digitalWrite (MotorB1,LOW);
      digitalWrite (MotorB2,LOW); 
      
      digitalWrite(led, LOW);
      
      //stop
      digitalWrite (enableA, LOW);
      digitalWrite (enableB, LOW);
  }
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}


void beep(int note, int duration)
{
  //Play tone on buzzer
  tone(buzzer, note, duration);
 
  delay(duration);
  
  //Stop tone on buzzer
  noTone(buzzer);
 
  delay(50);
}
