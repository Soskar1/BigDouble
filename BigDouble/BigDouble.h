#include <string>

namespace Big {
	class BigDouble {
	private:
		std::string m_Buffer;
		std::string m_FractionalPart;
		std::string m_IntegralPart;

		bool m_Memory = 0;

		const int ASCII_INT_DIFFERENCE = 48;

		void AddFractionParts(const BigDouble& bigDouble) {
			size_t minFractionLength = std::min(m_FractionalPart.length(), bigDouble.m_FractionalPart.length());

			for (int index = minFractionLength - 1; index >= 0; --index) {
				int num = (m_FractionalPart[index] - ASCII_INT_DIFFERENCE) + (bigDouble.m_FractionalPart[index] - ASCII_INT_DIFFERENCE) + m_Memory;
				
				if (m_Memory) {
					m_Memory = false;
				}

				if (num >= 10) {
					m_Memory = true;
					num -= 10;
				}

				m_FractionalPart[index] = num + ASCII_INT_DIFFERENCE;
			}

			if (m_FractionalPart.length() < bigDouble.m_FractionalPart.length()) {
				m_FractionalPart += bigDouble.m_FractionalPart.substr(minFractionLength, bigDouble.m_FractionalPart.length());
			}
		}

		void AddIntegralParts(const BigDouble& bigDouble) {
			size_t minIntegralLength = std::min(m_IntegralPart.length(), bigDouble.m_IntegralPart.length());

			for (int index = 0; index < minIntegralLength; ++index) {
				int num = (m_IntegralPart[m_IntegralPart.length() - 1 - index] - ASCII_INT_DIFFERENCE) + (bigDouble.m_IntegralPart[bigDouble.m_IntegralPart.length() - 1 - index] - ASCII_INT_DIFFERENCE) + m_Memory;

				if (m_Memory) {
					m_Memory = false;
				}

				if (num >= 10) {
					m_Memory = true;
					num -= 10;
				}

				m_IntegralPart[m_IntegralPart.length() - 1 - index] = num + ASCII_INT_DIFFERENCE;
			}

			if (m_IntegralPart.length() < bigDouble.m_IntegralPart.length()) {
				m_IntegralPart.insert(0, bigDouble.m_IntegralPart.substr(0, bigDouble.m_IntegralPart.length() - m_IntegralPart.length()));
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
			m_Buffer = m_IntegralPart + "." + m_FractionalPart;
		}

	public:
		BigDouble(std::string buffer) {
			m_Buffer = buffer;

			size_t fractionPosition = buffer.find('.');

			if (fractionPosition == std::string::npos) {
				m_Buffer.insert(m_Buffer.length(), ".0");
				fractionPosition = m_Buffer.length() - 2;
			}

			m_IntegralPart = m_Buffer.substr(0, fractionPosition);
			m_FractionalPart = m_Buffer.substr(fractionPosition + 1, m_Buffer.length() - fractionPosition);
		}

		BigDouble operator+(const BigDouble& bigDouble) {
			BigDouble newBigDouble(m_Buffer);

			newBigDouble.AddFractionParts(bigDouble);
			newBigDouble.AddIntegralParts(bigDouble);
			newBigDouble.UpdateBuffer();

			return newBigDouble;
		}

		std::string ToString() {
			return m_Buffer;
		}
	};
}