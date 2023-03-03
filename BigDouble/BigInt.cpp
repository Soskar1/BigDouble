#include "BigInt.h"

#define ASCII_INT_DIFFERENCE 48

namespace Big {
	BigInt::BigInt() {
		m_IntegralBuffer.str(std::string());
	}

	BigInt::BigInt(const std::string& buffer) {
		m_IntegralBuffer << buffer;
		m_IntegralString = buffer;

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
			newBigInt = bigInt - *this;
			return newBigInt;
		}
		else if (!this->m_IsNegative && bigInt.m_IsNegative) {
			newBigInt = *this - bigInt;
			return newBigInt;
		}
		else if (this->m_IsNegative && bigInt.m_IsNegative) {
			newBigInt.SetIsNegative(true);
		}

		std::string firstBuffer = this->m_IntegralString;
		std::string secondBuffer = bigInt.m_IntegralString;

		std::string newBuffer;

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

		newBigInt.SetBuffer(newBuffer);

		return newBigInt;
	}

	BigInt BigInt::operator+(bool& memory) const {
		BigInt newBigInt(this->ToString());

		if (!memory)
			return newBigInt;

		int i = 0;
		std::string buffer = newBigInt.m_IntegralBuffer.str();
		
		while (memory) {
			if (i == buffer.length()) {
				buffer.insert(0, 1, '1');
				memory = false;
				break;
			}

			int num = buffer[buffer.length() - 1 - i] - ASCII_INT_DIFFERENCE + memory;

			if (memory) {
				memory = false;
			}

			if (num >= 10) {
				memory = true;
				num -= 10;
			}

			buffer[buffer.length() - 1 - i] = num + ASCII_INT_DIFFERENCE;

			++i;
		}

		newBigInt.SetBuffer(buffer);

		return newBigInt;
	}

	BigInt BigInt::operator-(const BigInt& bigInt) const {
		BigInt newBigInt;

		std::string firstBuffer = this->m_IntegralString;
		std::string secondBuffer = bigInt.m_IntegralString;

		std::string newBuffer;

		bool memory = false;

		BigInt tmp1(this->ToString());
		BigInt tmp2(bigInt.ToString());

		if (tmp1.m_IsNegative) {
			tmp1 = -tmp1;
		}

		if (tmp2.m_IsNegative) {
			tmp2 = -tmp2;
		}

		if (tmp1 < tmp2) {
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

		if (newBuffer.length() > 1 && newBuffer[0] == '0') {
			newBuffer.erase(0, 1);
		}

		newBigInt.SetBuffer(newBuffer);
		return newBigInt;
	}

	BigInt BigInt::operator-(bool& memory) const {
		BigInt newBigInt(this->ToString());

		if (!memory)
			return newBigInt;

		int i = 0;
		std::string buffer = newBigInt.m_IntegralBuffer.str();

		while (memory) {
			if (i == buffer.length() - 1) {
				memory = false;
				buffer.erase(0, 1);
				break;
			}

			int num = buffer[buffer.length() - 1 - i] - ASCII_INT_DIFFERENCE - memory;

			if (memory) {
				memory = false;
			}

			if (num < 0) {
				memory = true;
				num += 10;
			}

			buffer[buffer.length() - 1 - i] = num + ASCII_INT_DIFFERENCE;

			++i;
		}

		if (buffer.length() == 0) {
			buffer.insert(0, 1, '0');
		}

		newBigInt.SetBuffer(buffer);

		return newBigInt;
	}

	BigInt BigInt::operator-() const {
		BigInt newBigInt(this->ToString());

		if (this->ToString() != "0") {
			newBigInt.SetIsNegative(!this->m_IsNegative);
		}

		return newBigInt;
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

	void BigInt::SetBuffer(const std::string& newBuffer) {
		m_IntegralBuffer.str(std::string());

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

		this->SetBuffer(this->m_IntegralString);
	}
}