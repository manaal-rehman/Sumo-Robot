char incomingByte;  // Bluetooth Data

//**********************Assigning names for pins ************************************//
int RM1 = 8;        // RM1 pin
int RM2 = 9;        // RM2 pin
int LM1 = 10;       // LM1 pin
int LM2 = 11;       // LM2 pin
int Buzz = 13;       // Buzzer pin

//**********************************************************************************//

//****************** This function executes only once at the start *********************//
void setup() 
{
    Serial.begin(9600);                   // Sets the BUAD rate for serial communication(For bluetooth)
    
    //****************************Sets PINS as output pins****************************//
            
    pinMode(RM2,OUTPUT);
    pinMode(RM1,OUTPUT);
    pinMode(LM1,OUTPUT);
    pinMode(LM2,OUTPUT);
    pinMode(Buzz,OUTPUT);

    //*******************************************************************************//

    //***************************Starting values for the pins***********************//

    digitalWrite(RM2,LOW);
    digitalWrite(RM1,LOW);
    digitalWrite(LM1,LOW);
    digitalWrite(LM2,LOW);
   

    //******************************************************************************//
    
    Serial.println("System powered on...");

}

//**************************************************************************************//
void loop() 
{
  if (Serial.available() > 0)
  {  
    incomingByte = Serial.read(); // read byte
    Serial.println(incomingByte);  // print message

    switch(incomingByte)
    {
      case'F':
          digitalWrite(RM1,HIGH);
          digitalWrite(RM2,LOW);
          digitalWrite(LM1,HIGH);
          digitalWrite(LM2,LOW);
          Serial.println("Moving Forward..."); 
      break;

      case'B':
        digitalWrite(RM1,LOW);
        digitalWrite(RM2,HIGH);
        digitalWrite(LM1,LOW);
        digitalWrite(LM2,HIGH);
      
        Serial.println("Moving Backward...");
      break;

      case'R':
        digitalWrite(RM1,LOW);
        digitalWrite(RM2,LOW);
        digitalWrite(LM1,HIGH);
        digitalWrite(LM2,LOW);
      
        Serial.println("Right...");
      break;

      case'L':
        digitalWrite(RM1,HIGH);
        digitalWrite(RM2,LOW);
        digitalWrite(LM1,LOW);
        digitalWrite(LM2,LOW);
      
        Serial.println("Left...");
      break;

      case'S':
        digitalWrite(RM1,LOW);
        digitalWrite(RM2,LOW);
        digitalWrite(LM1,LOW);
        digitalWrite(LM2,LOW);
      
        Serial.println("Stopped...");
      break;

      case'V':    
        digitalWrite(Buzz,HIGH);
        delay(20);
        Serial.println("Horn on...");
      break;

      case'v':
        digitalWrite(Buzz,LOW);
        Serial.println("Horn off...");
      break;    

    }
  }

   
}
