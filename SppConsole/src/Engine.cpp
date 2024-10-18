#include "Engine.h"
#include <time.h>
#include <algorithm>
#include <string>
#include <iterator>
#include <iostream>
#include "Utils.h"
#include <sstream>
#include <iomanip>

Engine::Engine(int version, std::vector<int>* multiVersion)
{
	//_gOssString.clear();
	//std::cout << "Engine Version " << version << " requested" << std::endl;
	//CONSOLE_WRITELINE(_gOssString.str());
	//_gOssString.clear();
	m_version = version;
	if (multiVersion != nullptr)
	{
		m_seeds = GetCombinedSelectedVersionsSeed(multiVersion);
	}
	else
	{
		m_seeds = GetSeeds(version);
	}
	//std::cout << m_seeds.size() << " SCORES seeded successfully " << std::endl;
	//CONSOLE_WRITELINE(_gOssString.str());

}

std::vector<std::string> Engine::GetSeeds(int version)
{
	switch (version)
	{
	case 1:
		return GetSeedV1();
	case 2:
		return GetSeedV2();
	case 3:
		return GetSeedV3();
	case 0:
		return GetCombinedSeed();

	default:
		std::cerr << "Error: Invalid version detected" << std::endl;
		break;
	}
}
std::vector<std::string> Engine::GetCombinedSeed()
{
	std::vector<std::string> ls = GetSeedV1();
	std::vector<std::string> v2 = GetSeedV2();
	ls.insert(ls.end(), v2.begin(), v2.end());

	std::vector<std::string> v3 = GetSeedV3();
	ls.insert(ls.end(), v3.begin(), v3.end());
	return ls;
}
std::vector<std::string> Engine::GetCombinedSelectedVersionsSeed(const std::vector<int>* selectedVersions)
{
	std::vector<std::string> result;
	std::vector<std::string> v;

	for (const auto& i : *selectedVersions)
	{
		switch (i)
		{
		case 1: 
			v = GetSeedV1(); //of course ther's a better way to do this..
			break;
		case 2:
			v = GetSeedV2();
			break;
		case 3:
			v = GetSeedV3();
			break;
		default:
			break;
		}
		result.insert(result.end(), v.begin(), v.end());
	}

	return result;
}
std::vector<std::string> Engine::GetSeedV1()
{
	return std::vector<std::string>{
		"3.10 1.99 3.50 2", "3.33 2.15 3.10 2", "3.30 2.10 3.00 2", "3.10 1.89 4.25 2", "3.30 2.10 3.25 1", "3.40 2.15 3.10 1", "3.25 2.05 3.40 2", "3.25 2.05 3.10 2", "3.25 2.05 3.20 2", "3.25 2.05 3.40 2", "3.25 2.05 3.50 2", "3.10 1.99 3.50 2", "3.30 2.05 3.10 2", "3.10 1.95 3.70 1", "3.25 2.05 3.90 2", "3.40 2.15 3.40 2", "3.30 2.05 3.40 2", "3.10 1.93 3.75 2", "3.00 1.90 3.90 2", "3.10 2.00 3.40 2", "3.00 1.92 3.90 2", "3.30 2.10 3.00 1", "3.20 2.05 3.80 1", "3.20 2.00 3.90 1", "3.25 2.05 3.10 2", "3.40 2.10 3.33 2", "3.00 1.87 4.10 2", "3.33 2.10 3.33 1", "3.10 1.98 3.80 1", "3.10 1.95 3.70 2", "3.25 2.10 3.30 1", "3.20 2.05 3.30 2", "3.20 2.00 4.10 1", "3.25 2.05 3.20 1", "3.25 2.10 3.80 1", "3.20 2.05 3.40 2", "3.33 2.15 3.50 1", "3.25 2.10 3.10 2", "3.20 2.05 3.40 2", "3.50 2.20 3.10 2", "3.33 2.10 3.70 1", "3.30 2.10 3.70 2", "3.25 2.10 3.10 2", "3.30 2.05 3.90 1", "3.30 2.05 3.50 1", "3.20 2.05 3.50 1", "3.20 1.95 4.50 2", "3.20 2.10 3.33 2", "3.33 2.15 3.10 1", "3.50 2.15 3.33 1", "3.33 2.10 3.70 1", "3.25 2.00 4.10 2", "3.50 2.25 3.10 1", "3.30 2.10 3.75 2", "3.30 2.10 3.75 2", "3.33 2.05 3.80 2", "3.40 2.10 3.60 1", "3.25 1.99 4.20 2", "3.25 2.05 4.00 2", "3.40 2.15 3.40 2", "3.30 2.05 3.80 2", "3.25 2.05 4.00 1", "3.30 2.10 3.75 1", "3.33 2.05 3.75 2", "3.33 2.05 3.75 2", "3.30 2.05 3.80 2", "3.25 2.05 4.00 2", "3.30 2.05 3.90 2", "3.40 2.10 3.50 2", "3.25 2.05 3.90 2", "3.25 2.05 3.90 2", "3.30 2.10 3.00 2", "3.10 1.89 4.25 2", "3.10 1.99 3.50 2", "3.25 2.05 3.40 2", "3.40 2.15 3.10 1", "3.30 2.10 3.25 1", "3.20 2.05 3.40 2", "3.33 2.15 3.50 1", "3.25 2.10 3.10 2", "3.20 2.05 3.40 2", "3.50 2.20 3.10 2", "3.33 2.10 3.70 1", "3.30 2.10 3.70 2", "3.25 2.10 3.10 2", "3.40 2.10 3.50 2", "3.20 2.05 3.50 1", "3.20 1.95 4.50 2", "3.30 2.05 3.50 1", "3.20 2.10 3.33 2", "3.20 2.05 3.20 2", "3.10 1.93 3.75 1", "3.25 2.05 3.40 0", "3.20 1.96 4.00 2", "3.33 2.05 3.80 2", "3.40 2.15 3.40 2", "3.33 2.10 3.10 0", "3.20 2.05 3.40 1", "3.40 2.15 3.25 0", "3.40 2.20 3.10 0", "3.25 2.10 3.10 2", "3.10 2.05 3.40 2", "3.10 1.94 3.70 2", "3.00 1.85 4.25 2", "3.10 2.00 3.60 0", "3.20 2.05 3.25 0", "3.10 2.00 3.50 2", "3.25 2.05 3.50 2", "3.10 1.91 3.80 1", "3.20 2.00 3.60 1", "3.10 2.00 3.75 2", "3.20 2.00 3.60 2", "3.10 2.00 4.00 0", "3.33 2.05 3.75 1", "3.40 2.10 3.60 2", "3.40 2.10 3.50 0", "3.30 2.15 3.60 1", "3.40 2.15 3.40 2", "3.40 2.20 3.33 1", "3.20 1.98 4.30 0", "3.20 1.97 4.30 0", "3.50 2.25 3.10 1", "3.30 2.10 3.70 1", "3.30 2.05 3.90 2", "3.20 1.94 4.50 2", "3.25 1.97 4.25 0", "3.30 2.00 4.00 1", "3.00 1.91 3.90 2", "3.20 2.00 3.75 2", "3.25 2.05 3.40 1", "3.30 2.05 3.60 2", "3.20 2.00 3.30 0", "3.25 2.05 3.20 0", "3.00 1.91 3.90 0", "3.00 1.84 4.30 2", "3.10 2.00 3.40 2", "3.20 2.05 3.30 1", "3.20 2.00 3.60 1", "3.30 2.05 3.50 0", "3.40 2.15 3.30 2", "3.33 2.10 3.40 2", "3.25 2.10 3.10 0", "3.00 1.92 3.90 1", "3.25 2.05 3.33 0", "3.10 1.97 3.70 2", "3.10 1.96 3.60 1", "3.20 2.05 3.20 0", "3.40 2.15 3.10 1", "3.20 2.05 3.40 2", "3.10 1.96 3.60 1", "3.10 1.94 3.70 2", "3.10 1.96 3.60 2", "3.10 1.97 3.80 2", "3.10 1.97 3.90 1", "3.20 2.00 3.50 2", "3.25 2.05 3.33 2", "3.20 2.05 3.40 1", "3.25 2.05 3.40 2", "3.20 2.00 3.30 2", "3.20 2.00 3.33 0", "3.20 2.00 3.33 2", "3.20 2.00 3.60 0", "3.25 2.00 3.50 2", "3.25 2.00 3.50 2", "3.25 2.05 3.40 1", "3.30 2.05 3.33 0", "3.30 2.10 3.25 1", "3.20 1.95 4.10 1", "3.40 2.25 2.65 2", "3.25 2.10 3.10 2", "3.25 2.05 3.10 1", "3.25 2.05 3.20 0", "3.20 2.00 3.90 0", "3.25 2.10 3.50 2", "3.25 2.10 3.70 1", "3.30 2.10 3.25 1", "3.10 2.05 3.40 2", "3.30 2.10 3.25 1", "3.33 2.10 3.70 1", "3.33 2.10 3.70 2", "3.25 2.10 3.70 1", "3.50 2.20 3.30 2", "3.00 1.87 4.10 1", "3.10 1.93 3.70 2", "3.10 1.90 3.90 0", "3.10 1.89 3.90 0", "2.90 1.93 4.00 0", "3.10 1.98 3.50 0", "3.30 2.10 2.95 2", "3.10 2.00 3.40 2", "3.20 2.00 3.40 2", "3.33 2.10 2.95 2", "3.25 2.05 4.00 1", "3.10 2.05 3.60 2", "3.33 2.10 3.60 1", "3.10 1.92 4.10 1", "3.25 2.05 3.40 1", "3.20 2.00 3.60 0", "3.20 2.00 3.90 2", "3.33 2.10 3.33 1", "3.50 2.25 2.95 0", "3.30 2.10 3.25 1", "3.10 1.92 3.75 2", "3.33 2.10 3.20 2", "3.10 1.96 3.90 1", "3.20 2.10 3.20 2", "3.33 2.10 3.50 1", "3.30 2.10 3.50 2", "3.25 2.00 3.75 2", "3.00 1.84 4.30 2", "3.10 1.91 3.80 0", "3.10 1.98 3.80 2", "3.10 1.95 3.90 0", "3.20 1.99 3.90 0", "3.25 2.10 3.33 0", "3.00 1.97 3.60 1", "3.25 2.05 3.50 0", "3.20 2.10 3.10 2", "3.20 1.98 3.70 2", "3.10 1.98 3.50 1", "3.00 1.89 4.00 1", "3.40 2.15 3.00 1", "3.10 1.97 3.60 2", "3.10 1.98 3.60 0", "3.00 1.97 3.60 0", "3.10 1.99 3.60 0", "3.10 2.05 3.30 1", "3.30 2.25 2.75 1", "3.30 2.05 3.60 0", "3.40 2.15 3.50 2", "3.30 2.05 3.60 0", "3.40 2.15 3.50 2", "3.20 2.05 3.50 2", "3.10 1.92 4.00 2", "3.40 2.15 3.00 2", "3.10 1.87 4.30 2", "3.50 2.15 3.40 2", "3.10 1.94 3.90 0", "3.20 1.94 3.90 2", "3.10 1.93 3.90 2", "3.10 1.93 3.70 0", "3.10 1.97 3.50 2", "3.10 1.93 3.70 0", "3.10 1.91 3.80 2", "3.20 1.98 3.50 2", "3.10 1.94 3.70 2", "3.10 1.99 3.50 1", "3.10 1.95 3.60 2", "3.10 1.96 3.60 1", "3.10 2.00 3.50 1", "3.00 1.82 4.40 1", "3.00 1.87 4.00 2", "3.00 1.85 4.20 2", "3.20 1.97 3.75 1", "3.30 2.15 3.60 1", "3.10 1.89 3.90 0", "3.25 2.10 3.60 2", "3.30 2.05 3.60 0", "3.10 1.98 3.75 2", "3.40 2.10 3.60 2", "3.30 2.05 4.00 0", "3.20 2.00 4.20 2", "3.33 2.10 3.50 1", "3.33 2.05 3.70 0", "3.30 2.10 3.25 0", "3.25 2.00 3.80 2", "3.20 2.00 4.00 1", "3.33 2.05 3.70 2", "3.25 2.05 3.40 0", "3.20 1.97 3.75 2", "3.25 2.00 4.10 1", "3.10 1.85 4.50 2", "3.00 1.98 3.60 2", "3.40 2.10 3.33 0", "3.40 2.15 3.25 1", "3.40 2.15 3.25 1", "3.20 2.05 3.30 2", "3.10 1.99 3.60 2", "3.10 2.05 3.25 2", "3.10 1.91 3.80 1", "3.00 1.80 4.50 2", "3.10 1.91 3.80 1", "3.10 1.94 3.60 1", "3.10 1.89 4.20 2", "3.10 1.90 3.90 2", "3.10 2.00 3.40 2", "3.10 1.97 3.50 1", "3.20 1.99 3.70 2", "3.25 2.00 3.50 2", "3.20 1.99 3.70 2", "3.20 1.95 3.80 0", "3.10 1.91 4.00 0", "3.10 1.93 4.00 1", "3.10 2.05 3.40 2", "3.10 1.93 3.70 1", "3.10 1.92 3.80 0", "3.25 2.10 3.10 2", "3.10 2.00 3.50 2", "3.20 2.05 3.25 2", "3.00 1.84 4.30 2", "3.25 2.10 3.30 0", "3.20 2.05 3.30 2", "3.20 2.00 3.33 1", "3.10 2.05 3.33 1", "3.10 1.92 3.80 1", "3.10 1.92 3.80 1", "3.10 1.96 3.50 2", "3.10 1.99 3.50 0", "3.10 1.93 3.70 2", "3.10 1.99 3.50 1", "3.10 1.98 3.50 1", "3.10 1.96 3.60 1", "3.10 1.93 3.80 1", "3.20 2.00 3.50 2", "3.20 2.00 3.60 0", "3.20 2.00 3.60 2", "3.20 2.05 3.25 1", "3.25 2.05 3.10 1", "3.25 2.05 3.20 0", "3.00 1.94 3.75 1", "3.10 1.98 3.50 1", "3.20 2.00 3.40 1", "3.10 2.00 3.50 1", "3.10 2.00 3.50 0", "3.10 1.95 3.60 1", "3.40 2.20 2.95 0", "3.25 2.10 3.10 1", "3.10 1.90 3.90 2", "3.10 1.96 3.60 2", "3.10 1.99 3.50 2", "3.20 2.05 3.20 2", "3.10 2.05 3.30 0", "3.10 2.00 3.70 2", "3.20 1.99 3.40 0", "3.00 1.85 4.20 2", "3.10 2.00 3.50 1", "3.10 1.89 3.80 2", "3.33 2.05 3.80 1", "3.40 2.10 3.70 1", "3.33 2.10 3.60 2", "3.40 2.10 3.60 2", "3.50 2.15 3.33 1"
	};
}

