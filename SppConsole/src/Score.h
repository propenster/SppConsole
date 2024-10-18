#pragma once
#include <string>

class Score {
public:
    Score() = default;
    Score(int score, double percentage, int numerator, int denominator);

    int GetScore() const;
    double GetPercentage() const;
    int GetNumerator() const;
    int GetDenominator() const;

    std::string ToString(const std::string& input) const; //want to have like I had in my C# impl like this:
    //Console.WriteLine("Result of {0} => {1} with confidence percent ({2}/{3}): {4:N2}%", input, result.score, result.numerator, result.denominator, result.percentage);

private:
    int m_score;
    double m_percentage; 
    int m_numerator;     
    int m_denominator = 1;   
};
