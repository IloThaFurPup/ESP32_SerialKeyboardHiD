#include <Arduino.h>
#include <KeyboardDevice.h>
#include <BleCompositeHID.h>
#include <list>
#include <string>
#include <algorithm>

BleCompositeHID dispositivoBLE("Keyboard", "IloThaFurPup", 100); // Name, creator, battery percentage
KeyboardDevice* teclado;

bool conectadoAntes = false;

void setup() {
  Serial.begin(115200);
  
  teclado = new KeyboardDevice();
  dispositivoBLE.addDevice(teclado);
  dispositivoBLE.begin();
 Serial.println("All ready and waiting for user!");
// set up
}
void loop() {

  bool conectadoAhora = dispositivoBLE.isConnected();

  if (conectadoAhora && !conectadoAntes) {
    Serial.println("Connected!");
  }

  if (!conectadoAhora && conectadoAntes) {
    Serial.println("Desconectado...");
    Serial.println("Waiting for other connection");
  }

  conectadoAntes = conectadoAhora;

  if (conectadoAhora) {
    writeInTerminal(); // do function if connected
  }
}


void writeInTerminal() {
  
  if (!Serial.available()) return;
  String data = Serial.readStringUntil('\n');
  data.trim(); // Read serial

  bool tabPrs = false;
  bool ctrlPrs = false;

  std::list<String> comandosValidos = {"!MAYUS",
                                        "!ENTR",
                                        "!CTRL", 
                                        "!ESC", 
                                        "!DEL", 
                                        "!TAB", 
                                        "!BKSP", 
                                        "!INS", 
                                        "!HOME", 
                                        "!PGUP", 
                                        "!DEL", 
                                        "!END", 
                                        "!PGDW", 
                                        "!UP", 
                                        "!DWN", 
                                        "!LFT", 
                                        "!RGHT",
                                        "!LSHF",}; // All valid commands



auto it = std::find(comandosValidos.begin(), comandosValidos.end(), data);
  if (it != comandosValidos.end()) { // Si 'it' isn't at the end, one of the commands were found
        if (data == "!MAYUS"){
          teclado->keyClick(KEY_CAPSLOCK); //if command, then click key
          Serial.println("Caps pressed");
        }else if (data == "!ENTR"){
          teclado->keyClick(KEY_ENTER);
          Serial.println("Enter");
        }else if (data == "!ESC"){
          teclado->keyClick(KEY_ESC);
          Serial.println("Escape pressed");
        }else if (data == "!CTRL"){
          teclado->keyClick(KEY_LEFTCTRL);
          Serial.println("Control pressed");
        }else if (data == "!TAB"){
          teclado->keyClick(KEY_TAB);
          Serial.println("Tab pressed");
        }else if (data == "!BKSP") {
          teclado->keyClick(KEY_BACKSPACE);
          Serial.println("Backspace pressed");
        }else if (data == "!INS"){
          teclado->keyClick(KEY_INSERT);
          Serial.println("Insert pressed");
        }else if (data == "!HOME"){
          teclado->keyClick(KEY_HOME);
          Serial.println("Home pressed");
        }else if (data == "!PGUP"){
          teclado->keyClick(KEY_PAGEUP);
          Serial.println("Page up pressed");
        }else if (data == "!DEL"){
          teclado->keyClick(KEY_DELETE);
          Serial.println("Key forward delete pressed");
        }else if (data == "!END"){
          teclado->keyClick(KEY_END);
          Serial.println("Page end pressed");
        }else if (data == "!PGDW") {
          teclado->keyClick(KEY_PAGEDOWN);
          Serial.println("Page down pressed");
        }else if (data == "!UP"){
          teclado->keyClick(KEY_UP);
          Serial.println("Arrow up pressed");
        }else if (data == "!DWN"){
          teclado->keyClick(KEY_DOWN);
          Serial.println("Arrow down pressed");
        }else if (data == "!LFT"){
          teclado->keyClick(KEY_LEFT);
          Serial.println("Arrow left pressed");
        }else if (data == "!RGHT") {
          teclado->keyClick(KEY_RIGHT);
          Serial.println("Arrow right pressed");
        }else if (data == "!LSHF"){
          teclado->keyClick(KEY_LEFTSHIFT);
          Serial.println("Shift pressed");
        }
    } else {
 
for (int i = 0; i < data.length(); i++) {
  char c = data[i]; // goes through every letter by adding 1

  switch (c) { // sends in base of what 'c' is
    case '_': 
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
    case '-':
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
    case 'a':
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
    case ' ':
      teclado->keyClick(KEY_SPACE);
      break;
    case '1':
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
    case '!':
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

    case 'A':
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
  delay(50);
  }
}
}
