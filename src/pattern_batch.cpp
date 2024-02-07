#include "all.hpp"
#include "pattern_batch.hpp"
#include "range.hpp"

#define HEX_TO_UPPER(value) "0x" << std::hex << std::uppercase << (DWORD64)value << std::dec << std::nouppercase

namespace sdss::memory
{
	void pattern_batch::add(std::string name, pattern pattern, std::function<void(handle)> callback)
	{
		m_entries.emplace_back(std::move(name), std::move(pattern), std::move(callback));
	}

	void pattern_batch::run(range region)
	{
		bool all_found = true;

		for (auto& entry : m_entries)
		{
			bool entry_found = true;

			if (auto result = region.scan(entry.m_pattern))
			{
				if (entry.m_callback)
				{
					std::invoke(entry.m_callback, result);
				}
				else
				{
					all_found = false;
					entry_found = false;
				}
			}
			else
			{
				all_found = false;
				entry_found = false;
			}

			if (!entry_found)
				throw std::runtime_error("Failed to find '" + entry.m_name + "'.");
		}

		m_entries.clear();

		if (!all_found)
			throw std::runtime_error("Failed to find some patterns.");
	}
}
