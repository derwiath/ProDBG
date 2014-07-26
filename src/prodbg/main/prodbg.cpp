#include <stdlib.h>
#include <core/Core.h>
#include <core/PluginHandler.h>
#include "ui/Application.h"

#ifdef PRODBG_WIN
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

namespace prodbg
{

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static const char* s_plugins[] =
{
	"Registers", 
	// "LLDBPlugin",
};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int main(int argc, const char** argv)
{
	for (uint32_t i = 0; i < sizeof_array(s_plugins); ++i)
	{
		if (!PluginHandler_addPlugin(OBJECT_DIR, s_plugins[i]))
			return 0;
	}

	return Application_init(argc, argv);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef PRODBG_WIN

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	return prodbg::main(__argc, __argv);
}

#else

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, const char** argv)
{
	return prodbg::main(argc, argv);
}

#endif
