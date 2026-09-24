#pragma once

#define TYPE int
#define NAME IntArray
#include "DynamicArray.def"

static inline void IntArray_print(IntArray* self) {
  printf("IntArray\n---------\n[");
  for (size_t i = 0; i < self->size; i++) {
    printf("%d ", self->data[i]);
  }
  printf("]\n\n");
}

#define TYPE double
#define NAME DoubleArray
#include "DynamicArray.def"

static inline void DoubleArray_print(DoubleArray* self) {
  printf("DoubleArray\n---------\n[");
  for (size_t i = 0; i < self->size; i++) {
    printf("%f ", self->data[i]);
  }
  printf("]\n\n");
}

typedef struct {
  double x, y, z;
} Vec3;

#define TYPE Vec3
#define NAME Vec3Array
#include "DynamicArray.def"

static inline void Vec3Array_print(Vec3Array* self) {
  printf("Vec3Array\n---------\n");
  for (size_t i = 0; i < self->size; i++) {
    printf("(%f %f %f)\n", self->data[i].x, self->data[i].y, self->data[i].z);
  }
  printf("\n");
}

#define ARR_INIT_CAP 4

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define array_reserve(self, cap)                                                                            \
  do {                                                                                                      \
    if ((cap) > (self)->capacity) {                                                                         \
      if ((self)->capacity == 0) {                                                                          \
        (self)->capacity = ARR_INIT_CAP;                                                                    \
      }                                                                                                     \
      while ((cap) > (self)->capacity) {                                                                    \
        (self)->capacity *= 1.5;                                                                            \
      }                                                                                                     \
      (self)->data = (typeof((self)->data))realloc((self)->data, (self)->capacity * sizeof(*(self)->data)); \
      assert((self)->data != nullptr);                                                                      \
    }                                                                                                       \
  } while (false)

#define array_free(self)            \
  do {                              \
    free((self)->data);             \
    *(self) = (typeof(*(self))){0}; \
  } while (false)

#define array_push(self, value)            \
  do {                                     \
    array_reserve(self, (self)->size + 1); \
    (self)->data[(self)->size++] = value;  \
  } while (false)

#define array_cat(self, other, other_size)                                            \
  do {                                                                                \
    array_reserve((self), (self)->size + (other_size));                               \
    memcpy((self)->data + (self)->size, other, (other_size) * sizeof(*(self)->data)); \
    (self)->size += (other_size);                                                     \
  } while (false)

#define array_pop(self)     \
  do {                      \
    if ((self)->size > 0) { \
      --(self)->size;       \
    }                       \
  } while (false)
