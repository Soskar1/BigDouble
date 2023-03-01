#pragma once

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

		std::string GetFractionalPart() const;

		std::string GetIntegralPart() const;

		void AddFractionParts(const BigDouble& bigDouble);

		void AddIntegralParts(const BigDouble& bigDouble);

		void UpdateBuffer();

	public:
		BigDouble(const std::string& buffer);

		BigDouble operator+(const BigDouble& bigDouble);

		std::string ToString();
	};
}