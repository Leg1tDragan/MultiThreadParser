#include "Parser.h"
#include <fstream>
#include <filesystem>
#include <cctype>
#include <string>
#include <iostream>

using namespace std;

Parser::~Parser()
{
}

Parser::Parser(const std::string& obj)
{
}

void Parser::resetAnalytics()
{
	analytics = Analytics();
}

bool Parser::readFile(const string& file_path)
{
	validatePath(file_path);
	ifstream file(file_path);
	if (file)
	{
		string line;
		while (getline(file, line))
		{
			parseLine(line);
		}
	}
	else throw runtime_error("[Error] readFile method something wrong");
	file.close();
	return true;
}

void Parser::trimAndCollapse(string& line)
{
	string newLine;
	size_t i = 0;
	bool wasSpace = false;

	while (i < line.size() && isspace((unsigned char)line[i])) i++;

	while (!line.empty() && isspace((unsigned char)line.back()))
		line.pop_back();
	
	for (; i < line.size(); i++)
	{
		if (!isspace((unsigned char)line[i]))
		{
			newLine += line[i];
			wasSpace = false;
		}
		else if (!wasSpace)
		{
			newLine += ' ';
			wasSpace = true;
		}
	}

	line = newLine;
}

void Parser::printAnalytics()
{
	cout << "Total Words: " << analytics.totalWords << endl;
	cout << "Total Chars: " << analytics.totalChars << endl;
	cout << "Total Letters: " << analytics.totalLetters << endl;
	cout << "Total Digits: " << analytics.totalDigits << endl;
}

void Parser::validatePath(const std::string& file_path) const
{
	if (file_path.empty()) { throw runtime_error("[Error] Path is empty"); }
	if (!filesystem::exists(file_path)) { throw runtime_error("[Error] File is not exists"); }
	if (!filesystem::is_regular_file(file_path)) { throw runtime_error("[Error] It's not a file"); }
	if (filesystem::is_symlink(file_path)) { throw runtime_error("[Error] Path is a symlink"); }
	ifstream test(file_path);
	if (!test.is_open()) { throw runtime_error("[Error] Cannot open file (permissions or lock)"); }
	uintmax_t size = filesystem::file_size(file_path);
	if (size == 0) { throw runtime_error("[Error] File is empty"); }
	if (size > maxSize) { throw runtime_error("[Error] File too large"); }
	auto ext = filesystem::path(file_path).extension();
	if (ext != ".txt" && ext != ".log") { throw runtime_error("[Error] Extension error"); }
}

void Parser::parseLine(string& line)
{
	cout << "Before: [" << line << "]\n";

	// ---

	trimAndCollapse(line);

	// ---

	if (settings.removePunctuation == true)
	{
		string newLine;
		for (size_t i = 0; i < line.size(); i++)
		{
			if (!ispunct(static_cast<unsigned char>(line[i])) || line[i] == '-')
			{
				newLine += line[i];
			}
		}
		line = newLine;
	}

	// ---

	if (settings.ignoreDigits)
	{
		string newLine;
		for (size_t i = 0; i < line.size(); i++)
		{
			if (!isdigit(static_cast<unsigned char>(line[i])))
			{
				newLine += line[i];
			}
		}
		line = newLine;
	}
	else
	{
		for (size_t i = 0; i < line.size(); i++)
		{
			if (isdigit(static_cast<unsigned char>(line[i]))) { analytics.totalDigits += 1; }
		}
	}

	// ---

	trimAndCollapse(line);

	// ---

	if (settings.toLowerCase == true)
	{
		for (size_t i = 0; i < line.size(); i++)
		{
			line[i] = tolower(static_cast<unsigned char>(line[i]));
		}
	}

	// ---

	bool inWord = false;

	for (size_t i = 0; i < line.size(); i++)
	{
		bool isAlnum =
			isalpha((unsigned char)line[i]) ||
			isdigit((unsigned char)line[i]);

		if (isAlnum)
		{
			if (!inWord)
			{
				analytics.totalWords++;
				inWord = true;
			}
		}
		else
		{
			inWord = false;
		}
	}

	// ---

	for (size_t i = 0; i < line.size(); i++)
	{
		if (isalpha(static_cast<unsigned char>(line[i]))) { analytics.totalLetters += 1; }
	}

	// ---

	analytics.totalChars += line.size();
	cout << "After: [" << line << "]\n\n";
}
