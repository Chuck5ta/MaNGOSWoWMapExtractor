#pragma once

#include <direct.h>
#include <iostream>
#include "MaNGOS_map.h"
#include "ExtractorCommon.h"
#include "TypeConversion.h"

/*
* this function extracts a single DBC file from the dbc.MPQ archive and writes it to the disk
*
* @PARAM HANDLE hCurrentDBCFile;    // handle to the archived dbc file currently being processed
* @PARAM HANDLE hDiskFile;          // handle to the dbc file that will be created on disk
* @PARAM SFILE_FIND_DATA pFile;     // a pointer to the current dbc file in the dbc.MPQ archive
*
*/
void extractFile(HANDLE hCurrentDBCFile, HANDLE hDiskFile, SFILE_FIND_DATA pFile);

/*
 * This function applies all the patches to the current file
 *
 * @PARAM iCore the game version (Classic, TBC, WOTLK, etc)
 * @PARAM sFileType the type of file being processed (dbc, adt, wmo, etc.)
 * @PARAM hMPQArchiveFile the handle to the MPQ archive
 * @PARAM sLocale the locale of the client (enFR, enUS, enRU, etc.)
 */
void addPatchFiles(int iCore, std::string sFileType, HANDLE hMPQArchiveFile, std::string sLocale);

/*
 * This function extracts a file from the dbc.MPQ archive.
 *
 * @PARAM iCore the game version (Classic, TBC, WOTLK, etc)
 * @PARAM sFileType the type of file being processed (dbc, adt, wmo, etc.)
 * @PARAM hMPQArchiveFile the handle to the MPQ archive
 * @PARAM sLocale the locale of the client (enFR, enUS, enRU, etc.)
 */
void processMPQFile(int iCore, std::string sFileType, std::string sDestinationFolder, std::string sLocale, std::string sMPQFileName);


/*
* This function starts off the processing of all the MPQ archivs.
*
* @PARAM iCore the game version (Classic, TBC, WOTLK, etc)
* @PARAM sLocale the locale of the client (enFR, enUS, enRU, etc.)
*/
void processTheMPQFiles(unsigned int iCore, std::string sLocale);