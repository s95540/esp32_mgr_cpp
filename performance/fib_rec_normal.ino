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
  
  uint32_t startTimeMicros = micros();
  int result = fibbonaci(fibonacciSeqIndex);
  uint32_t endTimeMicros = micros();

  uint32_t executionTimeMicros = endTimeMicros - startTimeMicros;
  Serial.print("Execution time (us): ");
  Serial.println(executionTimeMicros);
}

void loop() {
}
