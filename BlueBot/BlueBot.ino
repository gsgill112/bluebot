/*
  BluetoothBot Example Application
  
  This Example Appplication caontrolls my bluetooth Bot using 
  Ti's LMX9838 Bluetooth2.0 SoC. I have configured the Module 
  to Tx/Rx at 9600 Baud. To know more on making your own 
  Bluetooth module please visit my blog(technervers.blogspot.in)
  or visit my web(technetvers.com)
  Echo has also been provided for you to see the values being 
  sent to the module 
  
  Hardware Required:
  * LaunchPad
  * TI LMX9838 Breakout Module Board
  * L293D Motor Control Board
  * 3.3v Battery Supply for MSP430
  * 5v Battery Supply for Motor Control
  * A assembled 2 Motor Robot with chasis
  * An Android/etc Mobile with Bluetooth Serial App
  
  Authors :
      Gurinder Singh Gill (gsgill112@gmail.com)
      
  My Web  : 
      technervers.com
      
  Visit my blog for further information :
      technervers.blogspot.in
  
  This example code is in the public domain.
*/

// most launchpads have a red LED
#define RLED RED_LED

//see pins_energia.h for more LED definitions
#define GLED GREEN_LED

int BLUE = -1;  // Bluetooh Var

void setup() {                
  pinMode(GLED, OUTPUT);     // defineing LED's 
  pinMode(RLED, OUTPUT);
  pinMode(P2_1, OUTPUT);     // Right Motor control
  pinMode(P2_2, OUTPUT);
  pinMode(P2_3, OUTPUT);     // Left Motor Control
  pinMode(P2_4, OUTPUT);
  
  Serial.begin(9600);
  //BLUE = '';
  digitalWrite(GLED, LOW);    // turn the Green LED off by making the voltage LOW  
  digitalWrite(RLED, LOW);    // turn the RED LED off by making the voltage LOW
  digitalWrite(P2_1, LOW);     // Right Motor STOP
  digitalWrite(P2_2, LOW);
  digitalWrite(P2_3, LOW);     // Left Motor STOP
  digitalWrite(P2_4, LOW);
  
}

// the loop routine runs over and over again forever:
void loop() {
  if (Serial.available() > 0) {
    BLUE = Serial.read();
    Serial.println(BLUE);     // echo the values 
    switch(BLUE){
      case 48 : Motor_Stop();                // 0 is sent 
                break;
      case 49 : Motor_Fwd();                 // 1 is sent
                break;
      case 50 : Motor_Left();                // 2 is sent
                break;
      case 51 : Motor_Right();               // 3 is sent
                break;
      case 52 : Motor_Back();                // 4 is sent
                break;
      case 53 : digitalWrite(GLED, LOW);     // 5 is sent     // Both Led's Off
                digitalWrite(RLED, LOW);                
                break;
      case 54 : digitalWrite(RLED, HIGH);    // 6 is sent     // Red Led High
                break;
      case 55 : digitalWrite(GLED, HIGH);    // 7 is sent     // Green Led High
                break;
      default : BLUE = -1;
    }
  }
}

void Motor_Stop(){
  digitalWrite(P2_1, LOW);     // Right Motor STOP
  digitalWrite(P2_2, LOW);
  digitalWrite(P2_3, LOW);     // Left Motor STOP
  digitalWrite(P2_4, LOW);
}

void Motor_Fwd(){
  digitalWrite(P2_1, HIGH);     // Right Motor STOP
  digitalWrite(P2_2, LOW);
  digitalWrite(P2_3, HIGH);     // Left Motor STOP
  digitalWrite(P2_4, LOW);
}

void Motor_Left(){
  digitalWrite(P2_1, HIGH);     // Right Motor STOP
  digitalWrite(P2_2, LOW);
  digitalWrite(P2_3, LOW);     // Left Motor STOP
  digitalWrite(P2_4, LOW);
}

void Motor_Right(){
  digitalWrite(P2_1, LOW);     // Right Motor STOP
  digitalWrite(P2_2, LOW);
  digitalWrite(P2_3, HIGH);     // Left Motor STOP
  digitalWrite(P2_4, LOW);
}

void Motor_Back(){
  digitalWrite(P2_1, LOW);     // Right Motor STOP
  digitalWrite(P2_2, HIGH);
  digitalWrite(P2_3, LOW);     // Left Motor STOP
  digitalWrite(P2_4, HIGH);
}

/* Gurinder Singh Gill */
