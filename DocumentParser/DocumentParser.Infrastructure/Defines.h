#pragma once

#include <string>

namespace DocumentParser { namespace Infrastructure {
	enum SearchMethod {
		StringMatch = 1,
		RegEx = 2,
		Indexed = 3
	};

	typedef struct configurations {
		std::string searchString;
		SearchMethod searchMethod;
	} Configurations;
}}