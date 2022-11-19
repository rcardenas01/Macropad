#include <Keyboard.h>
#include <KeyboardLayout.h>

#include <String.h>
#define MAX_SIZE 5
#define PAGE_SIZE 12

class Macro
{
private:
  struct KeyCombo
  {
    /*
      codes are as follows: 
      p: press a key
      f: print to screen 
      l: print with ln
      w: write to keyboard
      u: unpress
    */
    char op;
    char key;
    String message;
    
    KeyCombo(char press, char key_in, String message_in) : op(press), key(key_in), message(message_in) { }
    KeyCombo() : op(0), key(0), message("") { }

    void execute() 
    {
      if (op == 'u')
      {
        Keyboard.releaseAll();
      }
      else if (op == 'p') 
      {
        Keyboard.press(key);
      }
      else if (op == 'f')
      {
        Keyboard.print(message);
      }
      else if (op == 'l')
      {
        Keyboard.println(message);
      }
      else if (op == 'w')
      {
        Keyboard.write(key);
      }
    }
  };

  int num_keystrokes;
  String name;
  KeyCombo key_strokes[MAX_SIZE];
  
public:
  Macro(String name_in) : name(name_in), num_keystrokes(0) { }

  Macro() : name(""), num_keystrokes(0) { }

  int add(char op, String message)
  {
    if(num_keystrokes == MAX_SIZE) return 1;

    key_strokes[num_keystrokes++] = KeyCombo(op, 0, message);
    return 0;
    
  }

  int add(char op, char press)
  {
    if(num_keystrokes == MAX_SIZE) return 1;

    key_strokes[num_keystrokes++] = KeyCombo(op, press, "");
    return 0;
  }

  void execute() 
  {
    for(int i = 0; i < num_keystrokes; ++i)
    {
      key_strokes[i].execute();
    }
  }
  void clear_macro()
  {
    num_keystrokes = 0;
  }
};

class Page
{
private:
  int num_macros;
  String page_name;
  Macro macros[PAGE_SIZE];
public:
  Page(String name) : page_name(name) { }
  Macro &operator[] (unsigned int index) 
  {
    return macros[index];
  }
};

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
