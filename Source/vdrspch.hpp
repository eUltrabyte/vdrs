#pragma once
#ifndef VDRS_PRECOMPILED_HEADER
#define VDRS_PRECOMPILED_HEADER

#if defined(_WIN32)
    #define VDRS_WIN32

    #ifndef NOMINMAX
        #define NOMINMAX
    #endif

    #include <windows.h>
#elif defined(__linux__)
    #define VDRS_LINUX

	#include <signal.h>

    #include <xcb/xcb.h>
    #include <xcb/xproto.h>
#else
    #define VDRS_UNKNOWN
#endif

#ifdef VDRS_DEBUG
	#if defined(VDRS_WIN32)
		#define VDRS_DEBUGBREAK() __debugbreak()
	#elif defined(VDRS_LINUX)
		#define VDRS_DEBUGBREAK() raise(SIGTRAP)
	#endif

    #define VDRS_ASSERT(x) if(x != 0) { VDRS_DEBUGBREAK(); }
    #define VDRS_LOG(x) { std::cout << "vdrs (log) - " << x << '\n'; }
    #define VDRS_ERROR(x) { std::cout << "vdrs (error) - " << x << '\n'; }
#else
	#define VDRS_DEBUGBREAK()
    #define VDRS_ASSERT(x)
    #define VDRS_LOG(x)
    #define VDRS_ERROR(x)
#endif

#define VDRS_EXPAND(x) x
#define VDRS_STRINGIFY(x) #x
#define VDRS_BIT(x) (1 << x)

#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <limits>
#include <string>
#include <string_view>
#include <vector>
#include <span>
#include <thread>
#include <future>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <array>
#include <random>
#include <chrono>
#include <utility>
#include <functional>
#include <memory>
#include <iomanip>
#include <complex>
#include <typeinfo>
#include <type_traits>
#include <regex>
#include <cmath>
#include <ctime>
#include <complex>
#include <cstring>
#include <cstdint>
#include <cstddef>
#include <cstdlib>
#include <cstdarg>

#endif