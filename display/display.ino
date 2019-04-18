/* display
 *  
 *  CSE 132 - Assignment 7
 *  
 *  Fill this out so we know whose assignment this is.
 *  
 *  Name: Karen Ye
 *  WUSTL Key: 454998
 *  
 *  Name:
 *  WUSTL Key:
 *  
 */

#include "font.h"

int upButtonState;
int downButtonState;

void setup () {
 Serial.begin(9600);
 pinMode(A0, INPUT);
 pinMode(A1, INPUT);
 
// Serial.println("hi");
// char h = 0x28;  // 'H'
// char i = 0x29;  // 'I'
// Serial.println(font_5x7[h][0],BIN);
// Serial.println(font_5x7[h][1],BIN);
// Serial.println(font_5x7[h][2],BIN);
// Serial.println(font_5x7[h][3],BIN);
// Serial.println(font_5x7[h][4],BIN);
//
// Serial.println(font_5x7[i][0],BIN);
// Serial.println(font_5x7[i][1],BIN);
// Serial.println(font_5x7[i][2],BIN);
// Serial.println(font_5x7[i][3],BIN);
// Serial.println(font_5x7[i][4],BIN);

  //make all rows LOW
  for(int i = 2; i <= 8; ++i){
     digitalWrite(i, LOW);
  }
  // make all columns HIGH
  for(int i = 9; i <= 13; ++i){
     digitalWrite(i, HIGH);
  }
  for(int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }

}

int character = 0x10;
long previousMillis = 0;
long delta = 250;

void loop () {
//  upButtonState = analogRead(A0);
//  downButtonState = analogRead(A1);
//  
//  Serial.print("Increment:");
//  Serial.println(upButtonState);
//  Serial.print("Decrement");
//  Serial.println(downButtonState);
//  Serial.println();
//  delay(500);

unsigned long currentMillis = millis();
if (currentMillis - previousMillis > delta) {
  previousMillis = currentMillis;

      upButtonState = analogRead(A0);
      downButtonState = analogRead(A1);
        if (upButtonState == 0) {
          character++;
          Serial.println("hi");
        }

        else if (downButtonState == 0) {
          character--;
          Serial.println("bye");
        }
    
  }
  writeChar(character);
}


void resetRow() {
  for(int z = 2; z <=8; z++) {
    digitalWrite(z, LOW);
  }
}

void writeChar(char c){
  
  for(int j = 9; j <= 13; j++){   //loops through column

    
    for(int k = 9; k <= 13; k++){   //loops through column again
      if(k == j) {
        digitalWrite(k, LOW);
      }
      else {
        digitalWrite(k, HIGH);
      }
    }
    for(int i = 2; i <= 8; i++) {    //loops through row
      int pt = (font_5x7[c][j-9] >> (7-i+2)) & 1;
      if(pt == 1) {
        digitalWrite(i, HIGH);
      }
      else {
        digitalWrite(i, LOW);
      }
    }  
    digitalWrite(j, LOW);
    resetRow();
    
  }
}
