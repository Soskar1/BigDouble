#include "BigInt.h"

#define ASCII_INT_DIFFERENCE 48

namespace Big {
	BigInt::BigInt() {
		m_IntegralBuffer.str("0");
		m_IntegralString = "0";
		m_IsNegative = false;
	}

	BigInt::BigInt(const std::string& buffer) {
		m_IntegralBuffer << buffer;
		m_IntegralString = buffer;
		m_IsNegative = false;

		if (m_IntegralString.length() > 0) {
			if (m_IntegralString[0] == '-') {
				m_IsNegative = true;
				m_IntegralString.erase(0, 1);
			}
		}
	}

	BigInt BigInt::operator+(const BigInt& bigInt) const {
		BigInt newBigInt;

		if (this->m_IsNegative && !bigInt.m_IsNegative) {
			newBigInt = bigInt - (-*this);
			return newBigInt;
		}
		else if (!this->m_IsNegative && bigInt.m_IsNegative) {
			newBigInt = *this - (-bigInt);
			return newBigInt;
		}
		else if (this->m_IsNegative && bigInt.m_IsNegative) {
			newBigInt.SetIsNegative(true);
		}

		std::string firstBuffer = this->m_IntegralString;
		std::string secondBuffer = bigInt.m_IntegralString;

		std::string newBuffer;

		if (*this < bigInt) {
			std::string tmp = firstBuffer;
			firstBuffer = secondBuffer;
			secondBuffer = tmp;
		}

		bool memory = false;

		size_t minNumberSize = std::min(firstBuffer.length(), secondBuffer.length());

		for (int index = 0; index < minNumberSize; ++index) {
			int num = (firstBuffer[firstBuffer.length() - index - 1] - ASCII_INT_DIFFERENCE) + (secondBuffer[secondBuffer.length() - index - 1] - ASCII_INT_DIFFERENCE) + memory;

			if (memory) {
				memory = false;
			}

			if (num >= 10) {
				num -= 10;
				memory = true;
			}

			newBuffer += num + ASCII_INT_DIFFERENCE;
		}

		while (memory) {
			if (newBuffer.length() == firstBuffer.length()) {
				newBuffer += '1';
				memory = false;
				break;
			}

			int num = firstBuffer[firstBuffer.length() - newBuffer.length() - 1] - ASCII_INT_DIFFERENCE + memory;

			if (memory) {
				memory = false;
			}

			if (num >= 10) {
				num -= 10;
				memory = true;
			}

			newBuffer += num + ASCII_INT_DIFFERENCE;
		}

		std::reverse(newBuffer.begin(), newBuffer.end());

		if (newBuffer.length() < firstBuffer.length()) {
			newBuffer.insert(0, firstBuffer.substr(0, firstBuffer.length() - newBuffer.length()));
		}
		else if (newBuffer.length() < secondBuffer.length()) {
			newBuffer.insert(0, secondBuffer.substr(0, secondBuffer.length() - newBuffer.length()));
		}

		newBigInt.SetIntegralBuffer(newBuffer);

		return newBigInt;
	}

	BigInt BigInt::operator-(const BigInt& bigInt) const {
		BigInt newBigInt;

		if (!this->m_IsNegative && bigInt.m_IsNegative) {
			newBigInt = *this + (-bigInt);
			return newBigInt;
		}
		else if (this->m_IsNegative && !bigInt.m_IsNegative) {
			newBigInt = -*this + bigInt;

			newBigInt.SetIsNegative(true);
			return newBigInt;
		}
		else if (this->m_IsNegative && bigInt.m_IsNegative) {
			newBigInt = *this + (-bigInt);
			return newBigInt;
		}

		std::string firstBuffer = this->m_IntegralString;
		std::string secondBuffer = bigInt.m_IntegralString;

		std::string newBuffer;

		bool memory = false;

		if (*this < bigInt) {
			std::string tmp = firstBuffer;
			firstBuffer = secondBuffer;
			secondBuffer = tmp;

			newBigInt.SetIsNegative(true);
		}

		size_t minNumberSize = std::min(firstBuffer.length(), secondBuffer.length());

		for (int index = 0; index < minNumberSize; ++index) {
			int num = (firstBuffer[firstBuffer.length() - index - 1] - ASCII_INT_DIFFERENCE) - (secondBuffer[secondBuffer.length() - index - 1] - ASCII_INT_DIFFERENCE) - memory;

			if (memory) {
				memory = false;
			}

			if (num < 0) {
				num += 10;
				memory = true;
			}

			newBuffer += num + ASCII_INT_DIFFERENCE;
		}

		while (memory) {
			int num = firstBuffer[firstBuffer.length() - newBuffer.length() - 1] - ASCII_INT_DIFFERENCE - memory;

			if (memory) {
				memory = false;
			}

			if (num < 0) {
				num += 10;
				memory = true;
			}

			newBuffer += num + ASCII_INT_DIFFERENCE;
		}
		
		std::reverse(newBuffer.begin(), newBuffer.end());

		if (newBuffer.length() < firstBuffer.length()) {
			newBuffer.insert(0, firstBuffer.substr(0, firstBuffer.length() - newBuffer.length()));
		}

		while (newBuffer.length() > 1 && newBuffer[0] == '0') {
			newBuffer.erase(0, 1);
		}

		newBigInt.SetIntegralBuffer(newBuffer);
		return newBigInt;
	}

