#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "../DynamicArray.h"

static void test_int_array(void) {
  IntArray arr = {0};

  for (int i = 0; i < 10; ++i) {
    array_push(&arr, i * 2);
  }

  assert(arr.size == 10);
  assert(arr.capacity >= 10);
  for (size_t i = 0; i < arr.size; ++i) {
    assert(arr.data[i] == (int)(i * 2));
  }

  array_free(&arr);
  assert(arr.data == NULL);
  assert(arr.size == 0);
  assert(arr.capacity == 0);
}

static void test_double_array(void) {
  DoubleArray arr = {0};

  for (int i = 0; i < 8; ++i) {
    array_push(&arr, (double)i * 1.5);
  }

  assert(arr.size == 8);
  for (size_t i = 0; i < arr.size; ++i) {
    assert(fabs(arr.data[i] - ((double)i * 1.5)) < 1e-12);
  }

  array_free(&arr);
  assert(arr.data == NULL);
}

static void test_vec3_array(void) {
  Vec3Array arr = {0};

  for (int i = 0; i < 5; ++i) {
    Vec3 value = {i * 2.1, i * 2.2, i * 2.3};
    array_push(&arr, value);
  }

  assert(arr.size == 5);
  for (size_t i = 0; i < arr.size; ++i) {
    assert(fabs(arr.data[i].x - (double)i * 2.1) < 1e-12);
    assert(fabs(arr.data[i].y - (double)i * 2.2) < 1e-12);
    assert(fabs(arr.data[i].z - (double)i * 2.3) < 1e-12);
  }

  array_free(&arr);
  assert(arr.data == NULL);
}

static void test_array_cat(void) {
  IntArray left = {0};
  IntArray right = {0};

  for (int i = 0; i < 3; ++i) {
    array_push(&left, i + 1);
  }
  for (int i = 10; i < 13; ++i) {
    array_push(&right, i);
  }

  array_cat(&left, right.data, right.size);
  assert(left.size == 6);
  assert(left.data[0] == 1);
  assert(left.data[1] == 2);
  assert(left.data[2] == 3);
  assert(left.data[3] == 10);
  assert(left.data[4] == 11);
  assert(left.data[5] == 12);

  array_free(&left);
  array_free(&right);
}

static void test_array_pop(void) {
  IntArray arr = {0};

  for (int i = 0; i < 3; ++i) {
    array_push(&arr, i + 1);
  }
  array_pop(&arr);
  assert(arr.size == 2);
  assert(arr.data[0] == 1);
  assert(arr.data[1] == 2);
}

int main(void) {
  test_int_array();
  test_double_array();
  test_vec3_array();
  test_array_cat();
  test_array_pop();

  puts("All DynamicArray tests passed.");
  return 0;
}
