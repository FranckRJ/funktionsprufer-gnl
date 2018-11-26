#include "colors.hpp"

bool colors::showColors = true;

std::string colors::bold()
{
	return (showColors ? "\033[1m" : "");
}

std::string colors::red()
{
	return (showColors ? "\033[31m" : "");
}

std::string colors::green()
{
	return (showColors ? "\033[32m" : "");
}

std::string colors::yellow()
{
	return (showColors ? "\033[33m" : "");
}

std::string colors::blue()
{
	return (showColors ? "\033[34m" : "");
}

std::string colors::magenta()
{
	return (showColors ? "\033[35m" : "");
}

std::string colors::cyan()
{
	return (showColors ? "\033[36m" : "");
}

std::string colors::reset()
{
	return (showColors ? "\033[0m" : "");
}
