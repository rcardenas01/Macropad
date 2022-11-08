#ifndef MACRO_H
#define MACRO_H

#include <Ardruino.h>
#include <String.h>

class Macro
{
private:
  String name;
  
public:
  Macro();

  struct KeyCombo
  {
    char press;
    String message;
  };

  void add(KeyCombo);
  void execute();
  void clear_
};

#endif //MACRO_H