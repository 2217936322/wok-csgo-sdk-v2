#pragma once
#include "../common_includes.h"
#include "../sdk/definitions.h"

#include "math/datatypes.h"
#include "math/math.h"

#include "obfuscation/fnv1a.h"
#include "obfuscation/xor.h"

#include "memory/memory.h"

#include "imgui/imgui.h"
#include "imgui/imgui_freetype.h"
#include "imgui/imgui_impl_dx9.h"
#include "imgui/imgui_impl_win32.h"

#include "render/render.h"

#include "netvars/datamap.h"
#include "netvars/netvars.h"

#include "input/input.h"

#include "cfg/cfg.h"

namespace utils {
	__forceinline std::string to_utf8(const std::wstring& txt) {
		if (txt.empty())
			return std::string();

		const auto size = WideCharToMultiByte(CP_UTF8, 0, &txt[0], txt.size(), 0, 0, 0, 0);

		auto ret = std::string(size, 0);

		WideCharToMultiByte(CP_UTF8, 0, &txt[0], txt.size(), &ret[0], size, 0, 0);

		return ret;
	}

	__forceinline std::wstring to_unicode(const std::string& txt) {
		if (txt.empty())
			return std::wstring();

		const auto size = MultiByteToWideChar(CP_UTF8, 0, &txt[0], txt.size(), 0, 0);

		auto ret = std::wstring(size, 0);

		MultiByteToWideChar(CP_UTF8, 0, &txt[0], txt.size(), &ret[0], size);

		return ret;
	}
}