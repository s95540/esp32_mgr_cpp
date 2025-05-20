#include <Arduino.h>

int fibbonaci(int n){
  if (n==0 || n==1){
    return n;
  }
  return fibbonaci(n-1) + fibbonaci(n-2);
}


void setup() {
  Serial.begin(115200);
  const int fibonacciSeqIndex = 25;
  
  Serial.print("Minimum free heap size before alg: ");
  Serial.println(esp_get_free_heap_size());
  
  uint32_t startTimeMicros = micros();
  int result = fibbonaci(fibonacciSeqIndex);
  uint32_t endTimeMicros = micros();
  
  Serial.print("Minimum free heap size after alg: ");
  Serial.println(esp_get_free_heap_size());

  uint32_t executionTimeMicros = endTimeMicros - startTimeMicros;
  Serial.print("Execution time: ");
  Serial.println(executionTimeMicros);
}

void loop() {
}
