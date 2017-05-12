#pragma once

#include <vector>
#include <string>

namespace DocumentParser { namespace Infrastructure {
	class Document
	{
	private:
		std::string _content;
		std::string _fileName;

	public:
		Document(std::string name)
		{
			this->_fileName = name;
		}

		~Document()
		{
		}

		AddLine(std::string line)
		{
			if(this->_content.empty())
			{
				this->_content = line;
			}
			else
			{
				this->_content = this->_content + "\n" + line;
			}
		}

		inline std::string GetName() { return this->_fileName; }
		inline std::string GetContent() { return this->_content; }
	};
}}