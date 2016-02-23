/* *********************************************
* MPQarchive.cpp
*
* Author: Chuck E
* Date: 19 Feb 2016
*
*/

#include "MPQarchive.h"
#include "StormLib.h"


char * pDBCfolder = "./dbc/";
char * pMAPSfolder = "./maps/";
char * pVMAPSfolder = "./vmaps/";
char * pMMAPSfolder = "./mmaps/";


/**
* this function extracts a single DBC file from the dbc.MPQ archive and writes it to the disk
*
* @PARAM HANDLE hCurrentDBCFile;    // handle to the archived dbc file currently being processed
* @PARAM HANDLE hDiskFile;          // handle to the dbc file that will be created on disk
* @PARAM SFILE_FIND_DATA pFile;     // a pointer to the current dbc file in the dbc.MPQ archive
*
*/
void extractFile(HANDLE hCurrentDBCFile, HANDLE hDiskFile, SFILE_FIND_DATA pFile)
{
    char  szBuffer[0x10000];
    DWORD dwBytes = 1;

    // extract the file and write it to the disk
    while (dwBytes > 0)
    {
        // extract the dbc file's contents from the MPQ archive
        SFileReadFile(hCurrentDBCFile, szBuffer, sizeof(szBuffer), &dwBytes, NULL);
        if (dwBytes > 0)
            // write the contents to the new file on disk
            if (WriteFile(hDiskFile, szBuffer, dwBytes, &dwBytes, NULL))
                std::cout << "File extraction successful, creating file:  " << pFile.cFileName << std::endl;
            else
                std::cout << "Failed to write the file to the disk:  " << pFile.cFileName << std::endl;
    }
}

