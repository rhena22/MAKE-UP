@echo off
g++ -std=c++11 -Wall -Wextra main.cpp Product.cpp Catalog.cpp ProductTree.cpp Cart.cpp OrderQueue.cpp UndoStack.cpp BrandList.cpp Sorting.cpp Input.cpp Display.cpp Cleanup.cpp Menus.cpp -o makeup.exe
if errorlevel 1 (echo BUILD FAILED) else (echo BUILD OK - running... & makeup.exe)
pause
