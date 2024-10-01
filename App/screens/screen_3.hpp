#pragma once

#include "i_screen.hpp"
#include "logger.hpp"

namespace App
{
class Screen3: public IScreen
{

public:
	Screen3(const std::string_view &title, const ImVec2 &size)
		: IScreen(title, size)
	{
		logger.debug("Constructor {}", get_title());
	}
	void render() override
	{
		Widget::TextView(get_title(), Font::Size::DEFAULT, Widget::Layout::Position::WINDOW_CENTER);
	}
};
}