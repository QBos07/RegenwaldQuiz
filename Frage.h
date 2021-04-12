#pragma once

#include <string>
#include <array>
#include "Antwort.h"

class Frage
{
private:
	std::string text;
	std::array<Antwort, 3> Antworten;

public:
	Frage(std::string, Antwort, Antwort, Antwort);
	Frage(Antwort, Antwort, Antwort, std::string);

	std::string getText();
	std::array<Antwort, 3> getCasses();

	unsigned int Test(std::array<bool, 3>);
	unsigned int Test(bool, bool, bool);
};

