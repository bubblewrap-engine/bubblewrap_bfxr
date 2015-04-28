#ifndef BUBBLEWRAP_BGFX_RENDER_BGFXTEXT_HPP
#define BUBBLEWRAP_BGFX_RENDER_BGFXTEXT_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Render/Drawable.hpp"
#include "Bubblewrap/Math/Vector2.hpp"
#include "Bubblewrap/Render/Colour.hpp"
#include "Bubblewrap/Render/Window.hpp"
#include "Bubblewrap/Render/Text.hpp"
namespace Bubblewrap
{
	namespace Render
	{

		/*! An implementation of Text using Bgfx's sf::Text */
		class BgfxText
			: public Text
		{
		public:
			BgfxText();
			void Initialise( Json::Value Params );

			CREATE_REGISTER_OVERRIDE( BgfxText, Text );

			virtual void Update( float dt );
			virtual void OnAttach();

			virtual void Draw();
		private:
		};
	}
}




#endif