#include <iostream>

#include "BigDouble.h"
#include "BigInt.h"

void main() {
	//Big::BigInt first("4646546854161");
	//Big::BigInt second("9879823168068548");

	//Big::BigInt third = first + second;

	//std::cout << third.ToString() << std::endl;

	Big::BigDouble first("9870432798603.3843054138547698940");
	Big::BigDouble second("789402345709.089472354089746308");

	Big::BigDouble third = first + second;

	std::cout << third.ToString() << std::endl;
}