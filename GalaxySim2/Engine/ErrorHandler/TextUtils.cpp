#include "TextUtils.h"

namespace Console {
	const HANDLE TextUtils::handle = GetStdHandle(STD_OUTPUT_HANDLE);
	void TextUtils::redText(const std::string& text)
	{
		SetConsoleTextAttribute(handle, TextColor::RED);
		std::cout << text << std::endl;
		SetConsoleTextAttribute(handle, TextColor::WHITE);

	}
	void TextUtils::yellowText(const std::string& text)
	{
		SetConsoleTextAttribute(handle, TextColor::YELLOW);
		std::cout << text << std::endl;
		SetConsoleTextAttribute(handle, TextColor::WHITE);
	}
	void TextUtils::whiteText(const std::string& text)
	{
		SetConsoleTextAttribute(handle, TextColor::WHITE);
		std::cout << text << std::endl;
	}

	void TextUtils::errorText(const std::string& text)
	{
		std::string error = "[ERROR]:";
		std::string result = error + text;
		TextUtils::redText(result);
	}
	void TextUtils::warningText(const std::string& text)
	{
		std::string error = "[WARNING]:";
		std::string result = error + text;
		TextUtils::yellowText(result);
	}
	void TextUtils::noteText(const std::string& text)
	{
		std::string error = "[NOTE]:";
		std::string result = error + text;
		TextUtils::whiteText(result);
	}
}