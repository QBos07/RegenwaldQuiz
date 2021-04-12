#pragma once

#include <string>

class Antwort
{
private:
	bool isTrue;
	std::string text;

public:
	Antwort(bool, std::string);
	Antwort(std::string, bool);

	bool getIsTrue();
	std::string getText();

	bool Test(bool);
};

