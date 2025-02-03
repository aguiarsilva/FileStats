#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	std::ifstream infile;
	infile.open("scores.txt");

	double inputScore;
	double avg = 0;
	double max = 0;
	double min = 0;
	double totalInputs = 0;
	double sumInputs = 0;

	std::vector<int> inputScores;

	if (!infile)
	{
		std::cout << "Error opening file. Bailing out." << std::endl;
		return 1;
	}

	while (!infile.eof())
	{
		infile >> inputScore;
		if (inputScore < 100 && inputScore > 0)
			inputScores.push_back(inputScore);
	}

	max = inputScores[0];
	min = inputScores[0];

	for (int num : inputScores)
	{
		if (num > max)
			max = num;
		if (num < min)
			min = num;
		sumInputs += num;
		totalInputs++;
	}

	avg = sumInputs / totalInputs;

	std::cout << "Statistics: " << std::endl;
	std::cout << "\tMax Score : " << max << std::endl;
	std::cout << "\tMin Score : " << min << std::endl;
	std::cout << "\tAverage Score : " << avg << std::endl;



	infile.close();

	return 0;
}