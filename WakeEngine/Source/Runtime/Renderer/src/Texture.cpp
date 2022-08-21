#include "../include/Texture.h"
#include "../../Utils/include/Debug.h"



/* =======================================================================  /
/  =======	   Constructor/Destructors		==============================  /
/  ======================================================================= */


Wake::Texture::Texture() {
	Wake::Debug::log_warning("WARNING: No ID provided to texture...");
	id = 1;
	set_default_texture_options();
}


Wake::Texture::Texture(int32_t _id) {
	id = _id;
	set_default_texture_options();
}


Wake::Texture::Texture(const char* filename) {
	set_default_texture_options();
	load_texture(filename);
}


Wake::Texture::Texture(std::string filename) {
	set_default_texture_options();
	load_texture(filename.c_str());
}


Wake::Texture::Texture(const char* filename, int32_t _id) {
	id = _id;
	set_default_texture_options();
	load_texture(filename);
}


Wake::Texture::Texture(std::string filename, int32_t _id) {
	id = _id;
	set_default_texture_options();
	load_texture(filename.c_str());
}


Wake::Texture::~Texture() {
	// do nothing
}



/* =======================================================================  /
/  =======	   Public Methods				==============================  /
/  ======================================================================= */


void Wake::Texture::load(const char* filename) {
	load_texture(filename);
	apply();
}


void Wake::Texture::load(std::string filename) {
	load(filename.c_str());
}


void Wake::Texture::apply() {
	// ensure data isn't null...
	if (data) {
		// setup texture buffer
		glGenTextures(id, &texture_buffer);
		glBindTexture(GL_TEXTURE_2D, texture_buffer);

		// apply settings
		apply_wrap_settings();
		apply_filter_settings();
		apply_mipmap_settings();

		// todo: support multiple kinds of images (e.g. alpha channels, etc)
		switch (image_type) {
		case TextureImageType::RGB:
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			break;
		case TextureImageType::RGBA:
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			break;
		default:
			std::string msg = "ERROR: Invalid image type applid to texture...";
			Wake::Debug::log_error(msg, "Runtime/Render/Texture.cpp::apply()");
			return;
		}
		
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(data);
	}
	else {
		Wake::Debug::log_error("ERROR: Tried to load texture with no data loaded...");
	}
}


void Wake::Texture::activate(int texture_id) {
	switch (texture_id) {
	case 0:
		glActiveTexture(GL_TEXTURE0);
		break;
	case 1:
		glActiveTexture(GL_TEXTURE1);
		break;
	case 2:
		glActiveTexture(GL_TEXTURE2);
		break;
	case 3:
		glActiveTexture(GL_TEXTURE3);
		break;
	case 4:
		glActiveTexture(GL_TEXTURE4);
		break;
	case 5:
		glActiveTexture(GL_TEXTURE5);
		break;
	case 6:
		glActiveTexture(GL_TEXTURE6);
		break;
	case 7:
		glActiveTexture(GL_TEXTURE7);
		break;
	case 8:
		glActiveTexture(GL_TEXTURE8);
		break;
	case 9:
		glActiveTexture(GL_TEXTURE9);
		break;
	case 10:
		glActiveTexture(GL_TEXTURE10);
		break;
	case 11:
		glActiveTexture(GL_TEXTURE11);
		break;
	case 12:
		glActiveTexture(GL_TEXTURE12);
		break;
	case 13:
		glActiveTexture(GL_TEXTURE13);
		break;
	case 14:
		glActiveTexture(GL_TEXTURE14);
		break;
	case 15:
		glActiveTexture(GL_TEXTURE15);
		break;
	case 16:
		glActiveTexture(GL_TEXTURE16);
		break;
	default:
		std::string msg = "ERROR: bad texture id passed to Texture.activate(): ";
		msg += std::to_string(texture_id);
		Wake::Debug::log_error(msg, "Runtime/Render/Texture.cpp::activate(int texture_id)");
		return;
	}
	glBindTexture(GL_TEXTURE_2D, texture_buffer);
}


unsigned char* Wake::Texture::get_data() {
	return data;
}


int32_t Wake::Texture::get_width() {
	return width;
}


int32_t Wake::Texture::get_height() {
	return height;
}


int32_t Wake::Texture::get_num_channels() {
	return num_channels;
}


unsigned int Wake::Texture::get_buffer() {
	return texture_buffer;
}


void Wake::Texture::set_wrap_setting(TextureWrappingOptions setting) {
	wrap_setting = setting;
}


void Wake::Texture::set_filter_setting(TextureFilterOptions setting) {
	filter_setting = setting;
}


void Wake::Texture::set_mipmap_setting(TextureMipmapOptions setting) {
	mipmap_setting = setting;
}


void Wake::Texture::set_image_type(TextureImageType type) {
	image_type = type;
}


void Wake::Texture::set_id(int32_t _id) {
	Wake::Debug::log("id set to: " + std::to_string(id));
	id = _id;
}



/* =======================================================================  /
/  =======	   Helper Methods				==============================  /
/  ======================================================================= */


void Wake::Texture::set_default_texture_options() {
	set_wrap_setting(Wake::TextureWrappingOptions::Repeat);
	set_filter_setting(Wake::TextureFilterOptions::Linear);
	set_mipmap_setting(Wake::TextureMipmapOptions::LinearLinear);
}


void Wake::Texture::set_default_image_type() {
	image_type = TextureImageType::RGB;
}


void Wake::Texture::load_texture(const char* filename) {
	data = stbi_load(filename, &width, &height, &num_channels, 0);
	if (data) {
		std::string msg = "Success loading texture:  ";
		msg += filename;
		Wake::Debug::log(msg);
	}
	else {
		std::string msg = "ERROR: Failed to load texture: ";
		msg += filename;
		Wake::Debug::log_error(msg);
	}
}


void Wake::Texture::apply_wrap_settings() {
	// set up texture wrapping settings (for both axes)
	switch (wrap_setting) {
	case Wake::TextureWrappingOptions::Repeat:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		break;
	case Wake::TextureWrappingOptions::Mirror:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
		break;
	case Wake::TextureWrappingOptions::Stretch:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		break;
	case Wake::TextureWrappingOptions::Border:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
		break;
	default:
		Wake::Debug::log_error("ERROR: Bad texture wrapping option given: " + wrap_setting);
		break;
	}
}


void Wake::Texture::apply_filter_settings() {
	// set up texture filtering settings (for magnifying and shrinking textures)
	switch (filter_setting) {
	case Wake::TextureFilterOptions::Nearest:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		break;
	case Wake::TextureFilterOptions::Linear:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		break;
	default:
		Wake::Debug::log_error("ERROR: Bad texture filter option given: " + filter_setting);
		break;
	}
}


void Wake::Texture::apply_mipmap_settings() {
	// set up texture mipmap settings (only happens for downscaling textures)
	switch (mipmap_setting) {
	case Wake::TextureMipmapOptions::NearestNearest:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
		break;
	case Wake::TextureMipmapOptions::LinearNearest:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
		break;
	case Wake::TextureMipmapOptions::NearestLinear:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
		break;
	case Wake::TextureMipmapOptions::LinearLinear:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		break;
	default:
		Wake::Debug::log_error("ERROR: Bad texture mipmap option given: " + mipmap_setting);
		break;
	}
}