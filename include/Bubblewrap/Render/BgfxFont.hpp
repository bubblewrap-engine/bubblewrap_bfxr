#ifndef BUBBLEWRAP_BGFX_RENDER_BGFXFONT_HPP
#define BUBBLEWRAP_BGFX_RENDER_BGFXFONT_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Render/Font.hpp"
#include "Bubblewrap/Math/Vector2.hpp"
#include "Bubblewrap/Render/Colour.hpp"
#include "Bubblewrap/Render/Window.hpp"
#include "Bubblewrap/Base/BgfxPhysFsInputStream.hpp"

namespace Bubblewrap
{
	namespace Render
	{

		/*! An implementation of Font using Bgfx's sf::Font 
		*/
		class BgfxFont
			: public Font
		{
		public:
			BgfxFont();
			void Initialise( Json::Value Params );

			CREATE_REGISTER_OVERRIDE( BgfxFont, Font );

			virtual void Update( float dt );
			virtual void OnAttach();
			/*! Gets the font data currently stored in Font_
			\return THE sf::Font object stored in this object
			*/
			// sf::Font& GetBgfxFont();
		protected:
			/*! Storage class for the font data
			*/
			// sf::Font Font_;
			Base::BgfxPhysFsInputStream Stream_;
		};
	}
}




#endif