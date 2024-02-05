#pragma once

#include "all.hpp"
#include "range.hpp"

namespace sdss::memory
{
	class module : public range
	{
	public:
		module(HMODULE mod);
		explicit module(std::nullptr_t);
		explicit module(std::string_view name);
		explicit module(std::wstring_view name);

		memory::handle get_export(std::string_view symbol_name);
	};
}
