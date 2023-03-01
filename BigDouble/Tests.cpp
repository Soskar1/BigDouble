#include <iostream>
#include <cassert>
#include <string>

#include "BigDouble.h"
#include "BigInt.h"

void BigIntSubtractTest(std::string firstArg, std::string secondArg, std::string result) {
	Big::BigInt first(firstArg);
	Big::BigInt second(secondArg);

	Big::BigInt third = first - second;

	assert(third.ToString() == result);
}

void main() {
	BigIntSubtractTest("8", "5", "3");
	BigIntSubtractTest("999", "187", "812");
	BigIntSubtractTest("10", "2", "8");
	BigIntSubtractTest("1000", "1", "999");
	BigIntSubtractTest("132", "87", "45");
	BigIntSubtractTest("63545641", "600", "63545041");
}