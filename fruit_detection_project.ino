//ultrasonic connector
const int pingPin = 7;
const int echoPin = 6;
//buzzer adding
const int buzzer = 10; //buzzer to arduino pin 

int pot=A0;
int MQ2pin=A1;
void setup()
{//setup for lcd
  Serial.begin(9600);
  //sound setup for buzzer
  pinMode(buzzer, OUTPUT);
  pinMode(A0,INPUT); 
}
int potentio=0;
//Global Variable for ultrasonic sensor
void loop()
{//gassensor value indicator
  potentio=analogRead(pot);
  float sensorValue;
  sensorValue=analogRead(MQ2pin);
  //declaration for ultrasonic sensor
  long duration, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   cm = microsecondsToCentimeters(duration);
   delay(100);
  //condition for banana
  if (potentio==0){
    //condition for ultrasonic distance ditaction
    if(cm<20)
    { 
      Serial.println("Distance is:");
      Serial.println(cm);
      //condition for analysis of gas
      if (401<sensorValue && sensorValue<450)
      {
        Serial.println(sensorValue);
        Serial.println("Banana is 25% ROTTEN");
        
        
      }
      else if (449<sensorValue && sensorValue<500){
        Serial.println(sensorValue);
        Serial.println("Banana is 50% ROTTEN");
         //sound function for buzzer
        tone(buzzer,300); // Send 1KHz sound signal...
        delay(1000);        // ...for 1 sec
        noTone(buzzer);     // Stop sound...
        delay(1000);        // ...for 1sec
      }
      else if(sensorValue>=500){
        Serial.println(sensorValue);
        Serial.println("Banana is 100% ROTTEN");
        //sound function for buzzer
        tone(buzzer,1000); // Send 1KHz sound signal...
        delay(1000);        // ...for 1 sec
        noTone(buzzer);     // Stop sound...
        delay(1000);        // ...for 1sec
      }

      //another condition for analysis of gas
      else
      {
        Serial.println("sensorValue:");
        Serial.println(sensorValue);
        Serial.println("BANANA is FRESH");
      }
      //time delay for whole void loop operation
      delay(300);
      
    }
    //another conditon for ultrasonic distance measurment
    if(cm>20)                                                                              
    {
      
      Serial.println("PLACR PROPERLY....!!");
      
    }
  } 
  delay(500);
  //condition for apple checking
  if (potentio==1023){
    if(cm<20)
    { 
      Serial.println("Distance is:");
      Serial.println(cm);
      //condition for analysis of gas
      if (sensorValue>350 && sensorValue<390)
      {
        Serial.println(sensorValue);
        Serial.println("APPLE is 25% ROTTEN");
       
      }
      else if(sensorValue>389 && sensorValue<430){
        Serial.println(sensorValue);
        Serial.println("APPLE is 50% ROTTEN");
         //sound function for buzzer
        tone(buzzer,300); // Send 1KHz sound signal...
        delay(1000);        // ...for 1 sec
        noTone(buzzer);     // Stop sound...
        delay(1000);        // ...for 1sec
        }
      else if (sensorValue>=430){
        Serial.print("APPLE is 100% ROTTEN");
         //sound function for buzzer
        tone(buzzer,1000); // Send 1KHz sound signal...
        delay(1000);        // ...for 1 sec
        noTone(buzzer);     // Stop sound...
        delay(1000);        // ...for 1sec
      }
      //another condition for analysis of gas
      else
      {
        Serial.println("sensorValue:");
        Serial.println(sensorValue);
        Serial.println("APPLE is FRESH");
      }
      //time delay for whole void loop operation
      delay(300);
      
    }
    //another conditon for ultrasonic distance measurment
    if(cm>20)                                                                              
    {
      
      Serial.println("PLACR PROPERLY....!!");
      
    }
    delay(500);

  }
  if(0<potentio && 1023>potentio)
  {
    Serial.println("Place the NOBE Correctly");
  }
  delay(500);
  
}
long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}