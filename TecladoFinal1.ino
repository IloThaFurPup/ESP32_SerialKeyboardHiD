#include <Arduino.h>
#include <KeyboardDevice.h> 
#include <BleCompositeHID.h>
#include <list>
#include <string>
#include <algorithm>

BleCompositeHID dispositivoBLE("Teclado", "IloThaFurPup", 100); // We specify (<Name of the device>, <Author / Manufacturer>, <Battery percentage (leave in 100 by now)>)
KeyboardDevice* teclado; // And how the device is going to be called in the code

bool connectedBefore = false;

void setup() {
  Serial.begin(115200); //Start serial
  
  teclado = new KeyboardDevice(); 
  dispositivoBLE.addDevice(teclado);
  dispositivoBLE.begin(); // Inital setup
 Serial.println("All ready and waiting for user!");
}

void loop() {

  bool connectedNow = dispositivoBLE.isConnected();

  if (connectedNow && !connectedBefore) { // if it is connected by the first time
    Serial.println("Connected!");
  }

  if (!connectedNow && connectedBefore) { // if it was connected but disconnected
    Serial.println("Disconnected...");
    Serial.println("Waiting for other connection...");
  }

  connectedBefore = connectedNow; // Executes afterwards so the messages won't repeat

  if (connectedNow) { // If it is connected
    writeInTerminal(); //Do function  
  }
}


