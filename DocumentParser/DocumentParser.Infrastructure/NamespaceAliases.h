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
		namespace Mocks {
			class MockDocumentLoader;
			class MockConfigLoader;
		}
	}
	namespace Infrastructure {
		class Document;
	}
}

namespace DPBE = DocumentParser::Business::Engine;
namespace DPBS = DocumentParser::Business::Service;
namespace DPBM = DocumentParser::Business::Mocks;
namespace DPI = DocumentParser::Infrastructure;