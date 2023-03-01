#include <iostream>

#include "BigDouble.h"
#include "BigInt.h"

void main() {
	/*Big::BigDouble first("486.86");
	Big::BigDouble second("13.14");*/

	Big::BigInt first("999");
	Big::BigInt second("1");

	Big::BigInt third = first + second;

	std::cout << third.ToString() << std::endl;
}