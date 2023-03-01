#include "BigInt.h"

namespace Big {
	BigInt::BigInt(std::string buffer) : m_Memory(false) {
		m_Buffer << buffer;
	}

	BigInt BigInt::operator+(const BigInt& bigInt) const {
		BigInt newBigInt(m_Buffer.str());

		newBigInt.Addition(bigInt);
		return newBigInt;
	}

	std::string BigInt::ToString() const {
		return m_Buffer.str();
	}

	void BigInt::Addition(const BigInt& bigInt) {
		std::string thisIntegralPart = this->ToString();
		std::string tempIntegralPart = bigInt.ToString();

		size_t minIntegralPartLength = std::min(thisIntegralPart.length(), tempIntegralPart.length());

		for (int index = 0; index < minIntegralPartLength; ++index) {
			int num = (thisIntegralPart[thisIntegralPart.length() - 1 - index] - ASCII_INT_DIFFERENCE) + (tempIntegralPart[tempIntegralPart.length() - 1 - index] - ASCII_INT_DIFFERENCE) + m_Memory;

			if (m_Memory) {
				m_Memory = false;
			}

			if (num >= 10) {
				m_Memory = true;
				num -= 10;
			}

			thisIntegralPart[thisIntegralPart.length() - 1 - index] = num + ASCII_INT_DIFFERENCE;
		}

		if (thisIntegralPart.length() < tempIntegralPart.length()) {
			thisIntegralPart.insert(0, tempIntegralPart.substr(0, tempIntegralPart.length() - thisIntegralPart.length()));
		}

		while (m_Memory) {
			if (minIntegralPartLength == thisIntegralPart.length()) {
				thisIntegralPart.insert(0, 1, '1');
				m_Memory = false;
				break;
			}

			int num = thisIntegralPart[thisIntegralPart.length() - 1 - minIntegralPartLength] - ASCII_INT_DIFFERENCE + m_Memory;

			if (m_Memory) {
				m_Memory = false;
			}

			if (num >= 10) {
				m_Memory = true;
				num -= 10;
			}

			thisIntegralPart[thisIntegralPart.length() - 1 - minIntegralPartLength] = num + ASCII_INT_DIFFERENCE;

			++minIntegralPartLength;
		}

		this->m_Buffer.str(thisIntegralPart);
	}
}