// Based on https://github.com/LaurentGomila/Bgfx/wiki/Source:-PhysicsFS-Input-Stream

#ifndef BUBBLEWRAP_BASE_BGFXPHYSFSINPUTSTREAM_HPP
#define BUBBLEWRAP_BASE_BGFXPHYSFSINPUTSTREAM_HPP

#include <iostream>
#include <physfs/physfs.h>
namespace Bubblewrap
{
	namespace Base
	{
		class BgfxPhysFsInputStream
		{
		public:
			/*!*/
			BgfxPhysFsInputStream( const char* filename = 0x0 ) :
				m_File( 0x0 )
			{
				if ( filename )
					open( filename );
			}

			virtual ~BgfxPhysFsInputStream()
			{
				close();
			}

			bool isOpen() const
			{
				return ( m_File != 0x0 );
			}

			bool open( const std::string filename )
			{
				close();
				m_File = PHYSFS_openRead( filename.c_str() );
				return isOpen();
			}

			void close()
			{
				if ( isOpen() )
					PHYSFS_close( m_File );
				m_File = 0x0;
			}

			virtual long long read( void* data, long long size )
			{
				if ( !isOpen() )
					return -1;

				// PHYSFS_read returns the number of 'objects' read or -1 on error.
				// We assume our objects are single bytes and request to read size
				// amount of them.
				return PHYSFS_read( m_File, data, 1, static_cast< PHYSFS_uint32 >( size ) );
			}

			virtual long long seek( long long position )
			{
				if ( !isOpen() )
					return -1;

				// PHYSFS_seek return 0 on error and non zero on success
				if ( PHYSFS_seek( m_File, position ) )
					return tell();
				else
					return -1;
			}

			virtual long long tell()
			{
				if ( !isOpen() )
					return -1;

				// PHYSFS_tell returns the offset in bytes or -1 on error just like Bgfx wants.
				return PHYSFS_tell( m_File );
			}

			virtual long long getSize()
			{
				if ( !isOpen() )
					return -1;

				// PHYSFS_fileLength also the returns length of file or -1 on error just like Bgfx wants.
				return PHYSFS_fileLength( m_File );
			}

		private:
			PHYSFS_File* m_File;

		};
	}
}

#endif