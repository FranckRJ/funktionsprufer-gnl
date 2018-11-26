#ifndef COLORS_HPP
#define COLORS_HPP

#include <string>

class colors
{
public:
	static bool showColors;
	static std::string bold();
	static std::string red();
	static std::string green();
	static std::string yellow();
	static std::string blue();
	static std::string magenta();
	static std::string cyan();
	static std::string reset();
};

#endif
