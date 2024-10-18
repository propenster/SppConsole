#include "Backend.h"
#include "Score.h"
#include "Engine.h"
#include "Utils.h"
#include <array>
#include <format>
#include <set>
#include <numeric>
Backend::Backend(const std::string& input)
{
	m_input = input;
}

int Backend::m_2_half[] = { 6, 42, 51, 19, 59, 66, 24, 80, 18, 61, 88, 82, 67, 73, 61, 55, 34, 42, 57, 47, 67, 55, 89, 42 };
std::vector<Vector3> Backend::vv = {
		Vector3{85, 96, 1},
		Vector3{86, 43, 1},
		Vector3{87, 32, 2},
		Vector3{89, 78, 1},
		Vector3{88, 44, 0},
		Vector3{91, 45, 1},
		Vector3{89, 4, 0},
		Vector3{90, 76, 0},
		Vector3{87, 50, 2},
		Vector3{91, 93, 1},
		Vector3{89, 84, 1},
		Vector3{86, 95, 2},
		Vector3{94, 90, 1},
		Vector3{89, 96, 2},
		Vector3{85, 60, 0},
		Vector3{87, 50, 1},
		Vector3{87, 15, 1},
		Vector3{90, 10, 1},
		Vector3{85, 60, 0},
		Vector3{87, 40, 2},
		Vector3{85, 25, 0},
		Vector3{91, 0, 1},
		Vector3{86, 75, 2},
		Vector3{88, 30, 2},
		Vector3{87, 70, 0},
		Vector3{86, 75, 2},
		Vector3{86, 10, 0},
		Vector3{93, 17, 2},
		Vector3{86, 84, 1},
		Vector3{87, 98, 2},
		Vector3{91, 62, 1},
		//new cue -> Under 05 EVEN, Over 25 EVEN Under 25 ODD and... O1.5 and O0.5 must be OPPS  -> a conjoined triangle of success
		Vector3{84, 69, 1},
		Vector3{84, 95, 1},
		Vector3{86, 97, 0},
		Vector3{96, 93, 2},
		Vector3{84, 19, 0},
		Vector3{88, 62, 1},
		Vector3{84, 5, 2},

};


Score& Backend::RunHighestScoringHalf(Engine& engine, const std::string& input)
{
	Score& score = engine.GetScore(input);
	return score;
}
void Backend::RunHighestScoringHalfQuadratic(const std::string& input)
{
	double sum = split_string_to_double_sum(input, " ");
	std::cout << "Sum of real numbers >>> " << sum << std::endl;
}
void Backend::RunDrawCatcher(const std::string& input)
{
	std::vector<std::string> pool = split_string(input, "_");
	std::vector<std::string> first = split_string(pool[0], ",");
	std::vector<std::string> second = split_string(pool[1], ",");
	bool condition1 = find_min_from_double_list(first) == to_double(first[0]);
	int rem = std::stoi(split_string(std::to_string(get_sum_from_double_list(second)), ".")[1]); //this is a lot to unpack I know... 
	bool condition2 = rem % 3 == 0;

	int last = std::stoi(split_string(first[1], ".")[1]);
	bool condition3 = rem % 3 == 0 || last % 3 == 0;
	bool isDrawPossible = Backend::IsDrawPossible(condition1, condition2, condition3);
	if (!isDrawPossible)
	{
		std::cout << ">>> Draw NO" << std::endl;
		return;
	}
	std::cout << ">>> Draw YES" << std::endl;
}
void Backend::Run2HalfHighestScoring(const std::string& input)
{
	double sum = split_string_to_double_sum(input, " ");
	int res = GetFloatRemainder(sum);
	bool condition = array_contains(m_2_half, res);

	//"Sum = {0} 2Half >>> {1}", res, condition ? "YES" : "NO"
	std::cout << "Sum = " << res << " 2Half >>> " << (condition ? "YES" : "NO") << std::endl;
}
int Backend::GetFloatRemainder(double number)
{
	float fractionalPart = number - (int)number;
	int rem = (int)(fractionalPart * 100);
	return rem;
}
bool Backend::IsDrawPossible(bool condition1, bool condition2, bool condition3)
{
	return (condition1 && condition2 && condition3);
}
void Backend::RunQuadraticFormulaMethod(const std::string& input)
{

}
int Backend::SelectFigureFromInt(const int& in, const int& figurePosition)
{
	std::string str = std::to_string(in);
	char y = str[figurePosition];
	std::string yts(1, y);
	return std::stoi(yts);
}
/**
This is the star algorithm for the year of 2024...
The aduptative Function F(x) of a cojoined associative stochastic list that result to a boolean attractor is a function of Euclidian geomtric expression and
alpha value...
:returns
*/
void Backend::RunSeptember2024(const std::string& input)
{
	std::vector<std::string> numStrings = split_string(input, " ");
	if (numStrings.size() > 3) return;
	std::vector<int> nums;
	nums.resize(numStrings.size());

	int N = 0;
	for (int i = 0; i < numStrings.size(); i++)
	{
		double d = to_double(numStrings[i]);
		int j = 100 * d; //e.g 3.25 * 100 becomes 325
		nums[i] = j;
	}

	//extract figure N...
	N = Backend::SelectFigureFromInt(nums[2], 1);
	int a, b, c, n = 0;
	a = SelectFigureFromInt(nums[0], 0);
	b = SelectFigureFromInt(nums[1], 0);
	c = SelectFigureFromInt(nums[2], 0);
	n = a + b + c;

	bool condition1 = ((n + 1) == N) || ((n - 1) == N);
	bool condition2 = n == N;
	bool condition3 = ((n + 2) == N) || ((n - 2) == N);
	bool condition4 = false;
	if (N != 0) //avoid DivideByZero Exception
	{
		condition4 = ((n % N) == 0) || ((N % n) == 0);
	}
	bool condition5 = n % 4 == N;

	bool twoHp = condition1 || condition2 || condition3 || condition4 || condition5;

	bool alternateCondition = (nums[0] != 330) && (nums[1] != 210);

	std::ostringstream oss;

	std::cout << "2H Possible 95%+ degree confidence >> " << (twoHp && alternateCondition ? "YES" : "NO") << std::endl;
}

