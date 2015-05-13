#include "Bubblewrap/Base/BgfxClock.hpp"
#include <bx/timer.h>
namespace Bubblewrap
{
	namespace Base
	{
		BgfxClock::BgfxClock()
		{
			LastTime = bx::getHPCounter();
		}

		Time BgfxClock::GetElapsedTime()
		{
			const double Freq = double( bx::getHPFrequency() );
			const double ToMs = 1000.0 / Freq;
			return Time( bx::getHPCounter() * ToMs * 0.001f );
		}

		void BgfxClock::Copy( BgfxClock* Target, BgfxClock* Base )
		{

		}

		void BgfxClock::Update( float dt )
		{

		}
	}
}
