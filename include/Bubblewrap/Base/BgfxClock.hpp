#ifndef BUBBLEWRAP_BGFX_BASE_BGFXCLOCK_HPP
#define BUBBLEWRAP_BGFX_BASE_BGFXCLOCK_HPP

#include "Bubblewrap/Base/Clock.hpp"
namespace Bubblewrap
{
	namespace Base
	{
		/*! An implementation of Clock using Bgfx's sf::Clock*/
		class BgfxClock
			: public Clock
		{
		public:
			CREATE_REGISTER_OVERRIDE( BgfxClock, Clock );

		public:
			Time GetElapsedTime();
			void Update( float dt );

		private:
		};
	}
}


#endif