#pragma once

#include "i_screen.hpp"
#include "logger.hpp"

namespace App
{
class Screen5: public IScreen
{
public:
	Screen5(const std::string_view &title, const ImVec2 &size)
		: IScreen(title, size)
	{
		logger.debug("Constructor {}", get_title());
	}
	void render() override
	{
		Widget::TextView(get_title(), Font::Size::_36px, Widget::Layout::Position::WINDOW_CENTER);
	}
};
}