/*
* This function adds all the required patches to an open MPQ archive
*
* @PARAM iCore the game version (Classic, TBC, WOTLK, etc)
* @PARAM sFileType the type of file being processed (dbc, adt, wmo, etc.)
* @PARAM hMPQArchiveFile the handle to the MPQ archive
* @PARAM sLocale the locale of the client (enFR, enUS, enRU, etc.)
*/
void addPatchFiles(unsigned int iCore, std::string sFileType, HANDLE hMPQArchiveFile, std::string sLocale)
{
    std::cout << "Adding patch files, please wait" << std::endl << std::endl;

    if (iCore == CLIENT_CLASSIC)
    {
        if (sFileType == "dbc")
        {
            if (!SFileOpenPatchArchive(hMPQArchiveFile, "./Data/patch.MPQ", "", NULL))
            {
                std::cout << "Failed to add patch archive: " << "patch.MPQ" << " file!!!" << std::endl << std::endl;
            }
            if (!SFileOpenPatchArchive(hMPQArchiveFile, "./Data/patch-2.MPQ", "", NULL))
            {
                std::cout << "Failed to add patch archive: " << "patch-2.MPQ" << " file!!!" << std::endl << std::endl;
            }
        }
        else if (sFileType == "adt")
        {
            if (!SFileOpenPatchArchive(hMPQArchiveFile, "./Data/patch.MPQ", "", NULL))
            {
                std::cout << "Failed to add patch archive: " << "patch.MPQ" << " file!!!" << std::endl << std::endl;
            }
            if (!SFileOpenPatchArchive(hMPQArchiveFile, "./Data/patch-2.MPQ", "", NULL))
            {
                std::cout << "Failed to add patch archive: " << "patch-2.MPQ" << " file!!!" << std::endl << std::endl;
            }
        }
    }

    if (iCore >= CLIENT_TBC && iCore <= CLIENT_WOTLK && sFileType == "dbc")
    {
        if (!SFileOpenPatchArchive(hMPQArchiveFile, ("./Data/" + sLocale + "/patch-" + sLocale + ".MPQ").c_str(), "", NULL))
        {
            std::cout << "Failed to add patch archive: " << "patch.MPQ" << " file!!!" << std::endl << std::endl;
        }
        if (!SFileOpenPatchArchive(hMPQArchiveFile, ("./Data/" + sLocale + "/patch-" + sLocale + "-2.MPQ").c_str(), "", NULL))
        {
            std::cout << "Failed to add patch archive: " << "patch-2.MPQ" << " file!!!" << std::endl << std::endl;
        }
    }

    if (iCore == CLIENT_WOTLK && sFileType == "dbc")
    {
        if (!SFileOpenPatchArchive(hMPQArchiveFile, ("./Data/" + sLocale + "/patch-" + sLocale + "-3.MPQ").c_str(), "", NULL))
        {
            std::cout << "Failed to add patch archive: " << "patch-3.MPQ" << " file!!!" << std::endl << std::endl;
        }
    }

    if (iCore == CLIENT_CATA && sFileType == "dbc")
    {
        if (!SFileOpenPatchArchive(hMPQArchiveFile, ("./Data/" + sLocale + "/wow-update-" + sLocale + "-15211.MPQ").c_str(), "", NULL))
        {
            std::cout << "Failed to add patch archive: " << "wow-update-???-15211.MPQ" << " file!!!" << std::endl << std::endl;
        }

        if (!SFileOpenPatchArchive(hMPQArchiveFile, ("./Data/" + sLocale + "/wow-update-" + sLocale + "-15354.MPQ").c_str(), "", NULL))
        {
            std::cout << "Failed to add patch archive: " << "wow-update-???-15354.MPQ" << " file!!!" << std::endl << std::endl;
        }

        if (!SFileOpenPatchArchive(hMPQArchiveFile, ("./Data/" + sLocale + "/wow-update-" + sLocale + "-15595.MPQ").c_str(), "", NULL))
        {
            std::cout << "Failed to add patch archive: " << "wow-update-???-15595.MPQ" << " file!!!" << std::endl << std::endl;
        }

    }

    if (iCore == CLIENT_MOP && sFileType == "dbc")
    {
        if (!SFileOpenPatchArchive(hMPQArchiveFile, ("./Data/" + sLocale + "/wow-update-" + sLocale + "-16016.MPQ").c_str(), "", NULL))
        {
            std::cout << "Failed to add patch archive: " << "wow-update-???-16016.MPQ" << " file!!!" << std::endl << std::endl;
        }
        if (!SFileOpenPatchArchive(hMPQArchiveFile, ("./Data/" + sLocale + "/wow-update-" + sLocale + "-16048.MPQ").c_str(), "", NULL))
        {
            std::cout << "Failed to add patch archive: " << "wow-update-???-16048.MPQ" << " file!!!" << std::endl << std::endl;
        }
        if (!SFileOpenPatchArchive(hMPQArchiveFile, ("./Data/" + sLocale + "/wow-update-" + sLocale + "-16057.MPQ").c_str(), "", NULL))
        {
            std::cout << "Failed to add patch archive: " << "wow-update-???-16057.MPQ" << " file!!!" << std::endl << std::endl;
        }
        if (!SFileOpenPatchArchive(hMPQArchiveFile, ("./Data/" + sLocale + "/wow-update-" + sLocale + "-16309.MPQ").c_str(), "", NULL))
        {
            std::cout << "Failed to add patch archive: " << "wow-update-???-16309.MPQ" << " file!!!" << std::endl << std::endl;
        }
        if (!SFileOpenPatchArchive(hMPQArchiveFile, ("./Data/" + sLocale + "/wow-update-" + sLocale + "-16357.MPQ").c_str(), "", NULL))
        {
            std::cout << "Failed to add patch archive: " << "wow-update-???-16357.MPQ" << " file!!!" << std::endl << std::endl;
        }
        if (!SFileOpenPatchArchive(hMPQArchiveFile, ("./Data/" + sLocale + "/wow-update-" + sLocale + "-16516.MPQ").c_str(), "", NULL))
        {
            std::cout << "Failed to add patch archive: " << "wow-update-???-16516.MPQ" << " file!!!" << std::endl << std::endl;
        }
        if (!SFileOpenPatchArchive(hMPQArchiveFile, ("./Data/" + sLocale + "/wow-update-" + sLocale + "-16650.MPQ").c_str(), "", NULL))
        {
            std::cout << "Failed to add patch archive: " << "wow-update-???-16650.MPQ" << " file!!!" << std::endl << std::endl;
        }
        if (!SFileOpenPatchArchive(hMPQArchiveFile, ("./Data/" + sLocale + "/wow-update-" + sLocale + "-16844.MPQ").c_str(), "", NULL))
        {
            std::cout << "Failed to add patch archive: " << "wow-update-???-16844.MPQ" << " file!!!" << std::endl << std::endl;
        }
        if (!SFileOpenPatchArchive(hMPQArchiveFile, ("./Data/" + sLocale + "/wow-update-" + sLocale + "-16965.MPQ").c_str(), "", NULL))
        {
            std::cout << "Failed to add patch archive: " << "wow-update-???-16965.MPQ" << " file!!!" << std::endl << std::endl;
        }
        if (!SFileOpenPatchArchive(hMPQArchiveFile, ("./Data/" + sLocale + "/wow-update-" + sLocale + "-17116.MPQ").c_str(), "", NULL))
        {
            std::cout << "Failed to add patch archive: " << "wow-update-???-17116.MPQ" << " file!!!" << std::endl << std::endl;
        }
        if (!SFileOpenPatchArchive(hMPQArchiveFile, ("./Data/" + sLocale + "/wow-update-" + sLocale + "-17266.MPQ").c_str(), "", NULL))
        {
            std::cout << "Failed to add patch archive: " << "wow-update-???-17266.MPQ" << " file!!!" << std::endl << std::endl;
        }
        if (!SFileOpenPatchArchive(hMPQArchiveFile, ("./Data/" + sLocale + "/wow-update-" + sLocale + "-17325.MPQ").c_str(), "", NULL))
        {
            std::cout << "Failed to add patch archive: " << "wow-update-???-17325.MPQ" << " file!!!" << std::endl << std::endl;
        }
        if (!SFileOpenPatchArchive(hMPQArchiveFile, ("./Data/" + sLocale + "/wow-update-" + sLocale + "-17345.MPQ").c_str(), "", NULL))
        {
            std::cout << "Failed to add patch archive: " << "wow-update-???-17345.MPQ" << " file!!!" << std::endl << std::endl;
        }
        if (!SFileOpenPatchArchive(hMPQArchiveFile, ("./Data/" + sLocale + "/wow-update-" + sLocale + "-17538.MPQ").c_str(), "", NULL))
        {
            std::cout << "Failed to add patch archive: " << "wow-update-???-17538.MPQ" << " file!!!" << std::endl << std::endl;
        }
        if (!SFileOpenPatchArchive(hMPQArchiveFile, ("./Data/" + sLocale + "/wow-update-" + sLocale + "-17645.MPQ").c_str(), "", NULL))
        {
            std::cout << "Failed to add patch archive: " << "wow-update-???-17645.MPQ" << " file!!!" << std::endl << std::endl;
        }
        if (!SFileOpenPatchArchive(hMPQArchiveFile, ("./Data/" + sLocale + "/wow-update-" + sLocale + "-17688.MPQ").c_str(), "", NULL))
        {
            std::cout << "Failed to add patch archive: " << "wow-update-???-17688.MPQ" << " file!!!" << std::endl << std::endl;
        }
        if (!SFileOpenPatchArchive(hMPQArchiveFile, ("./Data/" + sLocale + "/wow-update-" + sLocale + "-17898.MPQ").c_str(), "", NULL))
        {
            std::cout << "Failed to add patch archive: " << "wow-update-???-17898.MPQ" << " file!!!" << std::endl << std::endl;
        }
        if (!SFileOpenPatchArchive(hMPQArchiveFile, ("./Data/" + sLocale + "/wow-update-" + sLocale + "-18273.MPQ").c_str(), "", NULL))
        {
            std::cout << "Failed to add patch archive: " << "wow-update-???-18273.MPQ" << " file!!!" << std::endl << std::endl;
        }

    }

}

