#include "Texture.h"

Texture::Texture(const string &filename, int width, int height) : filename(filename), width(width), height(height) {}

Texture::~Texture() {
    free();
}

GLuint Texture::getId() const {
    return id;
}

void Texture::setId(GLuint id) {
    Texture::id = id;
}

const string &Texture::getFilename() const {
    return filename;
}

void Texture::setFilename(const string &filename) {
    Texture::filename = filename;
}

int Texture::getWidth() const {
    return width;
}

void Texture::setWidth(int width) {
    Texture::width = width;
}

int Texture::getHeight() const {
    return height;
}

void Texture::setHeight(int height) {
    Texture::height = height;
}

bool Texture::load() {

    GLuint texture;
    unsigned char *data;
    FILE *file;

    //The following code will read in our RAW file
    file = fopen(filename.c_str(), "rb");
    if (file == NULL) return false;
    data = (unsigned char *) malloc(width * height * 3);
    fread(data, width * height * 3, 1, file);
    fclose(file);

    glGenTextures(1, &texture); //generate the wallTexture with the loaded data
    //glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glBindTexture(GL_TEXTURE_2D, texture); //bind the wallTexture to it�s array
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); //set wallTexture environment parameters

    //here we are setting what textures to use and when. The MIN filter is which quality to show
    //when the wallTexture is near the view, and the MAG filter is which quality to show when the wallTexture
    //is far from the view.

    //The qualities are (in order from worst to best)
    //GL_NEAREST
    //GL_LINEAR
    //GL_LINEAR_MIPMAP_NEAREST
    //GL_LINEAR_MIPMAP_LINEAR

    //And if you go and use extensions, you can use Anisotropic filtering textures which are of an
    //even better quality, but this will do for now.
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //Here we are setting the parameter to repeat the wallTexture instead of clamping the wallTexture
    //to the edge of our shape.
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    //Generate the wallTexture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    std::free(data); //free the wallTexture

    this->id = texture; //return whether it was successfull
    return true;
}

void Texture::free() {
    glDeleteTextures(1, &id);
}
