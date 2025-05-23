#include <Arduino.h>

void sieve(bool *tab, unsigned int n) {
  for (unsigned int i = 2; i * i <= n; i++) {
    if (!tab[i]) {
      for (unsigned int j = i * i; j <= n; j += i)
        tab[j] = 1;
    }
  }
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
  
  print_free_heap("Before alg: ");
  
  unsigned int n = 10 000;
  bool *tab = new bool[n + 1];
  for (unsigned int i = 0; i <= n; i++) {
    tab[i] = 0;
  }
  
  sieve(tab, n);

  print_free_heap("After alg: ");
  
  delete[] tab;
}

void loop() {
}
