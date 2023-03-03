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

void BigIntGreaterTest(const std::string& firstArg, const std::string& secondArg, bool result) {
	++test;

	Big::BigInt first(firstArg);
	Big::BigInt second(secondArg);

	bool greater = first > second;

	fout << test << "# result: " << greater << std::endl;

	assert(greater == result);
}

void BigDoubleGreaterTest(const std::string& firstArg, const std::string& secondArg, bool result) {
	++test;

	Big::BigDouble first(firstArg);
	Big::BigDouble second(secondArg);

	bool greater = first > second;

	fout << test << "# result: " << greater << std::endl;

	assert(greater == result);
}

void BigIntLessOrEqualTest(const std::string& firstArg, const std::string& secondArg, bool result) {
	++test;

	Big::BigInt first(firstArg);
	Big::BigInt second(secondArg);

	bool lessOrEqual = first <= second;

	fout << test << "# result: " << lessOrEqual << std::endl;

	assert(lessOrEqual == result);
}

void BigDoubleLessOrEqualTest(const std::string& firstArg, const std::string& secondArg, bool result) {
	++test;

	Big::BigDouble first(firstArg);
	Big::BigDouble second(secondArg);

	bool lessOrEqual = first <= second;

	fout << test << "# result: " << lessOrEqual << std::endl;

	assert(lessOrEqual == result);
}

void BigIntEqualTest(const std::string& firstArg, const std::string& secondArg, bool result) {
	++test;

	Big::BigInt first(firstArg);
	Big::BigInt second(secondArg);

	bool equal = first == second;

	fout << test << "# result: " << equal << std::endl;

	assert(equal == result);
}

void BigDoubleEqualTest(const std::string& firstArg, const std::string& secondArg, bool result) {
	++test;

	Big::BigDouble first(firstArg);
	Big::BigDouble second(secondArg);

	bool equal = first == second;

	fout << test << "# result: " << equal << std::endl;

	assert(equal == result);
}

void BigIntGreaterOrEqualTest(const std::string& firstArg, const std::string& secondArg, bool result) {
	++test;

	Big::BigInt first(firstArg);
	Big::BigInt second(secondArg);

	bool greaterOrEqual = first >= second;

	fout << test << "# result: " << greaterOrEqual << std::endl;

	assert(greaterOrEqual == result);
}

void BigDoubleGreaterOrEqualTest(const std::string& firstArg, const std::string& secondArg, bool result) {
	++test;

	Big::BigDouble first(firstArg);
	Big::BigDouble second(secondArg);

	bool greaterOrEqual = first >= second;

	fout << test << "# result: " << greaterOrEqual << std::endl;

	assert(greaterOrEqual == result);
}

void BigIntNotEqualTest(const std::string& firstArg, const std::string& secondArg, bool result) {
	++test;

	Big::BigInt first(firstArg);
	Big::BigInt second(secondArg);

	bool notEqual = first != second;

	fout << test << "# result: " << notEqual << std::endl;

	assert(notEqual == result);
}

