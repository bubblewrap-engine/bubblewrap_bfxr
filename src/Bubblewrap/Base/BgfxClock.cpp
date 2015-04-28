#include "Bubblewrap/Base/BgfxClock.hpp"

namespace Bubblewrap
{
	namespace Base
	{
		Time BgfxClock::GetElapsedTime()
		{
			return Time( 1.0f / 25.0f);
		}

		void BgfxClock::Copy( BgfxClock* Target, BgfxClock* Base )
		{

		}

		void BgfxClock::Update( float dt )
		{

		}
	}
}
