#include "MultiThreadParser.h"
#include "Parser/Parser.h"
#include "Parser/ParseSettings.h"
#include <windows.h>

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	try
	{
		ParseSettings cfg;
		cfg.ignoreDigits = false;
		cfg.textLog = true;
		cfg.removePunctuation = true;
		cfg.toLowerCase = true;
		cfg.successfullySendToDatabaseMessage = true;

		Parser parser(cfg);

		parser.readFile("test.txt");

		parser.printAnalytics();
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}