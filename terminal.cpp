#include "terminal.h"

/*positionnement du curseur:
Force Cursor Position <ESC>[{ROW};{COLUMN}f
*/
void terminalPosition(int ligne, int col){
  int longCol,longLig;
  char bufferCol[5];
  char bufferLig[5];
  longCol=sprintf(bufferCol,"%d",col);
  longLig=sprintf(bufferLig,"%d",ligne);
  Serial.write(0x1b);
  Serial.write('[');
  Serial.write(bufferLig[0]);
  if (longLig==2){
    Serial.write(bufferLig[1]);
  }
  Serial.write(';');
  Serial.write(bufferCol[0]);
  if (longCol==2){
    Serial.write(bufferCol[1]);
  }
  Serial.write('f');
}


/*initialisation du terminal
Set Attribute Mode <ESC>[{attr1};...;{attrn}m
Sets multiple display attribute settings. The following lists standard attributes:
0 Reset all attributes
*/
void terminalInit(void){
  //remettre a 0 toutes les attributs d'affichages
  Serial.write(0x1b);
  Serial.write('[');
  Serial.write('0');
  Serial.write('m');
  terminalEfface();
}


/*effacer le terminal
Erase Screen <ESC>[2J
Erases the screen with the background colour and moves the cursor to home.
*/
void terminalEfface(void){
  Serial.write(0x1b);
  Serial.write('[');
  Serial.write('2');
  Serial.write('J');
}



/*choix des couleurs pour le texte et le fond d'ecran
            Foreground Colours
              30 Black
              31 Red
              32 Green
              33 Yellow
              34 Blue
              35 Magenta
              36 Cyan
              37 White
            Background Colours
              40 Black
              41 Red
              42 Green
              43 Yellow
              44 Blue
              45 Magenta
              46 Cyan
              47 White
*/
void terminalCouleur (int texte,int font){
  char couleurTexte[3];
  char couleurFont[3];
  sprintf(couleurTexte,"%d",texte);
  sprintf(couleurFont,"%d",font);
  Serial.write(0x1b);
  Serial.write('[');
  Serial.write(couleurTexte[0]);
  Serial.write(couleurTexte[1]);
  Serial.write(';');
  Serial.write(couleurFont[0]);
  Serial.write(couleurFont[1]); 
  Serial.write('m');
}
