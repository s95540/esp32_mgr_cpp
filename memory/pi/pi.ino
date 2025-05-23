#include <Arduino.h>

double piGaussLegendre(long int n) {
  long double an = 1.0, bn = 1.0 / sqrt(2), tn = 0.25, pn = 1.0, a_pom;
  while (n--) {
    a_pom = an;
    an = (an + bn) / 2;
    bn = sqrt(a_pom * bn);
    tn = tn - pn * pow(a_pom - an, 2);
    pn *= 2;
  }
  return pow(an + bn, 2) / (4.0 * tn);
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
  
  long int iterations = 25;

  double result = piGaussLegendre(iterations);

  print_free_heap("After alg: ");
}

void loop() {
}