/**
* This function
*
* @PARAM sFileType is the file to search for (dbc, adt, wmo, etc.)
*
*/
void processMPQFile(unsigned int iCore, std::string sFileType, std::string sDestinationFolder, std::string sLocale, std::string sMPQFileName)
{
    HANDLE hMPQArchiveFile;    // handle to the dbc.MPQ archive
    HANDLE hDBCFirstFile;      // handle to the first file in the dbc.MPQ archive
    HANDLE hDBCNextFile;       // handle to each of the archived files after the first file
    SFILE_FIND_DATA pFile;     // a pointer to the current dbc file in the dbc.MPQ archive

                               // open the MPQ archive, so that we can extract the dbc files
    if (!SFileOpenArchive(sMPQFileName.c_str(), 0, MPQ_OPEN_READ_ONLY, &hMPQArchiveFile))
        std::cout << "Balls, cannot locate the " << sMPQFileName << " file!!!" << std::endl << std::endl;
    else
    {
        std::cout << "Yay, located the MPQ file!" << std::endl << std::endl;

        // add patch files
  //      addPatchFiles(iCore, sFileType, hMPQArchiveFile, sLocale);

        // go through the archive and extract each file
        // ============================================

        // we need to deal with the first file, then we can process each of the remaining files
        if ((hDBCFirstFile = SFileFindFirstFile(hMPQArchiveFile, ("*." + sFileType).c_str(), &pFile, 0)) != NULL)
        {
            std::cout << "File: " << pFile.szPlainName << std::endl;
            std::cout << "=============" << std::endl;

            // open the file in the MPQ archive
            if (SFileOpenFileEx(hMPQArchiveFile, pFile.cFileName, 0, &hDBCFirstFile))
            {
                std::cout << "Successfully openned the first file:  " << pFile.szPlainName << std::endl;

                ExtractMapFromMpq(hDBCFirstFile, pFile, iCore);


                int i;
                std::cin >> i;


                // grab the rest of the dbc files
                // ==============================

                while (SFileFindNextFile(hDBCFirstFile, &pFile))
                {
                    std::cout << "File: " << pFile.cFileName << std::endl;

                    // open the dbc file in the MPQ archive
                    if (SFileOpenFileEx(hMPQArchiveFile, pFile.cFileName, 0, &hDBCNextFile))
                    {
                        std::cout << "Successfully openned the file:  " << pFile.cFileName << std::endl;


                        ExtractMapFromMpq(hDBCNextFile, pFile, iCore);


                    }
                    else
                        std::cout << "Failed to open the archive file:  " << pFile.cFileName << std::endl;
                }
                // Cleanup and exit
                if (hDBCNextFile != NULL)
                    CloseHandle(hDBCNextFile);
            }
            else
            {
                std::cout << "Failed to open the archived file:  " << pFile.cFileName << std::endl;
            }
            if (hDBCFirstFile != NULL)
                CloseHandle(hDBCFirstFile);
        }
        else
        {
            std::cout << "There were no files of the type found in the archive!!! " << std::endl;
        }
        // Cleanup and exit
        if (hMPQArchiveFile != NULL)
            CloseHandle(hMPQArchiveFile);
    }
}

/**
* This function starts off the processing of all of the MPQ files that hold DBC (.dbc), MAPS (.adt), VMAPS (.wom), and MMAPS files
*
* @PARAM iCore the game version of the exe (Classic, TBC, WOTLK, etc)
* @PARAM sLocale the locale of the client (enUS, enFR, enGB, etc.)
*/
void processTheMPQFiles(unsigned int iCore, std::string sLocale)
{
    // process MAP files
    mkdir("./maps");

    if (iCore == CLIENT_CLASSIC) // Classic
    {
        processMPQFile(iCore, "adt", pMAPSfolder, sLocale, "./Data/terrain.MPQ");
    }


    // process VMAP files
    // process MMAP files
}