#include "PreProcessor.h"

PreProcessor::PreProcessor(std::string fileName) : _fileName(fileName)
{
}


PreProcessor::~PreProcessor()
{
}

void PreProcessor::decommentize(std::vector<char>& in, std::vector<char>& out)
{
	char c;
	for (std::vector<char>::size_type ii = 0; ii < in.size(); ii++)
	{
		c = in[ii];
		if (isCommand(c))
		{
			out.push_back(c);
		}
	}
}

void PreProcessor::parse()
{
	//I don't really understand this code, but it reads the contents of a file into a vector.
	std::ifstream inStream(_fileName.c_str());
	std::istreambuf_iterator<char> start(inStream), end;
	std::vector<char> fileData(start, end);
	inStream.close();
	decommentize(fileData, _commands);
}

std::vector<char>& PreProcessor::getCommands()
{
	return _commands;
}

bool PreProcessor::isCommand(char c)
{
	switch (c)
	{
	case '>':
	case '<':
	case '+':
	case '-':
	case '.':
	case ',':
	case '[':
	case ']':
		return true;
	default:
		return false;
	}
}