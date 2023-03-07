//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

/*//Motor Driver Values
int ENA = 3;
int ENB = 10;
int MotorA1 = 4;
int MotorA2 = 5;
int MotorB1 = 6;
int MotorB2 = 9;

*/
//create an RF24 object
RF24 radio(7, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";


// Variables to receive values
struct data {
  int xAxis;
  int yAxis;

};
data receive_data;


void setup()
{
   /*Temp Code */
  Serial.begin(9600);

//Radio acting as Receiver
radio.begin();
//radio.setPALevel(RF24_PA_LOW);
radio.openReadingPipe(0,address);
radio.startListening();

/*/Setting Pins for motors
pinMode(ENA, OUTPUT);
pinMode(ENB, OUTPUT);
pinMode(MotorA1, OUTPUT);
pinMode(MotorA2, OUTPUT);
pinMode(MotorB1, OUTPUT);
pinMode(MotorB2, OUTPUT);*/
}

void loop()
{
  if(radio.available()) {
    radio.read(&receive_data, sizeof(data));
   Serial.print(receive_data.xAxis);
   Serial.print("------------------");
   Serial.print(receive_data.yAxis);
   Serial.println("");
/* if(receive_data.yAxis > 355) {
  digitalWrite(MotorA1, LOW);//forward
  digitalWrite(MotorA2, HIGH);
  digitalWrite(MotorB1, HIGH);
  digitalWrite(MotorB2, LOW);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
  
}else if(receive_data.yAxis < 321) {
  digitalWrite(MotorA1, HIGH);//reverse
  digitalWrite(MotorA2, LOW);
  digitalWrite(MotorB1, LOW);
  digitalWrite(MotorB2, HIGH);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
} else if(receive_data.xAxis < 295){
  digitalWrite(MotorA1, HIGH);//left
  digitalWrite(MotorA2, LOW);
  digitalWrite(MotorB1, HIGH);
  digitalWrite(MotorB2, LOW);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}else if(receive_data.xAxis > 400){
  digitalWrite(MotorA1, LOW);//right
  digitalWrite(MotorA2, HIGH);
  digitalWrite(MotorB1, LOW);
  digitalWrite(MotorB2, HIGH);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}else {
  digitalWrite(MotorA1, LOW);
  digitalWrite(MotorA2, LOW);
  digitalWrite(MotorB1, LOW);
  digitalWrite(MotorB2, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  }*/
 }
  Serial.print("Not found");
}
