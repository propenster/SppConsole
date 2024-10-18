#pragma once
#include <string>
#include "Score.h"
#include <vector>

struct Engine
{
public:
	Engine() = default;
	Engine(int version = 0, std::vector<int>* multiVersion = nullptr);

	Score& GetScore(const std::string& fix);
	std::vector<std::string> GetSeeds(int version);

	std::vector<int> m_multiVersion;

private:
	std::vector<std::string> GetCombinedSeed();
	std::vector<std::string> GetSeedV1();
	std::vector<std::string> GetSeedV2();
	std::vector<std::string> GetSeedV3();
	Score& CalculatePercentScore(std::vector<std::string> select_space, const std::string& item);
	std::vector<std::string> GetCombinedSelectedVersionsSeed(const std::vector<int>* selectedVersions);

private:
	Score m_score;
	std::vector<std::string> m_seeds;
	int m_version = 0;

};


