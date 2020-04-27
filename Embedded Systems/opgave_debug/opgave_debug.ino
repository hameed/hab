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
// Indsæt kommentar
int ledPin1 = 3;
int ledPin2 = 5;
int buzz = 8; // Hvis I kun har én buzzer, så sørg for at sætte den på i henhold til denne linje.

int counter = 0;

void setup() {
  // Indsæt kommentar
  Serial.begin(9600);

  // Indsæt kommentar
  pinMode(buzz, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

// Indsæt kommentar
int numbers = 0;
String data;

void loop() {

  // Indsæt kommentar
  while (Serial.available()) {
    numbers = Serial.read();
    delay(500);

    // Indsæt kommentar
    data += (char)numbers;

    // Ændr dette kald til noget, der giver mening i forhold til at debugge programmet.
    Serial.println("Edit This Line");

    // Indsæt kommentar
    if (data == "CASE_1") {
      digitalWrite(ledPin2, LOW);
      noTone(5);
      delay(3000);
    }

    // Indsæt kommentar
    if (data == "CASE_2") {
      digitalWrite(ledPin2, HIGH);
      tone(ledPin2, 0);
      delay(3000);
    }

    // Indsæt kommentar
    if (data == "CASE_3") {
      digitalWrite(ledPin1, HIGH);
      delay(3000);
    }

    // Indsæt kommentar
    if (data == "CASE_4") {
      digitalWrite(ledPin1, LOW);
      delay(3000);
    }

    /* ---------------------------------------------------------------------------------------------
       ---------------------------------------------------------------------------------------------
       ----------------------------- DEBUG IKKE RESTEN! -------------------------------------------
       -----------------------------------------------------------------------------------------------
       ----------------------------------------------------------------------------------------------*/


    if (strcmp(data.c_str(), rot13(str)) == 0) {
      //Play first section
      int count = 0;

      while (count < ledPin2) {
        count ++;

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

void beep(int note, int duration) {

  tone(buzz, note, duration);


  if (counter % 2 == 0) {
    digitalWrite(ledPin1, HIGH);
    delay(duration);
    digitalWrite(ledPin1, LOW);
  }
  else {
    digitalWrite(ledPin2, HIGH);
    delay(duration);
    digitalWrite(ledPin2, LOW);
  }

  noTone(buzz);
  delay(50);
  counter++;
}

void firstSection() {
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

void secondSection() {
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
