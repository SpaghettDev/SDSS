#pragma once

#include "all.hpp"
#include "fwddec.hpp"
#include "handle.hpp"

namespace sdss::memory
{
	class pattern
	{
		friend pattern_batch;
		friend range;
	public:
		pattern(std::string_view ida_sig);
		explicit pattern(const void* bytes, std::string_view mask);

		inline pattern(const char* ida_sig) :
			pattern(std::string_view(ida_sig))
		{}
	private:
		std::vector<std::optional<std::uint8_t>> m_bytes;
	};
}