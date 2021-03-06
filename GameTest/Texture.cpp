#include "Texture.h"



void Texture::initTexture(const char* name) {
	
	//Load the image from the file into SDL's surface representation
	SDL_Surface* surf = SDL_LoadBMP(name);


	//Determine the data format of the surface by seeing how SDL arranges a test pixel.  This probably only works
	//  correctly for little-endian machines.
	GLenum data_fmt;
	Uint8 test = SDL_MapRGB(surf->format, 0xAA, 0xBB, 0xCC) & 0xFF;
	if (test == 0xAA) data_fmt = GL_RGB;
	else if (test == 0xCC) data_fmt = 0x80E0;//GL_BGR;

	//Generate an array of textures.  We only want one texture (one element array), so trick
	//it by treating "texture" as array of length one.
	glGenTextures(1, &this->texture);
	//Select (bind) the texture we just generated as the current 2D texture OpenGL is using/modifying.
	//All subsequent changes to OpenGL's texturing state for 2D textures will affect this texture.
	glBindTexture(GL_TEXTURE_2D, this->texture);
	//Specify the texture's data.  This function is a bit tricky, and it's hard to find helpful documentation.  A summary:
	//   GL_TEXTURE_2D:    The currently bound 2D texture (i.e. the one we just made)
	//               0:    The mipmap level.  0, since we want to update the base level mipmap image (i.e., the image itself,
	//                         not cached smaller copies)
	//         GL_RGBA:    The internal format of the texture.  This is how OpenGL will store the texture internally (kinda)--
	//                         it's essentially the texture's type.
	//         surf->w:    The width of the texture
	//         surf->h:    The height of the texture
	//               0:    The border.  Don't worry about this if you're just starting.
	//        data_fmt:    The format that the *data* is in--NOT the texture!  Our test image doesn't have an alpha channel,
	//                         so this must be RGB.
	//GL_UNSIGNED_BYTE:    The type the data is in.  In SDL, the data is stored as an array of bytes, with each channel
	//                         getting one byte.  This is fairly typical--it means that the image can store, for each channel,
	//                         any value that fits in one byte (so 0 through 255).  These values are to be interpreted as
	//                         *unsigned* values (since 0x00 should be dark and 0xFF should be bright).
	// surface->pixels:    The actual data.  As above, SDL's array of bytes.
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surf->w, surf->h, 0, data_fmt, GL_UNSIGNED_BYTE, surf->pixels);
	//Set the minification and magnification filters.  In this case, when the texture is minified (i.e., the texture's pixels (texels) are
	//*smaller* than the screen pixels you're seeing them on, linearly filter them (i.e. blend them together).  This blends four texels for
	//each sample--which is not very much.  Mipmapping can give better results.  Find a texturing tutorial that discusses these issues
	//further.  Conversely, when the texture is magnified (i.e., the texture's texels are *larger* than the screen pixels you're seeing
	//them on), linearly filter them.  Qualitatively, this causes "blown up" (overmagnified) textures to look blurry instead of blocky.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//Unload SDL's copy of the data; we don't need it anymore because OpenGL now stores it in the texture.
	SDL_FreeSurface(surf);

	glBindTexture(GL_TEXTURE_2D, this->texture);

}

void Texture::delTexture() {
	//Deallocate texture.  A lot of people forget to do this.
	glDeleteTextures(1, &this->texture);
}

