#include "Bubblewrap/Managers/Managers.hpp"
#include "Bubblewrap/Render/BgfxVertices.hpp"
#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/Render/Types.hpp"
#include "Bubblewrap/Math/Vector2.hpp"
#include "Bubblewrap/Base/Entity.hpp"
#include "Bubblewrap/Render/BgfxTexture.hpp"

namespace Bubblewrap
{
	namespace Render
	{
		BgfxVertices::BgfxVertices()
		{
			VertexCount_ = 0;
			SFReservedCount_ = 0;
			// SFTexture_ = nullptr;
			Dirty_ = false;
		}


		BgfxVertices::~BgfxVertices()
		{
		}

		void BgfxVertices::Initialise( Json::Value Params )
		{
			Vertices::Initialise( Params );
		}

		void BgfxVertices::Copy( BgfxVertices* Target, BgfxVertices* Base )
		{
			Vertices::Copy( Target, Base );
			Target->Refresh();
		}

		void BgfxVertices::OnAttach()
		{
			Vertices::OnAttach();
			// SFTexture_ = dynamic_cast<BgfxTexture*>( Texture_ );
		}

		void BgfxVertices::Update( float dt )
		{
			Vertices::Update( dt );
			assert( !Dirty_ );
			if ( ( Window_ == nullptr ) && ( WindowName_ != "" ) )
			{
				Window_ = GetManager().GetWindowManager().GetItem( WindowName_ );
			}
			Refresh();

		}

		void BgfxVertices::Draw()
		{
			
			/* sf::Transform transform;
			auto pos = GetParentEntity()->WorldPosition();
			transform.translate( pos.X(), pos.Y() );
			sf::RenderStates states;
			states.transform = transform;
			SFVertices_.setPrimitiveType( PrimitiveType );
			if ( Texture_ != nullptr )
				states.texture = SFTexture_->GetTexture();
			rw->draw( SFVertices_, states ); /**/

		}

		void BgfxVertices::Refresh()
		{ 
			InternalVertices_.clear();
			InternalVertices_.resize( VertexCount_ );
			float wid = 0;
			float hei = 0;
			/*if ( Texture_ != nullptr )
			{
				if ( SFTexture_ == nullptr )
				{
					SFTexture_ = dynamic_cast< BgfxTexture* >( Texture_ );
				}
				if ( SFTexture_ != nullptr )
				{
					sf::Vector2u dimensions = SFTexture_->GetTexture()->getSize();
					wid = ( float )SFTexture_->GetTexture()->getSize().x;
					hei = ( float ) SFTexture_->GetTexture()->getSize().y;
				}
			}/**/
			for ( unsigned int Idx = 0; Idx < VertexCount_; ++Idx )
			{
				InternalVertices_[ Idx ].m_abgr = Vertices_[ Idx ].Colour_.ABGR();
				InternalVertices_[ Idx ].m_x = Vertices_[ Idx ].Position_.X();
				InternalVertices_[ Idx ].m_y = Vertices_[ Idx ].Position_.Y();
				InternalVertices_[ Idx ].m_z = Vertices_[ Idx ].Position_.Z();
				//InternalVertices_[ Idx ].texCoords = sf::Vector2f( Vertices_[ Idx ].TexCoords_.X() * wid, Vertices_[ Idx ].TexCoords_.Y() * hei );
			}/**/ 
			Dirty_ = false;
		}
	}
}	