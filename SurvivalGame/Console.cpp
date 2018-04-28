#include "Console.h"

HANDLE Console::handle = GetStdHandle(STD_OUTPUT_HANDLE);

void Console::showCursor(bool show) {
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(handle, &cursorInfo);
	cursorInfo.bVisible = show;
	SetConsoleCursorInfo(handle, &cursorInfo);
}
