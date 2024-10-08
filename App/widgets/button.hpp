#pragma once

#include <functional>
#include "i_widget.hpp"

namespace App::Widget
{
class Button: public IWidget
{
public:
	explicit Button(const std::string_view &label,
					const std::function<void()> &callback = nullptr)
	{
		m_callback = callback;
		set_label(label);
	}

	explicit Button(const std::string_view &label,
					const ImVec2 &size = ImVec2(0.0f, 0.0f),
					const ImVec2 &position = ImVec2(0.0f, 0.0f),
					const std::function<void()> &callback = nullptr)
	{
		m_callback = callback;
		set_label(label);
		set_size(size);
		set_position(position);
	}

	bool operator()()
	{
		render();
		return m_state;
	}

	bool operator()(const ImVec2 &size, const ImVec2 &position)
	{
		set_size(size);
		set_position(position);
		return operator()();
	}

	[[nodiscard]] inline bool get_state() const
	{
		return m_state;
	}

	inline void set_state(bool state)
	{
		m_state = state;
	}

	inline void toggle_state()
	{
		m_state = !m_state;
	}

private:
	void render() override
	{
		if (ImGui::Button(get_label().c_str(), get_size())) {
			assert(m_callback);
			m_callback();
		}
	}

private:
	bool m_state = false;
	std::function<void()> m_callback = nullptr;
	ImTextureID m_id = nullptr;
};
}