	BigInt BigInt::operator-() const {
		BigInt newBigInt(this->ToString());

		if (this->ToString() != "0") {
			newBigInt.SetIsNegative(!this->m_IsNegative);
		}

		return newBigInt;
	}

	BigInt& BigInt::operator--() {
		*this = *this - BigInt("1");

		return *this;
	}

	BigInt& BigInt::operator++() {
		*this = *this + BigInt("1");

		return *this;
	}

	bool BigInt::operator<(const BigInt& bigInt) const {
		if (this->m_IsNegative && !bigInt.m_IsNegative)
			return true;
		else if (!this->m_IsNegative && bigInt.m_IsNegative)
			return false;

		std::string firstBuffer = this->ToString();
		std::string secondBuffer = bigInt.ToString();

		if (!this->m_IsNegative && !bigInt.m_IsNegative) {
			if (firstBuffer.length() < secondBuffer.length())
				return true;
			else if (firstBuffer.length() > secondBuffer.length())
				return false;

			for (int index = 0; index < firstBuffer.length(); ++index) {
				if (firstBuffer[index] < secondBuffer[index])
					return true;
				else if (firstBuffer[index] > secondBuffer[index])
					return false;
			}
		}
		else if (this->m_IsNegative && bigInt.m_IsNegative) {
			if (firstBuffer.length() < secondBuffer.length())
				return false;
			else if (firstBuffer.length() > secondBuffer.length())
				return true;

			for (int index = 0; index < firstBuffer.length(); ++index) {
				if (firstBuffer[index] > secondBuffer[index])
					return true;
				else if (firstBuffer[index] < secondBuffer[index])
					return false;
			}
		}

		return false;
	}

	bool BigInt::operator>(const BigInt& bigInt) const {
		if (this->m_IsNegative && !bigInt.m_IsNegative)
			return false;
		else if (!this->m_IsNegative && bigInt.m_IsNegative)
			return true;

		std::string firstBuffer = this->ToString();
		std::string secondBuffer = bigInt.ToString();

		if (this->m_IsNegative && bigInt.m_IsNegative) {
			if (firstBuffer.length() > secondBuffer.length())
				return false;
			else if (firstBuffer.length() < secondBuffer.length())
				return true;

			for (int index = 0; index < firstBuffer.length(); ++index) {
				if (firstBuffer[index] < secondBuffer[index])
					return true;
			}
		}
		else if (!this->m_IsNegative && !bigInt.m_IsNegative) {
			if (firstBuffer.length() > secondBuffer.length())
				return true;
			else if (firstBuffer.length() < secondBuffer.length())
				return false;

			for (int index = 0; index < firstBuffer.length(); ++index) {
				if (firstBuffer[index] > secondBuffer[index])
					return true;
				else if (firstBuffer[index] < secondBuffer[index])
					return false;
			}
		}

		return false;
	}

	bool BigInt::operator<=(const BigInt& bigInt) const {
		return (*this == bigInt || *this < bigInt);
	}

	bool BigInt::operator==(const BigInt& bigInt) const {
		return this->ToString() == bigInt.ToString();
	}

	bool BigInt::operator!=(const BigInt& bigInt) const {
		return this->ToString() != bigInt.ToString();
	}

	bool BigInt::operator>=(const BigInt& bigInt) const {
		return (*this == bigInt || *this > bigInt);
	}

	std::string BigInt::ToString() const {
		return m_IntegralBuffer.str();
	}

	void BigInt::SetIntegralBuffer(const std::string& newBuffer) {
		m_IntegralBuffer.str(std::string());
		m_IntegralString = newBuffer;

		if (this->m_IsNegative) {
			m_IntegralBuffer << "-" << newBuffer;
		}
		else {
			m_IntegralBuffer << newBuffer;
		}
	}

	bool BigInt::GetIsNegative() const {
		return this->m_IsNegative;
	}

	void BigInt::SetIsNegative(const bool& value) {
		this->m_IsNegative = value;

		this->SetIntegralBuffer(this->m_IntegralString);
	}
}