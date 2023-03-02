#include <iostream>
#include <cassert>
#include <string>

#include "BigDouble.h"
#include "BigInt.h"

int test = 0;

void BigIntAdditionTest(const std::string& firstArg, const std::string& secondArg, const std::string& result) {
	++test;

	Big::BigInt first(firstArg);
	Big::BigInt second(secondArg);

	Big::BigInt third = first + second;

	std::cout << test << "# result: " << third.ToString() << std::endl;

	assert(third.ToString() == result);
}

void BigDoubleAdditionTest(const std::string& firstArg, const std::string& secondArg, const std::string& result) {
	++test;

	Big::BigDouble first(firstArg);
	Big::BigDouble second(secondArg);

	Big::BigDouble third = first + second;

	std::cout << test << "# result: " << third.ToString() << std::endl;

	assert(third.ToString() == result);
}

void BigIntSubtractTest(const std::string& firstArg, const std::string& secondArg, const std::string& result) {
	++test;
	
	Big::BigInt first(firstArg);
	Big::BigInt second(secondArg);

	Big::BigInt third = first - second;

	std::cout << test << "# result: " << third.ToString() << std::endl;

	assert(third.ToString() == result);
}

void BigDoubleSubtractTest(const std::string& firstArg, const std::string& secondArg, const std::string& result) {
	++test;

	Big::BigDouble first(firstArg);
	Big::BigDouble second(secondArg);

	Big::BigDouble third = first - second;

	std::cout << test << "# result: " << third.ToString() << std::endl;

	assert(third.ToString() == result);
}

void BigIntLessTest(const std::string& firstArg, const std::string& secondArg, bool result) {
	++test;

	Big::BigInt first(firstArg);
	Big::BigInt second(secondArg);

	bool less = first < second;

	std::cout << test << "# result: " << less << std::endl;

	assert(less == result);
}

void BigDoubleLessTest(const std::string& firstArg, const std::string& secondArg, bool result) {
	++test;

	Big::BigDouble first(firstArg);
	Big::BigDouble second(secondArg);

	bool less = first < second;

	std::cout << test << "# result: " << less << std::endl;

	assert(less == result);
}

void BigIntEqualTest(const std::string& firstArg, const std::string& secondArg, bool result) {
	++test;

	Big::BigInt first(firstArg);
	Big::BigInt second(secondArg);

	bool equal = first == second;

	std::cout << test << "# result: " << equal << std::endl;

	assert(equal == result);
}

void main() {
	//std::cout << "BigInt Addition Tests: \n";
	//BigIntAdditionTest("2", "5", "7");
	//BigIntAdditionTest("7", "3", "10");
	//BigIntAdditionTest("1999", "1", "2000");
	//BigIntAdditionTest("999", "1", "1000");

	//test = 0;
	//std::cout << "---------\n";
	//std::cout << "BigDouble Addition Tests: \n";
	//BigDoubleAdditionTest("0.2", "0.5", "0.7");
	//BigDoubleAdditionTest("0.031", "0.071", "0.102");
	//BigDoubleAdditionTest("0.93", "0.12", "1.05");
	//BigDoubleAdditionTest("0.99999", "0.00001", "1.0");
	//BigDoubleAdditionTest("999.99999", "0.00001", "1000.0");

	//test = 0;
	//std::cout << "---------\n";
	//std::cout << "BigInt Subtract Tests: \n";
	//BigIntSubtractTest("8", "5", "3");
	//BigIntSubtractTest("999", "187", "812");
	//BigIntSubtractTest("10", "2", "8");
	//BigIntSubtractTest("1000", "1", "999");
	//BigIntSubtractTest("132", "87", "45");
	//BigIntSubtractTest("63545641", "600", "63545041");
	//BigIntSubtractTest("5", "8", "-3");
	//BigIntSubtractTest("72", "82", "-10");
	//BigIntSubtractTest("72", "172", "-100");
	//BigIntSubtractTest("1", "99999", "-99998");
	//BigIntSubtractTest("1", "10", "-9");
	//BigIntSubtractTest("1", "10000", "-9999");
	//BigIntSubtractTest("5", "5", "0");

	//test = 0;
	//std::cout << "---------\n";
	//std::cout << "BigDouble Subtract Tests: \n";
	//BigDoubleSubtractTest("0.5", "0.3", "0.2");
	//BigDoubleSubtractTest("0.537", "0.121", "0.416");
	//BigDoubleSubtractTest("0.47", "0.18", "0.29");
	//BigDoubleSubtractTest("0.501", "0.002", "0.499");
	//BigDoubleSubtractTest("0.101", "0.0001", "0.1009");
	//BigDoubleSubtractTest("0.973", "0.4", "0.573");
	//BigDoubleSubtractTest("1.5", "0.6", "0.9");
	//BigDoubleSubtractTest("1000.001", "0.002", "999.999");
	//BigDoubleSubtractTest("0.3", "0.7", "-0.4");
	//BigDoubleSubtractTest("0.01", "0.02", "-0.01");
	//BigDoubleSubtractTest("0.001", "0.01", "-0.009");

	test = 0;
	std::cout << "---------\n";
	std::cout << "BigInt < Tests: \n";
	BigIntLessTest("152", "372", true);
	BigIntLessTest("1", "0", false);
	BigIntLessTest("25", "1", false);
	BigIntLessTest("48", "4014158", true);
	BigIntLessTest("4014157", "4014158", true);
	BigIntLessTest("99999", "99999", false);

	test = 0;
	std::cout << "---------\n";
	std::cout << "BigDouble < Tests: \n";
	BigDoubleLessTest("2.0", "5.6", true);
	BigDoubleLessTest("7.2", "5.6", false);
	BigDoubleLessTest("777.2", "777.6", true);
	BigDoubleLessTest("1.8468", "1.84681", true);
	BigDoubleLessTest("1.8468", "1.845", false);
	BigDoubleLessTest("1.8468", "1.846", false);

	test = 0;
	std::cout << "---------\n";
	std::cout << "BigInt == Tests: \n";
	BigIntEqualTest("100", "100", true);
	BigIntEqualTest("1", "100", false);
	BigIntEqualTest("14684", "100", false);

}