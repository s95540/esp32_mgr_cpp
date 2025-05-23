#include <Arduino.h>

int fibbonaci(int n) {
  if (n == 0 || n == 1) {
    return n;
  }
  return fibbonaci(n - 1) + fibbonaci(n - 2);
}

void print_free_heap(const char* label){
  Serial.print(label);
  Serial.print("minimum free heap (bytes): ");
  Serial.println(esp_get_minimum_free_heap_size());
  Serial.print("current free heap (bytes): ");
  Serial.println(esp_get_free_heap_size());
}

void setup() {
  Serial.begin(115200);
  
  print_free_heap("Heap before alg:");
  
  const int fibonacciSeqIndex = 25;
  int* result = (int*)malloc(sizeof(int));
  
  *result = fibbonaci(fibonacciSeqIndex);

  print_free_heap("Heap after alg:");
  
  free(result);
}

void loop() {
}
