#pragma once

#include <stdio.h>
// #include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#define TYPE int32_t
#define NAME IntArray
#include "DynamicArray.h.def"

static inline void IntArray_print(IntArray* self) {
  printf("IntArray\n---------\n[");
  for (size_t i = 0; i < self->size; i++) {
    printf("%d ", self->data[i]);
  }
  printf("]\n\n");
}

#undef TYPE
#undef NAME

#define TYPE double
#define NAME DoubleArray
#include "DynamicArray.h.def"

static inline void DoubleArray_print(DoubleArray* self) {
  printf("DoubleArray\n---------\n[");
  for (size_t i = 0; i < self->size; i++) {
    printf("%f ", self->data[i]);
  }
  printf("]\n\n");
}

#undef TYPE
#undef NAME

typedef struct {
  double x, y, z;
} Vec3;

#define TYPE Vec3
#define NAME Vec3Array
#include "DynamicArray.h.def"

static inline void Vec3Array_print(Vec3Array* self) {
  printf("Vec3Array\n---------\n[");
  for (size_t i = 0; i < self->size; i++) {
    printf("(%f %f %f), ", self->data[i].x, self->data[i].y, self->data[i].z);
  }
  printf("]\n\n");
}

#undef TYPE
#undef NAME