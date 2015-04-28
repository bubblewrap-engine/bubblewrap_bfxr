#include "Bubblewrap/Render/BgfxTexture.hpp"
#include "Bubblewrap/Render/Texture.hpp"

namespace Bubblewrap
{
	namespace Render
	{
		BgfxTexture::BgfxTexture()
		{

		}

		void BgfxTexture::Initialise( Json::Value Params )
		{
			Texture::Initialise( Params );
			Stream_.open( Params[ "texture" ].asString() );
			// Texture_.loadFromStream( Stream_ );
			
		}

		void BgfxTexture::Copy( BgfxTexture* Target, BgfxTexture* Base )
		{
			Texture::CopyDef(Target, Base);
			// Target->Texture_ = Base->Texture_;
		}

		void BgfxTexture::Update( float dt )
		{
		}

	}
}