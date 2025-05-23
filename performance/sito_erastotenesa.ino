#include <Arduino.h>

void sieve(bool *tab, unsigned int n) {
  for (unsigned int i = 2; i * i <= n; i++) {
    if (!tab[i]) {
      for (unsigned int j = i * i; j <= n; j += i)
        tab[j] = 1;
    }
  }
}

void setup() {
  Serial.begin(115200);
  
  unsigned int n = 10000;
  bool *tab = new bool[n + 1];
  for (unsigned int i = 0; i <= n; i++) {
    tab[i] = 0;
  }
  
  uint32_t startTimeMicros = micros();
  sieve(tab, n);
  uint32_t endTimeMicros = micros();
  
  uint32_t executionTimeMicros = endTimeMicros - startTimeMicros;
  Serial.print("Execution time: ");
  Serial.println(executionTimeMicros);  
	
  delete[] tab;
}

void loop() {
}
