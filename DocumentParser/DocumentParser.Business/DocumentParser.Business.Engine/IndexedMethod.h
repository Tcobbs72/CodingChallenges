#pragma once

#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/ISearchMethod.h"

namespace DocumentParser { namespace Business { namespace Engine {
	class IndexedMethod : public ISearchMethod
	{
		public:
			IndexedMethod();
			~IndexedMethod();
			bool TryGetNextOccurence(int& out);
	};
}}}