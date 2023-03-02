#include "BigDouble.h"

#define ASCII_INT_DIFFERENCE 48

namespace Big {
	BigDouble::BigDouble() {
		m_Buffer.str(std::string());
	}

	BigDouble::BigDouble(const std::string& buffer) {
		m_Buffer << buffer;

		size_t fractionPosition = buffer.find('.');

		if (fractionPosition == std::string::npos) {
			m_Buffer << ".0";
			fractionPosition = buffer.length();
		}

		m_IntegralPart = BigInt(buffer.substr(0, fractionPosition));
		m_FractionalPart = buffer.substr(fractionPosition + 1, m_Buffer.str().length() - fractionPosition);
	}

	BigDouble BigDouble::operator+(const BigDouble& bigDouble) const {
		BigDouble newBigDouble;

		std::string firstFractionalPart = this->GetFractionalPart();
		std::string secondFractionalPart = bigDouble.GetFractionalPart();

		std::string newBuffer;

		size_t minFractionLength;

		if (firstFractionalPart.length() > secondFractionalPart.length()) {
			newBigDouble = BigDouble(this->ToString());
			minFractionLength = secondFractionalPart.length();
		}
		else {
			newBigDouble = BigDouble(bigDouble.ToString());
			minFractionLength = firstFractionalPart.length();
		}

		bool memory = false;

		for (int index = minFractionLength - 1; index >= 0; --index) {
			int num = (firstFractionalPart[index] - ASCII_INT_DIFFERENCE) + (secondFractionalPart[index] - ASCII_INT_DIFFERENCE) + memory;

			if (memory) {
				memory = false;
			}

			if (num >= 10) {
				memory = true;
				num -= 10;
			}

			if (num == 0 && newBuffer.length() == 0)
				continue;

			newBuffer += num + ASCII_INT_DIFFERENCE;
		}

		if (newBuffer.length() == 0) {
			newBuffer.insert(0, 1, '0');
		}
		else {
			std::reverse(newBuffer.begin(), newBuffer.end());
		}

		if (newBuffer.length() < secondFractionalPart.length()) {
			newBuffer.insert(0, secondFractionalPart.substr(minFractionLength, secondFractionalPart.length()));
		}

		newBigDouble.m_IntegralPart = this->m_IntegralPart + bigDouble.m_IntegralPart + memory;

		newBigDouble.SetBuffer(newBuffer);
		return newBigDouble;
	}

	BigDouble BigDouble::operator-(const BigDouble& bigDouble) const {
		BigDouble newBigDouble;

		std::string firstFractionalPart = this->GetFractionalPart();
		std::string secondFractionalPart = bigDouble.GetFractionalPart();

		std::string newBuffer;

		size_t maxFractionLength;

		if (firstFractionalPart.length() < secondFractionalPart.length()) {
			maxFractionLength = secondFractionalPart.length();
			firstFractionalPart.insert(firstFractionalPart.length(), maxFractionLength - firstFractionalPart.length(), '0');
		}
		else {
			maxFractionLength = firstFractionalPart.length();
			secondFractionalPart.insert(secondFractionalPart.length(), maxFractionLength - secondFractionalPart.length(), '0');
		}

		bool memory = false;

		for (int index = maxFractionLength - 1; index >= 0; --index) {
			int num = (firstFractionalPart[index] - ASCII_INT_DIFFERENCE) - (secondFractionalPart[index] - ASCII_INT_DIFFERENCE) - memory;

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

		newBigDouble.m_IntegralPart = this->m_IntegralPart - bigDouble.m_IntegralPart - memory;

		newBigDouble.SetBuffer(newBuffer);

		return newBigDouble;
	}

	std::string BigDouble::GetFractionalPart() const {
		return m_FractionalPart;
	}

	void BigDouble::SetBuffer(const std::string& buffer) {
		m_Buffer.str(std::string());
		this->m_FractionalPart = buffer;
		m_Buffer << m_IntegralPart.ToString() << "." << this->m_FractionalPart;
	}

	std::string BigDouble::ToString() const {
		return m_Buffer.str();
	}
}