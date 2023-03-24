#include <SoftwareSerial.h>

//PIN DECLARATION
//Motor 1 Right
#define M1R1    4
#define M1R2    6
#define M1RENA  5

//Motor 1 Left
#define M1L1    1
#define M1L2    2
#define M1LENA  3

//Motor 2 Right
#define M2R1    8
#define M2R2    9
#define M2RENA  10

//Motor 2 Left 
#define M2L1    12
#define M2L2    13
#define M2LENA  11

//Motor speed setting (pulse wave modulator)
#define PWM_HIGH  250
#define PWM_LOW   0


//Initiatlise HC05 bluetooth chip 
SoftwareSerial HC05(7, 13); // HC05 TX,RX
int BluetoothData = 0; 

void setup() {
  HC05.begin(9600);
  Serial.begin(9600);
  Serial.println("SETUP COMPLETE");
  
  //For testing
  //pinMode(LED_BUILTIN,OUTPUT); 

  //Motor 1 Right 
  pinMode(M1R1, OUTPUT);
  pinMode(M1R2, OUTPUT);
  pinMode(M1RENA, OUTPUT);

  //Motor 1 Left 
  pinMode(M1L1, OUTPUT);
  pinMode(M1L1, OUTPUT);
  pinMode(M1LENA, OUTPUT);

  //Motor 2 Right
  pinMode(M2R1, OUTPUT);
  pinMode(M2R2, OUTPUT);
  pinMode(M2RENA, OUTPUT);

  //Motor 2 Left
  pinMode(M2L1, OUTPUT);
  pinMode(M2L2, OUTPUT);
  pinMode(M2RENA, OUTPUT);
}

void motorTest() {
  int M1L_PWM = 250;
  int M1R_PWM = 250;
  int M2L_PWM = 250;
  int M2R_PWM = 250;

  //Motor 1 Left
  digitalWrite(M1L1, HIGH);
  digitalWrite(M1L2, LOW);
  analogWrite(M1LENA, M1L_PWM);

  //Motor 1 Right
  digitalWrite(M1R1, HIGH);
  digitalWrite(M1R2, LOW);
  analogWrite(M1RENA, M1R_PWM);

  //Motor 2 Left
  digitalWrite(M2L1, HIGH);
  digitalWrite(M2L2, LOW);
  analogWrite(M2LENA, M2L_PWM);

  //Motor 2 Right
  digitalWrite(M2R1, HIGH);
  digitalWrite(M2R2, LOW);
  analogWrite(M2RENA, M2R_PWM);
}


void forwards(){
  Serial.println("Forwards");
  //Motor 1 Left
  digitalWrite(M1L1, HIGH);
  digitalWrite(M1L2, LOW);
  analogWrite(M1LENA, PWM_HIGH);

  //Motor 1 Right
  digitalWrite(M1R1, HIGH);
  digitalWrite(M1R2, LOW);
  analogWrite(M1RENA, PWM_HIGH);

  //Motor 2 Left
  digitalWrite(M2L1, HIGH);
  digitalWrite(M2L2, LOW);
  analogWrite(M2LENA, PWM_HIGH);

  //Motor 2 Right
  digitalWrite(M2R1, HIGH);
  digitalWrite(M2R2, LOW);
  analogWrite(M2RENA, PWM_HIGH);
}

void backwards(){
  Serial.println("Backwards");

  //Motor 1 Left
  digitalWrite(M1L1, LOW);
  digitalWrite(M1L2, HIGH);
  analogWrite(M1LENA, PWM_HIGH);

  //Motor 1 Right
  digitalWrite(M1R1, LOW);
  digitalWrite(M1R2, HIGH);
  analogWrite(M1RENA, PWM_HIGH);

  //Motor 2 Left
  digitalWrite(M2L1, LOW);
  digitalWrite(M2L2, HIGH);
  analogWrite(M2LENA, PWM_HIGH);

  //Motor 2 Right
  digitalWrite(M2R1, LOW);
  digitalWrite(M2R2, HIGH);
  analogWrite(M2RENA, PWM_HIGH);
}

void right() {
  Serial.println("Right");
  //Motor 1 Left
  digitalWrite(M1L1, HIGH);
  digitalWrite(M1L2, LOW);
  analogWrite(M1LENA, PWM_HIGH);

  //Motor 1 Right
  digitalWrite(M1R1, LOW);
  digitalWrite(M1R2, HIGH);
  analogWrite(M1RENA, PWM_HIGH);

  //Motor 2 Left
  digitalWrite(M2L1, LOW);
  digitalWrite(M2L2, HIGH);
  analogWrite(M2LENA, PWM_HIGH);

  //Motor 2 Right
  digitalWrite(M2R1, HIGH);
  digitalWrite(M2R2, LOW);
  analogWrite(M2RENA, PWM_HIGH);
}

void left() {
  Serial.println("Left");
  //Motor 1 Left
  digitalWrite(M1L1, LOW);
  digitalWrite(M1L2, HIGH);
  analogWrite(M1LENA, PWM_HIGH);

  //Motor 1 Right
  digitalWrite(M1R1, HIGH);
  digitalWrite(M1R2, LOW);
  analogWrite(M1RENA, PWM_HIGH);

  //Motor 2 Left
  digitalWrite(M2L1, HIGH);
  digitalWrite(M2L2, LOW);
  analogWrite(M2LENA, PWM_HIGH);

  //Motor 2 Right
  digitalWrite(M2R1, LOW);
  digitalWrite(M2R2, HIGH);
  analogWrite(M2RENA, PWM_HIGH);
}

void stop(){
  Serial.println("Stop");

  int right2_pwm = 0;
  int left2_pwm = 0;
  int right1_pwm = 0;
  int left1_pwm = 0;

  //Motor 1 Left
  digitalWrite(M1L1, HIGH);
  digitalWrite(M1L2, LOW);
  analogWrite(M1LENA, PWM_LOW);

  //Motor 1 Right
  digitalWrite(M1R1, HIGH);
  digitalWrite(M1R2, LOW);
  analogWrite(M1RENA, PWM_LOW);

  //Motor 2 Left
  digitalWrite(M2L1, HIGH);
  digitalWrite(M2L2, LOW);
  analogWrite(M2LENA, PWM_LOW);

  //Motor 2 Right
  digitalWrite(M2R1, HIGH);
  digitalWrite(M2R2, LOW);
  analogWrite(M2RENA, PWM_LOW);
}


void loop() {  
  if (HC05.available()) {
    BluetoothData = HC05.read();
    
    if(BluetoothData == 'W') {  
      forwards();
    }
    
    else if(BluetoothData=='S'){ 
      backwards();  
    }

    else if(BluetoothData == 'D') { 
      right();
    }

    else if(BluetoothData=='A'){ 
      left();
    }
    
    else if (BluetoothData=='X'){ 
      stop();
    }
  }
}
