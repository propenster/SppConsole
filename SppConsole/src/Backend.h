#pragma once
#include <string>
#include "Engine.h"
#include "Vector3.h"

struct Backend {
public:
    Backend() = default;
    Backend(const std::string& input);
        
    Score& RunHighestScoringHalf(Engine& engine, const std::string& input);
    void RunHighestScoringHalfQuadratic(const std::string& input);
    void RunDrawCatcher(const std::string& input);
    void Run2HalfHighestScoring(const std::string& input);
    void RunQuadraticFormulaMethod(const std::string& input);

    void RunSeptember2024(const std::string& input);
    void RunPrimalSumsHSH(const std::string& input);
    void DrawASCIIArt();
    void RunSumAdjacency2024(const std::string& input);
    void RunSumAdjacency2024Improved(const std::string& input);
    void RunSumAdjacency2024_With015(const std::string& input);
    void RunSumAdjacency2024Improved34(const std::string& input);
    

private:
    int GetFloatRemainder(double number);
    bool IsDrawPossible(bool condition1, bool condition2, bool condition3);
    int SelectFigureFromInt(const int& in, const int& figurePosition);
    std::vector<double> SplitStringToDoubleList(const std::string& input, std::vector<std::string>* specs = nullptr);
    double extractFirst3CharactersOfDouble(double value);



private:
    std::string m_input;
    static int m_2_half[];
    static std::vector<Vector3> vv;
};
