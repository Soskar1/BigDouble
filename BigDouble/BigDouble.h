#include <string>
#include <sstream>

namespace Big {
	class BigDouble {
	private:
		std::stringstream m_Buffer;
		std::string m_FractionalPart;
		std::string m_IntegralPart;

		bool m_Memory = 0;

		const int ASCII_INT_DIFFERENCE = 48;

		std::string GetFractionalPart() const {
			return m_FractionalPart;
		}

		std::string GetIntegralPart() const {
			return m_IntegralPart;
		}

		void AddFractionParts(const BigDouble& bigDouble) {
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

		void AddIntegralParts(const BigDouble& bigDouble) {
			std::string tempIntegralPart = bigDouble.GetIntegralPart();

			size_t minIntegralLength = std::min(m_IntegralPart.length(), tempIntegralPart.length());

			for (int index = 0; index < minIntegralLength; ++index) {
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
				if (minIntegralLength == m_IntegralPart.length()) {
					m_IntegralPart.insert(0, 1, '1');
					m_Memory = false;
					break;
				}

				int num = m_IntegralPart[m_IntegralPart.length() - 1 - minIntegralLength] - ASCII_INT_DIFFERENCE + m_Memory;

				if (m_Memory) {
					m_Memory = false;
				}

				if (num >= 10) {
					m_Memory = true;
					num -= 10;
				}

				m_IntegralPart[m_IntegralPart.length() - 1 - minIntegralLength] = num + ASCII_INT_DIFFERENCE;

				++minIntegralLength;
			}
		}

		void UpdateBuffer() {
			m_Buffer.str(std::string());
			m_Buffer << m_IntegralPart << "." << m_FractionalPart;
		}

	public:
		BigDouble(std::string buffer) {
			m_Buffer << buffer;

			size_t fractionPosition = buffer.find('.');

			if (fractionPosition == std::string::npos) {
				m_Buffer << ".0";
				fractionPosition = buffer.length();
			}

			m_IntegralPart = m_Buffer.str().substr(0, fractionPosition);
			m_FractionalPart = m_Buffer.str().substr(fractionPosition + 1, m_Buffer.str().length() - fractionPosition);
		}

		BigDouble operator+(const BigDouble& bigDouble) {
			BigDouble newBigDouble(m_Buffer.str());

			newBigDouble.AddFractionParts(bigDouble);
			newBigDouble.AddIntegralParts(bigDouble);
			newBigDouble.UpdateBuffer();

			return newBigDouble;
		}

		std::string ToString() {
			return m_Buffer.str();
		}
	};
}