void Backend::RunPrimalSumsHSH(const std::string& input)
{
	std::vector<std::string> numStrings = split_string(input, " ");
	if (numStrings.size() > 3) return;

	std::vector<double> nums;
	nums.resize(numStrings.size());

	int N = 0;
	for (int i = 0; i < numStrings.size(); i++)
	{
		double d = to_double(numStrings[i]);
		nums[i] = d;
	}
	double sum = nums[0] + nums[1] + nums[2];

	std::cout << "Result is: " << sum << std::endl;
}
std::vector<double> Backend::SplitStringToDoubleList(const std::string& input, std::vector<std::string>* specs)
{
	std::vector<std::string> numStrings;
	if (specs != nullptr)
	{
		numStrings = *specs;
	}
	else
	{
		numStrings = split_string(input, " ");
	}

	//if (numStrings.size() > 3) return std::vector<double>();
	std::vector<double> nums;
	nums.resize(numStrings.size());

	int N = 0;
	for (int i = 0; i < numStrings.size(); i++)
	{
		double d = to_double(numStrings[i]);
		nums[i] = d;
	}
	return nums;
}

void Backend::DrawASCIIArt()
{
	// Define sets for X and Y
	std::set<double> setX = { 8.50, 8.53, 8.58, 8.67, 9.13, 9.28, 9.35, 9.37, 9.55, 9.56, 8.43, 9.47, 9.3, 8.95, 9.15 };
	std::set<double> setY = { 8.45, 8.48, 8.50, 8.63, 8.70, 8.78, 8.82, 8.84, 9.00, 9.05, 9.10, 9.13, 8.59, 8.93, 8.63, 8.88, 9.03, 9.15 };

	// Print Set X
	std::cout << "Set X (sums that resulted in 1):" << std::endl;
	std::cout << "{";
	for (auto it = setX.begin(); it != setX.end(); ++it)
	{
		std::cout << *it;
		if (std::next(it) != setX.end())
		{
			std::cout << ", ";
		}
	}
	std::cout << "}" << std::endl;

	// Print Set Y
	std::cout << "Set Y (sums that resulted in 2):" << std::endl;
	std::cout << "{";
	for (auto it = setY.begin(); it != setY.end(); ++it)
	{
		std::cout << *it;
		if (std::next(it) != setY.end())
		{
			std::cout << ", ";
		}
	}
	std::cout << "}" << std::endl;

	for (int i = 0; i < 5; i++)
	{
		if (i == 4)
		{
			std::cout << "[" << "\t\t\t" << "]" << std::endl;
			continue;
		}
		std::cout << "|" << "\t\t\t" << "|" << std::endl;
	}
	std::cout << std::endl;

}

