Just a simple wrapper library for SDL 2.0.3 for quickly starting an SDL-based application. Mainly for personal use so don't expect anything too complicated or documented here.

--------------------
Library Requirements
--------------------

SDL 2.0.3+ (download available below)
https://www.libsdl.org/download-2.0.php
- download the development libraries, store someplace
- put SDL2.dll into the same folder as the executable


--------------------
Visual Studio Setup
--------------------

Properties > Configuration Properties > VC++ Directories > Include Directories
- "[SDL folder]/include/"

Properties > Configuration Properties > VC++ Directories > Library Directories
"[SDL folder]/lib/x86" or "[SDL folder]/lib/x64", depending on application type

Properties > Configuration Properties > Linker > Input > Additional Dependencies
- "SDL2.lib;SDL2main.lib;"

Properties > Configuration Properties > Linker > System > SubSystem
- 'Console' if you want it to show up, 'Windows' otherwise

Properties > Configuration Properties > C/C++ > Code Generation > Runtime Library
- change it to 'Multi-threaded DLL (/MD)'