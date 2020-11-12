#include <iostream>
#include <vector>

std::string secretWord = "turbot";
std::string censoredSecretWord;

int counter = 0;
int maxTries = 5;
char guess;
std::vector<int> foundLocs;

// [x] Censor word and print out (aka make "dog" -> "_ _ _")
// [x] Fill in censored word based on correct guesses
// [x] Loop for guess
// [x] Make a losing condition
// [ ] Add number of attempts left
// [ ] Add list of possible secret words
// [ ] Hang a man

std::string censorSecretWord(std::string sw, char censorChar = '*')
{
    std::string output = sw;
    for (int i = 0; i < sw.length(); i += 1)
    {
        output[i] = censorChar;
    }

    return output;
}

std::vector<int> findGuessLocs(std::string sw, char g)
{
    std::vector<int> locs;
    for (int i = 0; i < sw.length(); i += 1)
    {
        if (sw[i] == g)
        {
            locs.push_back(i);
        }
    }

    return locs;
}
std::string decensor(std::string censored, char replace, std::vector<int> locs)
{
    for (int i = 0; i < locs.size(); i += 1)
    {
        censored[locs[i]] = replace;
    }
    return censored;
}

int main()
{
    censoredSecretWord = censorSecretWord(secretWord);

    while (true)
    {
        std::cout << "Guessed so far: '" << censoredSecretWord << "'" << std::endl;
        std::cout << "Guess a letter: ";
        std::cin >> guess;

        // check for substring in string

        foundLocs = findGuessLocs(secretWord, guess);

        if (foundLocs.size() > 0)
        {
            // Letter in word
            censoredSecretWord = decensor(censoredSecretWord, guess, foundLocs);
        }
        else
        {
            // Letter not in word
            std::cout << "Letter not in word" << std::endl;
            counter += 1;
        }

        // Check for gameover
        if (censoredSecretWord.find("*") == std::string::npos)
        {
            std::cout << "WINNER!" << std::endl;
            break;
        }
        else if (counter >= maxTries)
        {
            std::cout << "You lose!" << std::endl;
            break;
        }
        std::cout << std::endl;
    }

    return 0;
}