/**
THis is when SUM cue == cue of OVER 2.5
*/
void Backend::RunSumAdjacency2024(const std::string& input)
{
	std::vector<std::string> v = split_string(input, " ");
	std::vector < std::string> ve = std::vector<std::string>(v.begin(), v.begin() + 3);
	std::vector<double> nums = SplitStringToDoubleList(input, &ve);
	if (nums.empty()) return;

	double sum = std::accumulate(nums.begin(), nums.end(), 0.0);
	double reference = to_double(v.back());

	std::string y = "3223223";

	double cue1 = extractFirst3CharactersOfDouble(sum);
	double cue2 = extractFirst3CharactersOfDouble(reference);

	//bool is2H = (int(cue1 * 10) % 2 == 0 && int(cue2 * 10) % 2 == 0) || (int(cue1 * 10) % 2 == 1 && int(cue2 * 10) % 2 == 1);
	cue1 *= 10;
	cue2 *= 10;
	int firstToInt = std::stoi(std::to_string(cue1));
	int secondToInt = std::stoi(std::to_string(cue2));

	bool is2H = (firstToInt % 2 == 0 && secondToInt % 2 == 1) || (firstToInt % 2 == 1 && secondToInt % 2 == 0);

	if (cue1 - cue2 == 10) is2H = true;

	std::array<int, 4> hades = { 85, 88, 90, 92 };

	auto it = std::find(hades.begin(), hades.end(), cue1);
	if (it != hades.end()) is2H = false;


	std::ostringstream oss;
	oss << "Sum = " << cue1 << " Sum Cue = " << cue1 << " Reference = " << reference << " Reference Cue = " << cue2 << " Result = " << (is2H ? " 2 " : " 0 ");

	std::cout << oss.str() << "\n";

}
/**
THis is when SUM cue == cue of OVER 2.5 + cue of OVER 1.5
input: 3.50 2.20 3.00 7.20 2.95
*/
void Backend::RunSumAdjacency2024Improved(const std::string& input)
{
	std::vector<std::string> v = split_string(input, " ");
	/*std::vector < std::string> ve = std::vector<std::string>(v.begin(), v.begin() + 3);
	std::vector<std::string> last2 = std::vector<std::string>(v.begin() + 3, v.end());*/
	std::vector<double> nums = SplitStringToDoubleList(input, &v);
	if (nums.empty()) return;

	std::vector<double> first3 = std::vector<double>(nums.begin(), nums.begin() + 3);
	double sum = std::accumulate(nums.begin(), nums.begin() + 3, 0.0); //sum the front/first 3 -> they make up our sum CUE
	double reference = std::accumulate(nums.begin() + 3, nums.end(), 0.0);

	std::string y = "3223223";

	double cue1 = extractFirst3CharactersOfDouble(sum);


	std::ostringstream oss;
	oss << std::fixed << std::setprecision(2) << reference;
	std::string doubleStr = oss.str();

	int cue2 = (int)(std::stod(doubleStr) * 100) % 100;
	oss.clear();

	//double cue2 = extractFirst3CharactersOfDouble(reference);

	//bool is2H = (int(cue1 * 10) % 2 == 0 && int(cue2 * 10) % 2 == 0) || (int(cue1 * 10) % 2 == 1 && int(cue2 * 10) % 2 == 1);
	cue1 *= 10;
	//cue2 *= 10;
	int firstToInt = std::stoi(std::to_string(cue1));
	int secondToInt = cue2; //std::stoi(std::to_string(cue2));

	bool is2H = (firstToInt % 2 == 0 && secondToInt % 2 == 1) || (firstToInt % 2 == 1 && secondToInt % 2 == 0);

	if (cue1 - cue2 == 10) is2H = true;


	if (cue2 % 10 == 0) is2H = false;


	std::array<int, 4> hades = { 85, 88, 90, 92 };

	auto it = std::find(hades.begin(), hades.end(), cue1);
	if (it != hades.end()) is2H = false;


	std::ostringstream oss2;
	oss2 << "Sum = " << cue1 << " Sum Cue = " << cue1 << " Reference = " << reference << " Reference Cue = " << cue2 << " Result = " << (is2H ? " 2 " : " 0 ");

	std::cout << oss2.str() << "\n";

}
/**
this is when SUM cue equal to CUE of Over 1.5
*/
void Backend::RunSumAdjacency2024_With015(const std::string& input)
{
	std::vector<std::string> v = split_string(input, " ");
	std::vector < std::string> ve = std::vector<std::string>(v.begin(), v.begin() + 3);
	std::vector<double> nums = SplitStringToDoubleList(input, &ve);
	if (nums.empty()) return;

	double sum = std::accumulate(nums.begin(), nums.end(), 0.0);
	double reference = to_double(v.back());

	std::string y = "3223223";

	double cue1 = extractFirst3CharactersOfDouble(sum);
	double cue2 = extractFirst3CharactersOfDouble(reference);

	//bool is2H = (int(cue1 * 10) % 2 == 0 && int(cue2 * 10) % 2 == 0) || (int(cue1 * 10) % 2 == 1 && int(cue2 * 10) % 2 == 1);
	cue1 *= 10;
	cue2 *= 10;
	int firstToInt = std::stoi(std::to_string(cue1));
	int secondToInt = std::stoi(std::to_string(cue2));

	bool is2H = (firstToInt % 2 == 0 && secondToInt % 2 == 0) || (firstToInt % 2 == 1 && secondToInt % 2 == 1);

	std::ostringstream oss;
	oss << "Sum = " << cue1 << " Sum Cue = " << cue1 << " Reference = " << reference << " Reference Cue = " << cue2 << " Result = " << (is2H ? " 2 " : " 0 ");

	std::cout << oss.str() << "\n";

}

