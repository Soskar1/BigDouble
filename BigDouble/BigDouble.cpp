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
		BigDouble newBigDouble(this->ToString());

		std::string firstFractionalPart = this->GetFractionalPart();
		std::string secondFractionalPart = bigDouble.GetFractionalPart();

		std::string newBuffer;

		size_t maxFractionLength;

		if (firstFractionalPart.length() < secondFractionalPart.length()) {
			maxFractionLength = secondFractionalPart.length();
			firstFractionalPart.insert(firstFractionalPart.length(), maxFractionLength - firstFractionalPart.length(), '0');
		}
		else if (firstFractionalPart.length() > secondFractionalPart.length()) {
			maxFractionLength = firstFractionalPart.length();
			secondFractionalPart.insert(secondFractionalPart.length(), maxFractionLength - secondFractionalPart.length(), '0');

			if (*this < bigDouble) {
				newBigDouble.m_IntegralPart.SetIsNegative(true);

				std::string tmp = firstFractionalPart;
				firstFractionalPart = secondFractionalPart;
				secondFractionalPart = tmp;
			}
		}
		else {
			maxFractionLength = firstFractionalPart.length();
		}

		bool memory = false;

		for (int index = maxFractionLength - 1; index >= 0; --index) {
			int num = (firstFractionalPart[index] - ASCII_INT_DIFFERENCE) - (secondFractionalPart[index] - ASCII_INT_DIFFERENCE) - memory;

			if (memory) {
				memory = false;
			}

			if (num < 0) {
				if (!newBigDouble.m_IntegralPart.GetIsNegative() && *this < bigDouble) {
					num = -num;
					newBigDouble.m_IntegralPart.SetIsNegative(true);

					newBuffer += num + ASCII_INT_DIFFERENCE;
					break;
				}

				num += 10;
				memory = true;
			}

			newBuffer += num + ASCII_INT_DIFFERENCE;
		}

		std::reverse(newBuffer.begin(), newBuffer.end());

		if (newBuffer.length() < secondFractionalPart.length()) {
			newBuffer.insert(0, secondFractionalPart.substr(0, secondFractionalPart.length() - newBuffer.length()));
;		}

		newBigDouble.m_IntegralPart = newBigDouble.m_IntegralPart - bigDouble.m_IntegralPart - memory;

		newBigDouble.SetBuffer(newBuffer);
		return newBigDouble;
	}

	bool BigDouble::operator<(const BigDouble& bigDouble) const {
		if (this->m_IntegralPart < bigDouble.m_IntegralPart)
			return true;

		if (this->m_IntegralPart == bigDouble.m_IntegralPart) {
			std::string firstBuffer = this->GetFractionalPart();
			std::string secondBuffer = bigDouble.GetFractionalPart();

			size_t minFractionSize = std::min(firstBuffer.length(), secondBuffer.length());

			if (!this->m_IntegralPart.GetIsNegative() && !bigDouble.m_IntegralPart.GetIsNegative()) {
				for (int index = 0; index < minFractionSize; ++index) {
					if (firstBuffer[index] < secondBuffer[index])
						return true;
					else if (firstBuffer[index] > secondBuffer[index])
						return false;
				}

				if (firstBuffer.length() < secondBuffer.length()) {
					return true;
				}
			}
			else if (this->m_IntegralPart.GetIsNegative() && bigDouble.m_IntegralPart.GetIsNegative()) {
				for (int index = 0; index < minFractionSize; ++index) {
					if (firstBuffer[index] > secondBuffer[index])
						return true;
					else if (firstBuffer[index] < secondBuffer[index])
						return false;
				}

				if (firstBuffer.length() > secondBuffer.length()) {
					return true;
				}
			}
		}

		return false;
	}

	bool BigDouble::operator>(const BigDouble& bigDouble) const {
		if (this->m_IntegralPart > bigDouble.m_IntegralPart)
			return true;

		std::string firstBuffer = this->GetFractionalPart();
		std::string secondBuffer = bigDouble.GetFractionalPart();

		size_t minFractionSize = std::min(firstBuffer.length(), secondBuffer.length());

		if (!this->m_IntegralPart.m_IsNegative && !bigDouble.m_IntegralPart.m_IsNegative) {
			for (int index = 0; index < minFractionSize; ++index) {
				if (firstBuffer[index] > secondBuffer[index]) {
					return true;
				}
			}

			if (firstBuffer.length() > minFractionSize)
				return true;
		}
		else if (this->m_IntegralPart.m_IsNegative && bigDouble.m_IntegralPart.m_IsNegative) {
			for (int index = 0; index < minFractionSize; ++index) {
				if (firstBuffer[index] < secondBuffer[index]) {
					return true;
				}
				else if (firstBuffer[index] > secondBuffer[index]) {
					return false;
				}
			}

			if (firstBuffer.length() < minFractionSize)
				return true;
		}

		return false;
	}

	bool BigDouble::operator==(const BigDouble& bigDouble) const {
		if (this->ToString() == bigDouble.ToString())
			return true;

		return false;
	}

	bool BigDouble::operator<=(const BigDouble& bigDouble) const {
		return (*this == bigDouble || *this < bigDouble);
	}

	std::string BigDouble::GetFractionalPart() const {
		return this->m_FractionalPart;
	}

	void BigDouble::SetBuffer(const std::string& buffer) {
		this->m_Buffer.str(std::string());
		this->m_FractionalPart = buffer;

		this->m_Buffer << this->m_IntegralPart.ToString() << "." << this->m_FractionalPart;
	}

	std::string BigDouble::ToString() const {
		return this->m_Buffer.str();
	}
}