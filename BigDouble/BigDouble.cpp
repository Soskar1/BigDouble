#include "BigDouble.h"

#define ASCII_INT_DIFFERENCE 48

namespace Big {
	BigDouble::BigDouble() {
		m_Buffer.str("0.0");
		m_FractionalPart = "0";
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

		std::string firstBuffer = this->GetFractionalPart();
		std::string secondBuffer = bigDouble.GetFractionalPart();

		std::string newBuffer;

		bool memory = false;

		if (*this < bigDouble) {
			std::string tmp = firstBuffer;
			firstBuffer = secondBuffer;
			secondBuffer = tmp;
		}

		size_t minFractionSize = std::min(firstBuffer.length(), secondBuffer.length());
		
		for (int index = minFractionSize - 1; index >= 0; --index) {
			int num = (firstBuffer[index] - ASCII_INT_DIFFERENCE) + (secondBuffer[index] - ASCII_INT_DIFFERENCE) + memory;

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
			newBuffer.insert(newBuffer.length(), firstBuffer.substr(newBuffer.length(), firstBuffer.length() - newBuffer.length()));
		}

		while (newBuffer.length() > 1 && newBuffer[newBuffer.length() - 1] == '0') {
			newBuffer.erase(newBuffer.length() - 1, 1);
		}

		newBigDouble.m_IntegralPart = this->m_IntegralPart + bigDouble.m_IntegralPart;

		if (memory) {
			++newBigDouble;
			memory = false;
		}

		newBigDouble.SetBuffer(newBuffer);
		return newBigDouble;
	}

	BigDouble BigDouble::operator-(const BigDouble& bigDouble) const {
		BigDouble newBigDouble;

		std::string firstBuffer = this->GetFractionalPart();
		std::string secondBuffer = bigDouble.GetFractionalPart();

		std::string newBuffer;

		bool memory = false;

		if (firstBuffer.length() < secondBuffer.length()) {
			firstBuffer.insert(firstBuffer.length(), secondBuffer.length() - firstBuffer.length(), '0');
		}

		size_t minFractionSize = std::min(firstBuffer.length(), secondBuffer.length());

		for (int index = minFractionSize - 1; index >= 0; --index) {
			int num = (firstBuffer[index] - ASCII_INT_DIFFERENCE) - (secondBuffer[index] - ASCII_INT_DIFFERENCE) - memory;

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
			newBuffer.insert(newBuffer.length(), firstBuffer.substr(newBuffer.length(), firstBuffer.length() - newBuffer.length()));
		}

		newBigDouble.m_IntegralPart = this->m_IntegralPart - bigDouble.m_IntegralPart;

		if (memory) {
			--newBigDouble;
			memory = false;
		}

		newBigDouble.SetBuffer(newBuffer);
		return newBigDouble;
	}

	BigDouble& BigDouble::operator--() {
		*this = *this - BigDouble("1.0");
		return *this;
	}

	BigDouble& BigDouble::operator++() {
		*this = *this + BigDouble("1.0");
		return *this;
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
				else if (firstBuffer[index] < secondBuffer[index]) {
					return false;
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
		return this->ToString() == bigDouble.ToString();
	}

	bool BigDouble::operator!=(const BigDouble& bigDouble) const {
		return this->ToString() != bigDouble.ToString();;
	}

	bool BigDouble::operator<=(const BigDouble& bigDouble) const {
		return (*this == bigDouble || *this < bigDouble);
	}

	bool BigDouble::operator>=(const BigDouble& bigDouble) const {
		return (*this == bigDouble || *this > bigDouble);
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