std::vector<std::string> Engine::GetSeedV2()
{
	return std::vector<std::string>{
		"3.30 2.05 3.60 0",
			"3.40 2.15 3.50 2",
			"3.20 2.05 3.50 2",
			"3.10 1.92 4.00 2",
			"3.40 2.15 3.00 2",
			"3.10 1.87 4.30 2",
			"3.50 2.15 3.40 2",
			"3.10 1.94 3.90 0",
			"3.20 1.94 3.90 2",
			"3.10 1.93 3.90 2",
			"3.10 1.93 3.70 0",
			"3.10 1.97 3.50 2",
			"3.10 1.93 3.70 0",
			"3.10 1.91 3.80 2",
			"3.20 1.98 3.50 2",
			"3.10 1.94 3.70 2",
			"3.10 1.99 3.50 1",
			"3.10 1.95 3.60 2",
			"3.10 1.96 3.60 1",
			"3.10 2.00 3.50 1",
			"3.00 1.82 4.40 1",
			"3.00 1.87 4.00 2",
			"3.00 1.85 4.20 2",
			"3.20 1.97 3.75 1",
			"3.30 2.15 3.60 1",
			"3.30 2.15 3.10 2",
			"3.10 1.89 3.90 0",
			"3.25 2.10 3.60 2",
			"3.30 2.05 3.60 0",
			"3.10 1.98 3.75 2",
			"3.40 2.10 3.60 2",
			"3.30 2.05 4.00 0",
			"3.20 2.00 4.20 2",
			"3.33 2.10 3.50 1",
			"3.33 2.20 2.95 2",
			"3.25 2.15 3.33 0",
			"3.40 2.25 3.10 0",
			"3.60 2.25 2.95 1",
			"3.50 2.25 2.90 2",
			"3.20 2.05 3.50 2",
	};
}


