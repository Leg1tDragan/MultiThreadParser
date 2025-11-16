#pragma once

struct ParseSettings
{
	bool toLowerCase = true; // to lower case
	bool textLog = true;
	bool removePunctuation = true; // removed punctuations
	bool ignoreDigits = false; // ignored digits
	bool successfullySendToDatabaseMessage = true; // message when successfullySendToDatabase
};