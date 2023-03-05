#include <iostream>
#include <cassert>
#include <string>
#include <fstream>

#include "BigDouble.h"
#include "BigInt.h"
#include "BigMath.h"

std::ofstream fout("log.txt");

int test = 0;

#pragma region Test Methods
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

void BigDoubleNotEqualTest(const std::string& firstArg, const std::string& secondArg, bool result) {
	++test;

	Big::BigDouble first(firstArg);
	Big::BigDouble second(secondArg);

	bool notEqual = first != second;

	fout << test << "# result: " << notEqual << std::endl;

	assert(notEqual == result);
}

void BigIntUnaryMinusTest(const std::string& firstArg, const std::string& result) {
	++test;

	Big::BigInt first(firstArg);
	Big::BigInt second;
	second = -first;

	fout << test << "# result: " << second.ToString() << std::endl;

	assert(second.ToString() == result);
}

void BigDoubleUnaryMinusTest(const std::string& firstArg, const std::string& result) {
	++test;

	Big::BigDouble first(firstArg);
	Big::BigDouble second;
	second = -first;

	fout << test << "# result: " << second.ToString() << std::endl;

	assert(second.ToString() == result);
}

void BigIntPreDecrementTest(const std::string& firstArg, const std::string& result) {
	++test;

	Big::BigInt first(firstArg);
	
	--first;

	fout << test << "# result: " << first.ToString() << std::endl;

	assert(first.ToString() == result);
}

void BigIntPreIncrementTest(const std::string& firstArg, const std::string& result) {
	++test;

	Big::BigInt first(firstArg);

	++first;

	fout << test << "# result: " << first.ToString() << std::endl;

	assert(first.ToString() == result);
}

void BigDoublePreDecrementTest(const std::string& firstArg, const std::string& result) {
	++test;

	Big::BigDouble first(firstArg);

	--first;

	fout << test << "# result: " << first.ToString() << std::endl;

	assert(first.ToString() == result);
}

void BigDoublePreIncrementTest(const std::string& firstArg, const std::string& result) {
	++test;

	Big::BigDouble first(firstArg);

	++first;

	fout << test << "# result: " << first.ToString() << std::endl;

	assert(first.ToString() == result);
}

void BigIntMultiplicationTest(const std::string& firstArg, const std::string& secondArg, const std::string& result) {
	++test;

	Big::BigInt first(firstArg);
	Big::BigInt second(secondArg);

	Big::BigInt third = first * second;

	fout << test << "# result: " << third.ToString() << std::endl;

	assert(third.ToString() == result);
}

void BigDoubleMultiplicationTest(const std::string& firstArg, const std::string& secondArg, const std::string& result) {
	++test;

	Big::BigDouble first(firstArg);
	Big::BigDouble second(secondArg);

	Big::BigDouble third = first * second;

	fout << test << "# result: " << third.ToString() << std::endl;

	assert(third.ToString() == result);
}

void BigIntAddAssignmentTest(const std::string& firstArg, const std::string& secondArg, const std::string& result) {
	++test;

	Big::BigInt first(firstArg);
	Big::BigInt second(secondArg);

	first += second;

	fout << test << "# result: " << first.ToString() << std::endl;

	assert(first.ToString() == result);
}

void BigDoubleAddAssignmentTest(const std::string& firstArg, const std::string& secondArg, const std::string& result) {
	++test;

	Big::BigDouble first(firstArg);
	Big::BigDouble second(secondArg);

	first += second;

	fout << test << "# result: " << first.ToString() << std::endl;

	assert(first.ToString() == result);
}

void BigIntMultiplierAssignmentTest(const std::string& firstArg, const std::string& secondArg, const std::string& result) {
	++test;

	Big::BigInt first(firstArg);
	Big::BigInt second(secondArg);

	first *= second;

	fout << test << "# result: " << first.ToString() << std::endl;

	assert(first.ToString() == result);
}

void BigIntDivisionTest(const std::string& firstArg, const std::string& secondArg, const std::string& result) {
	++test;

	Big::BigInt first(firstArg);
	Big::BigInt second(secondArg);
	Big::BigInt third;

	third = first / second;

	fout << test << "# result: " << third.ToString() << std::endl;

	assert(third.ToString() == result);
}

