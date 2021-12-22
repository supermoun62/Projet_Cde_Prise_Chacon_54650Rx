/* Synopsis: Cde Prise Chacon 54650RX_RSL660RF__V1
   Carte   : Arduino Nano
   Capteur : Emetteur 433.   
             
   Biblio  : ReceiveDemo_Simple            
             
   Source  : https://github.com/sui77/rc-switch/blob/master/examples/ReceiveDemo_Simple/ReceiveDemo_Simple.ino
   
           
   https://electroniquepassion.fr/ 
   C.Mercier  62128 Boiry-Becquerelle  
*/
//-----------------------------------------------------------------

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup()
{
  Serial.begin(9600);  
  mySwitch.enableTransmit(10);// Emetteur connecté D10 pin 13 Nano
}

void loop()
{

// TEST 1-----------------------------------------------------------
/*  
// on envoie la trame "on" avec sa valeur Tri-State Touche 2 groupe 1
  mySwitch.sendTriState("0FFFF0FFFFFF");
  delay(10000); 
// on envoie la trame "off" avec sa valeur Tri-State Touche 2 groupe 1  
  mySwitch.sendTriState("0FFFF0FFFFF0");
  delay(10000);
*/  
  
// TEST 2-----------------------------------------------------------
/*
// on envoie la trame "on" avec sa valeur décimale Touche 1 groupe 1
  mySwitch.send( 1381717, 24);
  delay(1000);  
// on envoie la trame "off" avec sa valeur décimale Touche 1 groupe 1
  mySwitch.send( 1381716, 24);
  delay(1000);
*/

// TEST 3-----------------------------------------------------------  

// on envoie la trame "on" avec sa valeur binaire Touche 3 groupe 2
  mySwitch.send("010001010101000101010101");
  delay(10000);  
// on envoie la trame "off" avec sa valeur binaire Touche 3 groupe 2
  mySwitch.send("010001010101000101010100");
  delay(10000);

}
