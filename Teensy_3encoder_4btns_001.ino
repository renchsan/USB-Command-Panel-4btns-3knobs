//  Matt Rencher
//  Created: 1/29/2018
//  Teensy LC USB Control Panel
//  3 Rotary Encoders, 4 Pushbuttons
//  Keyboard Commands @ https://www.pjrc.com/teensy/td_keyboard.html
//  10cm x 6cm plastic enclosure

#include <Bounce2.h>
#include <Rotary.h>

// Rotary Encoder 1: (CLK, DATA, SW)
// Rotary Encoder 2: (CLK, DATA, SW)
// Rotary Encoder 3: (CLK, DATA, SW)

Rotary rotary1 = Rotary(3,2);
Rotary rotary2 = Rotary(7,6);
Rotary rotary3 = Rotary(10,9);

int rot1BtnPin = 4;
int rot2BtnPin = 8;
int rot3BtnPin = 11;

int btn1Pin = 13;  // Button 1;
int btn2Pin = 14;  // Button 2;
int btn3Pin = 15;  // Button 3;
int btn4Pin = 16;  // Button 4;

Bounce rot1Btn = Bounce(4, 10);
Bounce rot2Btn = Bounce(8, 10);
Bounce rot3Btn = Bounce(11,10);
Bounce btn1 = Bounce(13, 10);
Bounce btn2 = Bounce(14, 10);
Bounce btn3 = Bounce(15, 10);
Bounce btn4 = Bounce(16, 10);

void setup() {
  pinMode (rot1BtnPin, INPUT_PULLUP);
  pinMode (rot2BtnPin, INPUT_PULLUP);
  pinMode (rot3BtnPin, INPUT_PULLUP);
  pinMode (btn1Pin, INPUT_PULLUP);
  pinMode (btn2Pin, INPUT_PULLUP);
  pinMode (btn3Pin, INPUT_PULLUP);
  pinMode (btn4Pin, INPUT_PULLUP);

  Serial.begin (9600);
}

void loop() {
  unsigned char result1 = rotary1.process();
  if (result1 == DIR_CW) {
    rot1CW();
  } else if (result1 == DIR_CCW) {
    rot1CCW();
  }
  unsigned char result2 = rotary2.process();
  if (result2 == DIR_CW) {
    rot2CW();
  } else if (result2 == DIR_CCW) {
    rot2CCW();
  }
  unsigned char result3 = rotary3.process();
  if (result3 == DIR_CW) {
    rot3CW();
  } else if (result3 == DIR_CCW) {
    rot3CCW();
  }
  
  rot1Btn.update();
  rot2Btn.update();
  rot3Btn.update();
  btn1.update();
  btn2.update();
  btn3.update();
  btn4.update();
  
  if (rot1Btn.fallingEdge()) {
    rot1pushBtn();
  }
  if (rot2Btn.fallingEdge()) {
    rot2pushBtn();
  }
  if (rot3Btn.fallingEdge()) {
    rot3pushBtn();
  }
  if (btn1.fallingEdge()) {
    btn1pushBtn();
  }
  if (btn2.fallingEdge()) {
    btn2pushBtn();
  }
  if (btn3.fallingEdge()) {
    btn3pushBtn();
  }
  if (btn4.fallingEdge()) {
    btn4pushBtn();
  }
}


// Keyboard Input Command Assignment
// Edit these keyboard statements to change your controller's inputs

void rot1pushBtn()
{
  Keyboard.press(KEY_MEDIA_PLAY_PAUSE);
  Keyboard.release(KEY_MEDIA_PLAY_PAUSE);
  delay(30);
  Serial.println("Rotary 1 Button Pressed, Play/Pause");
}
void rot1CCW(){
  Keyboard.press(KEY_MEDIA_VOLUME_DEC);
  Keyboard.release(KEY_MEDIA_VOLUME_DEC);
  delay(30);
  Serial.println("Rotary 1 CCW; Volume - ");
}
void rot1CW(){
  Keyboard.press(KEY_MEDIA_VOLUME_INC);   
  Keyboard.release(KEY_MEDIA_VOLUME_INC);
  Serial.println("Rotary 1 CW; Volume + ");
  delay(30);
}
void rot2pushBtn()
{
  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.press(KEY_F10);
  delay(30);
  Keyboard.releaseAll();
  Serial.println("Rotary 2 Pressed; ALT F10");
}
void rot2CCW()
{
  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.press(KEY_F11);
  delay(30);
  Keyboard.releaseAll();
  Serial.println("Rotary 2 CCW; ALT F11");
}
void rot2CW()
{
  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.press(KEY_F12);
  delay(30);
  Keyboard.releaseAll();
  Serial.println("Rotary 2 CW; ALT F12");
}
void rot3pushBtn()
{
  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.press(KEY_F13);
  delay(30);
  Keyboard.releaseAll();
  Serial.println("Rotary 3 Button Pressed, ALT + F13");
}
void rot3CCW()
{
  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.press(KEY_F14);
  delay(30);
  Keyboard.releaseAll();
  Serial.println("Rotary 3 CCW; Page Up");
}
void rot3CW()
{
  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.press(KEY_F15);
  delay(30);
  Keyboard.releaseAll();
  Serial.println("Rotary 3 CW; Page Down");
}
void btn1pushBtn()
{
  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.press(KEY_F16);
  delay(30);
  Keyboard.releaseAll();
  Serial.println("BTN1 Pressed, ALT+F14");
}
void btn2pushBtn()
{
  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.press(KEY_F17);
  delay(30);
  Keyboard.releaseAll();
  Serial.println("BTN2 Pressed, ALT+F15");
}
void btn3pushBtn()
{
  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.press(KEY_F18);
  delay(30);
  Keyboard.releaseAll();  
  Serial.println("BTN3 Pressed, ALT+F16");
}
void btn4pushBtn()
{
  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.press(KEY_F19);
  delay(30);
  Keyboard.releaseAll();
  Serial.println("BTN4 Pressed, ALT+F17");
}
