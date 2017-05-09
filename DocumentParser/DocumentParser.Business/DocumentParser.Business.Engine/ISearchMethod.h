#pragma once

namespace DocumentParser { namespace Business { namespace Engine { 
	class ISearchMethod 
	{
	public:
		virtual ~ISearchMethod() {};
		virtual bool TryGetNextOccurence(int& out) = 0;
	};
}}}