void writeInTerminal() {
  
  if (!Serial.available()) return; // If serial isn't avaliable don't do anything
  String Dato = Serial.readStringUntil('\n'); // Read the string gotten until '\n' ('\n' == enter)
  Dato.trim(); // Deletes '\n'

  std::list<String> comandosValidos = {"!MAYUS",
                                       "!ENTR", 
                                       "!DEL"};

auto it = std::find(comandosValidos.begin(), comandosValidos.end(), Dato); // We ask "it" to find in between the begin and end of the list of valid commands the variable "Dato"
  if (it != comandosValidos.end()) { // if 'it' isn't the end, a coincidence was found
  
/*
From here we will:
Detect the type command
Translate it to one of the three buttons (Caps, enter or backspace)
*/


        if (Dato == "!MAYUS"){
          teclado->keyClick(KEY_CAPSLOCK);
          Serial.println("Caps clicked");
        }if (Dato == "!ENTR"){
          teclado->keyClick(KEY_ENTER);
          Serial.println("Enter");
        }if (Dato == "!DEL") {
          teclado->keyClick(KEY_BACKSPACE);
          Serial.println("Backspace");
        }
    } else {
 
for (int i = 0; i < Dato.length(); i++) { // 'i' is zero, while Dato length is bigger than 'i', 'i' will add up to 1
  char c = Dato[i]; // c is the index of 'i', which is adding up to one until it is bigger than 'i', so each letter will be wrote

/*
From here:
We will detect the character ('c') and depending on what character it is, it will click the corresponding button
Reamamber this is a EN keyboard, other keys or if the system has another layout, the changes won't be perfect for the non alpha-numeric characters
*/

  switch (c) { 
    case '_':// for the second options in the right of you keyboard (ouch), with the shift)
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_MINUS);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case '+':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_EQUAL);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case '{':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_LEFTBRACE);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case '}':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_RIGHTBRACE);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case ':':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_SEMICOLON);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case '"':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_APOSTROPHE);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case '~':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_BACKSLASH);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
    case '<':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_COMMA);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case '>':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_DOT);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case '?':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_SLASH);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case '-': // for the first options in the right of you keyboard)
      teclado->keyClick(KEY_MINUS);
      break;
    case '=':
      teclado->keyClick(KEY_EQUAL);
      break;
    case '[':
      teclado->keyClick(KEY_LEFTBRACE);
      break;
    case ']':
      teclado->keyClick(KEY_RIGHTBRACE);
      break;
    case ';':
      teclado->keyClick(KEY_SEMICOLON);
      break;
    case '\'':
      teclado->keyClick(KEY_APOSTROPHE);
      break;
    case '\\':
      teclado->keyClick(KEY_BACKSLASH);
    case ',':
      teclado->keyClick(KEY_COMMA);
      break;
    case '.':
      teclado->keyClick(KEY_DOT);
      break;
    case '/':
      teclado->keyClick(KEY_SLASH);
      break;
    case 'a': //lowercase
      teclado->keyClick(KEY_A);
      break;
    case 'b':
      teclado->keyClick(KEY_B);
      break;
    case 'c':
      teclado->keyClick(KEY_C);
      break;
    case 'd':
      teclado->keyClick(KEY_D);
      break;
    case 'e':
      teclado->keyClick(KEY_E);
      break;
    case 'f':
      teclado->keyClick(KEY_F);
      break;
    case 'g':
      teclado->keyClick(KEY_G);
      break;
    case 'h':
      teclado->keyClick(KEY_H);
      break;
    case 'i':
      teclado->keyClick(KEY_I);
      break;
    case 'j':
      teclado->keyClick(KEY_J);
      break;
    case 'k':
      teclado->keyClick(KEY_K);
      break;
    case 'l':
      teclado->keyClick(KEY_L);
      break;
    case 'm':
      teclado->keyClick(KEY_M);
      break;
    case 'n':
      teclado->keyClick(KEY_N);
      break;
    case 'o':
      teclado->keyClick(KEY_O);
      break;
    case 'p':
      teclado->keyClick(KEY_P);
      break;
    case 'q':
      teclado->keyClick(KEY_Q);
      break;
    case 'r':
      teclado->keyClick(KEY_R);
      break;
    case 's':
      teclado->keyClick(KEY_S);
      break;
    case 't':
      teclado->keyClick(KEY_T);
      break;
    case 'u':
      teclado->keyClick(KEY_U);
      break;
    case 'v':
      teclado->keyClick(KEY_V);
      break;
    case 'w':
      teclado->keyClick(KEY_W);
      break;
    case 'x':
      teclado->keyClick(KEY_X);
      break;
    case 'y':
      teclado->keyClick(KEY_Y);
      break;
    case 'z':
      teclado->keyClick(KEY_Z);
      break;
    case ' ': //space
      teclado->keyClick(KEY_SPACE);
      break;
    case '1': // numbers
      teclado->keyClick(KEY_1);
      break;
    case '2':
      teclado->keyClick(KEY_2);
      break;
    case '3':
      teclado->keyClick(KEY_3);
      break;
    case '4':
      teclado->keyClick(KEY_4);
      break;
    case '5':
      teclado->keyClick(KEY_5);
      break;
    case '6':
      teclado->keyClick(KEY_6);
      break;
    case '7':
      teclado->keyClick(KEY_7);
      break;
    case '8':
      teclado->keyClick(KEY_8);
      break;
    case '9':
      teclado->keyClick(KEY_9);
      break;
    case '0':
      teclado->keyClick(KEY_0);
      break;
    case '!': //Second option next to numbers
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      teclado->keyClick(KEY_1);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case '@':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_2);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case '#':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_3);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case '$':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_4);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case '%':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_5);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case '^':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_6);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case '&':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_7);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case '*':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_8);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case '(':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_9);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case ')':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_0);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case 'A': //For all Upper case
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      teclado->keyClick(KEY_A);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case 'B':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_B);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case 'C':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_C);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case 'D':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_D);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case 'E':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_E);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case 'F':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_F);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case 'G':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_G);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case 'H':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_H);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case 'I':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_I);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case 'J':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      teclado->keyClick(KEY_J);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case 'K':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_K);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case 'L':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_L);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case 'M':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_M);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case 'N':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_N);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case 'O':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_O);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case 'P':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_P);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case 'Q':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_Q);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case 'R':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_R);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case 'S':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_S);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case 'T':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      teclado->keyClick(KEY_T);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case 'U':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_U);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case 'V':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_V);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case 'W':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_W);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case 'X':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_X);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case 'Y':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_Y);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break;
    case 'Z':
      teclado->modifierKeyPress(KEY_MOD_LSHIFT);
      delay(10);
      teclado->keyClick(KEY_Z);
      teclado->modifierKeyRelease(KEY_MOD_LSHIFT);
      break; 
   }
  delay(25); // the click takes 10 seconds so, for the double letters to not jam, a delay is required, and for the other where you click the keymod.
  }
}
}