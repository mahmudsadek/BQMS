#pragma once
#include <iostream>
#include <string>
class Utility
{
public:
	static std::string GetInHourFormat(int min)
	{
		int hour = (min - (min % 60)) / 60;
		std::string h = (hour < 10 ? '0' + std::to_string(hour) : std::to_string(hour));
		int minutes = (min % 60);
		std::string m = (minutes < 10 ? '0' + std::to_string(minutes) : std::to_string(minutes));
		return h + ":" + m;
	}
};

