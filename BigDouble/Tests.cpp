#include <iostream>
#include <cassert>
#include <string>
#include <fstream>

#include "BigDouble.h"
#include "BigInt.h"

std::ofstream fout("log.txt");

int test = 0;

void BigIntAdditionTest(const std::string& firstArg, const std::string& secondArg, const std::string& result) {
	++test;

	Big::BigInt first(firstArg);
	Big::BigInt second(secondArg);

	Big::BigInt third = first + second;

	fout << test << "# result: " << third.ToString() << std::endl;

	assert(third.ToString() == result);
}

void BigDoubleAdditionTest(const std::string& firstArg, const std::string& secondArg, const std::string& result) {
	++test;

	Big::BigDouble first(firstArg);
	Big::BigDouble second(secondArg);

	Big::BigDouble third = first + second;

	fout << test << "# result: " << third.ToString() << std::endl;

	assert(third.ToString() == result);
}

void BigIntSubtractTest(const std::string& firstArg, const std::string& secondArg, const std::string& result) {
	++test;
	
	Big::BigInt first(firstArg);
	Big::BigInt second(secondArg);

	Big::BigInt third = first - second;

	fout << test << "# result: " << third.ToString() << std::endl;

	assert(third.ToString() == result);
}

void BigDoubleSubtractTest(const std::string& firstArg, const std::string& secondArg, const std::string& result) {
	++test;

	Big::BigDouble first(firstArg);
	Big::BigDouble second(secondArg);

	Big::BigDouble third = first - second;

	fout << test << "# result: " << third.ToString() << std::endl;

	assert(third.ToString() == result);
}

void BigIntLessTest(const std::string& firstArg, const std::string& secondArg, bool result) {
	++test;

	Big::BigInt first(firstArg);
	Big::BigInt second(secondArg);

	bool less = first < second;

	fout << test << "# result: " << less << std::endl;

	assert(less == result);
}

void BigDoubleLessTest(const std::string& firstArg, const std::string& secondArg, bool result) {
	++test;

	Big::BigDouble first(firstArg);
	Big::BigDouble second(secondArg);

	bool less = first < second;

	fout << test << "# result: " << less << std::endl;

	assert(less == result);
}

void BigIntEqualTest(const std::string& firstArg, const std::string& secondArg, bool result) {
	++test;

	Big::BigInt first(firstArg);
	Big::BigInt second(secondArg);

	bool equal = first == second;

	fout << test << "# result: " << equal << std::endl;

	assert(equal == result);
}

void main() {
	/*fout << "bigint addition tests: \n";
	bigintadditiontest("2", "5", "7");
	bigintadditiontest("7", "3", "10");
	bigintadditiontest("1999", "1", "2000");
	bigintadditiontest("999", "1", "1000");

	test = 0;
	fout << "---------\n";
	fout << "bigdouble addition tests: \n";
	bigdoubleadditiontest("0.2", "0.5", "0.7");
	bigdoubleadditiontest("0.031", "0.071", "0.102");
	bigdoubleadditiontest("0.93", "0.12", "1.05");
	bigdoubleadditiontest("0.99999", "0.00001", "1.0");
	bigdoubleadditiontest("999.99999", "0.00001", "1000.0");

	test = 0;
	fout << "---------\n";
	fout << "bigint subtract tests: \n";
	bigintsubtracttest("8", "5", "3");
	bigintsubtracttest("999", "187", "812");
	bigintsubtracttest("10", "2", "8");
	bigintsubtracttest("1000", "1", "999");
	bigintsubtracttest("132", "87", "45");
	bigintsubtracttest("63545641", "600", "63545041");
	bigintsubtracttest("5", "8", "-3");
	bigintsubtracttest("72", "82", "-10");
	bigintsubtracttest("72", "172", "-100");
	bigintsubtracttest("1", "99999", "-99998");
	bigintsubtracttest("1", "10", "-9");
	bigintsubtracttest("1", "10000", "-9999");
	bigintsubtracttest("5", "5", "0");

	test = 0;
	fout << "---------\n";
	fout << "bigdouble subtract tests: \n";
	bigdoublesubtracttest("0.5", "0.3", "0.2");
	bigdoublesubtracttest("0.537", "0.121", "0.416");
	bigdoublesubtracttest("0.47", "0.18", "0.29");
	bigdoublesubtracttest("0.501", "0.002", "0.499");
	bigdoublesubtracttest("0.101", "0.0001", "0.1009");
	bigdoublesubtracttest("0.973", "0.4", "0.573");
	bigdoublesubtracttest("1.5", "0.6", "0.9");
	bigdoublesubtracttest("1000.001", "0.002", "999.999");
	bigdoublesubtracttest("0.3", "0.7", "-0.4");
	bigdoublesubtracttest("0.01", "0.02", "-0.01");
	bigdoublesubtracttest("0.001", "0.01", "-0.009");
	bigdoublesubtracttest("7.7", "8.8", "-1.1");
	bigdoublesubtracttest("177.7", "188.8", "-11.1");
	bigdoublesubtracttest("5.7", "5.7", "0.0");
	bigdoublesubtracttest("1.0", "10000.1", "-9999.1");*/

	test = 0;
	fout << "---------\n";
	fout << "BigInt < Tests: \n";
	BigIntLessTest("152", "372", true);
	BigIntLessTest("1", "0", false);
	BigIntLessTest("25", "1", false);
	BigIntLessTest("48", "4014158", true);
	BigIntLessTest("4014157", "4014158", true);
	BigIntLessTest("99999", "99999", false);
	BigIntLessTest("-1", "1", true);
	BigIntLessTest("-1", "-2", false);
	BigIntLessTest("-100", "-20", true);
	BigIntLessTest("-100", "-101", false);
	BigIntLessTest("97800", "-97800", false);
	BigIntLessTest("-97800", "-97800", false);
	BigIntLessTest("-1970", "-1969", true);

	test = 0;
	fout << "---------\n";
	fout << "BigDouble < Tests: \n";
	BigDoubleLessTest("2.0", "5.6", true);
	BigDoubleLessTest("7.2", "5.6", false);
	BigDoubleLessTest("777.2", "777.6", true);
	BigDoubleLessTest("1.8468", "1.84681", true);
	BigDoubleLessTest("1.8468", "1.845", false);
	BigDoubleLessTest("1.8468", "1.846", false);
	BigDoubleLessTest("0.001", "0.01", true);
	BigDoubleLessTest("0.47", "0.18", false);
	BigDoubleLessTest("-1.0", "1.0", true);
	BigDoubleLessTest("-1.0", "-2.0", false); //10
	BigDoubleLessTest("-1970.0", "-1969.0", true);
	BigDoubleLessTest("-1.5", "-1.0", true);
	BigDoubleLessTest("-1.5578", "-1.55781", false);
	BigDoubleLessTest("-1.00001", "-1.0001", false);
	BigDoubleLessTest("-1.00001", "-1.000001", true);
	BigDoubleLessTest("0.47", "-0.18", false);
	BigDoubleLessTest("0.0", "0.0", false);

	test = 0;
	fout << "---------\n";
	fout << "BigInt == Tests: \n";
	BigIntEqualTest("100", "100", true);
	BigIntEqualTest("1", "100", false);
	BigIntEqualTest("14684", "100", false);

	fout.close();
}