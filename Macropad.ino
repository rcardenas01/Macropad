#include <String.h>
#include <Keyboard.h>
#define MAX_SIZE 5

class Macro
{
private:
  struct KeyCombo
  {
    char press;
    arduino::String message;
    KeyCombo(char op, String message_in) : press(op), message(message_in) { }
  };

  String name;
  int num_keystrokes;
  KeyCombo key_strokes[MAX_SIZE];
  
public:
  Macro(String name_in) : name(name_in), num_keystrokes(0) {  }

  int add(char op, String message)
  {
    if(num_keystrokes == MAX_SIZE) return 1;

    key_strokes[num_keystrokes++] = {}
  }
  void execute();
  void clear_macro();
};

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
