#ifndef MACRO_H
#define MACRO_H

#include <Ardruino.h>
#include <String.h>
#include <Keyboard.h>

class Macro
{
private:
  arduino::String name;
  struct KeyCombo
  {
    char press;
    arduino::String message;
  };
  
public:
  Macro(arduino::String);

  void add(char, arduino::String);
  void execute();
  void clear_macro();
};

#endif //MACRO_H