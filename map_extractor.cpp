/* *********************************************
 * DBC Extractor
 *
 * Author: Chuck E
 * Date: 11 Feb 2016
 *
 */

#include "map_extractor.h"



int main(int argc, char* arg[])
{
    // identify the build of the exe

    int iWoWExeBuildNumber = 0;
    std::string sLocale;

    if ((iWoWExeBuildNumber = getBuildNumber()) != NULL)
    {
        // output the build number of the WoW exe
        std::cout << "Exe build number: " << iWoWExeBuildNumber << std::endl << std::endl << std::endl << std::endl;

        sLocale = getLocale();

        // output the build number of the WoW exe
        std::cout << "Returned locale: " << sLocale << std::endl << std::endl;
        int iCore = getCoreNumber();
        std::cout << "Returned core: " << iCore << std::endl << std::endl;

        // make sure we have a valid locale if the core is not Classic
        // this is required for accessing the locale folder and certain files.
        if (iCore != CLIENT_CLASSIC && sLocale == "")
        {
            std::cout << "ERROR: Unable to identify your client's locale! " << std::endl;
            std::cout << "You must have a Config.wtf file in the WTF folder with the line:" << std::endl;
            std::cout << "SET locale <your locale>" << std::endl << std::endl;
            std::cout << "<your locale> will be in quotes and be something like enCN, enUS, enRU, etc." << std::endl << std::endl;

            // an error occured, exit the program
            return 0;
        }
        
        // we can now deal with all the required MPQ files for DBC, MAPS, VMAPS, and MMAPS
        processTheMPQFiles(iCore, sLocale);

    }
    else // failed to locate the WoW executable
        std::cout << "The WoW exe file could not be found!!!" << std::endl << std::endl;

    std::cout << std::endl << "ALL DONE!!!" << std::endl << std::endl;

    int input = 0;
    std::cin >> input;

    return 0;
}
