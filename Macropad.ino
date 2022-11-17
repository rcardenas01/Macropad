#include <String.h>
#include <Keyboard.h>
#define MAX_SIZE 7

class Macro
{
private:
  struct KeyCombo
  {
    char op;
    String message;
    
    KeyCombo(char press, String message_in) : press(op), message(message_in) { }
    KeyCombo() : press(0), message("") { }

    void execute() 
    {
      if (op == 'p')
    }
  };

  String name;
  int num_keystrokes;
  KeyCombo key_strokes[MAX_SIZE];
  
public:
  Macro(String name_in) : name(name_in), num_keystrokes(0) { }

  int add(char op, String message)
  {
    if(num_keystrokes == MAX_SIZE) return 1;

    key_strokes[num_keystrokes++] = KeyCombo(op, message);
    return 0;
    
  }
  void execute() 
  {
    for(int i = 0; i < num_keystrokes; ++i)
    {

    }
  }
  void clear_macro();
};

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
