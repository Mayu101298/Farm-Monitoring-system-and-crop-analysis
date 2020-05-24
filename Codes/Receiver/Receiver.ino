/* Data terminal of receiver is connected to digital pin 11 of arduino 
uno. Data received will be displayed in the serial monitor*/

#include <VirtualWire.h>
byte message[VW_MAX_MESSAGE_LEN]; // a buffer to store the incoming messages
byte messageLength = VW_MAX_MESSAGE_LEN; // the size of the message
 
void setup()
{
  Serial.begin(9600);
  //Serial.println("Receiver is ready");
  //Serial.println("temp,humidity,moisture");
  // Initialize the IO and ISR
  vw_setup(2000); // Bits per sec
  vw_rx_start(); // Start the receiver 
}

String str[3];

void loop()
{
  if (vw_get_message(message, &messageLength)) {
   // Serial.print("\nReceived: ");
   int k=0;
    for (int i = 0; i < messageLength; i++)
    {
      
//      Serial.write(message[i]);     
      if(ispunct(message[i]))
        k++;
      else if(isdigit(message[i]))
        str[k]+=(char)message[i];
      delay(50);
     }
     
  //   Serial.println();
    // Serial.println(str[0]);
     //Serial.println(str[1]);
     //Serial.println(str[2]);
     int temp = str[0].toInt();
     int humid = str[1].toInt();
     int mois = str[2].toInt();
     Serial.print(temp);
     Serial.print(",");
     Serial.print(humid);
     Serial.print(",");
     Serial.println(mois);
     for(int i=0;i<3;i++)
      str[i]="";
     //Serial.println();
    } 
}
 
