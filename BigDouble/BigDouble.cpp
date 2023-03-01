#include "BigDouble.h"

namespace Big {
	std::string BigDouble::GetFractionalPart() const {
		return m_FractionalPart;
	}

	std::string BigDouble::GetIntegralPart() const {
		return m_IntegralPart;
	}

	void BigDouble::AddFractionParts(const BigDouble& bigDouble) {
		std::string tempFractionalPart = bigDouble.GetFractionalPart();

		size_t minFractionLength = std::min(m_FractionalPart.length(), tempFractionalPart.length());

		for (int index = minFractionLength - 1; index >= 0; --index) {
			int num = (m_FractionalPart[index] - ASCII_INT_DIFFERENCE) + (tempFractionalPart[index] - ASCII_INT_DIFFERENCE) + m_Memory;

			if (m_Memory) {
				m_Memory = false;
			}

			if (num >= 10) {
				m_Memory = true;
				num -= 10;
			}

			m_FractionalPart[index] = num + ASCII_INT_DIFFERENCE;
		}

		if (m_FractionalPart.length() < tempFractionalPart.length()) {
			m_FractionalPart += tempFractionalPart.substr(minFractionLength, tempFractionalPart.length());
		}
	}

	void BigDouble::AddIntegralParts(const BigDouble& bigDouble) {
		std::string tempIntegralPart = bigDouble.GetIntegralPart();

		size_t minIntegralPartLength = std::min(m_IntegralPart.length(), tempIntegralPart.length());

		for (int index = 0; index < minIntegralPartLength; ++index) {
			int num = (m_IntegralPart[m_IntegralPart.length() - 1 - index] - ASCII_INT_DIFFERENCE) + (tempIntegralPart[tempIntegralPart.length() - 1 - index] - ASCII_INT_DIFFERENCE) + m_Memory;

			if (m_Memory) {
				m_Memory = false;
			}

			if (num >= 10) {
				m_Memory = true;
				num -= 10;
			}

			m_IntegralPart[m_IntegralPart.length() - 1 - index] = num + ASCII_INT_DIFFERENCE;
		}

		if (m_IntegralPart.length() < tempIntegralPart.length()) {
			m_IntegralPart.insert(0, tempIntegralPart.substr(0, tempIntegralPart.length() - m_IntegralPart.length()));
		}

		while (m_Memory) {
			if (minIntegralPartLength == m_IntegralPart.length()) {
				m_IntegralPart.insert(0, 1, '1');
				m_Memory = false;
				break;
			}

			int num = m_IntegralPart[m_IntegralPart.length() - 1 - minIntegralPartLength] - ASCII_INT_DIFFERENCE + m_Memory;

			if (m_Memory) {
				m_Memory = false;
			}

			if (num >= 10) {
				m_Memory = true;
				num -= 10;
			}

			m_IntegralPart[m_IntegralPart.length() - 1 - minIntegralPartLength] = num + ASCII_INT_DIFFERENCE;

			++minIntegralPartLength;
		}
	}

	void BigDouble::UpdateBuffer() {
		m_Buffer.str(std::string());
		m_Buffer << m_IntegralPart << "." << m_FractionalPart;
	}

	BigDouble::BigDouble(const std::string& buffer) {
		m_Buffer << buffer;

		size_t fractionPosition = buffer.find('.');

		if (fractionPosition == std::string::npos) {
			m_Buffer << ".0";
			fractionPosition = buffer.length();
		}

		m_IntegralPart = m_Buffer.str().substr(0, fractionPosition);
		m_FractionalPart = m_Buffer.str().substr(fractionPosition + 1, m_Buffer.str().length() - fractionPosition);
	}

	BigDouble BigDouble::operator+(const BigDouble& bigDouble) {
		BigDouble newBigDouble(m_Buffer.str());

		newBigDouble.AddFractionParts(bigDouble);
		newBigDouble.AddIntegralParts(bigDouble);
		newBigDouble.UpdateBuffer();

		return newBigDouble;
	}

	std::string BigDouble::ToString() {
		return m_Buffer.str();
	}
}