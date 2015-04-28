#include "Bubblewrap/Render/BgfxImage.hpp"
#include "Bubblewrap/Base/Entity.hpp"
#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/Base/BgfxPhysFsInputStream.hpp"
namespace Bubblewrap
{
	namespace Render
	{
		BgfxImage::BgfxImage()
		{
		}

		void BgfxImage::Initialise( Json::Value Params )
		{
			Image::Initialise( Params );
			Stream_.open( Filename_ );
			// TODO
		}


		void BgfxImage::Copy( BgfxImage* Target, BgfxImage* Base )
		{
			Image::Copy( Target, Base );
		}

		Colour BgfxImage::GetColour( int X, int Y )
		{
			// TOOD
			/* sf::Vector2u size = LoadedImage_.getSize();
			if ( ( 0 <= X ) && ( X < size.x ) && ( 0 <= Y ) && ( Y < size.y ) )
			{
				sf::Color colour = LoadedImage_.getPixel( X, Y );
				return Colour( colour.r, colour.g, colour.b, colour.a ); 
			}/**/
			return Colour( 0.0f, 0 , 0 );
		}

		int BgfxImage::GetWidth()
		{
			// TODO
			return -1;
		}

		int BgfxImage::GetHeight()
		{
			// TODO
			return -1;
		}
	}
}