void BigDoubleDivisionTest(const std::string& firstArg, const std::string& secondArg, const std::string& result) {
	++test;

	Big::BigDouble first(firstArg);
	Big::BigDouble second(secondArg);
	Big::BigDouble third;

	third = first / second;

	fout << test << "# result: " << third.ToString() << std::endl;

	assert(third.ToString() == result);
}

void BigIntModulusTest(const std::string& firstArg, const std::string& secondArg, const std::string& result) {
	++test;

	Big::BigInt first(firstArg);
	Big::BigInt second(secondArg);
	Big::BigInt third;

	third = first % second;

	fout << test << "# result: " << third.ToString() << std::endl;

	assert(third.ToString() == result);
}
#pragma endregion

int main() {
#pragma region BigInt + Tests
	fout << "BigInt + tests: \n";
	BigIntAdditionTest("2", "5", "7");
	BigIntAdditionTest("4", "1", "5");
	BigIntAdditionTest("7", "3", "10");
	BigIntAdditionTest("10", "8", "18");
	BigIntAdditionTest("19", "8", "27");
	BigIntAdditionTest("5", "35", "40");
	BigIntAdditionTest("1999", "1", "2000");
	BigIntAdditionTest("999", "1", "1000");
	BigIntAdditionTest("658646351", "6842654", "665489005");
	BigIntAdditionTest("5", "-3", "2");
	BigIntAdditionTest("5", "-6", "-1");
	BigIntAdditionTest("1354", "-6418", "-5064");
	BigIntAdditionTest("1354631452", "-641865", "1353989587");
	BigIntAdditionTest("-5", "6", "1");
	BigIntAdditionTest("-107", "2000", "1893");
	BigIntAdditionTest("-107894", "2000", "-105894");
	BigIntAdditionTest("-5", "-4", "-9");
	BigIntAdditionTest("-564", "-136", "-700");
	BigIntAdditionTest("-84265", "-96514", "-180779");
	BigIntAdditionTest("-275", "-25", "-300");
#pragma endregion

#pragma region BigDouble + Tests
	test = 0;
	fout << "---------\n";
	fout << "BigDouble + tests: \n";
	BigDoubleAdditionTest("0.2", "0.5", "0.7");
	BigDoubleAdditionTest("0.4", "0.2", "0.6");
	BigDoubleAdditionTest("0.27", "0.42", "0.69");
	BigDoubleAdditionTest("0.39", "0.02", "0.41");
	BigDoubleAdditionTest("0.48", "0.02", "0.5");
	BigDoubleAdditionTest("0.4897", "0.02", "0.5097");
	BigDoubleAdditionTest("0.0999", "0.0001", "0.1");
	BigDoubleAdditionTest("0.02", "0.39", "0.41");
	BigDoubleAdditionTest("0.02", "0.48", "0.5");
	BigDoubleAdditionTest("0.02", "0.4897", "0.5097");
	BigDoubleAdditionTest("0.0001", "0.0999", "0.1");
	BigDoubleAdditionTest("0.93", "0.12", "1.05");
	BigDoubleAdditionTest("0.99999", "0.00001", "1.0");
	BigDoubleAdditionTest("0.12", "0.93", "1.05");
	BigDoubleAdditionTest("999.99999", "0.00001", "1000.0");
	BigDoubleAdditionTest("0.00001", "999.99999", "1000.0");
	BigDoubleAdditionTest("75.25", "100.25", "175.5");
	BigDoubleAdditionTest("0.5", "-0.3", "0.2");
	BigDoubleAdditionTest("0.7895", "-0.1489", "0.6406");
	BigDoubleAdditionTest("1.7", "-1.5", "0.2");
	BigDoubleAdditionTest("1.7", "-2.5", "-0.8");
	BigDoubleAdditionTest("1486.767", "-1000.295", "486.472");
	BigDoubleAdditionTest("500.767", "-1000.295", "-499.528");
	BigDoubleAdditionTest("-0.5", "0.3", "-0.2");
	BigDoubleAdditionTest("-0.895", "0.385", "-0.51");
	BigDoubleAdditionTest("-1.2", "0.3", "-0.9");
	BigDoubleAdditionTest("-5.2", "3.2", "-2.0");
	BigDoubleAdditionTest("-5.2", "3.8", "-1.4");
	BigDoubleAdditionTest("-1068.98642", "4563.38451", "3494.39809");
	BigDoubleAdditionTest("-0.5", "-0.3", "-0.8");
	BigDoubleAdditionTest("-0.2987", "-0.1121", "-0.4108");
	BigDoubleAdditionTest("-5.01", "-7.99", "-13.0");
	BigDoubleAdditionTest("-565.0154", "-6145.8491546", "-6710.8645546");
	BigDoubleAdditionTest("-6145.8491546", "-565.0154", "-6710.8645546");
#pragma endregion

#pragma region ++BigInt Tests
	test = 0;
	fout << "---------\n";
	fout << "++BigInt tests: \n";
	BigIntPreIncrementTest("1", "2");
	BigIntPreIncrementTest("9", "10");
	BigIntPreIncrementTest("999", "1000");
	BigIntPreIncrementTest("-1", "0");
	BigIntPreIncrementTest("-10", "-9");
	BigIntPreIncrementTest("-1000", "-999");
#pragma endregion

#pragma region ++BigDouble Tests
	test = 0;
	fout << "---------\n";
	fout << "++BigDouble tests: \n";
	BigDoublePreIncrementTest("1.0", "2.0");
	BigDoublePreIncrementTest("9.0", "10.0");
	BigDoublePreIncrementTest("999.999", "1000.999");
	BigDoublePreIncrementTest("-2.2", "-1.2");
	BigDoublePreIncrementTest("-10.0", "-9.0");
	BigDoublePreIncrementTest("-0.2", "0.8");
	BigDoublePreIncrementTest("-1.0", "0.0");
#pragma endregion

#pragma region --BigInt Tests
	test = 0;
	fout << "---------\n";
	fout << "--BigInt tests: \n";
	BigIntPreDecrementTest("2", "1");
	BigIntPreDecrementTest("10", "9");
	BigIntPreDecrementTest("1000", "999");
#pragma endregion

#pragma region --BigDouble Tests
	test = 0;
	fout << "---------\n";
	fout << "--BigDouble tests: \n";
	BigDoublePreDecrementTest("2.0", "1.0");
	BigDoublePreDecrementTest("10.0", "9.0");
	BigDoublePreDecrementTest("1000.0", "999.0");
	BigDoublePreDecrementTest("1000.105", "999.105");
#pragma endregion

#pragma region BigInt - Tests
	test = 0;
	fout << "---------\n";
	fout << "BigInt - tests: \n";
	BigIntSubtractTest("8", "5", "3");
	BigIntSubtractTest("7", "6", "1");
	BigIntSubtractTest("10", "6", "4");
	BigIntSubtractTest("25", "12", "13");
	BigIntSubtractTest("25", "9", "16");
	BigIntSubtractTest("999", "187", "812");
	BigIntSubtractTest("1000", "1", "999");
	BigIntSubtractTest("132", "87", "45");
	BigIntSubtractTest("63545641", "600", "63545041");
	BigIntSubtractTest("684625246842", "9894046894", "674731199948");
	BigIntSubtractTest("5", "5", "0");
	BigIntSubtractTest("5684", "5684", "0");
	BigIntSubtractTest("5", "8", "-3");
	BigIntSubtractTest("72", "82", "-10");
	BigIntSubtractTest("72", "172", "-100");
	BigIntSubtractTest("1", "99999", "-99998");
	BigIntSubtractTest("1", "10", "-9");
	BigIntSubtractTest("1", "10000", "-9999");
	BigIntSubtractTest("68716542684", "89798286458908", "-89729569916224");
	BigIntSubtractTest("5", "-2", "7");
	BigIntSubtractTest("57", "-43", "100");
	BigIntSubtractTest("6845625", "-970909", "7816534");
	BigIntSubtractTest("-5", "3", "-8");
	BigIntSubtractTest("-5", "35", "-40");
	BigIntSubtractTest("-58462", "6872", "-65334");
	BigIntSubtractTest("-6548", "684232456", "-684239004");
	BigIntSubtractTest("-5", "-2", "-3");
	BigIntSubtractTest("-5", "-8", "3");
	BigIntSubtractTest("-5684", "-5684", "0");
	BigIntSubtractTest("-94826", "-897254", "802428");
#pragma endregion

#pragma region BigDouble - Tests
	test = 0;
	fout << "---------\n";
	fout << "BigDouble - tests: \n";
	BigDoubleSubtractTest("0.5", "0.3", "0.2");
	BigDoubleSubtractTest("0.8", "0.4", "0.4");
	BigDoubleSubtractTest("0.36", "0.12", "0.24");
	BigDoubleSubtractTest("0.537", "0.121", "0.416");
	BigDoubleSubtractTest("0.47", "0.18", "0.29");
	BigDoubleSubtractTest("0.501", "0.002", "0.499");
	BigDoubleSubtractTest("0.101", "0.0001", "0.1009");
	BigDoubleSubtractTest("0.973", "0.4", "0.573");
	BigDoubleSubtractTest("1.5", "0.6", "0.9");
	BigDoubleSubtractTest("2.5", "0.6", "1.9");
	BigDoubleSubtractTest("1000.001", "0.002", "999.999");
	BigDoubleSubtractTest("0.3", "0.7", "-0.4");
	BigDoubleSubtractTest("0.01", "0.02", "-0.01");
	BigDoubleSubtractTest("0.001", "0.01", "-0.009");
	BigDoubleSubtractTest("1.1", "1.2", "-0.1");
	BigDoubleSubtractTest("7.7", "8.8", "-1.1");
	BigDoubleSubtractTest("177.7", "188.8", "-11.1");
	BigDoubleSubtractTest("5.7", "5.7", "0.0");
	BigDoubleSubtractTest("1.0", "10000.1", "-9999.1");
	BigDoubleSubtractTest("0.5", "-0.3", "0.8");
	BigDoubleSubtractTest("0.4875", "-0.1225", "0.61");
	BigDoubleSubtractTest("48.25", "-24.48", "72.73");
	BigDoubleSubtractTest("6845.9987", "-1456.7452", "8302.7439");
	BigDoubleSubtractTest("-0.5", "0.2", "-0.7");
	BigDoubleSubtractTest("-0.489", "0.1248", "-0.6138");
	BigDoubleSubtractTest("-7.48", "3.57", "-11.05");
	BigDoubleSubtractTest("-712085.48904865", "386754.57468523", "-1098840.06373388");
	BigDoubleSubtractTest("-0.5", "-0.2", "-0.3");
	BigDoubleSubtractTest("-0.2", "-0.5", "0.3");
	BigDoubleSubtractTest("-0.458", "-0.542", "0.084");
	BigDoubleSubtractTest("-4865.1698", "-1008.1008", "-3857.069");
	BigDoubleSubtractTest("-0.1", "-412.846", "412.746");
#pragma endregion

#pragma region BigInt * Tests
	test = 0;
	fout << "---------\n";
	fout << "BigInt * Tests: \n";
	BigIntMultiplicationTest("4", "2", "8");
	BigIntMultiplicationTest("2", "3", "6");
	BigIntMultiplicationTest("2", "5", "10");
	BigIntMultiplicationTest("3", "6", "18");
	BigIntMultiplicationTest("6", "4", "24");
	BigIntMultiplicationTest("11", "2", "22");
	BigIntMultiplicationTest("13", "3", "39");
	BigIntMultiplicationTest("3", "13", "39");
	BigIntMultiplicationTest("50", "2", "100");
	BigIntMultiplicationTest("12", "12", "144");
	BigIntMultiplicationTest("5647", "684", "3862548");
	BigIntMultiplicationTest("684", "5647", "3862548");
	BigIntMultiplicationTest("-5", "5", "-25");
	BigIntMultiplicationTest("5", "-5", "-25");
	BigIntMultiplicationTest("-5", "-5", "25");
	BigIntMultiplicationTest("651", "325", "211575");
	BigIntMultiplicationTest("65481", "2", "130962");
	BigIntMultiplicationTest("65481", "-25965", "-1700214165");
	BigIntMultiplicationTest("20", "10", "200");
	BigIntMultiplicationTest("5", "0", "0");
	BigIntMultiplicationTest("0", "5", "0");
	BigIntMultiplicationTest("10", "0", "0");
#pragma endregion

#pragma region BigDouble * Tests
	test = 0;
	fout << "---------\n";
	fout << "BigDouble * Tests: \n";
	BigDoubleMultiplicationTest("1.0", "1.0", "1.0");
	BigDoubleMultiplicationTest("2.0", "3.0", "6.0");
	BigDoubleMultiplicationTest("0.2", "1.0", "0.2");
	BigDoubleMultiplicationTest("0.2", "0.8", "0.16");
	BigDoubleMultiplicationTest("5.2", "9.8", "50.96");
	BigDoubleMultiplicationTest("2.0", "0.5", "1.0");
	BigDoubleMultiplicationTest("2.0", "0.005", "0.01");
	BigDoubleMultiplicationTest("0.005", "2.0", "0.01");
	BigDoubleMultiplicationTest("0.01", "0.1", "0.001");
	BigDoubleMultiplicationTest("0.005", "0.00000001", "0.00000000005");
	BigDoubleMultiplicationTest("0.00000001", "0.005", "0.00000000005");
	BigDoubleMultiplicationTest("123.123", "0.005", "0.615615");
	BigDoubleMultiplicationTest("6845455.22445", "962442656546.89864515651", "6588358111492504326.9312580674286695");
	BigDoubleMultiplicationTest("83957209573290750932672903672903804891782184018250185601286.65823579237639207693267290672390673296723906",
		"0.000000000000000000000000000057281572937653276930262869030632626000603602306023060234274923789048329054832580923589032568932686005",
		"4809201023814296104800879450164.8568490188916090045886280654749145987365297497433233505770010262056569038490072728264057954101302967822925614568365803447725038735598712585610222625926936721455220747513553");
	BigDoubleMultiplicationTest("0.0", "0.0", "0.0");
	BigDoubleMultiplicationTest("123.0", "0.0", "0.0");
	BigDoubleMultiplicationTest("1.41421356237309504880168872420969807856967187537694",
		"1.41421356237309504880168872420969807856967187537694",
		"1.9999999999999999999999999999999999999999999999999771656080961606813043742880457326381198582670837636");
	BigDoubleMultiplicationTest("1.00000000000000000000000000000000000000000000000001",
		"1.00000000000000000000000000000000000000000000000001",
		"1.0000000000000000000000000000000000000000000000000200000000000000000000000000000000000000000000000001");
	BigDoubleMultiplicationTest("1.00000000000000000000000000000000000000000000000001",
		"0.00000000000000000000000000000000000000000000000001",
		"0.0000000000000000000000000000000000000000000000000100000000000000000000000000000000000000000000000001");
	BigDoubleMultiplicationTest("-5.0", "5.0", "-25.0");
	BigDoubleMultiplicationTest("5.0", "-5.0", "-25.0");
	BigDoubleMultiplicationTest("-5.0", "-5.0", "25.0");
	BigDoubleMultiplicationTest("-5.0", "5.0", "-25.0");
	BigDoubleMultiplicationTest("2.0", "2.1", "4.2");
	BigDoubleMultiplicationTest("2.0", "2.01", "4.02");
	BigDoubleMultiplicationTest("2.01", "2.0", "4.02");
	BigDoubleMultiplicationTest("20.0", "2.0", "40.0");
	BigDoubleMultiplicationTest("2.0", "20.0", "40.0");
	BigDoubleMultiplicationTest("20.123", "2.0", "40.246");
	BigDoubleMultiplicationTest("20.0", "2.123", "42.46");
	BigDoubleMultiplicationTest("20.123456789", "2.798", "56.305432095622");
	BigDoubleMultiplicationTest("20.1232346", "2.7897988798789", "56.13977734662032428994");
	BigDoubleMultiplicationTest("20.0", "2.123", "42.46");
	BigDoubleMultiplicationTest("1.123456789", "0.798", "0.896518517622");
	BigDoubleMultiplicationTest("1.1232346", "0.7897988798789", "0.88712942892122428994");
	BigDoubleMultiplicationTest("9.9999999999999999999999999999999999999999999999999", 
		"1.0000000000000000000000000000000000000000000000001",
		"10.00000000000000000000000000000000000000000000000089999999999999999999999999999999999999999999999999");
	BigDoubleMultiplicationTest("9.0",
		"0.0000000000000000000000000000000000000000000000001",
		"0.0000000000000000000000000000000000000000000000009");
#pragma endregion
	
#pragma region BigInt / Tests
	test = 0;
	fout << "---------\n";
	fout << "BigInt / Tests: \n";
	BigIntDivisionTest("6", "2", "3");
	BigIntDivisionTest("6", "1", "6");
	BigIntDivisionTest("9999999", "1", "9999999");
	BigIntDivisionTest("9999999", "0", "0");
	BigIntDivisionTest("31", "2", "15");
	BigIntDivisionTest("-31", "2", "-15");
	BigIntDivisionTest("31", "-2", "-15");
	BigIntDivisionTest("0", "100000", "0");
	BigIntDivisionTest("100000", "0", "0");
#pragma endregion

#pragma region BigDouble / Tests
	test = 0;
	fout << "---------\n";
	fout << "BigDouble / Tests: \n";
	BigDoubleDivisionTest("36.0", "6.0", "6.0");
	BigDoubleDivisionTest("0.0001", "10000.0", "0.00000001");
	BigDoubleDivisionTest("6.0", "2.0", "3.0");
	BigDoubleDivisionTest("8.0", "4.0", "2.0");
	BigDoubleDivisionTest("24.0", "6.0", "4.0");
	BigDoubleDivisionTest("3.0", "7.0", "0.4285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714286");
	BigDoubleDivisionTest("7.0", "3.0", "2.3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333");
#pragma endregion

#pragma region BigInt % Tests
	test = 0;
	fout << "---------\n";
	fout << "BigInt / Tests: \n";
	BigIntModulusTest("5", "2", "1");
	BigIntModulusTest("3", "5", "3");
	BigIntModulusTest("187", "36", "7");
	BigIntModulusTest("187", "1", "0");
	BigIntModulusTest("1", "187", "187");
	BigIntModulusTest("0", "187", "0");
	BigIntModulusTest("187", "0", "0");
	BigIntModulusTest("-11", "5", "-11");
	BigIntModulusTest("23", "-11", "1");
	BigIntModulusTest("36", "6", "0");
#pragma endregion

#pragma region BigInt += Tests
	test = 0;
	fout << "---------\n";
	fout << "BigInt += Tests: \n";
	BigIntAddAssignmentTest("1", "1", "2");
	BigIntAddAssignmentTest("125", "3846", "3971");
	BigIntAddAssignmentTest("9991", "19", "10010");
	BigIntAddAssignmentTest("-5", "5", "0");
	BigIntAddAssignmentTest("-275", "25", "-250");
	BigIntAddAssignmentTest("275", "-25", "250");
	BigIntAddAssignmentTest("-275", "-25", "-300");
	BigIntAddAssignmentTest("-25", "-275", "-300");
#pragma endregion

#pragma region BigDouble += Tests
	test = 0;
	fout << "---------\n";
	fout << "BigDouble += Tests: \n";
	BigDoubleAddAssignmentTest("0.1", "0.1", "0.2");
	BigDoubleAddAssignmentTest("125.125", "3846.3846", "3971.5096");
	BigDoubleAddAssignmentTest("100.001", "399.999", "500.0");
	BigDoubleAddAssignmentTest("-100.275", "50.25", "-50.025");
	BigDoubleAddAssignmentTest("-275.275", "-25.025", "-300.3");
	BigDoubleAddAssignmentTest("-25.025", "-275.275", "-300.3");
#pragma endregion

#pragma region BigInt *= Tests
	test = 0;
	fout << "---------\n";
	fout << "BigInt *= Tests: \n";
	BigIntMultiplierAssignmentTest("2", "3", "6");
	BigIntMultiplierAssignmentTest("32", "3", "96");
	BigIntMultiplierAssignmentTest("157", "579", "90903");
	BigIntMultiplierAssignmentTest("-8", "-2", "16");
	BigIntMultiplierAssignmentTest("-750", "2", "-1500");
#pragma endregion

#pragma region BigInt < Tests
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
#pragma endregion

#pragma region BigDouble < Tests
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
#pragma endregion

#pragma region BigInt > Tests
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
#pragma endregion

#pragma region BigDouble > Tests
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
#pragma endregion

#pragma region BigInt == Tests
	test = 0;
	fout << "---------\n";
	fout << "BigInt == Tests: \n";
	BigIntEqualTest("100", "100", true);
	BigIntEqualTest("1", "100", false);
	BigIntEqualTest("14684", "100", false);
	BigIntEqualTest("-105", "-105", true);
	BigIntEqualTest("-105", "105", false);
	BigIntEqualTest("105", "-105", false);
#pragma endregion

#pragma region BigDouble == Tests
	test = 0;
	fout << "---------\n";
	fout << "BigDouble == Tests: \n";
	BigDoubleEqualTest("0.0", "0.0", true);
	BigDoubleEqualTest("1.0", "2.0", false);
	BigDoubleEqualTest("1.0", "1.1", false);
	BigDoubleEqualTest("1.1654", "1.1654", true);
	BigDoubleEqualTest("-864.1586", "864.1586", false);
	BigDoubleEqualTest("0.001", "0.1", false);
#pragma endregion

#pragma region BigInt <= Tests
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
#pragma endregion

#pragma region BigDouble <= Tests
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
#pragma endregion

#pragma region BigInt >= Tests
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
#pragma endregion

#pragma region BigDouble >= Tests
	test = 0;
	fout << "---------\n";
	fout << "BigDouble >= Tests: \n";
	BigDoubleGreaterOrEqualTest("0.0", "0.0", true);
	BigDoubleGreaterOrEqualTest("5.0", "7.0", false);
	BigDoubleGreaterOrEqualTest("51145.0", "51644.0", false);
	BigDoubleGreaterOrEqualTest("0.51145", "0.51644", false);
	BigDoubleGreaterOrEqualTest("-105.501", "-105.888", true);
	BigDoubleGreaterOrEqualTest("-1.501", "0.78545", false);
#pragma endregion

#pragma region BigInt != Tests
	test = 0;
	fout << "---------\n";
	fout << "BigInt != Tests: \n";
	BigIntNotEqualTest("0", "1", true);
	BigIntNotEqualTest("0", "0", false);
	BigIntNotEqualTest("-165", "165", true);
	BigIntNotEqualTest("-100", "-100", false);
#pragma endregion

#pragma region BigDouble != Tests
	test = 0;
	fout << "---------\n";
	fout << "BigDouble != Tests: \n";
	BigDoubleNotEqualTest("0.0", "0.1", true);
	BigDoubleNotEqualTest("0.0", "0.0", false);
	BigDoubleNotEqualTest("3546512.0", "0.3546512", true);
	BigDoubleNotEqualTest("-684.684", "684.684", true);
	BigDoubleNotEqualTest("-104.000001", "-104.000001", false);
#pragma endregion

#pragma region BigInt unary- Tests
	test = 0;
	fout << "---------\n";
	fout << "BigInt unary- Tests: \n";
	BigIntUnaryMinusTest("1", "-1");
	BigIntUnaryMinusTest("1876", "-1876");
	BigIntUnaryMinusTest("-165", "165");
	BigIntUnaryMinusTest("0", "0");
#pragma endregion

#pragma region BigDouble unary- Tests
	test = 0;
	fout << "---------\n";
	fout << "BigDouble unary- Tests: \n";
	BigDoubleUnaryMinusTest("1.0", "-1.0");
	BigDoubleUnaryMinusTest("498.648", "-498.648");
	BigDoubleUnaryMinusTest("-1.84", "1.84");
	BigDoubleUnaryMinusTest("-15898.8426", "15898.8426");
	BigDoubleUnaryMinusTest("0.0", "0.0");
#pragma endregion

	fout.close();
	return 0;
}