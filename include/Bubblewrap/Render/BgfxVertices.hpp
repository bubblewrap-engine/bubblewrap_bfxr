#ifndef BUBBLEWRAP_BGFX_RENDER_BGFXVERTICES_HPP
#define BUBBLEWRAP_BGFX_RENDER_BGFXVERTICES_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Render/Vertices.hpp"
#include "Bubblewrap/Render/Drawable.hpp"
#include "Bubblewrap/Render/Types.hpp"
#include "Bubblewrap/Base/Base.hpp"
namespace Bubblewrap
{
	namespace Render
	{
		class BgfxTexture;
		/*! An implementation of Vertices using Bgfx's sf::Vertex*/
		class BgfxVertices
			: public Vertices
		{
		public:
			BgfxVertices();
			~BgfxVertices();
			void Initialise( Json::Value Params );

			CREATE_REGISTER_OVERRIDE( BgfxVertices, Vertices );

			virtual void Update( float dt );
			virtual void OnAttach();

			void Refresh();
			void Draw();
		protected:
			/*! A pointer to an array of vertices used to draw*/
			//sf::VertexArray SFVertices_;

			/*! The number of vertices we have currently stored in SFVertices_ */
			unsigned int SFReservedCount_;

		private:
			// BgfxTexture* SFTexture_;
		};
	}
}


#endif