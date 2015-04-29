#ifndef BUBBLEWRAP_BGFX_RENDER_BGFXWINDOW_HPP
#define BUBBLEWRAP_BGFX_RENDER_BGFXWINDOW_HPP


#include "Bubblewrap/Managers/BaseManager.hpp"
#include "Bubblewrap/Render/Window.hpp"
#include <functional>
namespace Bubblewrap
{
	namespace Render
	{
		/*! An implementation of Window using Bgfx's sf::RenderWindow */
		class BgfxWindow
			: public Window
		{
		public:
			/*! Creates an BgfxWindow
			\param Settings The settings that should be used to setup the window */
			BgfxWindow( Window::WindowSettings Settings );

			void Update( float dt );
			void Display();
			void HandleEvents();

			/*! Performs a function on the RenderWindow 
			\param Function The function that should be called on Window
			*/
			void Do( std::function<void( void* Window )> Function );

			/*! Creates a new Window
			\param Params a pointer to the parameters that should be used to create the window
			\returns A pointer to a new window
			*/
			static Window* Create(void *Params);
		private:

			// sf::RenderWindow* sfWindow_;
			int View_;
		};

	}
}

#endif