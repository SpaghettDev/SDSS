#pragma once

#include "all.hpp"
#include "pattern.hpp"

namespace sdss::memory
{
	class pattern_batch
	{
	public:
		explicit pattern_batch() = default;
		~pattern_batch() noexcept = default;

		void add(std::string name, pattern pattern, std::function<void(handle)> callback);
		void run(range region);

		struct entry
		{
			std::string m_name;
			pattern m_pattern;
			std::function<void(handle)> m_callback;

			explicit entry(std::string name, pattern pattern, std::function<void(handle)> callback) :
				m_name(name),
				m_pattern(pattern),
				m_callback(callback)
			{}
		};

	private:
		std::vector<entry> m_entries;
	};
}
