#pragma once

#include <Windows.h>
#include "Vector2D.h"

class Console {
public:
	inline static HANDLE getHandle() { return handle; }
	inline static CONSOLE_SCREEN_BUFFER_INFO getInfo() {
		static CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(handle, &info);
		return info;
	}
	inline static COORD getCursorPosition() { return getInfo().dwCursorPosition; }
	inline static void setCursorPosition(const COORD& position) { SetConsoleCursorPosition(handle, position); }
	inline static void setCursorPosition(const Vector2D& position) { SetConsoleCursorPosition(handle, { (SHORT)position.x, (SHORT)position.y }); }
	inline static void setCursorPosition(int x, int y) { SetConsoleCursorPosition(handle, { (SHORT)x, (SHORT)y }); }

private:
	Console();
	Console(const Console&) = delete;
	Console(Console&&) = delete;
	void operator=(const Console&) = delete;
	void operator=(Console&&) = delete;

	static HANDLE handle;
};

