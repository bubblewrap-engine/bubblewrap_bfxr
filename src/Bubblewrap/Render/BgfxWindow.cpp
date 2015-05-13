#include "Bubblewrap/Render/BgfxWindow.hpp"
#include "Bubblewrap/Managers/Managers.hpp"
#include "Bubblewrap/Base/Game.hpp"
#include "Bubblewrap/Events/Events.hpp"
#include "Bubblewrap/Events/EventManager.hpp"
// #include "Bgfx/Graphics.hpp"
#include "Bubblewrap/Events/BgfxKeyTranslator.hpp"
#ifdef BUBBLEWRAP_SDL
	#include <SDL.h>
	#include <SDL_syswm.h>
#endif
#include <bgfxplatform.h> 
#include "bgfx.h"
#include <bx/bx.h>

namespace Bubblewrap
{
	namespace Render
	{
		BgfxWindow::BgfxWindow( Window::WindowSettings Settings, Managers::Managers* Owner )
			: Window( Settings )
		{
			// Window_ = sfWindow_ = new sf::RenderWindow( sf::VideoMode( Settings.Width_, Settings.Height_ ), Settings.Title_ );
			InternalWindow_ = nullptr;
			InternalWindow_ = Owner->GetWindowManager().CreateOver( Settings.Name_, &Settings );
			InternalWindow_->SetManager( Owner );
#ifdef BUBBLEWRAP_SDL
			if ( InternalWindow_->GetInternalPointer() != nullptr )
				bgfx::sdlSetWindow( (SDL_Window* ) InternalWindow_->GetInternalPointer() );
#endif
			bgfx::init();
			bgfx::reset( Settings.Width_, Settings.Height_, BGFX_RESET_VSYNC );

			// Enable debug text.
			bgfx::setDebug( BGFX_DEBUG_TEXT );

			// Set view 0 clear state.
			bgfx::setViewClear( 0
				, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH
				, Settings.Colour_.RGBA()
				, 1.0f
				, 0
				);

		}

		Window* BgfxWindow::Create( void* Params, Managers::Managers* Owner )
		{
			Window::WindowSettings* Settings = ( Window::WindowSettings* )Params;
			return ( Window* ) ( new BgfxWindow( *Settings, Owner ) );
		}
	

		void BgfxWindow::Update( float dt )
		{
			// InternalWindow_->Update( dt );
			
			bgfx::setViewRect( 0, 0, 0, Settings_.Width_, Settings_.Height_ );
			// This dummy draw call is here to make sure that view 0 is cleared
			// if no other draw calls are submitted to view 0.
			bgfx::submit( 0 );

			bgfx::dbgTextClear();
			bgfx::dbgTextPrintf( 0, 1, 0x4f, "Bgfx Window" );
			bgfx::dbgTextPrintf( 0, 2, 0x6f, "Description: Yeah, rendering is a thing" );
		}

		void BgfxWindow::Display()
		{
			Window::Display();
			
			bgfx::frame();
			//InternalWindow_->Display();
		}

		void BgfxWindow::HandleEvents()
		{
			InternalWindow_->HandleEvents();
			// entry::processEvents( Settings_.Width_, Settings_.Height_, BGFX_DEBUG_TEXT, BGFX_RESET_VSYNC );
			/*sf::Event event;
			while ( sfWindow_->pollEvent( event ) )
			{
				// sm->Input( event );
				//if ( event.type == sf::Event::Closed )
				//window.close();
				if ( ( event.type == sf::Event::KeyPressed ) )
				{
					auto code = Bubblewrap::Events::TranslateKey( event.key.code );
					Events::InputData* newEvent = new Events::InputData();
					newEvent->InputType_ = Events::InputData::InputType::KeyDown;
					newEvent->Key_ = Bubblewrap::Events::TranslateKey( event.key.code );
					newEvent->Alt_ = event.key.alt;
					newEvent->Control_ = event.key.control;
					newEvent->Shift_ = event.key.shift;
					Events::Event evt = Events::Event( Events::EventTypes::Input, newEvent );
					GetManagers().GetEventManager().QueueEvent( evt );
				}
				else if ( ( event.type == sf::Event::KeyReleased ) )
				{
					auto code = Bubblewrap::Events::TranslateKey( event.key.code );
					Events::InputData* newEvent = new Events::InputData();
					newEvent->InputType_ = Events::InputData::InputType::KeyUp;
					newEvent->Key_ = Bubblewrap::Events::TranslateKey( event.key.code );
					newEvent->Alt_ = event.key.alt;
					newEvent->Control_ = event.key.control;
					newEvent->Shift_ = event.key.shift;
					Events::Event evt = Events::Event( Events::EventTypes::Input, newEvent );
					GetManagers().GetEventManager().QueueEvent( evt );
				}
				else if ( ( event.type == sf::Event::EventType::Closed ) )
				{
					GetManagers().GetGame()->Shutdown();
				}
			}/**/

		}


	}
}