int main() {
	fout << "BigInt addition tests: \n";
	BigIntAdditionTest("2", "5", "7");
	BigIntAdditionTest("7", "3", "10");
	BigIntAdditionTest("1999", "1", "2000");
	BigIntAdditionTest("999", "1", "1000");

	//test = 0;
	//fout << "---------\n";
	//fout << "BigDouble addition tests: \n";
	//BigDoubleAdditionTest("0.2", "0.5", "0.7");
	//BigDoubleAdditionTest("0.031", "0.071", "0.102");
	//BigDoubleAdditionTest("0.93", "0.12", "1.05");
	//BigDoubleAdditionTest("0.99999", "0.00001", "1.0");
	//BigDoubleAdditionTest("999.99999", "0.00001", "1000.0");

	//test = 0;
	//fout << "---------\n";
	//fout << "BigInt subtract tests: \n";
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
	//fout << "---------\n";
	//fout << "BigDouble subtract tests: \n";
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
	//BigDoubleSubtractTest("7.7", "8.8", "-1.1");
	//BigDoubleSubtractTest("177.7", "188.8", "-11.1");
	//BigDoubleSubtractTest("5.7", "5.7", "0.0");
	//BigDoubleSubtractTest("1.0", "10000.1", "-9999.1");

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
	BigIntLessTest("-100", "-101", false); //10
	BigIntLessTest("97800", "-97800", false);
	BigIntLessTest("-97800", "-97800", false);
	BigIntLessTest("-1970", "-1969", true);
	BigIntLessTest("-16784068463455", "-16784168463451", false);
	BigIntLessTest("16784068463455", "16784168463451", true);
	BigIntLessTest("16784068463455", "10784168463451", false);

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
	BigDoubleLessTest("0.16784068463455", "0.10784168463451", false);
	BigDoubleLessTest("0.16784068463455", "0.16784168463451", true); //10
	BigDoubleLessTest("-1.0", "1.0", true);
	BigDoubleLessTest("-1.0", "-2.0", false);
	BigDoubleLessTest("-1970.0", "-1969.0", true);
	BigDoubleLessTest("-1.5", "-1.0", true);
	BigDoubleLessTest("-1.5578", "-1.55781", false);
	BigDoubleLessTest("-1.00001", "-1.0001", false);
	BigDoubleLessTest("-1.00001", "-1.000001", true);
	BigDoubleLessTest("0.47", "-0.18", false);
	BigDoubleLessTest("0.0", "0.0", false);

	test = 0;
	fout << "---------\n";
	fout << "BigInt > Tests: \n";
	BigIntGreaterTest("8", "2", true);
	BigIntGreaterTest("2", "8", false);
	BigIntGreaterTest("12", "8", true);
	BigIntGreaterTest("8", "12", false);
	BigIntGreaterTest("24", "23", true);
	BigIntGreaterTest("23", "23", false);
	BigIntGreaterTest("23", "24", false);
	BigIntGreaterTest("199870", "199869", true);
	BigIntGreaterTest("-1", "1", false);
	BigIntGreaterTest("1", "-1", true);	//10
	BigIntGreaterTest("-4", "-8", true);
	BigIntGreaterTest("-4", "-3", false);
	BigIntGreaterTest("-208", "-3", false);
	BigIntGreaterTest("-200978", "-200979", true);
	BigIntGreaterTest("-1001", "-1001", false);
	BigIntGreaterTest("51145", "51644", false);

	test = 0;
	fout << "---------\n";
	fout << "BigDouble > Tests: \n";
	BigDoubleGreaterTest("5.0", "2.0", true);
	BigDoubleGreaterTest("2.0", "5.0", false);
	BigDoubleGreaterTest("2700.0", "72.0", true);
	BigDoubleGreaterTest("72.0", "2700.0", false);
	BigDoubleGreaterTest("7200.0", "2700.0", true);
	BigDoubleGreaterTest("0.0", "0.0", false);
	BigDoubleGreaterTest("0.1", "0.0", true);
	BigDoubleGreaterTest("0.0", "0.1", false);
	BigDoubleGreaterTest("0.15", "0.1", true);
	BigDoubleGreaterTest("0.15", "0.27", false); //10
	BigDoubleGreaterTest("0.15", "0.156", false);
	BigDoubleGreaterTest("0.001", "0.00001", true);
	BigDoubleGreaterTest("0.7854", "0.7854", false);
	BigDoubleGreaterTest("-1.0", "1.0", false);
	BigDoubleGreaterTest("1.0", "-1.0", true);
	BigDoubleGreaterTest("-1.0", "-1.0", false);
	BigDoubleGreaterTest("-5.0", "-3.0", false);
	BigDoubleGreaterTest("-3.0", "-5.0", true);
	BigDoubleGreaterTest("-34186.0", "-34187.0", true);
	BigDoubleGreaterTest("-0.1", "-0.2", true); //20
	BigDoubleGreaterTest("-0.102", "-0.103", true);
	BigDoubleGreaterTest("-0.802", "-0.103", false);
	BigDoubleGreaterTest("-0.001", "-0.1", true);
	BigDoubleGreaterTest("-0.1", "-0.001", false);
	BigDoubleGreaterTest("-1.157412", "-10.4165841", true);

	test = 0;
	fout << "---------\n";
	fout << "BigInt == Tests: \n";
	BigIntEqualTest("100", "100", true);
	BigIntEqualTest("1", "100", false);
	BigIntEqualTest("14684", "100", false);
	BigIntEqualTest("-105", "-105", true);
	BigIntEqualTest("-105", "105", false);
	BigIntEqualTest("105", "-105", false);

	test = 0;
	fout << "---------\n";
	fout << "BigDouble == Tests: \n";
	BigDoubleEqualTest("0.0", "0.0", true);
	BigDoubleEqualTest("1.0", "2.0", false);
	BigDoubleEqualTest("1.0", "1.1", false);
	BigDoubleEqualTest("1.1654", "1.1654", true);
	BigDoubleEqualTest("-864.1586", "864.1586", false);
	BigDoubleEqualTest("0.001", "0.1", false);

	test = 0;
	fout << "---------\n";
	fout << "BigInt <= Tests: \n";
	BigIntLessOrEqualTest("0", "0", true);
	BigIntLessOrEqualTest("0", "1", true);
	BigIntLessOrEqualTest("1", "0", false);
	BigIntLessOrEqualTest("105", "105", true);
	BigIntLessOrEqualTest("50", "105", true);
	BigIntLessOrEqualTest("1068", "1067", false);
	BigIntLessOrEqualTest("-1", "0", true);
	BigIntLessOrEqualTest("0", "-1", false);
	BigIntLessOrEqualTest("-1", "-1", true);
	BigIntLessOrEqualTest("-16784168463455", "-16784168463451", true);
	BigIntLessOrEqualTest("-16784068463455", "-16784168463451", false);

	test = 0;
	fout << "---------\n";
	fout << "BigDouble <= Tests: \n";
	BigDoubleLessOrEqualTest("0.0", "0.0", true);
	BigDoubleLessOrEqualTest("1.0", "0.0", false);
	BigDoubleLessOrEqualTest("6854.0", "9999.0", true);
	BigDoubleLessOrEqualTest("0.801", "0.8", false);
	BigDoubleLessOrEqualTest("0.801", "1.8", true);
	BigDoubleLessOrEqualTest("-16784168463455.16784168463451", "-16784168463451.16784168463451", true);
	BigDoubleLessOrEqualTest("-15641.1354", "-15641.136", false);

	test = 0;
	fout << "---------\n";
	fout << "BigInt >= Tests: \n";
	BigIntGreaterOrEqualTest("0", "0", true);
	BigIntGreaterOrEqualTest("0", "2", false);
	BigIntGreaterOrEqualTest("564651", "560051", true);
	BigIntGreaterOrEqualTest("-164", "164", false);
	BigIntGreaterOrEqualTest("-164", "-181", true);
	BigIntGreaterOrEqualTest("-16004", "-16001", false);
	BigIntGreaterOrEqualTest("-16004", "-16011", true);

	test = 0;
	fout << "---------\n";
	fout << "BigDouble >= Tests: \n";
	BigDoubleGreaterOrEqualTest("0.0", "0.0", true);
	BigDoubleGreaterOrEqualTest("5.0", "7.0", false);
	BigDoubleGreaterOrEqualTest("51145.0", "51644.0", false);
	BigDoubleGreaterOrEqualTest("0.51145", "0.51644", false);
	BigDoubleGreaterOrEqualTest("-105.501", "-105.888", true);
	BigDoubleGreaterOrEqualTest("-1.501", "0.78545", false);

	test = 0;
	fout << "---------\n";
	fout << "BigInt != Tests: \n";
	BigIntNotEqualTest("0", "1", true);
	BigIntNotEqualTest("0", "0", false);
	BigIntNotEqualTest("-165", "165", true);
	BigIntNotEqualTest("-100", "-100", false);

	fout.close();
	return 0;
}