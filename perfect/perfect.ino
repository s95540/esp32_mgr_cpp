#include <Arduino.h>
//algorytm.edu.pl
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

void print_free_heap(const char* label){
  Serial.print(label);
  Serial.println(esp_get_free_heap_size());
}

void setup() {
  Serial.begin(115200);

  int a = 92233;
  bool result;

  print_free_heap("Before alg: ");

  uint32_t startTimeMicros = micros();

  result = isPerfect(a);

  uint32_t endTimeMicros = micros();

  print_free_heap("After alg: ");
  
  uint32_t executionTimeMicros = endTimeMicros - startTimeMicros;
  Serial.print("Execution time: ");
  Serial.println(executionTimeMicros);
}

void loop() {
}
