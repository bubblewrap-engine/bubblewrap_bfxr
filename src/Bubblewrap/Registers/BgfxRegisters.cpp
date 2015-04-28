#include "Bubblewrap/Registers/BgfxRegisters.hpp"
#include "Bubblewrap/Base/ObjectRegister.hpp"
#include "Bubblewrap/Base/BgfxClock.hpp"
#include "Bubblewrap/Managers/Managers.hpp"
#include "Bubblewrap/Render/BgfxWindow.hpp"
#include "Bubblewrap/Render/BgfxTexture.hpp"
#include "Bubblewrap/Render/BgfxVertices.hpp"
#include "Bubblewrap/Render/BgfxText.hpp"
#include "Bubblewrap/Render/BgfxFont.hpp"
#include "Bubblewrap/Render/BgfxImage.hpp"

namespace Bubblewrap
{
	namespace Registers
	{
		void BgfxRegisters::RegisterUtilities( void* ObjectRegister )
		{
			Base::ObjectRegister* Register = ( Base::ObjectRegister* ) ObjectRegister;

			Register->RegisterCreator( "Clock", Base::BgfxClock::Create, Base::BgfxClock::CopyDef, true );

			Register->GetManager()->GetWindowManager().SetCreate( Render::BgfxWindow::Create );
		}

		void BgfxRegisters::RegisterGraphics( void* ObjectRegister )
		{
			Base::ObjectRegister* Register = (Base::ObjectRegister*) ObjectRegister;

			Register->RegisterCreator( "Texture", Render::BgfxTexture::Create, Render::BgfxTexture::CopyDef, true );
			Register->RegisterCreator( "Vertices", Render::BgfxVertices::Create, Render::BgfxVertices::CopyDef, true );
			
			Register->RegisterCreator( "Font", Render::BgfxFont::Create, Render::BgfxFont::CopyDef, true );
			Register->RegisterCreator( "Text", Render::BgfxText::Create, Render::BgfxText::CopyDef, true );

			Register->RegisterCreator("Image", Render::BgfxImage::Create, Render::BgfxImage::CopyDef, true );

			Register->GetManager()->GetWindowManager().SetCreate(Render::BgfxWindow::Create);
		}

	}
}