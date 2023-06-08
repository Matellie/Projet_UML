#include <iostream>

#include "InterfaceConsole.h"

int main(int argc, char *argv[])
{
  if (argc == 1)
  {
    InterfaceConsole interface;
    interface.Start();
  }
  else if (argc == 2)
  {
    InterfaceConsole interface(argv[1]);
    interface.Start();
  }

  return 0;
}