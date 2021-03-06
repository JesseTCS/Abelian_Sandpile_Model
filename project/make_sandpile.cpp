#include <algorithm>
#include <fstream>
#include <iterator>
#include <random>
#include <sstream>
#include <string>
#include <vector>

#include "make_sandpile.h"

#include <thread>

// define a function for generating a random sandpile given a size and count
Sandpile create_sandpile(int s, int n)
{   
    Row row(s, 0);
    Sandpile sandpile(s, row);
    std::mt19937_64 eng(1337);
    std::uniform_int_distribution<int> dis(0, s-1);
    for (int i = 0; i < n; i++)
    {
        sandpile[dis(eng)][dis(eng)] += 1;
    }

    return sandpile;
}

// define a function for reading a sandpile from a file given its filename
Sandpile read_sandpile_file(char* file_name)
{
    std::ifstream f(file_name);
    std::string buffer;
    Sandpile sandpile;
    while (std::getline(f, buffer))
    {
        std::istringstream ss(buffer);
        std::copy(std::istream_iterator<int>(ss), {}, std::back_inserter(sandpile.emplace_back()));
    }
    return sandpile;
}