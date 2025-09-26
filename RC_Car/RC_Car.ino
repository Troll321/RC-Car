#include <Servo.h>
#include <NeoSWSerial.h>
#define SERVO_PWM 11
#define DC_ENA 10
#define DC_IN2 8
#define DC_IN1 7
#define BL_TX 6
#define BL_STATE 5
#define BL_RX 4

const int MAXN = 100;
char readBuff[MAXN];
int readBuffL = 0;
char writeBuff[MAXN];
int writeBuffL = 0;

Servo servo;
NeoSWSerial bSerial(BL_TX, BL_RX);
char reading = ' ';

void DCMove(double percent) {
  if(abs(percent) > 100) {return ;}

  if(percent == 0) {
    digitalWrite(DC_IN1, 0);
    digitalWrite(DC_IN2, 0);
    analogWrite(DC_ENA, 0);
    return ;
  }
  
  if (percent > 0) {
    digitalWrite(DC_IN1, 1);
    digitalWrite(DC_IN2, 0);
  } else if (percent < 0) {
    digitalWrite(DC_IN1, 0);
    digitalWrite(DC_IN2, 1);
  }
  analogWrite(DC_ENA, (int)(abs(percent)/(double)100*(double)255));
}

void initialPosition() {
  servo.write(90);
  DCMove(0);
}

void setup() {
  Serial.begin(9600);

  pinMode(SERVO_PWM, 1);
  pinMode(DC_ENA, 1);
  pinMode(DC_IN2, 1);
  pinMode(DC_IN1, 1);
  pinMode(BL_RX, 1);
  pinMode(BL_TX, 0);
  pinMode(BL_STATE, 0);

  servo.attach(SERVO_PWM);
  bSerial.begin(38400);

  initialPosition();

  Serial.println("Starting!");
}

void loop() {
  // put your main code here, to run repeatedly:
  // DCMove(100);
  // delay(2000);
  // DCMove(-100);
  // delay(2000);
  // DCMove(50);
  // delay(2000);
  // DCMove(-50);
  // delay(2000);
  // DCMove(0);
  // delay(2000);
  // servo.write(0);
  // delay(2000);
  // servo.write(180);
  // delay(2000);
  // servo.write(90.3);
  // delay(2000);

  // Serial.print("Hello\n");
  // delay(3000);
  // Serial.print("AAB");
  // delay(3000);
  // Serial.print(SERIAL_RX_BUFFER_SIZE);
  // delay(3000);
  // Serial.println(digitalRead(BL_STATE));

  // if(bSerial.available() > 0) {
  //   int len = bSerial.available();
  //   bSerial.readBytes(readBuff+readBuffL, len);
  //   readBuffL += len;
  // }

  // if(Serial.availableForWrite() >= readBuffL) {
  //   Serial.write(readBuff, readBuffL);
  //   Serial.flush();
  //   readBuffL = 0;
  // }

  // if(Serial.available() > 0) {
  //   int len = Serial.available();
  //   Serial.readBytes(writeBuff+writeBuffL, len);
  //   writeBuffL += len;
  // }

  // if(writeBuffL > 0) {
  //   bSerial.write(writeBuff, writeBuffL);
  //   bSerial.flush();
  //   writeBuffL = 0;
  // }

  if (bSerial.available()) {
    reading = bSerial.read();
    Serial.write(reading);
  }
  
  if (Serial.available()) {
    reading = Serial.read();
    bSerial.write(reading);
  }
}
