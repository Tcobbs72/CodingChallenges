#pragma once

#include <stdexcept>

namespace DocumentParser { namespace Infrastructure {
	static DPI::SearchMethod TranslateIntToSearchMethod(int searchMethod)
	{
		switch(searchMethod)
		{
			case 1:
				return DPI::StringMatch;
			case 2:
				return DPI::RegEx;
			case 3:
				return DPI::Indexed;
			default:
				throw std::invalid_argument("Invalid search method received");
		}
	}
}}