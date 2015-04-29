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
		}
	PsyAddEngineLinks {
		"base"
	}
	
	PsyAddExternalLinks {
		"physfs",
		"json",
	}
