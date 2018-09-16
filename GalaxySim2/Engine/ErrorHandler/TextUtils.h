#pragma once
#include <iostream>
#include <string>
#include <windows.h>
namespace Console 
{
	class TextUtils {
	private:
		const static HANDLE handle;
	public:
		enum TextColor
		{
			RED = 12, YELLOW = 14, WHITE = 15
		};
		static void redText(const std::string& text);
		static void yellowText(const std::string& text);
		static void whiteText(const std::string& text);
		static void errorText(const std::string& text);
		static void warningText(const std::string& text);
		static void noteText(const std::string& text);
	};
}