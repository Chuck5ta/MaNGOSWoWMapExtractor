/* *********************************************
* MaNGOS_map.cpp
*
* Author: Chuck E
* Date: 19 Feb 2016
*
*/

#include "MaNGOS_map.h"


/**
* @brief
*
* @param filename
* @param filename2
* @param build
* @return bool
*/
bool ConvertADT(HANDLE hFileHandle, char* pADTFileName, std::string sDestinationFileName, unsigned int build)
{

    return true;
}


void ExtractMapFromMpq(HANDLE hFile, SFILE_FIND_DATA pFile, unsigned int uBuild)
{
    std::cout << "converting file: " << pFile.cFileName << std::endl;

    ConvertADT(hFile, pFile.cFileName, concatStrings("./maps/", pFile.szPlainName), uBuild);


    std::cout << "Any joy? " << std::endl << std::endl;

    int i;
    std::cin >> i;

}









