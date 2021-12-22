/* Synopsis: Cde Prise Chacon 54650RX_RSL660RF__V2
   Carte   : Arduino Nano
   Capteur : Emetteur 433.   
             
  Biblio:  ReceiveDemo_Simple 
           simpleBouton.h 1.4.2   
             
   Source  : https://github.com/sui77/rc-switch/blob/master/examples/ReceiveDemo_Simple/ReceiveDemo_Simple.ino
             https://forum.arduino.cc/index.php?topic=375232.0 
             http://forum.arduino.cc/index.php?topic=398112.0
           
   https://electroniquepassion.fr/ 
   C.Mercier  62128 Boiry-Becquerelle  
*/
//-----------------------------------------------------------------
#include <simpleBouton.h>
//Cablage : pin---BP---GND
const uint8_t pin_bouton1 = 2;//pin 5 du Nano
const uint8_t pin_bouton2 = 3;//pin 6 du Nano
const uint8_t pin_bouton3 = 4;//pin 7 du Nano
const uint8_t pin_bouton4 = 5;//pin 8 du Nano
const uint8_t pin_bouton5 = 6;//pin 9 du Nano
const uint8_t pin_bouton6 = 7;//pin 10 du Nano
simpleBouton bouton1(pin_bouton1);
simpleBouton bouton2(pin_bouton2);
simpleBouton bouton3(pin_bouton3);
simpleBouton bouton4(pin_bouton4);
simpleBouton bouton5(pin_bouton5);
simpleBouton bouton6(pin_bouton6);
//-------------------------------------
#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();
//-------------------------------------
bool prise1 = false;
bool bit1 = false;
bool prise2 = false;
bool bit2 = false;
bool prise3 = false;
bool bit3 = false;
bool prise4 = false;
bool bit4 = false;
bool prise5 = false;
bool bit5 = false;
bool prise6 = false;
bool bit6 = false; 
const int ledPrise1 = A0;
const int ledPrise2 = A1;
const int ledPrise3 = A2;
const int ledPrise4 = A3;
const int ledPrise5 = A4;
const int ledPrise6 = A5;
const int led13 = 13;
//Ne pas utiliser les sorties A6 et A7 en digital.
//-------------------------------------
void setup()
{  
  //Serial.begin(9600);  
  mySwitch.enableTransmit(12);// Transmission par la sortie 12 pin 15 du Nano  
  pinMode(ledPrise1, OUTPUT);
  pinMode(ledPrise2, OUTPUT);
  pinMode(ledPrise3, OUTPUT);
  pinMode(ledPrise4, OUTPUT);
  pinMode(ledPrise5, OUTPUT);
  pinMode(ledPrise6, OUTPUT);
  pinMode(led13, INPUT_PULLUP);    
  digitalWrite(ledPrise1, LOW);
  digitalWrite(ledPrise2, LOW);
  digitalWrite(ledPrise3, LOW);
  digitalWrite(ledPrise4, LOW);
  digitalWrite(ledPrise5, LOW);
  digitalWrite(ledPrise6, LOW); 
  //A la mise sous tension, mise en OFF de toutes les prises
  mySwitch.send(1381716, 24);
  delay(150);
  mySwitch.send(1394004, 24);
  delay(150);
  mySwitch.send(1397076, 24);
  delay(150);
  mySwitch.send(1397844, 24);
  delay(150);
  mySwitch.send(4539732, 24);
  delay(150);
  mySwitch.send(4542804, 24); 
  digitalWrite(ledPrise1, HIGH);
  digitalWrite(ledPrise2, HIGH);
  digitalWrite(ledPrise3, HIGH);
  digitalWrite(ledPrise4, HIGH);
  digitalWrite(ledPrise5, HIGH);
  digitalWrite(ledPrise6, HIGH);  
  delay(1000);
}//FIN SETUP---------------------------
void loop()
{  
bouton1.actualiser();  
if (bouton1.vientDEtreEnfonce())
  {
    prise1 = !prise1; //inversion
  } 

if (prise1 == true && bit1 == false)
  {
    // on envoie la trame "on"
    //mySwitch.send("010001010101000101010101");
    mySwitch.send(4542805, 24);
    bit1 = true;
    digitalWrite(ledPrise1, LOW);   
  }

if (prise1 == false && bit1 == true)
  {
    // on envoie la trame "off"
    mySwitch.send(4542804, 24);
    bit1 = false;
    digitalWrite(ledPrise1, HIGH);
  }
//-------------------------------------
bouton2.actualiser();  
if (bouton2.vientDEtreEnfonce())
  {
    prise2 = !prise2; //inversion
  } 

if (prise2 == true && bit2 == false)
  {
    // on envoie la trame "on"
    //mySwitch.send("000101010001010101010101");
    //mySwitch.send(1381717, 24);
    bit2 = true;
    digitalWrite(ledPrise2, LOW);
  }

if (prise2 == false && bit2 == true)
  {
    // on envoie la trame "off" 
    //mySwitch.send("000101010001010101010100");
    //mySwitch.send(1381716, 24);
    bit2 = false; 
    digitalWrite(ledPrise2, HIGH);
  }
//-------------------------------------
bouton3.actualiser();  
if (bouton3.vientDEtreEnfonce())
  {
    prise3 = !prise3; //inversion
  } 

if (prise3 == true && bit3 == false)
  {
    // on envoie la trame "on"
    //mySwitch.send("000101010001010101010101");
    //mySwitch.send(1381717, 24);
    bit3 = true;
    digitalWrite(ledPrise3, LOW);
  }

if (prise3 == false && bit3 == true)
  {
    // on envoie la trame "off" 
    //mySwitch.send("000101010001010101010100");
    //mySwitch.send(1381716, 24);
    bit3 = false; 
    digitalWrite(ledPrise3, HIGH);
  }
//-------------------------------------
bouton4.actualiser();  
if (bouton4.vientDEtreEnfonce())
  {
    prise4 = !prise4; //inversion
  } 

if (prise4 == true && bit4 == false)
  {
    // on envoie la trame "on"
    //mySwitch.send("000101010001010101010101");
    //mySwitch.send(1381717, 24);
    bit4 = true;
    digitalWrite(ledPrise4, LOW);
  }

if (prise4 == false && bit4 == true)
  {
    // on envoie la trame "off" 
    //mySwitch.send("000101010001010101010100");
    //mySwitch.send(1381716, 24);
    bit4 = false; 
    digitalWrite(ledPrise4, HIGH);
  }
//-------------------------------------
bouton5.actualiser();  
if (bouton5.vientDEtreEnfonce())
  {
    prise5 = !prise5; //inversion
  } 

if (prise5 == true && bit5 == false)
  {
    // on envoie la trame "on"
    //mySwitch.send("000101010001010101010101");
    //mySwitch.send(1381717, 24);
    bit5 = true;
    digitalWrite(ledPrise5, LOW);
  }

if (prise5 == false && bit5 == true)
  {
    // on envoie la trame "off" 
    //mySwitch.send("000101010001010101010100");
    //mySwitch.send(1381716, 24);
    bit5 = false; 
    digitalWrite(ledPrise5, HIGH);
  }
//-------------------------------------
bouton6.actualiser();  
if (bouton6.vientDEtreEnfonce())
  {
    prise6 = !prise6; //inversion
  } 

if (prise6 == true && bit6 == false)
  {
    // on envoie la trame "on"
    //mySwitch.send("000101010001010101010101");
    mySwitch.send(1381717, 24);
    bit6 = true;
    digitalWrite(ledPrise6, LOW);
  }

if (prise6 == false && bit6 == true)
  {
    // on envoie la trame "off" 
    //mySwitch.send("000101010001010101010100");
    mySwitch.send(1381716, 24);
    bit6 = false; 
    digitalWrite(ledPrise6, HIGH);
  }  
}//Fin LOOP  
