#ifndef BUBBLEWRAP_BGFX_RENDER_BGFXSHADER_HPP
#define BUBBLEWRAP_BGFX_RENDER_BGFXSHADER_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Component.hpp"
#include "Bubblewrap/Render/Shader.hpp"
#include "Bubblewrap/Base/BgfxPhysFsInputStream.hpp"
#include "bgfx.h"
namespace Bubblewrap
{
	namespace Render
	{

		/*! An implementation of Texture using Bgfx's sf::Texture */
		class BgfxShader
			: public Shader
		{
		public:
			BgfxShader();
			void Initialise(Json::Value Params);

			CREATE_REGISTER_OVERRIDE( BgfxShader, Shader );

			virtual void Update( float dt );

			/*! Gets the currently stored Texture
			\returns A pointer to an sf::Textre 
			*/
			// sf::Texture* GetTexture();
		private:

			// sf::Texture Texture_;
			bgfx::ShaderHandle VertexShaderHandle_;
			bgfx::ShaderHandle FragmentShaderHandle_;
		};
	}
}


#endif