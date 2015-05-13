#include "Bubblewrap/Render/BgfxShader.hpp"
#include "Bubblewrap/Render/Shader.hpp"
#include "Bubblewrap/Managers/Managers.hpp"
namespace Bubblewrap
{
	namespace Render
	{
		BgfxShader::BgfxShader()
		{

		}

		void BgfxShader::Initialise( Json::Value Params )
		{
			Shader::Initialise( Params );
			std::string vertexFile = Params[ "vertexShader" ].asString();
			std::string fragmentFile = Params[ "fragmentShader" ].asString();

			char* data;
			bgfx::Memory memory;
			File::File file = GetManager().GetFileManager().GetFile( vertexFile );
			file.Open( File::FileMode::Read );
			data = file.ReadAll();
			memory.data = ( uint8_t* ) data;
			memory.size = file.Size();
			file.Close();
			VertexShaderHandle_ = bgfx::createShader( &memory );

			file = GetManager().GetFileManager().GetFile( fragmentFile );
			file.Open( File::FileMode::Read );
			data = file.ReadAll();
			memory.data = ( uint8_t* ) data;
			memory.size = file.Size();
			file.Close();
			FragmentShaderHandle_ = bgfx::createShader( &memory );


			delete data;

		}

		void BgfxShader::Copy( BgfxShader* Target, BgfxShader* Base )
		{
			Shader::CopyDef(Target, Base);
			// Target->Texture_ = Base->Texture_;
		}

		void BgfxShader::Update( float dt )
		{
		}

	}
}