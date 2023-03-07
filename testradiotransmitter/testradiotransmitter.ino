//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


const int x_out = A1;
const int y_out = A2;

//create an RF24 object
RF24 radio(7, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

// variables for accelerometer value
typedef struct {
  int xAxis;
  int yAxis;

}data;

data send_data;


void setup()
{
  radio.begin();

  /*//Temp Code*/
  Serial.begin(9600);

  
  //set the address
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  //Set module as transmitter
  radio.stopListening();
}
void loop()
{
  //reading values from accelerometer
    send_data.xAxis = analogRead(x_out);
    send_data.yAxis = analogRead(y_out);
    
      radio.write(&send_data, sizeof(send_data));

      /*/Temp Code*/
 Serial.print(send_data.xAxis);     
Serial.print("-------------");
Serial.print(send_data.yAxis);
Serial.println(" ");

    
    delay(500);
}
