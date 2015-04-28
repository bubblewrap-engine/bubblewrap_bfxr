#ifndef BUBBLEWRAP_BGFX_RENDER_BGFXIMAGE_HPP
#define BUBBLEWRAP_BGFX_RENDER_BGFXIMAGE_HPP

#include "Bubblewrap/Render/Image.hpp"
#include "Bubblewrap/Base/BgfxPhysFsInputStream.hpp"

namespace Bubblewrap
{
	namespace Render
	{
		class BgfxImage : 
			public Image
		{
			BgfxImage();
		public:
			void Initialise( Json::Value Params );

			CREATE_REGISTER_OVERRIDE( BgfxImage, Image );

			Colour GetColour( int X, int Y );

			int GetWidth();
			int GetHeight();

		private:
			// sf::Image LoadedImage_;
			Base::BgfxPhysFsInputStream Stream_;
		};
	}
}


#endif