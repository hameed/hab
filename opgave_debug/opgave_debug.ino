#include "encrypt.h";

/* ----------------------------------------------------------------------------------------------
   -------------------------- Denne del skal ikke debugges --------------------------------------
   ---------------------------------------------------------------------------------------------- */
const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;

/* ----------------------------------------------------------------------------------------------
    -------------------------------- DEBUG BEGIN ------------------------------------------------
    --------------------------------------------------------------------------------------------- */

int pin1 = 3;
int pin2 = 5;
int buzz = 8;

int counter = 0;

void setup() {
  // Indsæt kommentar
  Serial.begin(9600);

  // Indsæt kommentar
  pinMode(buzz, OUTPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);

}
// Indsæt kommentar
int numbers = 0;
String data;

void loop() {

  // Tjek om buffer indeholder noget, der skal indlæses
  while (Serial.available()) {

    // Indlæser 1 chars talværdi ad gangen i bytes
    numbers = Serial.read();
    Serial.println(numbers);

    // Blot for at illustrere en pointe
    delay(3000);

    // vedhæfter char i enden på allerede opsamlet string
    data += (char)numbers;
    Serial.println(data);

    if (data == "CASE_1") {

      // slukker pin2 (som er pin 5)
      digitalWrite(pin2, LOW);

      // slukker for buzzer på pin 5
      noTone(5);
      delay(1000);
    }

    if (data == "CASE_2") {
      Serial.println("HEJ CASE 2");

      // tænder pin2 (som er pin 5)
      digitalWrite(pin2, HIGH);

      // tænder buzzeren med angivet frekvens
      tone(pin2, 500);
      delay(1000);

    }

    if (data == "CASE_3") {

      // tænder pin1 som er pin 3 (LED)
      digitalWrite(pin1, HIGH);
      delay(100);
    }

    if (data == "CASE_4") {

      // slukker pin1 som er pin 3 (LED)
      digitalWrite(pin1, LOW);
      delay(100);
    }

    /* ---------------------------------------------------------------------------------------------
       ---------------------------------------------------------------------------------------------
       ----------------------------- DEBUG IKKE RESTEN! -------------------------------------------
       -----------------------------------------------------------------------------------------------
       ----------------------------------------------------------------------------------------------*/


    // Vi venter som sagt med det her!

    /*
        rot13(str) er blot "hej med dig" krypteret med Cæsar chiffer, hvor ASCII-værdierne er rykket 13
        pladser som defineret i encrypt.h, som bliver inkluderet i toppen af denne fil med #include encrypt.h */
    if (strcmp(data.c_str(), rot13(str)) == 0) {
      //Play first section
      int foo = 0;

      while (foo < pin2) {
        foo ++;
        Serial.println(foo);
        firstSection();

        //Play second section
        secondSection();

        //Variant 1
        beep(f, 250);
        beep(gS, 500);
        beep(f, 350);
        beep(a, 125);
        beep(cH, 500);
        beep(a, 375);
        beep(cH, 125);
        beep(eH, 650);

        delay(500);

        //Repeat second section
        secondSection();

        //Variant 2
        beep(f, 250);
        beep(gS, 500);
        beep(f, 375);
        beep(cH, 125);
        beep(a, 500);
        beep(f, 375);
        beep(cH, 125);
        beep(a, 650);

        delay(650);
      }
    }
  }
  data = "";
}

void beep(int note, int duration)
{

  tone(buzz, note, duration);


  if (counter % 2 == 0)
  {
    digitalWrite(pin1, HIGH);
    delay(duration);
    digitalWrite(pin1, LOW);
  } else
  {
    digitalWrite(pin2, HIGH);
    delay(duration);
    digitalWrite(pin2, LOW);
  }


  noTone(buzz);

  delay(50);


  counter++;
}

void firstSection()
{
  beep(a, 500);
  beep(a, 500);
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);

  delay(500);

  beep(eH, 500);
  beep(eH, 500);
  beep(eH, 500);
  beep(fH, 350);
  beep(cH, 150);
  beep(gS, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);

  delay(500);
}

void secondSection()
{
  beep(aH, 500);
  beep(a, 300);
  beep(a, 150);
  beep(aH, 500);
  beep(gSH, 325);
  beep(gH, 175);
  beep(fSH, 125);
  beep(fH, 125);
  beep(fSH, 250);

  delay(325);

  beep(aS, 250);
  beep(dSH, 500);
  beep(dH, 325);
  beep(cSH, 175);
  beep(cH, 125);
  beep(b, 125);
  beep(cH, 250);

  delay(350);
}
