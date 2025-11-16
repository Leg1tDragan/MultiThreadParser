#pragma once

#include <string>
#include "Analytics.h"
#include "ParseSettings.h"
#include <vector>
#include <mutex>

class Parser
{
	uintmax_t minSize = 0;
	uintmax_t maxSize = 2147483648;

	Analytics analytics;
	ParseSettings settings;
	std::mutex mtx;
    std::mutex count_mtx;

public:
	Parser(const ParseSettings& cfg = ParseSettings()) : settings(cfg) {};
	~Parser();
	Parser(const std::string& obj);

	bool readFile(const std::string& file_path);
	std::vector<std::string> loadLines(const std::string& file_path);
	void validatePath(const std::string& file_path) const;
	void parseLine(std::string& line);
	void parseLines(std::vector<std::string>& lines);

	void resetAnalytics();
	void trimAndCollapse(std::string& line);
	void printAnalytics();
};