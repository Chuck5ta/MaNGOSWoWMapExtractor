# MaNGOSWoWMapExtractor
A map extractor for the getMaNGOS cores Zero (Classic) to Four (MoP).

This is required to convert the .adt map files that exist in the MPQ archives into MaNGOS .map files.

As an example, on Zero (Classic) this reduces the resulting file down to about 17% of its original size. This is done by only taking what is needed from the .adt files.

**NOT WORKING, AS YET**

Author: Chuck E (aka Chucksta)</br>
[getMaNGOS](https://www.getmangos.eu) developer
 
TOOL BUILT ON/WITH
---------------

**Programming language:**</br>
C++

**Compilers/IDE/Editors:** </br>
[CMAKE 3.3.0](https://cmake.org)</br>
[Visual Studio 2015](https://msdn.microsoft.com/en-us/library/dd831853.aspx)</br>
[Notepad++](https://notepad-plus-plus.org)</br>
[MarkdownPad 2](http://markdownpad.com)</br>

**O/S:**</br> 
MS Windows 7

**libraries:**</br>
StormLib 9.20</br>
[http://www.zezula.net/en/mpq/stormlib.html](http://www.zezula.net/en/mpq/stormlib.html)

**How to create the VS project:**

At a command prompt (cmd), go to the extractor's root folder. This is where the dbc_extractor.cpp file is, and enter:</br>
**cmake**

The Visual Studio solution will now be built.

**note:** you can build it from anywhere, you just need to direct cmake to the location of the cmakelists file.
e.g. from the build folder, you would type</br>
**cmake ..**

### REASON FOR BEING
---------------
A means to learn.