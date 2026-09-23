#include <stdio.h>

#include "DynamicArray.h"

int main() {
  IntArray arr = {0};
  for (int i = 0; i < 10; i++) {
    array_push(&arr, i * 2);
  }
  IntArray_print(&arr);

  DoubleArray darr = {0};
  for (int i = 0; i < 10; i++) {
    array_push(&darr, (double)(i) * 2.0);
  }
  DoubleArray_print(&darr);

  Vec3Array varr = {};
  for (double d = 0.; d < 10.; d += 1.) {
    array_push(&varr, ((Vec3){d * 2.1, d * 2.2, d * 2.3}));
  }
  Vec3Array_print(&varr);

  array_free(&arr);
  array_free(&darr);
  return 0;
}