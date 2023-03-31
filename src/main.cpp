/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include <Arduino.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// NOTE: These pin numbers will probably not work with your hardware and may
// need to be adapted
#define CLK_PIN   13  // or SCK
#define DATA_PIN  11  // or MOSI
#define CS_PIN    10  // or SS

// Uncomment according to your hardware type
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW

// Defining size, and output pins
#define MAX_DEVICES 4

MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

const char* wordList[]= {"TIM",   "MOM",  "DAD",  "JENNA","COLD",
                       "HOT",   "SNOW", "RAIN", "ON",   "OFF",
                       "SANTA", "FISH", "STRAW","ELSA", "POOP"};
//sizeof gets # of bytes. 
//so total array bytes / one element bytes. 
//(ex: 80 bytes / 8 bytes = 10 elements)
const size_t wordListSize = sizeof(wordList) / sizeof (wordList[0]);  

void setup()
{
  Serial.begin(9600);
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void printRandomWord(){
  Serial.println(wordList[random(wordListSize)]);
}

void loop()
{
  printRandomWord();
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);

  // wait for a second
  delay(100);

  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);

   // wait for a second
  delay(100);
}