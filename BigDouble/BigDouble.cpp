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

		std::string thisFractionalPart = this->GetFractionalPart();
		std::string tempFractionalPart = bigDouble.GetFractionalPart();

		size_t minFractionLength;

		if (thisFractionalPart.length() > tempFractionalPart.length()) {
			newBigDouble = BigDouble(this->ToString());
			minFractionLength = tempFractionalPart.length();
		}
		else {
			newBigDouble = BigDouble(bigDouble.ToString());
			minFractionLength = thisFractionalPart.length();
		}

		bool memory = false;

		for (int index = minFractionLength - 1; index >= 0; --index) {
			int num = (thisFractionalPart[index] - ASCII_INT_DIFFERENCE) + (tempFractionalPart[index] - ASCII_INT_DIFFERENCE) + memory;

			if (memory) {
				memory = false;
			}

			if (num >= 10) {
				memory = true;
				num -= 10;
			}

			newBigDouble.m_FractionalPart[index] = num + ASCII_INT_DIFFERENCE;
		}

		if (newBigDouble.m_FractionalPart.length() < tempFractionalPart.length()) {
			newBigDouble.m_FractionalPart += tempFractionalPart.substr(minFractionLength, tempFractionalPart.length());
		}

		newBigDouble.m_IntegralPart = this->m_IntegralPart + bigDouble.m_IntegralPart + memory;

		newBigDouble.UpdateBuffer();
		return newBigDouble;
	}

	std::string BigDouble::GetFractionalPart() const {
		return this->m_FractionalPart;
	}

	void BigDouble::UpdateBuffer() {
		m_Buffer.str(std::string());
		m_Buffer << m_IntegralPart.ToString() << "." << m_FractionalPart;
	}

	std::string BigDouble::ToString() const {
		return m_Buffer.str();
	}
}