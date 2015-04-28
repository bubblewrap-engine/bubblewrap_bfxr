#ifndef BUBBLEWRAP_BGFX_RENDER_BGFXTEXTURE_HPP
#define BUBBLEWRAP_BGFX_RENDER_BGFXTEXTURE_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Component.hpp"
#include "Bubblewrap/Render/Texture.hpp"
#include "Bubblewrap/Base/BgfxPhysFsInputStream.hpp"
namespace Bubblewrap
{
	namespace Render
	{

		/*! An implementation of Texture using Bgfx's sf::Texture */
		class BgfxTexture
			: public Texture
		{
		public:
			BgfxTexture();
			void Initialise(Json::Value Params);

			CREATE_REGISTER_OVERRIDE( BgfxTexture, Texture );

			virtual void Update( float dt );

			/*! Gets the currently stored Texture
			\returns A pointer to an sf::Textre 
			*/
			// sf::Texture* GetTexture();
		private:

			// sf::Texture Texture_;

			Base::BgfxPhysFsInputStream Stream_;
		};
	}
}


#endif