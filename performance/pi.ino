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

void setup() {
  Serial.begin(115200);
  
  long int iterations = 25;

  uint32_t startTimeMicros = micros();
  double result = piGaussLegendre(iterations);
  uint32_t endTimeMicros = micros();
  
  uint32_t executionTimeMicros = endTimeMicros - startTimeMicros;
  Serial.print("Execution time: ");
  Serial.println(executionTimeMicros);
}

void loop() {
}
