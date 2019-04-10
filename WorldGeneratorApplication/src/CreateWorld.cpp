#include "CreateWorld.h"

CreateWorld::CreateWorld()
{
    //ctor
    fileName = genWorld();
}

CreateWorld::CreateWorld(int seed)
{
    isSeed = true;
    this->seed = seed;
    fileName = genWorld();
}

CreateWorld::~CreateWorld()
{
    //dtor
}

string CreateWorld::getFileName()
{
    return fileName;
}


string CreateWorld::genWorld()
{
    cout << "Setting up base variables..." << endl;
    if (!isSeed)
    {
        seed = time(NULL);
    }
    srand(seed);
    static int SURFACE_AREA = 500000000; //Kilometers

    string obj = patch::to_string(seed);
    mkdir("seeds");
    string fileName = "seeds\\Seed_" + obj + ".txt";
    ofstream myFile;
    string line;
    myFile.open(fileName);

    //Results prep
    string magic[] = {"Magic is virtually nonexistent.",
                      "Only a few living people have ever seen magic.",
                      "Magic is used by very few.",
                      "Magic is used by some, and people know of it.",
                      "Magic is used by many, but not all.",
                      "Magic is taken for granted as an aspect of everyday life, and almost everyone uses it.",
                      "Every sentient being can use magic."
                     };

    string magicType[] = {"inner power/strength.",
                          "monstrous bloodlines.",
                          "souls.",
                          "nature.",
                          "deities or spirits.",
                          "memorized words of power and spells.",
                          "blood.",
                          "pacts with monsters and demons.",
                          "alchemy."
                         };

    string magicAttitudes[] = {"fear", "hostility", "discomfort", "indifference", "admiration", "awe", "worship"};

    string technology[] = {"Technology is prehistoric, consisting of rocks and sticks.",
                           "Technology is prehistoric, consisting of bows, plows, and maybe copper.",
                           "Technology is ancient, consisting of ironworking and writing.",
                           "Technology is ancient, consisting of aqueducts and better ships than in the past.",
                           "Technology is similar to the medieval period, consisting of windmills and the dry compass",
                           "Technology is similar to the renaissance, consisting of gunpowder and the printing press.",
                           "Technology is industrial, consisting of the steam engine and electricity.",
                           "Technology is modern, consisting of nukes and computers.",
                           "Technology is the near-future of Earth.",
                           "Technology is the distant future of Earth."
                          };
    string technologyType[] = {"similar to how it is on earth.",
                               "from the ruins of ancient civilizations.",
                               "steampunk/cyberpunk in nature, defying standard notions of logic.",
                               "powered by magic.",
                               "based upon discovered alien technology."
                              };
    string technologyAttitudes[] = {"fear", "hostility", "discomfort", "indifference", "admiration", "awe", "worship"};


    string temperature[] = {"extremely cold",
                            "cold",
                            "like earth",
                            "hot",
                            "extremely hot"
                           };
    string vegetation[] = {"virtually no life, and few things survive",
                           "low amount of life, which is hard to find",
                           "an amount of life similar to Earth",
                           "high amount of life, with few barren areas",
                           "an extremely high amount of life, and all ground is covered with vegetation"
                          };
    string landSeaBalanceSpecials[] = {"The vast majority of the world is frozen over.",
                                       "Large glaciers cover much of the world, growing each winter.",
                                       "Rain evaporates immediately upon hitting the ground.",
                                       "The ocean is boiling hot."
                                      };
    string biomeDescriptors[] = {"hot ", "", "cold "};

    string biomes[] = { "dry desert",
                        "coastal desert",
                        "semiarid desert",
                        "steppe",
                        "grassland",
                        "forest",
                        "jungle"
                      };
    string biomeAddOns[] = {" with a giant mushroom forest",
                            " that is completely inside a sprawling, underground cave system",
                            " with living, growing rocks and crystals",
                            " without much vegetation on the ground, only a swarm of beetles and bugs that photosynthesize",
                            " with giant living rocks",
                            " with a wetland",
                            " with an undead infestation",
                            " with floating islands",
                            " with sentient plants",
                            " with a thicket of thorns, ever-growing vines, and large trees",
                            " with lots of rocky volcanoes and lava rivers"
                           };
    string economy[] = {"There is no concept of property.",
                        "This is no concept of trade, but gifts are given.",
                        "Trade is done through barter.",
                        "Trade is done with coin and unregulated by authority.",
                        "Trade is done with coin, and authorities provide services such as roads and police.",
                        "There is no trade, property is collectively owned.",
                        "There is no trade, authorities own all property."
                       };
    string foodStaples[] = {"Corn",
                            "Rice",
                            "Wheat",
                            "Potatoes",
                            "Cassava",
                            "Soybeans",
                            "Sweet potatoes",
                            "Yams",
                            "Sorghum",
                            "Plantains"
                           };
    string foodMeats[] = {"monstrous meat such as dragons or griffins",
                          "uncommon meat such as lizards or insects",
                          "cattle",
                          "pig",
                          "chicken",
                          "buffalo",
                          "sheep",
                          "goat",
                          "game meat such as deer or elk",
                          "fish"
                         };
    string governments[] = {"Aristocracy - rule by several bloodlines",
                            "Geniocracy - rule by intelligence",
                            "Kratocracy - rule by strength",
                            "Meritocracy - rule by ability",
                            "Timocracy - rule by honor",
                            "Technocracy - rule by education",
                            "Autocracy - rule by one, the ruler has servants",
                            "Despotism - rule by one, the ruler has slaves",
                            "Dictatorship - rule by one, gained power through force",
                            "Military Dictatorship - rule by military",
                            "Fascism - rule by one, gained power through nationalism",
                            "Monarchy - rule by single bloodline",
                            "Constitutional Monarchy - rule by single bloodline that is limited by law",
                            "Diarchy - rule by two bloodlines",
                            "Bankocracy - rule by banks",
                            "Corporatocracy - rule by corporations",
                            "Kleptocracy - rule by thieves",
                            "Ochlocracy - mob rule",
                            "Chiefdom - rule by senior members of families or houses",
                            "Magrocracy - rule by magic",
                            "Theocracy - rule by religion",
                            "Direct Democracy - rule by enfranchised elections",
                            "Representative Democracy - rule by representatives chosen through enfranchised elections",
                            "Ergatocracy - rule by working class",
                            "Kritarchy - rule by legal judges",
                            "Plutocracy - rule by rich",
                            "Stratocracy - rule by military with conscription",
                            "Monstrous tyranny - rule by monsters through force",
                            "Anarchy - no enforced rule"
                           };
    string religiousSystems[] = {"Monotheism",
                               "Polytheism",
                               "Dualism",
                               "Animism",
                               "Shamanism",
                               "Totemism",
                               "Demon Worship",
                               "Ancestor Worship",
                               "Philosophical"
                              };
    string deityAlignments[] = {"Judgemental",
                              "Forgiving",
                              "Uncaring",
                              "Meddling",
                              "Punishing",
                              "Antagonistic",
                              "Obscure",
                              "Mysterious"
                             };
    string deityDomains[] = {"Life",
                            "Law",
                            "Creation",
                            "Fire",
                            "Land",
                            "War",
                            "Judgement",
                            "Sun",
                            "Wilderness",
                            "Intelligence",
                            "Luck",
                            "Harvest",
                            "Family",
                            "Travel",
                            "Disaster",
                            "Truth",
                            "Desire",
                            "Fighting",
                            "Day",
                            "Sky",
                            "Forest",
                            "Insanity",
                            "Metalworking",
                            "Writing",
                            "Afterlife",
                            "Magic",
                            "Demons",
                            "Death",
                            "Chaos",
                            "Destruction",
                            "Ice",
                            "Sea",
                            "Peace",
                            "Trickery",
                            "Moon",
                            "Civilization",
                            "Strength",
                            "Destiny",
                            "Plague",
                            "Love",
                            "Home",
                            "Beauty",
                            "Secrets",
                            "Hatred",
                            "Protection",
                            "Night",
                            "Stars",
                            "Desert",
                            "Mind",
                            "Weaving",
                            "Painting",
                            "Childbirth",
                            "Antimagic",
                            "Angels"
                            };

    //Random generation
    cout << "Generating language..." << endl;
    vector <string> worldLanguage = generateLanguage(8, 0, 1, 5);
    string worldName = worldLanguage.at(rand() % worldLanguage.size());

    cout << "Establishing magic and technology levels..." << endl;

    int magicLevel = rand() % 7;
    string magicDescription = magic[magicLevel];
    int magicVariance = rand() % 3;
    if (magicVariance == 1)
    {
        if (magicLevel + magicVariance < 7)
        {
            magicDescription += "\n     In some places, " + magic[magicLevel + magicVariance];
        }
        if (magicLevel - magicVariance >= 0)
        {
            magicDescription += "\n     In some places, " + magic[magicLevel - magicVariance];
        }
    }
    if (magicVariance == 2)
    {
        if (magicLevel + magicVariance < 7)
        {
            magicDescription += "\n     In some places, " + magic[magicLevel + magicVariance];
        }
        if (magicLevel - magicVariance >= 0)
        {
            magicDescription += "\n     In some places, " + magic[magicLevel - magicVariance];
        }
    }

    int magicSourceNum = rand() % 9;
    string magicSourceDescription = "The source of magic is " + magicType[magicSourceNum];
    if (rand() % 3 == 0)
    {
        magicSourceDescription += " However, some mages use " + magicType[rand() % 9];
    }

    int magicAttitudesNum = rand() % 7;
    string magicAttitudesDescription = "Around magic, people react with " + magicAttitudes[magicAttitudesNum] + ".";
    int magicAttitudesVariance = rand() % 3;
    if (magicAttitudesVariance == 1)
    {
        if (magicAttitudesNum + magicAttitudesVariance < 7)
        {
            magicAttitudesDescription += "\n     In some places, people react with " + magicAttitudes[magicAttitudesNum + magicAttitudesVariance] + ".";
        }
        if (magicAttitudesNum - magicAttitudesVariance >= 0)
        {
            magicAttitudesDescription += "\n     In some places, people react with " + magicAttitudes[magicAttitudesNum - magicAttitudesVariance] + ".";
        }
    }
    if (magicAttitudesVariance == 2)
    {
        if (magicAttitudesNum + magicAttitudesVariance < 7)
        {
            magicAttitudesDescription += "\n     In some places, people react with " + magicAttitudes[magicAttitudesNum + magicAttitudesVariance] + ".";
        }
        if (magicAttitudesNum - magicAttitudesVariance >= 0)
        {
            magicAttitudesDescription += "\n     In some places, people react with " + magicAttitudes[magicAttitudesNum - magicAttitudesVariance] + ".";
        }
    }



    //TECH START
    //
    //
    int technologyLevel = rand() % 10;
    string technologyDescription = technology[technologyLevel];
    int technologyVariance = rand() % 3;
    if (technologyVariance == 1)
    {
        if (technologyLevel + technologyVariance < 10)
        {
            technologyDescription += "\n     In some places, " + technology[technologyLevel + technologyVariance];
        }
        if (technologyLevel - technologyVariance >= 0)
        {
            technologyDescription += "\n     In some places, " + technology[technologyLevel - technologyVariance];
        }
    }
    if (technologyVariance == 2)
    {
        if (technologyLevel + technologyVariance < 7)
        {
            technologyDescription += "\n     In some places, " + technology[technologyLevel + technologyVariance];
        }
        if (technologyLevel - technologyVariance >= 0)
        {
            technologyDescription += "\n     In some places, " + technology[technologyLevel - technologyVariance];
        }
    }

    int technologySourceNum = rand() % 5;
    string technologySourceDescription = "Technology is " + technologyType[technologySourceNum];
    if (rand() % 3 == 0)
    {
        technologySourceDescription += " However, some have built technology " + technologyType[rand() % 5];
    }

    int technologyAttitudesNum = rand() % 7;
    string technologyAttitudesDescription = "Around technology, people react with " + technologyAttitudes[technologyAttitudesNum] + ".";
    int technologyAttitudesVariance = rand() % 3;
    if (technologyAttitudesVariance == 1)
    {
        if (technologyAttitudesNum + technologyAttitudesVariance < 7)
        {
            technologyAttitudesDescription += "\n     In some places, people react with " + technologyAttitudes[technologyAttitudesNum + technologyAttitudesVariance] + ".";
        }
        if (technologyAttitudesNum - technologyAttitudesVariance >= 0)
        {
            technologyAttitudesDescription += "\n     In some places, people react with " + technologyAttitudes[technologyAttitudesNum - technologyAttitudesVariance] + ".";
        }
    }
    if (technologyAttitudesVariance == 2)
    {
        if (technologyAttitudesNum + technologyAttitudesVariance < 7)
        {
            technologyAttitudesDescription += "\n     In some places, people react with " + technologyAttitudes[technologyAttitudesNum + technologyAttitudesVariance] + ".";
        }
        if (technologyAttitudesNum - technologyAttitudesVariance >= 0)
        {
            technologyAttitudesDescription += "\n     In some places, people react with " + technologyAttitudes[technologyAttitudesNum - technologyAttitudesVariance] + ".";
        }
    }
    //
    //
    //TECH END

    cout << "Establishing world climate..." << endl;
    int temperatureAvg = rand() % 30;
    string temperatureDescription = "The average temperature of the world is " + patch::to_string(temperatureAvg) + " degrees Celsius. It is ";
    if (temperatureAvg < 6)
    {
        temperatureDescription += temperature[0];
    }
    else if (temperatureAvg < 12)
    {
        temperatureDescription += temperature[1];
    }
    else if (temperatureAvg < 16)
    {
        temperatureDescription += temperature[2];
    }
    else if (temperatureAvg < 23)
    {
        temperatureDescription += temperature[3];
    }
    else
    {
        temperatureDescription += temperature[4];
    }
    temperatureDescription += ".";

    int tempModifier = temperatureAvg - 14;

    int vegetationLevel = (rand() % 5) - (abs(tempModifier) / 5);

    if (vegetationLevel < 0)
        vegetationLevel = 0;

    string vegetationDescription = "The world has " + vegetation[vegetationLevel] + ".";

    int oceanPercentage;

    if (rand() % 2 == 0)
    {
        oceanPercentage = rand() % 100 - tempModifier;
    }
    else
    {
        oceanPercentage = 50 + rand() % 50 - tempModifier;
    }


    if (oceanPercentage < 0)
        oceanPercentage = 0;
    if (oceanPercentage > 99)
        oceanPercentage = 99;

    string oceanDescription = "The world is " + patch::to_string(oceanPercentage) + "% water.";

    if (temperatureAvg > 20)
    {
        if (rand() % 2 == 0)
        {
            oceanDescription += "\n" + landSeaBalanceSpecials[2 + (rand() % 2)];
        }
    }
    if (temperatureAvg < 8)
    {
        if (rand() % 2 == 0)
        {
            oceanDescription += "\n" + landSeaBalanceSpecials[rand() % 2];
        }
    }


    int continentLandMass = (100 - oceanPercentage) * (SURFACE_AREA / 100);
    vector <Continent> continentsList;

    while (continentLandMass > 0)
    {
        Continent newContinent;
        newContinent.name = worldLanguage.at(rand() % worldLanguage.size());
        int newArea = 1000000 + ((rand() * rand()) % continentLandMass); //At a minimum, the continents will be about a tenth the size of Australia.
        if (newArea > continentLandMass)
            newArea = continentLandMass;
        newContinent.area = newArea;
        continentLandMass -= newArea;

        int biomeNumber = 1;
        if ((newArea / 1000000) <= 0)
            break;
        else
            biomeNumber = 1 + rand() % (newArea / 1000000); //Every million km is a chance at another biome;

        for (int i = 0; i < biomeNumber; i++)
        {
            Biome newBiome;
            newBiome.name = worldLanguage.at(rand() % worldLanguage.size());

            string biomeDesc;

            if (temperatureAvg > 20)
            {
                if (rand() % 3 != 0)
                {
                    biomeDesc = biomeDescriptors[0];
                }
                else
                {
                    biomeDesc = biomeDescriptors[rand() % 3];
                }
            }
            else if (temperatureAvg < 10)
            {
                if (rand() % 3 != 0)
                {
                    biomeDesc = biomeDescriptors[2];
                }
                else
                {
                    biomeDesc = biomeDescriptors[rand() % 3];
                }
            }
            else
            {
                biomeDesc = biomeDescriptors[rand() % 3];
            }


            int biomeType = rand() % 11 + vegetationLevel - 4;
            if (biomeType > 6)
                biomeType = 6;
            if (biomeType < 0)
                biomeType = 0;
            biomeDesc += biomes[biomeType];
            if (rand() % 4 == 0)
            {
                biomeDesc += biomeAddOns[rand() % 11];
            }

            biomeDesc += "\n       Cultures";
            int cultNum = rand() % 4;
            if (vegetationLevel < 3)
                cultNum--;
            if (vegetationLevel < 1)
                cultNum--;
            if (vegetationLevel > 3)
                cultNum++;


            if (cultNum <= 0)
            {
                biomeDesc += ": There are no cultures in this area.";
            }
            else
            {
                biomeDesc += ": ";
                biomeDesc += patch::to_string(cultNum);
                for (int i = 0; i < cultNum; i++)
                {
                    //Generate cultures
                    Culture newCulture;
                    newCulture.name = worldLanguage.at(rand() % worldLanguage.size());
                    newCulture.economy = economy[rand() % 7];
                    newCulture.food = foodStaples[rand() % 10];
                    if (rand() % 10 != 0)
                    {
                        int randNum = rand() % 4;
                        for (int i = 0; i < randNum; i++)
                        {
                            newCulture.food += ", " + foodMeats[rand() % 10];
                        }
                    }


                    newCulture.government = governments[rand() % 29];
                    int religionNumber = rand() % 9;
                    newCulture.religion = religiousSystems[religionNumber];
                    if (religionNumber == 0)
                    {
                            //Monotheism
                            string godName = worldLanguage.at(rand() % worldLanguage.size());
                            string godAlignment = deityAlignments[rand() % 8];
                            string domains = "";
                            int domainNumber = 1 + rand() % 6;
                            for (int i = 0; i < domainNumber; i++)
                            {
                                domains += ", " + deityDomains[rand() % 54];
                            }
                            string godDesc = godName + ", " + godAlignment + " deity" + domains;
                            newCulture.religion += "\n                   " + godDesc;
                    }
                    if (religionNumber == 1)
                    {
                            //Polytheism
                            int randomNumber = 2 + rand() % 19;
                            for (int i = 0; i < randomNumber; i++)
                            {
                                string godName = worldLanguage.at(rand() % worldLanguage.size());
                                string godAlignment = deityAlignments[rand() % 8];
                                string domains = "";
                                int domainNumber = 1 + rand() % 6;
                                for (int i = 0; i < domainNumber; i++)
                                {
                                    domains += ", " + deityDomains[rand() % 54];
                                }
                                string godDesc = godName + ", " + godAlignment + " deity" + domains;
                                newCulture.religion += "\n                   " + godDesc;
                            }
                    }
                    if (religionNumber == 2)
                    {
                            //Dualism
                            string godName1 = worldLanguage.at(rand() % worldLanguage.size());
                            string godAlignment1 = deityAlignments[rand() % 8];
                            string godName2 = worldLanguage.at(rand() % worldLanguage.size());
                            string godAlignment2 = deityAlignments[rand() % 8];

                            string domains1 = "";
                            string domains2 = "";
                            int domainNumber = 1 + rand() % 6;
                            for (int i = 0; i < domainNumber; i++)
                            {
                                int domainNum = rand() % 54;
                                int domainNum2;
                                if (domainNum < 27)
                                    domainNum2 = domainNum + 27;
                                else
                                    domainNum2 = domainNum - 27;

                                domains1 += ", " + deityDomains[domainNum];
                                domains2 += ", " + deityDomains[domainNum2];
                            }
                            string godDesc1 = godName1 + ", " + godAlignment1 + " deity" + domains1;
                            newCulture.religion += "\n                   " + godDesc1;

                            string godDesc2 = godName2 + ", " + godAlignment2 + " deity" + domains2;
                            newCulture.religion += "\n                   " + godDesc2;
                    }

                    //Magic

                    if (rand() % 100 < 90)
                    {
                        newCulture.magicType = magic[magicLevel];
                    }
                    else
                    {
                        int mageVar = magicVariance;
                        mageVar *= 2;
                        //cout << "mageVar: " << mageVar << endl;
                        //cout << "magicLevel: " << magicLevel << endl;
                        //cout << "magicVariance: " << magicVariance << endl;

                        int regionMagicLevel;
                        if (mageVar == 0)
                           regionMagicLevel = magicLevel;
                        else
                            regionMagicLevel = (magicLevel - magicVariance) + (rand() % abs(mageVar));
                        //cout << "Region Magic Level " << regionMagicLevel << endl;

                        //cout << "mageVar " << mageVar << endl;
                        if (regionMagicLevel < 7 && regionMagicLevel >= 0)
                        {
                            newCulture.magicType = magic[regionMagicLevel];
                        }
                        else
                            newCulture.magicType = magic[magicLevel];
                    }

                    if (rand() % 100 < 80)
                    {
                        newCulture.magicRelationship = magicAttitudes[magicAttitudesNum];
                    }
                    else
                    {
                        int mageVar = magicAttitudesVariance;
                        mageVar *= 2;

                        //cout << "mageVar: " << mageVar << endl;
                        //cout << "magicLevel: " << magicLevel << endl;
                        //cout << "magicAttitudesVariance: " << magicAttitudesVariance << endl;
                        int regionMagicLevel;
                        if (mageVar == 0)
                            regionMagicLevel = magicAttitudesNum;
                        else
                            regionMagicLevel = (magicAttitudesNum-magicAttitudesVariance) + (rand() % abs(mageVar));// + (rand() % (2 * magicAttitudesVariance));
                        if (regionMagicLevel < 7 && regionMagicLevel >= 0)
                        {
                            newCulture.magicRelationship = magicAttitudes[regionMagicLevel];
                        }
                        else
                            newCulture.magicRelationship = magicAttitudes[magicAttitudesNum];
                    }

                    //Tech

                    if (rand() % 100 < 90)
                    {
                        newCulture.techType = technology[technologyLevel];
                    }
                    else
                    {
                        int techVar = technologyVariance;
                        techVar *= 2;
                        int regionTechLevel;
                        if (techVar == 0)
                            regionTechLevel = technologyLevel;
                        else
                            regionTechLevel = (technologyLevel-technologyVariance) + (rand() % abs(techVar));// + (rand() % (2 * technologyVariance));
                        if (regionTechLevel < 7 && regionTechLevel >= 0)
                        {
                            newCulture.techType = technology[regionTechLevel];
                        }
                        else
                            newCulture.techType = technology[technologyLevel];
                    }



                    if (rand() % 100 < 90)
                    {
                        newCulture.techRelationship = technologyAttitudes[technologyAttitudesNum];
                    }
                    else
                    {
                        int techVar = technologyAttitudesVariance;
                        techVar *= 2;
                        int regionTechLevel;
                        if (techVar == 0)
                            regionTechLevel = technologyVariance;
                        else
                            regionTechLevel = (technologyLevel-technologyVariance) + (rand() % abs(techVar));// + (rand() % (2 * technologyAttitudesVariance));
                        if (regionTechLevel < 7 && regionTechLevel >= 0)
                        {
                            newCulture.techRelationship = magicAttitudes[regionTechLevel];
                        }
                        else
                            newCulture.techRelationship = magicAttitudes[technologyAttitudesNum];
                    }


                    newBiome.cultures.push_back(newCulture);
                }
                for (int i = 0; i < cultNum; i++)
                {
                    //Input cultures to description
                    biomeDesc += "\n         The " + newBiome.cultures.at(i).name + " People";
                    biomeDesc += "\n                 " + newBiome.cultures.at(i).government;
                    biomeDesc += "\n                 " + newBiome.cultures.at(i).economy;
                    biomeDesc += "\n                 Diet: " + newBiome.cultures.at(i).food;
                    biomeDesc += "\n                 Religion: " + newBiome.cultures.at(i).religion;
                    biomeDesc += "\n                 Magic: " + newBiome.cultures.at(i).magicType;
                    biomeDesc += "\n                 Magic attitude: " + newBiome.cultures.at(i).magicRelationship;
                    biomeDesc += "\n                 Tech: " + newBiome.cultures.at(i).techType;
                    biomeDesc += "\n                 Tech attitude: " + newBiome.cultures.at(i).techRelationship;
                    //biomeDesc += "\n";
                }
            }

            biomeDesc += "\n";
            newBiome.description = biomeDesc;

            newContinent.biomes.push_back(newBiome);
        }
        cout << "Generated land of " << newContinent.name << "." << endl;

        continentsList.push_back(newContinent);
    }
    string continentDescription = "There are " + patch::to_string(continentsList.size()) + " continents.";
    for (unsigned int i = 0; i < continentsList.size(); i++)
    {
        continentDescription += "\n-----------------------------";
        continentDescription += "\nThe land of " + continentsList.at(i).name;
        continentDescription += "\nArea (km): " + patch::to_string(continentsList.at(i).area);
        if (continentsList.at(i).biomes.size() != 0)
        {
            continentDescription += "\nRegions: ";
            for (unsigned int j = 0; j < continentsList.at(i).biomes.size(); j++)
            {
                continentDescription += "\n     " + continentsList.at(i).biomes.at(j).name + " Region - " + continentsList.at(i).biomes.at(j).description;
            }
        }

        continentDescription += "\n";
    }


    //Output
    myFile << "-----" << worldName << " world-----" << endl;
    myFile << endl;
    myFile << "--------------------------------------------" << endl;
    myFile << "-----MAGIC-----" << endl;
    myFile << "--------------------------------------------" << endl;
    myFile << magicDescription << endl;
    myFile << magicSourceDescription << endl;
    myFile << magicAttitudesDescription << endl;
    myFile << "--------------------------------------------" << endl;
    myFile << "--TECHNOLOGY --" << endl;
    myFile << "--------------------------------------------" << endl;
    myFile << technologyDescription << endl;
    myFile << technologySourceDescription << endl;
    myFile << technologyAttitudesDescription << endl;
    myFile << "--------------------------------------------" << endl;
    myFile << "----CLIMATE----" << endl;
    myFile << "--------------------------------------------" << endl;
    myFile << temperatureDescription << endl;
    myFile << vegetationDescription << endl;
    myFile << oceanDescription << endl;
    myFile << "--------------------------------------------" << endl;
    myFile << "--CONTINENTS --" << endl;
    myFile << "--------------------------------------------" << endl;
    myFile << continentDescription << endl;

    cout << worldName << " complete!" << endl;
    myFile.close();
    return fileName;
}





