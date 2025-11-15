#pragma once

#include <string>
#include "Analytics.h"
#include "ParseSettings.h"

class Parser
{
	uintmax_t minSize = 0;
	uintmax_t maxSize = 2147483648;

	Analytics analytics;
	ParseSettings settings;

public:
	Parser(const ParseSettings& cfg = ParseSettings()) : settings(cfg) {};
	~Parser();
	Parser(const std::string& obj);

	bool readFile(const std::string& file_path);
	void validatePath(const std::string& file_path) const;
	void parseLine(std::string& line);

	void resetAnalytics();
	void trimAndCollapse(std::string& line);
	void printAnalytics();
};