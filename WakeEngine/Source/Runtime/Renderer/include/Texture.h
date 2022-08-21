#pragma once

#include "glad.h"
#include <cstdint>
#include <string>
#include "../../../../../ExternalLibraries/stb_image/stb_image.h"

namespace Wake {
	enum TextureWrappingOptions { Repeat, Mirror, Stretch, Border };
	enum TextureFilterOptions { Nearest, Linear };
	enum TextureMipmapOptions { NearestNearest, LinearNearest, NearestLinear, LinearLinear };

	enum TextureImageType { RGB, RGBA };
	class Texture
	{
	public:
		Texture();
		Texture(int32_t _id);
		Texture(const char* filename);
		Texture(std::string filename);
		Texture(const char* filename, int32_t _id);
		Texture(std::string filename, int32_t _id);
		~Texture();

		void load(const char* filename);
		void load(std::string filename);

		void activate(int texture_id);

		unsigned int get_buffer();

		unsigned char* get_data();
		int32_t get_width();
		int32_t get_height();
		int32_t get_num_channels();

		void set_id(int32_t _id);
		void set_wrap_setting(TextureWrappingOptions setting);
		void set_filter_setting(TextureFilterOptions setting);
		void set_mipmap_setting(TextureMipmapOptions setting);
		void set_image_type(TextureImageType type);

	private:
		void set_default_texture_options();
		void set_default_image_type();
		void apply();
		void load_texture(const char* filename);
		void apply_wrap_settings();
		void apply_filter_settings();
		void apply_mipmap_settings();

		TextureWrappingOptions wrap_setting;
		TextureFilterOptions filter_setting;
		TextureMipmapOptions mipmap_setting;
		TextureImageType image_type;

		int32_t width, height, num_channels, id;
		unsigned int texture_buffer;
		unsigned char* data;
	};
}

