@echo off

:: You must have the VS command prompt env set up in your terminal or in the path to call cl
:: If you don't have it added to the path, try uncommenting the following line 
:: call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat" x64

 cl /Fo"./Output/8080EMU" /Fe"./Output/8080EMU" CPUShell.c