/**
This is the V3 Seeds... seeded today September 28th 2024
*/
std::vector<std::string> Engine::GetSeedV3()
{
	return std::vector<std::string>
	{
		"3.30 2.10 3.80 1",
			"3.25 1.96 4.30 2",
			"3.20 2.05 3.30 0",
			"3.20 2.05 3.50 1",
			"3.10 1.95 3.90 2",
			"3.20 1.97 3.80 0",
			"3.25 1.99 4.20 1",
			"3.30 2.05 3.90 0",
			"3.10 1.99 3.70 0",
			"3.00 1.97 3.70 2",
			"3.30 2.05 3.60 0",
			"3.25 2.10 3.10 2",
			"3.20 1.95 4.40 2",
			"3.10 1.96 3.60 1",
			"3.33 2.15 2.95 0",
			"3.10 1.98 3.80 2",
			"3.10 1.87 4.30 2",
			"3.30 2.15 3.50 2",
			"3.10 1.95 3.70 1",
			"3.25 2.05 3.20 2",
			"3.33 2.05 3.80 1",
			"3.25 2.00 4.10 1",
			"3.20 2.00 3.60 0",
			"3.30 2.05 3.10 2",
			"3.30 2.00 4.10 2",
			"3.30 2.05 3.80 1",
			"3.25 2.05 3.40 2",
			"3.20 2.05 3.50 1",

			//page 2
			"3.25 2.05 3.40 0",
			"3.10 1.98 3.75 1",
			"3.10 1.96 3.60 0",
			"3.00 1.97 3.70 1",
			"3.10 1.94 3.70 1",
			"3.25 2.05 3.20 2",
			"3.10 1.93 3.75 1",
			"3.25 2.05 3.20 1",
			"3.30 2.10 3.10 1",
			"3.00 1.80 4.50 2",
			"3.30 2.00 4.00 2",
			"3.30 2.10 3.10 1",
			"3.33 2.10 3.50 1",
			"3.10 1.89 4.25 2",
			"3.25 2.00 4.10 1",
			"3.10 1.97 3.50 2",
			"3.25 2.00 4.10 2",
			"3.20 2.05 3.25 0",
			"3.33 2.05 3.50 2",
			"3.40 2.20 3.25 0",
			"3.20 2.05 3.25 2",
			"3.00 1.94 3.75 2",
			"3.10 1.90 4.20 1",
			"3.20 2.00 3.90 1",
			"3.30 2.00 4.00 0",

			//page 3
			"3.25 2.00 3.80 1",
			"3.20 1.97 4.00 2",
			"3.20 1.98 4.00 0",
			"3.10 1.98 3.75 1",
			"3.40 2.20 2.95 1",
			"3.10 1.89 4.00 2",
			"3.25 2.05 3.40 0",
			"3.33 2.05 3.80 1",
			"3.25 2.05 3.80 2",
			"3.20 1.99 3.70 0",
			"3.40 2.15 3.40 0",
			"3.33 2.15 3.10 1",
			"3.20 2.05 3.40 0",
			"3.30 2.10 3.25 0",
			"3.50 2.20 3.30 2",
			"3.20 2.05 3.40 2",
			"3.50 2.30 3.10 0",
			"3.30 2.10 3.70 1",
			"3.40 2.20 2.90 2",
			"3.20 2.05 3.50 0",
			"3.33 2.05 3.50 1",
			"3.40 2.20 2.95 1",
			"3.50 2.20 3.20 1",
			"3.30 2.00 4.00 1",
			"3.20 1.98 4.00 1",
			"3.10 1.98 3.50 2",
			"3.25 2.05 3.40 2",
			"3.10 1.93 3.70 1",
			"3.10 1.93 3.70 2",
			"3.00 1.84 4.25 2",
			"3.25 2.15 3.20 2",
			"3.10 1.94 3.70 0",
			"3.30 2.05 3.30 2",
			"3.25 2.05 3.33 1",
			"3.20 2.00 4.10 2",
			"3.40 2.10 3.30 2",

			//page 4
			"3.20 2.00 3.33 1",
			"3.10 1.93 3.75 2",
			"3.25 2.05 3.20 2",
			"3.10 1.92 3.80 2",
			"3.10 1.99 3.50 2",
			"3.20 1.97 3.50 1",
			"3.20 2.00 3.33 2",
			"3.40 2.15 3.50 2",
			"3.50 2.15 3.33 2",
			"3.10 1.99 3.75 2",
			"3.20 2.00 3.33 1",
			"3.10 2.10 3.25 2",
			"3.10 1.90 3.90 2",
			"3.10 2.05 3.33 2",
			"3.20 1.95 4.40 1",
			"3.33 2.05 3.75 1",
			"3.20 1.96 4.40 2",
			"3.33 2.10 2.95 0",
			"3.33 2.05 3.80 0",
			"3.30 2.05 3.33 0",
			"3.25 2.00 4.10 1",
			"3.50 2.20 3.20 0",
			"3.33 2.15 3.10 1",
			"3.33 2.10 3.70 0",
			"3.33 2.10 3.20 2",
			"3.40 2.15 3.33 0",
			"3.33 2.05 3.90 1",
			"3.30 2.05 4.00 0",
			"3.40 2.15 3.00 2",
			"3.40 2.25 3.10 0",
			"3.20 2.10 3.20 1",
			"3.10 1.99 3.60 2",
			"3.25 2.05 3.20 0",
			"3.33 2.20 3.20 1",
			"3.25 2.15 3.10 1",
			"3.50 2.25 2.80 0",
			"3.40 2.20 2.90 0",
			"3.10 2.05 3.40 1",


			//page 5
			"3.33 2.05 3.75 2",
			"3.25 2.00 4.10 1",
			"3.40 2.15 3.20 2",
			"3.00 1.80 4.50 0",
			"3.10 1.91 4.10 2",
			"3.00 1.87 4.10 2",
			"3.20 1.92 4.25 1",
			"3.20 2.10 3.33 2",
			"3.20 2.10 3.40 2",
			"3.30 2.10 3.70 2",
			"3.20 2.00 3.33 2",
			"3.10 1.99 3.50 2",
			"3.33 2.15 2.95 1",
			
			



	};
}

