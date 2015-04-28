#include "Bubblewrap/Render/BgfxFont.hpp"
#include "Bubblewrap/Base/Entity.hpp"
#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/Base/BgfxPhysFsInputStream.hpp"
namespace Bubblewrap
{
	namespace Render
	{
		BgfxFont::BgfxFont()
		{
		}

		void BgfxFont::Initialise( Json::Value Params )
		{
			Font::Initialise( Params );
			Stream_.open( Params[ "fontFile" ].asString().c_str() );
			// TODO
		}


		void BgfxFont::Copy( BgfxFont* Target, BgfxFont* Base )
		{
			Font::Copy( Target, Base );
		}

		void BgfxFont::OnAttach()
		{
		}


		void BgfxFont::Update( float dt )
		{

		}



	}
}