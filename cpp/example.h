#include <jsi/jsilib.h>
#include <jsi/jsi.h>

#ifndef EXAMPLE_H
#define EXAMPLE_H

namespace example {
  void installJsi(facebook::jsi::Runtime& jsiRuntime);
  int multiply(float a, float b);
  int multiplyJsi(float a, float b);
  int add(float a, float b);
}

#endif /* EXAMPLE_H */
