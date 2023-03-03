#include "BigInt.h"

#define ASCII_INT_DIFFERENCE 48

namespace Big {
	BigInt::BigInt() {
		m_IntegralBuffer.str(std::string());
	}

	BigInt::BigInt(const std::string& buffer) {
		m_IntegralBuffer << buffer;

		if (buffer.length() > 0) {
			if (buffer[0] == '-') {
				m_IsNegative = true;
			}
		}
	}

	BigInt BigInt::operator+(const BigInt& bigInt) const {
		BigInt newBigInt;
		bool memory = false;

		std::string firstBuffer = this->ToString();
		std::string secondBuffer = bigInt.ToString();

		size_t minNumLength = std::min(firstBuffer.length(), secondBuffer.length());

		for (int index = 0; index < minNumLength; ++index) {
			int num = (firstBuffer[firstBuffer.length() - 1 - index] - ASCII_INT_DIFFERENCE) + (secondBuffer[secondBuffer.length() - 1 - index] - ASCII_INT_DIFFERENCE) + memory;

			if (memory) {
				memory = false;
			}

			if (num >= 10) {
				memory = true;
				num -= 10;
			}

			firstBuffer[firstBuffer.length() - 1 - index] = num + ASCII_INT_DIFFERENCE;
		}

		if (firstBuffer.length() < secondBuffer.length()) {
			firstBuffer.insert(0, secondBuffer.substr(0, secondBuffer.length() - firstBuffer.length()));
		}

		while (memory) {
			if (minNumLength == firstBuffer.length()) {
				firstBuffer.insert(0, 1, '1');
				memory = false;
				break;
			}

			int num = firstBuffer[firstBuffer.length() - 1 - minNumLength] - ASCII_INT_DIFFERENCE + memory;

			if (memory) {
				memory = false;
			}

			if (num >= 10) {
				memory = true;
				num -= 10;
			}

			firstBuffer[firstBuffer.length() - 1 - minNumLength] = num + ASCII_INT_DIFFERENCE;

			++minNumLength;
		}

		newBigInt.SetBuffer(firstBuffer);

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

		std::string firstBuffer = this->ToString();
		std::string secondBuffer = bigInt.ToString();

		std::string newBuffer;

		bool memory = false;

		size_t minNumLength = std::min(firstBuffer.length(), secondBuffer.length());

		if (firstBuffer.length() < secondBuffer.length() || *this < bigInt) {
			newBigInt.m_IsNegative = true;

			std::string tmp = firstBuffer;
			firstBuffer = secondBuffer;
			secondBuffer = tmp;
		}

		for (int index = 0; index < minNumLength; ++index) {
			int num = (firstBuffer[firstBuffer.length() - index - 1] - ASCII_INT_DIFFERENCE) - (secondBuffer[secondBuffer.length() - index - 1] - ASCII_INT_DIFFERENCE) - memory;

			if (memory) {
				memory = false;
			}

			if (num < 0) {
				if ((int)firstBuffer.length() - index - 2 < 0) {
					num = -num;
					newBigInt.m_IsNegative = true;

					newBuffer += num + ASCII_INT_DIFFERENCE;
					break;
				}

				num += 10;
				memory = true;
			}

			newBuffer += num + ASCII_INT_DIFFERENCE;
		}

		while (memory) {
			if (minNumLength == firstBuffer.length() - 1) {
				memory = false;
				firstBuffer.erase(0, 1);
				break;
			}

			int num = firstBuffer[firstBuffer.length() - 1 - minNumLength] - ASCII_INT_DIFFERENCE - memory;

			if (memory) {
				memory = false;
			}

			if (num < 0) {
				memory = true;
				num += 10;
			}

			newBuffer += num + ASCII_INT_DIFFERENCE;

			++minNumLength;
		}

		std::reverse(newBuffer.begin(), newBuffer.end());

		if (minNumLength < firstBuffer.length()) {
			newBuffer.insert(0, firstBuffer.substr(0, firstBuffer.length() - minNumLength));
		}
		else if (minNumLength < secondBuffer.length()) {
			newBuffer.insert(0, secondBuffer.substr(0, secondBuffer.length() - minNumLength));
			newBigInt.m_IsNegative = true;
		}

		if (newBuffer.length() > 1) {
			while (newBuffer[0] == '0') {
				newBuffer.erase(0, 1);
			}
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
			}
		}

		return false;
	}

	bool BigInt::operator==(const BigInt& bigInt) const {
		if (this->ToString() == bigInt.ToString())
			return true;

		return false;
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

		this->SetBuffer(this->m_IntegralBuffer.str());
	}
}