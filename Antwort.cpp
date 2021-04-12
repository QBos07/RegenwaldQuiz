#include "Antwort.h"

std::string Antwort::getText()
{
	return text;
}

bool Antwort::getIsTrue()
{
	return isTrue;
}

Antwort::Antwort(bool isTrue, std::string text)
	: isTrue(isTrue), text(text)
{

}

Antwort::Antwort(std::string text, bool isTrue)
	: isTrue(isTrue), text(text)
{

}

bool Antwort::Test(bool val2test)
{
	return isTrue == val2test;
}