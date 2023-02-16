#include <iostream>
#include <string>
#include "BigDouble.h"

using namespace std;

int main()
{
	string firstBuffer;
	string secondBuffer;

	cin >> firstBuffer;
	cin >> secondBuffer;

	Big::BigDouble first(firstBuffer);
	Big::BigDouble second(secondBuffer);

	Big::BigDouble third = first + second;

	cout << third.ToString();
}