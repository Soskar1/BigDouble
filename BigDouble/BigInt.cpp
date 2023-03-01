#include "BigInt.h"

#define ASCII_INT_DIFFERENCE 48

namespace Big {
	BigInt::BigInt() {
		m_Buffer.str(std::string());
	}

	BigInt::BigInt(const std::string& buffer) {
		m_Buffer << buffer;
	}

	BigInt BigInt::operator+(const BigInt& bigInt) const {
		BigInt newBigInt;
		bool memory = false;

		std::string thisBigIntBuffer = this->ToString();
		std::string tempBigIntBuffer = bigInt.ToString();

		size_t minIntegralPartLength = std::min(thisBigIntBuffer.length(), tempBigIntBuffer.length());

		for (int index = 0; index < minIntegralPartLength; ++index) {
			int num = (thisBigIntBuffer[thisBigIntBuffer.length() - 1 - index] - ASCII_INT_DIFFERENCE) + (tempBigIntBuffer[tempBigIntBuffer.length() - 1 - index] - ASCII_INT_DIFFERENCE) + memory;

			if (memory) {
				memory = false;
			}

			if (num >= 10) {
				memory = true;
				num -= 10;
			}

			thisBigIntBuffer[thisBigIntBuffer.length() - 1 - index] = num + ASCII_INT_DIFFERENCE;
		}

		if (thisBigIntBuffer.length() < tempBigIntBuffer.length()) {
			thisBigIntBuffer.insert(0, tempBigIntBuffer.substr(0, tempBigIntBuffer.length() - thisBigIntBuffer.length()));
		}

		while (memory) {
			if (minIntegralPartLength == thisBigIntBuffer.length()) {
				thisBigIntBuffer.insert(0, 1, '1');
				memory = false;
				break;
			}

			int num = thisBigIntBuffer[thisBigIntBuffer.length() - 1 - minIntegralPartLength] - ASCII_INT_DIFFERENCE + memory;

			if (memory) {
				memory = false;
			}

			if (num >= 10) {
				memory = true;
				num -= 10;
			}

			thisBigIntBuffer[thisBigIntBuffer.length() - 1 - minIntegralPartLength] = num + ASCII_INT_DIFFERENCE;

			++minIntegralPartLength;
		}

		newBigInt.UpdateBuffer(thisBigIntBuffer);

		return newBigInt;
	}

	BigInt BigInt::operator+(bool& memory) const {
		BigInt newBigInt(this->ToString());

		if (!memory)
			return newBigInt;

		int i = 0;
		std::string buffer = newBigInt.m_Buffer.str();
		
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

		newBigInt.UpdateBuffer(buffer);

		return newBigInt;
	}

	std::string BigInt::ToString() const {
		return m_Buffer.str();
	}

	void BigInt::UpdateBuffer(const std::string& newBuffer) {
		m_Buffer.str(newBuffer);
	}
}