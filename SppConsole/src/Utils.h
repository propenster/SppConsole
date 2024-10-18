#pragma once

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cctype>
#include <random>

#define CONSOLE_WRITELINE(buffer) std::cout << buffer << std::endl;
#define CONSOLE_ERROR(buffer) std::cerr << buffer << std::endl;

#define use_CRT_SECURE_NO_WARNINGS 1

using u32 = uint_least32_t;
using engine = std::mt19937;

int gen_random(int min, int max);
std::vector<std::string> split_string(const std::string& s, const std::string& delimiter);
double split_string_to_double_sum(const std::string& input, const std::string& delimiter);

double find_min_from_double_list(const std::vector<std::string> input);
double get_sum_from_double_list(const std::vector<std::string> input);
double to_double(const std::string& input);

template<typename C, typename T>
bool array_contains(C&& c, T e)
{
	return std::find(std::begin(c), std::end(c), e) != std::end(c);
};


