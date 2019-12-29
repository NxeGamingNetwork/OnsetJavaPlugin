#pragma once

#include <vector>
#include <tuple>
#include <functional>
#include <jni.h>
#include <PluginSDK.h>
#include "Singleton.hpp"
#include "JavaEnv.hpp"

class Plugin : public Singleton<Plugin>
{
	friend class Singleton<Plugin>;
private:
	Plugin();
	~Plugin() = default;
	JavaEnv* jenvs[30];

private:
	using FuncInfo_t = std::tuple<const char *, lua_CFunction>;
	std::vector<FuncInfo_t> _func_list;

private:
	inline void Define(const char * name, lua_CFunction func)
	{
		_func_list.emplace_back(name, func);
	}

public:
	decltype(_func_list) const &GetFunctions() const
	{
		return _func_list;
	}
	int CreateJava(std::string classPath);
	void DestroyJava(int id);
	JavaEnv* GetJavaEnv(int id);
	JavaEnv* FindJavaEnv(JNIEnv* jenv);
};
