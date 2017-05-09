#pragma once

#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/ISearchMethod.h"

namespace DocumentParser { namespace Business { namespace Engine {
	class StringMatchMethod : public ISearchMethod
	{
		public:
			StringMatchMethod();
			~StringMatchMethod();
			bool TryGetNextOccurence(int& out);
	};
}}}