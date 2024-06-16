#include <Arduino.h>
#include <IRremote.hpp>

// Definování použití AVR timeru a pinů
#define IR_USE_AVR_TIMER 1
#define IR_RECEIVE_PIN 12
#define ENTER 4127850240 // Kód klávesy ENTER
#define redLed 6
#define greenLed 5
#define blueLed 9

// Kódy IR signálů pro čísla 0-9
unsigned long codes[] = {
    3910598400, // 0
    4077715200, // 1
    3877175040, // 2
    2707357440, // 3
    4144561920, // 4
    3810328320, // 5
    2774204160, // 6
    3175284480, // 7
    2907897600, // 8
    3041591040, // 9
};

String stringNum = ""; // Proměnná pro uložení zadávaného čísla
int currentLED = 0;    // Aktuálně nastavovaná LED

int codesSize = sizeof(codes) / sizeof(codes[0]); // Velikost pole kódů

// Funkce pro převod IR kódu na odpovídající číslo
String receivedNum(unsigned long irData) {
  for (int i = 0; i < codesSize; i++) {
    if (irData == codes[i]) {
      return String(i);
    }
  }
  return ""; 
}

// Funkce pro nastavení hodnoty aktuálně nastavované LED
void setLED(int value) {
  switch (currentLED) {
    case 0:
      Serial.print("Nastavuji Červenou LED: ");
      analogWrite(redLed, value);
      Serial.println(value);
      currentLED = 1; // Přepnutí na další LED
      break;
    case 1:
      Serial.print("Nastavuji Zelenou LED: ");
      analogWrite(greenLed, value);
      Serial.println(value);
      currentLED = 2; // Přepnutí na další LED
      break;
    case 2:
      Serial.print("Nastavuji Modrou LED: ");
      analogWrite(blueLed, value);
      Serial.println(value);
      currentLED = 0; // Přepnutí zpět na první LED
      break;
    default:
      Serial.println("Nesprávný stav LED");
      break;
  }
}

void setup() {
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Inicializace IR přijímače
  Serial.begin(9600); // Inicializace sériové komunikace

  pinMode(redLed, OUTPUT); // Nastavení pinů LED jako výstupy
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);

  Serial.println("Setup dokončen");
}

void loop() {
  if (IrReceiver.decode()) { // Kontrola, zda byl přijat IR signál
    unsigned long irData = IrReceiver.decodedIRData.decodedRawData;
    if (irData > 0) {
      if (irData == ENTER) { // Kontrola, zda byl přijat kód ENTER
        int intNum = stringNum.toInt(); // Převod zadávaného čísla na integer
        if (intNum >= 0 && intNum <= 255) { // Kontrola, zda je číslo v povoleném rozsahu
          setLED(intNum); // Nastavení LED na zadanou hodnotu
          Serial.print("Nastavená hodnota: ");
          Serial.println(intNum);
          stringNum = ""; // Vymazání uloženého čísla
        } else {
          Serial.println("Mimo rozsah");
          stringNum = ""; // Vymazání uloženého čísla
        }
      } else {
        stringNum += receivedNum(irData); // Přidání přijatého čísla do stringu
        String ledName;
        switch (currentLED) {
          case 0:
            ledName = "Červená";
            break;
          case 1:
            ledName = "Zelená";
            break;
          case 2:
            ledName = "Modrá";
            break;
          default:
            ledName = "Neznámá";
            break;
        }
        Serial.print("LED: ");
        Serial.print(ledName);
        Serial.print(" Aktuální číslo: ");
        Serial.println(stringNum);
      }
    }

    IrReceiver.resume(); // Připravení přijímače na další signál
  }
}
