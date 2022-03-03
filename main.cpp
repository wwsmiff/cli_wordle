#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define DEFAULT "\033[0;0m"

static bool running = true;

namespace utils
{
	std::string convertToUpperCase(std::string &_str)
	{
		for(auto &x : _str) x = toupper(x);
		return _str;
	}
}

int main(void)
{
	srand(time(NULL));

	std::string word;
	std::string ans;

	std::ifstream wordsFile("words.txt");
	for(short i = 0; i < (random() % 5750 - 1); ++i)
	{
		std::getline(wordsFile, word);
	}

	utils::convertToUpperCase(word);
	
	std::cout << "RULES:\n1. There is a random word which consists of 5 letters.\n2. If the word you guessed has a letter which is there in the original word, it will be highlighted in " << YELLOW << "yellow." << DEFAULT << "\n3. If the word you guessed has a letter which is in the word and in the right position, it will be highlighted in " << GREEN << " green." << DEFAULT << "\n4. If he word you guessed has a letter which is not in the original word, it wont be highlighted." << std::endl;

	std::cout << std::endl;

	while(running)
	{
		static short count = 0;
		std::cout << "> ";
		std::cin >> std::setw(5) >> ans;
		utils::convertToUpperCase(ans);

		if(ans.size() < 5) 
		{
			std::cout << "The word must have 5 letters" << std::endl;
			std::cout << ans.size() << std::endl;
		}

		else
		{
			for(size_t i = 0; i < ans.size(); ++i)
			{

				if(ans[i] == word[i]) count++;
				

				if(word.find(ans[i]) != std::string::npos)
				{
					if(ans[i] == word[i]) std::cout << GREEN << ans[i];
					else if(ans[i] != word[i]) std::cout << YELLOW << ans[i];
				}

				else std::cout << DEFAULT << ans[i];

				if(count == 5)
				{
					running = false;
				}
			}
			count = 0;
			std::cout << DEFAULT << std::endl;
		}
	}

	return EXIT_SUCCESS;
}
