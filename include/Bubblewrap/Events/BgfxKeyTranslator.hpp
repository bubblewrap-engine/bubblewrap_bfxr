#ifndef BUBBLEWRAP_BGFX_EVENTS_BGFXKEYTRANSLATOR_HPP
#define BUBBLEWRAP_BGFX_EVENTS_BGFXKEYTRANSLATOR_HPP

#include "Bubblewrap/Events/EventKeyInput.hpp"

namespace Bubblewrap
{
	namespace Events
	{
		/*! Translates an sf::Keyboard::Key into a Bubblewrap::Events::Key
		\param key Bgfx keycode
		\returns The corresponding Bubblewrap keycode 
		*/
		Key TranslateKey( int key );
	}

}

#endif