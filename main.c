#include <stdio.h>
#include <stdlib.h>

#include "DynamicArray.h"

int main(void) {
  IntArray arr;
  IntArray_init(&arr, 10);
  for (int i = 0; i < 10; i++) {
    IntArray_push(&arr, i * 2);
  }
  IntArray_print(&arr);
  IntArray_free(&arr);

  DoubleArray darr;
  DoubleArray_init(&darr, 10);
  for (int i = 0; i < 10; i++) {
    DoubleArray_push(&darr, (double)(i) * 2.0);
  }
  DoubleArray_print(&darr);
  DoubleArray_free(&darr);

  Vec3Array varr;
  Vec3Array_init(&varr, 10);
  for (double d = 0.; d < 10.; d += 1.) {
    Vec3Array_push(&varr, (Vec3){d * 2.1, d * 2.2, d * 2.3});
  }
  Vec3Array_print(&varr);
  Vec3Array_free(&varr);

  return 0;
}