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

		size_t minNumLength = std::min(thisBigIntBuffer.length(), tempBigIntBuffer.length());

		for (int index = 0; index < minNumLength; ++index) {
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
			if (minNumLength == thisBigIntBuffer.length()) {
				thisBigIntBuffer.insert(0, 1, '1');
				memory = false;
				break;
			}

			int num = thisBigIntBuffer[thisBigIntBuffer.length() - 1 - minNumLength] - ASCII_INT_DIFFERENCE + memory;

			if (memory) {
				memory = false;
			}

			if (num >= 10) {
				memory = true;
				num -= 10;
			}

			thisBigIntBuffer[thisBigIntBuffer.length() - 1 - minNumLength] = num + ASCII_INT_DIFFERENCE;

			++minNumLength;
		}

		newBigInt.SetBuffer(thisBigIntBuffer);

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

		newBigInt.SetBuffer(buffer);

		return newBigInt;
	}

	BigInt BigInt::operator-(const BigInt& bigInt) const {
		BigInt newBigInt;

		std::string buffer = this->ToString();
		std::string tempBuffer = bigInt.ToString();

		std::string newBuffer;

		bool memory = false;

		size_t minNumLength = std::min(buffer.length(), tempBuffer.length());

		for (int index = 0; index < minNumLength; ++index) {
			int num = (buffer[buffer.length() - index - 1] - ASCII_INT_DIFFERENCE) - (tempBuffer[tempBuffer.length() - index - 1] - ASCII_INT_DIFFERENCE) - memory;

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
			if (minNumLength == buffer.length() - 1) {
				memory = false;
				break;
			}

			int num = buffer[buffer.length() - 1 - minNumLength] - ASCII_INT_DIFFERENCE - memory;

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

		if (minNumLength < buffer.length() - 1) {
			newBuffer.insert(0, buffer.substr(0, buffer.length() - minNumLength));
		}

		newBigInt.SetBuffer(newBuffer);

		return newBigInt;
	}

	std::string BigInt::ToString() const {
		return m_Buffer.str();
	}

	void BigInt::SetBuffer(const std::string& newBuffer) {
		m_Buffer.str(newBuffer);
	}
}