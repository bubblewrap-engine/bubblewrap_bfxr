dofile( "bgfx_genie.lua" )

PsyProjectEngineLib( "bgfx" )
	files 
	{ 
		"include/**.h", 
		"include/**.hpp", 
		"src/**.cpp" 
	}
	includedirs { 
		"./include", 
		"../bubblewrap/External",
		"../bubblewrap/include/",
		"./bgfx/include/",
		"./bx/include/",
		"../bubblewrap_sdl/sdl2/SDL2/include"
		}
	PsyAddEngineLinks {
		"base"
	}
	
	PsyAddExternalLinks {
		"physfs",
		"json",
	}
