#include "Score.h"
#include <sstream>
#include <iomanip>

Score::Score(int score, double percentage, int numerator, int denominator)
	: m_score(score), m_percentage(percentage),
	m_numerator(numerator), m_denominator(denominator) {}

int Score::GetScore() const { return m_score; }

double Score::GetPercentage() const { return m_percentage; }

int Score::GetNumerator() const { return m_numerator; }

int Score::GetDenominator() const { return m_denominator; }

//same like: //Console.WriteLine("Result of {0} => {1} with confidence percent ({2}/{3}): {4:N2}%", input, result.score, result.numerator, result.denominator, result.percentage);
std::string Score::ToString(const std::string& input) const {
	std::ostringstream oss;
	oss << "Result of " << input << " => Score: " << m_score
		<< ", Percentage: " << std::fixed << std::setprecision(2) << m_percentage
		<< "%, Confidence: (" << m_numerator << "/" << m_denominator << ")";
	return oss.str();
}
