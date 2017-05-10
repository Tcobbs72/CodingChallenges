#pragma once

#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/ISearchMethod.h"

namespace DocumentParser { namespace Business { namespace Engine {
	class RegExMethod : public ISearchMethod
	{
		public:
			RegExMethod();
			~RegExMethod();
			bool TryGetNextOccurence(int& out);
	};
}}}