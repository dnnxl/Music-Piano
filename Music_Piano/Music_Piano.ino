#include "piches.h"             // Archivo con todas las notas y frecuencias de los tonos.
#define ACTIVATED LOW           // Definir la variable global ACTIVATED a LOW.

const int PIEZO = 11;           // Variable PIEZO pin digital 11

int buttonSong = 8;             // Boton para la canción en el pin digital 8
const int BUTTON_C = 6;         // Boton en el pin digital 6
const int BUTTON_AS = 4;        // Boton en el pin digital 4  
const int BUTTON_A = 3;         // Boton en el pin digital 3
const int BUTTON_G = 2;         // Boton en el pin digital 2

void setup()                    // Función setup, solo se ejecuta una vez en todo el programa.
{
  Serial.begin(9600);             // Comunicación serial en la velocidad 9600 bps
  pinMode(BUTTON_C, INPUT);       // El boton BUTTON_C como entrada.
  digitalWrite(BUTTON_C, HIGH);   // Activar el boton BUTTON_C
  pinMode(BUTTON_AS, INPUT);      // El boton BUTTON_aS como entrada.
  digitalWrite(BUTTON_AS, HIGH);  // Activar el boton BUTTON_AS
  pinMode(BUTTON_A, INPUT);       // El boton BUTTON_A como entrada.
  digitalWrite(BUTTON_A, HIGH);   // Activar el boton BUTTON_A
  pinMode(BUTTON_G, INPUT);       // El boton BUTTON_G como entrada.
  digitalWrite(BUTTON_G, HIGH);   // Activar el boton BUTTON_G
  pinMode (buttonSong, INPUT);    // El boton buttonSong como entrada.
  digitalWrite(buttonSong, HIGH); // Activar el boton buttonSong
}

// Notas de las melodias de la canción
int melody[] = {
  NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4,  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_F4, 0, 0,
  NOTE_DS4, NOTE_DS4, NOTE_F4, NOTE_D4, 0, 0, 0, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D5, NOTE_D5,
  NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_G3, NOTE_G3, NOTE_AS3, NOTE_AS4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_AS4, NOTE_AS4,
  NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_G3, NOTE_G3, NOTE_AS3,

  NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4,  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_F4, 0, 0,
  NOTE_DS4, NOTE_DS4, NOTE_F4, NOTE_D4, NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_F3, NOTE_AS3, NOTE_A3, NOTE_F3,
  NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D5, NOTE_D5,
  NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_F3, NOTE_AS3, NOTE_G3, NOTE_AS4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_AS4, NOTE_AS4,
};

// Duracion de las notas: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4.5, 2.25, 2.25, 4.5, 2.25, 2.25, 2.25, 2.25, 2.25, 4.5, 3, 9, 4.5,
  4.5, 2.25, 4.5, 2.25, 1.125, 2.25, 4.5, 4.5, 2.25, 4.5, 2.25, 4.5, 2.25,
  4.5, 4.5, 4.5, 2.25, 4.5, 4.5, 4.5, 2.25, 4.5, 2.25, 4.5, 2,
  4.5, 4.5, 4.5, 2.25, 4.5, 4.5,

  4.5, 2.25, 2.25, 4.5, 2.25, 2.25, 2.25, 2.25, 2.25, 4.5, 3, 9, 4.5,
  4.5, 2.25, 4.5, 4.5, 4.5, 4.5, 4.5, 4.5, 3, 3, 4.5,
  2.25, 4.5, 2.25, 4.5, 2.25,
  4.5, 4.5, 4.5, 4.5, 2.25, 4.5, 4.5, 2.25, 4.5, 2.25, 4.5, 2.25,
} ;

// Notas de la melodia de la otra cancion
int melodyScared[] = {
  NOTE_E4, NOTE_E4, NOTE_B4, 0, NOTE_B4, NOTE_GS4,
  NOTE_E5, NOTE_E5,
  NOTE_D5, NOTE_D5, NOTE_DS5, NOTE_CS5, NOTE_DS5, NOTE_E5
};

// Duracion de las notas
int noteDurationsScared[] = {
  2.25, 2.25, 2.25, 3,  3.125, 2.65,
  2.25, 2.25, 2.25, 2.25, 2.25, 2.25, 2.25, 2.25
};

void loop()
{
  while (digitalRead(BUTTON_C) == ACTIVATED)            // Mientras que el BUTTON_C esta en desactivado 
  {
    tone(PIEZO, NOTE_C5);                               // La nota C5 de la melodia
  }
  while (digitalRead(BUTTON_AS) == ACTIVATED)           // Mientras que el BUTTON_AS esta en desactivado 
  {
    tone(PIEZO, NOTE_AS4);                              // La nota as4 de la melodia
  }

  while (digitalRead(BUTTON_A) == ACTIVATED)            // Mientras que el BUTTON_A esta en desactivado 
  {
    tone(PIEZO, NOTE_A4);                               // La nota a4 de la melodia
  }

  while (digitalRead(BUTTON_G) == ACTIVATED)            // Mientras que el BUTTON_G esta en desactivado 
  {
    tone(PIEZO, NOTE_G4);                               // La nota g4 de la melodia
  }

  if (digitalRead(buttonSong) == ACTIVATED) {          // Mientras que el buttonSong esta en desactivado, reproducir la melodia
    for (int thisNote = 0; thisNote < 14; thisNote++) {
      int noteDurationsScareds = 600 / noteDurationsScared[thisNote];
      tone(11, melodyScared[thisNote], noteDurationsScared);
      int pauseBetweenNotes = noteDurationsScareds * 1.50;
      delay(pauseBetweenNotes);
      noTone(11);
    }
  }
  noTone(PIEZO);
}
