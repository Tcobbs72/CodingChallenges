#pragma once

namespace DocumentParser {
	namespace Business {
		namespace Engine {
			class ISearchMethod;
			class SearchMethodFactory;
			class DocumentParserController;
			class IndexedMethod;
			class RegExMethod;
			class StringMatchMethod;
		}
		namespace Service {
			class Document;
			class DocumentLoader;
			class ConfigLoader;
		}
	}
	namespace Infrastructure {
		class Document;
	}
}

namespace DPBE = DocumentParser::Business::Engine;
namespace DPBS = DocumentParser::Business::Service;
namespace DPI = DocumentParser::Infrastructure;