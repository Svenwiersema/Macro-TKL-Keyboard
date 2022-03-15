// libraries
#include <Keyboard.h>

int modi = 0;
int tkl = 0;
int macro = 1;
int delayVal = 150;

// pins for the keys
#define INS 2
#define HOME 3
#define PGUP 4
#define DEL A3
#define END A2
#define PGDN A1
#define ARUP 16
#define ARLEFT 5
#define ARDOWN 6
#define ARRIGHT 10
#define MODIBTN 14

#define TKLLED A0
#define MACROLED 15

void setup() {
    pinMode(INS, INPUT_PULLUP);
    pinMode(HOME, INPUT_PULLUP);
    pinMode(PGUP, INPUT_PULLUP);
    pinMode(DEL, INPUT_PULLUP);
    pinMode(END, INPUT_PULLUP);
    pinMode(PGDN, INPUT_PULLUP);
    pinMode(ARUP, INPUT_PULLUP);
    pinMode(ARLEFT, INPUT_PULLUP);
    pinMode(ARDOWN, INPUT_PULLUP);
    pinMode(ARRIGHT, INPUT_PULLUP);
    pinMode(MODIBTN, INPUT_PULLUP);
    pinMode(TKLLED, OUTPUT);
    pinMode(MACROLED, OUTPUT);

    digitalWrite(TKLLED, HIGH);

    Serial.begin(9600);

}

void loop() {

    if(digitalRead(MODIBTN) == LOW) {
        if(modi == tkl) {
            modi = macro;
            digitalWrite(TKLLED, LOW);
            digitalWrite(MACROLED, HIGH);
            delay(delayVal);
        } else if(modi == macro) {
            modi = tkl;
            digitalWrite(TKLLED, HIGH);
            digitalWrite(MACROLED, LOW);
            delay(delayVal);
        }
    }

    if(modi == tkl) {
        if(digitalRead(INS) == LOW) {
          Keyboard.press(0xD1);
          //delay(delayVal);
        }else {
          Keyboard.release(0xD1);
        }
        if(digitalRead(HOME) == LOW) {
          Keyboard.press(0xD2);
          //delay(delayVal);
        }else {
          Keyboard.release(0xD2);
        }
        if(digitalRead(PGUP) == LOW) {
          Keyboard.press(0xD3);
          //delay(delayVal);
        }else {
          Keyboard.release(0xD3);
        }
        if(digitalRead(DEL) == LOW) {
          Keyboard.press(0xD4);
          //delay(delayVal);
        }else {
          Keyboard.release(0xD4);
        }
        if(digitalRead(END) == LOW) {
          Keyboard.press(0xD5);
          //delay(delayVal);
        }else {
          Keyboard.release(0xD5);
        }
        if(digitalRead(PGDN) == LOW) {
          Keyboard.press(0xD6);
          //delay(delayVal);
        }else {
          Keyboard.release(0xD6);
        }
        if(digitalRead(ARUP) == LOW) {
          Keyboard.press(0xDA);
          //delay(delayVal);
        }else {
          Keyboard.release(0xDA);
        }
        if(digitalRead(ARLEFT) == LOW) {
          Keyboard.press(0xD8);
          //delay(delayVal);
        }else {
          Keyboard.release(0xD8);
        }
        if(digitalRead(ARDOWN) == LOW) {
          Keyboard.press(0xD9);
          //delay(delayVal);
        }else {
          Keyboard.release(0xD9);
        }
        if(digitalRead(ARRIGHT) == LOW) {
          Keyboard.press(0xD7);
          //delay(delayVal);
        }else {
          Keyboard.release(0xD7);
        }
        
    } else if(modi == macro) {
        if(digitalRead(INS) == LOW) {
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_F2);
            Keyboard.releaseAll();
            delay(delayVal);
        }
        if(digitalRead(HOME) == LOW) {
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press('e');
            Keyboard.releaseAll();
            delay(delayVal);
        }
        if(digitalRead(PGUP) == LOW) {
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press('c');
          Keyboard.releaseAll();
          delay(delayVal);
        }
        if(digitalRead(DEL) == LOW) {
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press('v');
          Keyboard.releaseAll();
          delay(delayVal);
        }
        if(digitalRead(END) == LOW) {
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press('x');
          Keyboard.releaseAll();
          delay(delayVal);
        }
        if(digitalRead(PGDN) == LOW) {
          Keyboard.press(KEY_F3);
          Keyboard.press('g');
          Keyboard.releaseAll();
          delay(delayVal);
        }
        if(digitalRead(ARUP) == LOW) {
          Keyboard.press(KEY_F3);
          Keyboard.press('h');
          Keyboard.releaseAll();
          delay(delayVal);
        }
        if(digitalRead(ARLEFT) == LOW) {
          Keyboard.press(KEY_F3);
          Keyboard.press('b');
          Keyboard.releaseAll();
          delay(delayVal);
        }
    }

}