vector <string> CreateWorld::generateLanguage(int consStartCount, int consEndCount, int maxVowels, int syllableFrequency)
{
    vector <string> languageResult;
    char vowelsChar[] = { 'a', 'e', 'i', 'o', 'u'};
    char consonantsChar[] = { 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z' };
    vector <char> vowels;
    vector <char> commonConsonants;
    vector <char> uncommonConsonants;
    vector <char> rareConsonants;

    for (int i = 0; i < 5; i++) //Chooses vowels
    {
        if (rand() % 10 != 0)
            vowels.push_back(vowelsChar[i]);
    }

    while (commonConsonants.size() == 0 || uncommonConsonants.size() == 0 || rareConsonants.size() == 0) //Sorts consonants
    {
        commonConsonants.clear();
        uncommonConsonants.clear();
        rareConsonants.clear();

        for (int i = 0; i < 21; i++)
        {
            int choice = rand() % 10;
            if (choice < 3)
            {
                commonConsonants.push_back(consonantsChar[i]);
            }
            else if (choice < 6)
            {
                uncommonConsonants.push_back(consonantsChar[i]);
            }
            else if (choice < 9)
            {
                rareConsonants.push_back(consonantsChar[i]);
            }
        }
    }

    for (int i = 0; i < 1000; i++)
    {
        string newWord = "";
        bool firstLetter = true;
        int syllables = 1;
        if (syllableFrequency == 1)
        {
            syllables = 1;
        }
        else
        {
            syllables = 2 + (rand() % (syllableFrequency - 1));
        }

        int vowelCount = 0;

        for (int j = 0; j < syllables; j++)
        {
            if (vowelCount >= maxVowels)
            {
                //gen consonant
                int randomResult = rand() % 10;
                if (randomResult < 5)
                {
                    if (firstLetter)
                    {
                        newWord += toupper(commonConsonants.at(rand() % commonConsonants.size()));
                        firstLetter = false;
                    }
                    else
                        newWord += commonConsonants.at(rand() % commonConsonants.size());
                }
                else if (randomResult < 8)
                {
                    if (firstLetter)
                    {
                        newWord += toupper(uncommonConsonants.at(rand() % uncommonConsonants.size()));
                        firstLetter = false;
                    }
                    else
                        newWord += uncommonConsonants.at(rand() % uncommonConsonants.size());
                }
                else
                {
                    if (firstLetter)
                    {
                        newWord += toupper(rareConsonants.at(rand() % rareConsonants.size()));
                        firstLetter = false;
                    }
                    else
                        newWord += rareConsonants.at(rand() % rareConsonants.size());
                }
                vowelCount = 0;
            }
            else if (consStartCount != 0)
            {
                //potentially gen consonant
                if (rand() % consStartCount != 0)
                {
                    int randomResult = rand() % 10;
                    if (randomResult < 5)
                    {
                        if (firstLetter)
                        {
                            newWord += toupper(commonConsonants.at(rand() % commonConsonants.size()));
                            firstLetter = false;
                        }
                        else
                            newWord += commonConsonants.at(rand() % commonConsonants.size());
                    }
                    else if (randomResult < 8)
                    {
                        if (firstLetter)
                        {
                            newWord += toupper(uncommonConsonants.at(rand() %uncommonConsonants.size()));
                            firstLetter = false;
                        }
                        else
                            newWord += uncommonConsonants.at(rand() % uncommonConsonants.size());
                    }
                    else
                    {
                        if (firstLetter)
                        {
                            newWord += toupper(rareConsonants.at(rand() % rareConsonants.size()));
                            firstLetter = false;
                        }
                        else
                            newWord += rareConsonants.at(rand() % rareConsonants.size());
                    }
                    vowelCount = 0;
                }

            }

            //gen vowel
            if (firstLetter)
            {
                newWord += toupper(vowels.at(rand() % vowels.size()));
                firstLetter = false;
            }
            else
                newWord += vowels.at(rand() % vowels.size());

            vowelCount++;

            if (vowelCount < maxVowels)
            {
                //potentially gen another vowel
                if (rand() % 20 == 0)
                {
                    newWord += vowels.at(rand() % vowels.size());
                    vowelCount++;
                }
            }

            //potentially gen consonant
            if (consEndCount != 0)
            {
                //potentially gen consonant
                if (rand() % consEndCount != 0)
                {
                    int randomResult = rand() % 10;
                    if (randomResult < 5)
                    {
                        newWord += commonConsonants.at(rand() % commonConsonants.size());
                    }
                    else if (randomResult < 8)
                    {
                        newWord += uncommonConsonants.at(rand() % uncommonConsonants.size());
                    }
                    else
                    {
                        newWord += rareConsonants.at(rand() % rareConsonants.size());
                    }
                    vowelCount = 0;
                }

            }
        }

        languageResult.push_back(newWord);
    }

    return languageResult;
}

