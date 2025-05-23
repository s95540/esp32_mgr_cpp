#include <Arduino.h>

bool isPerfect(int n)
{
	int s = 1, p = sqrt(n);
	for(int i=2; i<=p; i++)
		if(n%i == 0)

			s+= i + n/i;

	if(n == p*p) s-=p;

	if(n == s) return 1;
	
	return 0;	
}

void setup() {
  Serial.begin(115200);
 
  int a = 92233;

  uint32_t startTimeMicros = micros();
  bool result = isPerfect(a);
  uint32_t endTimeMicros = micros();
  
  uint32_t executionTimeMicros = endTimeMicros - startTimeMicros;
  Serial.print("Execution time (us): ");
  Serial.println(executionTimeMicros);
}

void loop() {
}
