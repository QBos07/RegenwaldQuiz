#include "Frage.h"

Frage::Frage(std::string text, Antwort case1, Antwort case2, Antwort case3)
	: text(text), Antworten{ case1, case2, case3 }
{

}

Frage::Frage(Antwort case1, Antwort case2, Antwort case3, std::string text)
	: text(text), Antworten{ case1, case2, case3 }
{

}

std::string Frage::getText()
{
	return text;
}

std::array<Antwort, 3> Frage::getCasses()
{
	return Antworten;
}

unsigned int Frage::Test(std::array<bool, 3> casses)
{
	return Test(casses[0], casses[1], casses[2]);
}

unsigned int Frage::Test(bool case1, bool case2, bool case3)
{
	unsigned int err = 0;
	err += !Antworten[0].Test(case1);
	err += !Antworten[1].Test(case2);
	err += !Antworten[2].Test(case3);
	return err;
}