#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cctype>
#include <random>
#include "Utils.h"
#include <array>
#include <algorithm>


int gen_random(int min, int max)
{
	std::random_device os_seed;
	const u32 seed = os_seed();

	engine generator(seed);
	std::uniform_int_distribution< u32 > distribute(min, max);
	//return distribute(generator);
	for (int repetition = 0; repetition < 10; ++repetition)
	{
		int i = distribute(generator);
		if (repetition >= 9) return i; //i know there's some bias but bleep it... we take whatever rand comes on the 10th iteration...
	}
	return 0;
}
std::vector<std::string> split_string(const std::string& s, const std::string& delimiter)
{
	size_t pos_start = 0, pos_end, delim_len = delimiter.length();
	std::string token;
	std::vector<std::string> res;

	while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos)
	{
		token = s.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		res.push_back(token);
	}

	res.push_back(s.substr(pos_start));
	return res;
}

double split_string_to_double_sum(const std::string& input, const std::string& delimiter)
{
	std::string::size_type sz;
	double stof;
	double sum = 0;
	std::vector<std::string> elements = split_string(input, delimiter);
	if (elements.empty())
	{
		std::cerr << "Invalid input. Enter input string separated by a space like this: 25.12 34.05 89.21" << std::endl;
		return sum;
	}

	for (const auto& x : elements)
	{
		stof = std::stod(x, &sz);
		if (!stof) continue;
		sum += stof;
	}
	return sum;
}
/**
Return min from a list of doubles in a string... weird requirement, I know right?
You know something like 2.54 7.87 23.44

*/
double find_min_from_double_list(const std::vector<std::string> input)
{
	double f;
	double min_value = std::numeric_limits<double>::max();
	std::string::size_type sz;
	for (const auto& x : input)
	{
		f = std::stod(x, &sz);
		if (f < min_value)
		{
			min_value = f;
		}
	}
	return min_value;
}
/**
Return min from a list of doubles in a string... weird requirement, I know right?
You know something like 2.54 7.87 23.44

*/
double get_sum_from_double_list(const std::vector<std::string> input)
{
	double f, sum = 0;
	double min_value = std::numeric_limits<double>::max();
	std::string::size_type sz;
	for (const auto& x : input)
	{
		f = std::stod(x, &sz);
		sum += f;
	}
	return sum;
}
/**
This function converts a string to a double...


*/
double to_double(const std::string& input)
{
	std::string::size_type sz;
	return std::stod(input, &sz);
}


