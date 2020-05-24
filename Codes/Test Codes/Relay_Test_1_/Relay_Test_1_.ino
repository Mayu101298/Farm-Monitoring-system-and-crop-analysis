
  /*--Inclusion of IR Libraries-**/

  #include <IRremote.h>
  #include <IRremoteInt.h>
  int receiverpin = 5; /*--Output Pin of IR Receiver TSOP 1838 is connected to Arduino Digital PWM Pin 11--*/
  IRrecv irrecv(receiverpin); /*--To create an instance of 'irrecv'--*/
  decode_results results;
  
  /*--Declaration of Device Pins--*/

  int Relay_1 = 2; 
  int Relay_2 = 3;
  int Relay_3 = 4;

  int Relay_1_State;
  int Relay_2_State;
  int Relay_3_State;
  
  void setup()
  {
    // Declaration of Relay Pins
    pinMode(Relay_1, OUTPUT);
    pinMode(Relay_2, OUTPUT);
    pinMode(Relay_3, OUTPUT);
    // To start the IR receiver
    irrecv.enableIRIn();
  }

  /*--Declaration of various tasks to be performed by a particular function--*/


  
  void loop()
  {
    if (irrecv.decode(&results))   //Did we receive an IR signal?
    {
      // Serial.println(results.value, HEX); // display IR code on the Serial Monitor--*/
      translateIR();
      for (int z = 0 ; z < 2; z++) /*--To ignore the repeated codes--*/
      {
        irrecv.resume();           /*--Receive the next value--*/
      }
    }
  }
  
  /*--TO perform a dedicated task for a particular signal--*/
  
  void translateIR()
  {
    switch(results.value)
    {
     /*--Code Setup for Vire Remote and their alloted functions--*/
     
      case 0x1FE50AF: RelayA(); break;  // Press Button no.1 to turn on/off Relay 1
      case 0x1FED827: RelayB(); break;  // Press Button no.2 to turn on/off Relay 2
      case 0x1FEF807: RelayC(); break;  // Press Button no.3 to turn on/off Relay 3
    }  }
  
void RelayA()
{
  if( Relay_1_State == LOW )
  {
    digitalWrite( Relay_1, HIGH );
    Relay_1_State= HIGH;
      }
      else
      {
        digitalWrite( Relay_1, LOW );
        Relay_1_State = LOW;
        }
        }

void RelayB()
{
  if( Relay_2_State == LOW )
  {
    digitalWrite( Relay_2, HIGH );
    Relay_2_State= HIGH;
      }
      else
      {
        digitalWrite( Relay_2, LOW );
        Relay_2_State = LOW;
        }
        }

void RelayC()
{
  if( Relay_3_State == LOW )
  {
    digitalWrite( Relay_3, HIGH );
    Relay_3_State= HIGH;
      }
      else
      {
        digitalWrite( Relay_3, LOW );
        Relay_3_State = LOW;
        }
        }

