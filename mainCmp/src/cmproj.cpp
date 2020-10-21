#include <iostream>

#include "Example.hpp"
#include "Version.h"

int main(void)
{
  std::cout << "Version: " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH << std::endl;

  example::Example a(10);

  std::cout << "Var: " << a.getA() << std::endl;
  return 0;
}
