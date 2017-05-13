#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Service/DocumentLoader.h"

#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "DocumentParser/DocumentParser.Infrastructure/Document.h"

using DocumentParser::Business::Service::DocumentLoader;

DocumentLoader::DocumentLoader(std::string directory)
{
	DIR *dir = opendir(directory.c_str());
	if(dir != NULL)
	{
		struct dirent *ent;
		while((ent = readdir(dir)) != NULL)
		{
			this->TryAddDocument(directory, ent);
		}
		closedir(dir);
	}
	else
	{
		std::cout << "Invalid directory" << std::endl;
	}
}

DocumentLoader::~DocumentLoader()
{
}

void DocumentLoader::TryAddDocument(std::string directory, struct dirent* ent)
{
	std::string fileName = std::string(ent->d_name);
	std::string filePath = directory + fileName;
	if(!this->IsDirectory(filePath.c_str()))
	{
		std::ifstream file;
		file.open(filePath.c_str(), std::ios::in);
		if(file.is_open())
		{
			DPI::Document* document = new DPI::Document(fileName);
			std::string line;
			while(getline(file, line))
			{
				document->AddLine(line);
			}
			this->_documents.push_back(document);
		}
	}
}

int DocumentLoader::IsDirectory(const char* path)
{
	struct stat statbuf;
    if (stat(path, &statbuf) != 0){
    	 return 0;
    }
    return S_ISDIR(statbuf.st_mode);
}

void DocumentLoader::CleanupDocuments()
{
	for(auto document : this->_documents)
	{
		delete document;
	}
}
