#ifndef INPUT_H
#define INPUT_H
#include <string>

std::string toStr(int n);
std::string toLower(std::string s);
int askInt(std::string msg, int lo, int hi);   // safe number input
std::string askText(std::string msg);
#endif
