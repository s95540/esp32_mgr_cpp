#include <Arduino.h>

int fibbonaci(int n){
  if (n==0 || n==1){
    return n;
  }
  return fibbonaci(n-1) + fibbonaci(n-2);
}

void print_free_heap(const char* label){
  Serial.print(label);
  Serial.println(esp_get_free_heap_size());
}

void setup() {
  Serial.begin(115200);
  
  print_free_heap("Heap before alg:");
  
  const int fibonacciSeqIndex = 25;
  
  uint32_t startTimeMicros = micros();
  int result = fibbonaci(fibonacciSeqIndex);
  uint32_t endTimeMicros = micros();
  
  print_free_heap("Heap after alg:");

  uint32_t executionTimeMicros = endTimeMicros - startTimeMicros;
  Serial.print("Execution time (us): ");
  Serial.println(executionTimeMicros);
}

void loop() {
}
