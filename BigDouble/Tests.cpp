#include <iostream>
#include <cassert>
#include <string>

#include "BigDouble.h"
#include "BigInt.h"

int test = 0;

void BigIntSubtractTest(const std::string& firstArg, const std::string& secondArg, const std::string& result) {
	++test;
	
	Big::BigInt first(firstArg);
	Big::BigInt second(secondArg);

	Big::BigInt third = first - second;

	std::cout << test << "# result: " << third.ToString() << std::endl;

	assert(third.ToString() == result);
}

void main() {
	BigIntSubtractTest("8", "5", "3");
	BigIntSubtractTest("999", "187", "812");
	BigIntSubtractTest("10", "2", "8");
	BigIntSubtractTest("1000", "1", "999");
	BigIntSubtractTest("132", "87", "45");
	BigIntSubtractTest("63545641", "600", "63545041");
	BigIntSubtractTest("5", "8", "-3");
	BigIntSubtractTest("72", "82", "-10");
	BigIntSubtractTest("72", "172", "-100");
	BigIntSubtractTest("1", "99999", "-99998");
	BigIntSubtractTest("1", "10", "-9");
	BigIntSubtractTest("1", "10000", "-9999");
}