Score& Engine::GetScore(const std::string& fix)
{
	m_score = Score(0, 0, 0, 0);
	if (fix == "") return m_score;

	std::string part1 = fix.substr(0, fix.length());

	std::vector<std::string> select_space;
	for (const auto& line : m_seeds)
	{
		if (line.substr(0, line.length() - 2) != fix) continue; //we didn't find a match yet...
		select_space.push_back(line);
	}
	if (select_space.size() <= 0) return m_score;

	//_gOssString.clear();
	//std::cout << "So our search for : " << fix << " actually returned " << select_space.size() << " results. Good." << std::endl;
	//CONSOLE_WRITELINE(_gOssString.str());
	//int i_index = rand() % (int)select_space.size() + 1;
	int i_index = gen_random(0, select_space.size() - 1);
	//std::cout << "Random item index " << i_index << " to be selected" << std::endl;
	const std::string& item = select_space[i_index];

	m_score = CalculatePercentScore(select_space, item);

	return m_score;
}
Score& Engine::CalculatePercentScore(std::vector<std::string> select_space, const std::string& item)
{
	Score r_score;
	int a = 0;
	int b = select_space.size();
	for (const auto& x : select_space)
	{
		if (x == item) a++;
	}
	double result = (a * 100) / b;
	const auto& split = split_string(item.c_str(), " ");
	if (split.empty())
	{
		std::cerr << "Ops. Failed could not calculate percent score" << std::endl;
		r_score = { 0, 0, 0, 0 };
		return r_score;
	}
	//std::cout << "item after split has " << split.size() << " items" << std::endl;
	std::string::size_type sz;
	int score = std::stoi(split[3], &sz);
	if (!score) score = 0;
	//std::cout << "Prediction for " << item << " is " << score << std::endl;

	r_score = { score, result, a, b };
	return r_score;
}
