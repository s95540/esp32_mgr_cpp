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

void print_free_heap(const char* label){
  Serial.print(label);
  Serial.print("minimum free heap (bytes): ");
  Serial.println(esp_get_minimum_free_heap_size());
  Serial.print("current free heap (bytes): ");
  Serial.println(esp_get_free_heap_size());
}

void setup() {
  Serial.begin(115200);

  print_free_heap("Heap before alg: ");
 
  int a = 92233;

  bool result = isPerfect(a);

  print_free_heap("Heap after alg: ");
}

void loop() {
}
