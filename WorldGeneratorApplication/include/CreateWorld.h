#ifndef CREATEWORLD_H
#define CREATEWORLD_H
#include <tchar.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <time.h>
#include <sstream>
#include <direct.h>
#include <math.h>

using namespace std;

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

struct Culture
{
    string name;
    string economy;
    string food;
    string government;
    string religion;
    string techType;
    string techRelationship;
    string magicType;
    string magicRelationship;
};

struct Biome
{
    string name;
    string description;
    vector <Culture> cultures;
};

struct Continent
{
    int area;
    string name;
    vector <Biome> biomes;
};


class CreateWorld
{
    public:
        CreateWorld();
        CreateWorld(int seed);
        virtual ~CreateWorld();

        string getFileName();
    protected:
    private:
        string fileName;
        string genWorld();
        bool isSeed = false;
        int seed = 0;
        vector <string> generateLanguage(int consStartCount, int consEndCount, int maxVowels, int syllableFrequency);
};

#endif // CREATEWORLD_H