/**
THis is when SUM cue == cue of OVER 2.5 + cue of OVER 1.5
input: 3.50 2.20 3.00 7.20 2.95
*/
void Backend::RunSumAdjacency2024Improved34(const std::string& input)
{
	std::vector<std::string> v = split_string(input, " ");
	/*std::vector < std::string> ve = std::vector<std::string>(v.begin(), v.begin() + 3);
	std::vector<std::string> last2 = std::vector<std::string>(v.begin() + 3, v.end());*/
	std::vector<double> nums = SplitStringToDoubleList(input, &v);
	if (nums.empty()) return;

	std::vector<double> first3 = std::vector<double>(nums.begin(), nums.begin() + 3);
	double sum = std::accumulate(nums.begin(), nums.begin() + 3, 0.0); //sum the front/first 3 -> they make up our sum CUE
	double reference = std::accumulate(nums.begin() + 3, nums.end(), 0.0);

	std::string y = "3223223";

	double cue1 = extractFirst3CharactersOfDouble(sum);


	std::ostringstream oss;
	oss << std::fixed << std::setprecision(2) << reference;
	std::string doubleStr = oss.str();

	int cue2 = (int)(std::stod(doubleStr) * 100) % 100;
	oss.clear();

	//double cue2 = extractFirst3CharactersOfDouble(reference);

	//bool is2H = (int(cue1 * 10) % 2 == 0 && int(cue2 * 10) % 2 == 0) || (int(cue1 * 10) % 2 == 1 && int(cue2 * 10) % 2 == 1);
	cue1 *= 10;
	//cue2 *= 10;
	int firstToInt = std::stoi(std::to_string(cue1));
	int secondToInt = cue2; //std::stoi(std::to_string(cue2));


	std::vector<Vector3> lookup;
	int result = -1; //minus 1 is undefined or we did not find a match...
	//there's a better way to do this...
	for (size_t i = 0; i < vv.size(); i++)
	{
		if (vv[i].x == firstToInt && vv[i].y == secondToInt)
		{
			//the first match is OK...
			result = vv[i].z;
			break;
		}
		
	}


	std::ostringstream oss2;
	oss2 << "Sum = " << cue1 << " Sum Cue = " << cue1 << " Reference = " << reference << " Reference Cue = " << cue2 << " Result = " << result;

	std::cout << oss2.str() << "\n";

}

double Backend::extractFirst3CharactersOfDouble(double value)
{
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(6) << value;
	std::string doubleStr = oss.str();
	std::string firstThreeChars = doubleStr.substr(0, 3);
	return std::stod(firstThreeChars);
}

