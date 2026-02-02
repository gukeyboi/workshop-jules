#include <sil/sil.hpp>
#include <random.hpp>

void keep_green_only(sil::Image &image) {
    for (int x{0}; x < image.width(); x++)
{
    for (int y{0}; y < image.height(); y++)
    {
        image.pixel(x, y).b = 0.f;
        image.pixel(x, y).r = 0.f;
    }
}
}

void black_and_white(sil::Image &image) {
    for (int x{0}; x < image.width(); x++)
{
    for (int y{0}; y < image.height(); y++)
    {
        float z = image.pixel(x, y).b * 0.114f + image.pixel(x, y).r * 0.299f + image.pixel(x, y).g * 0.587f;
       
        image.pixel(x, y).b = z;
        image.pixel(x, y).r = z;
        image.pixel(x, y).g = z;
    }
}
}

void swap_colors(sil::Image &image) {
    for (int x{0}; x < image.width(); x++)
{
    for (int y{0}; y < image.height(); y++)
    {
        std::swap(image.pixel(x, y).b, image.pixel(x, y).r);
    }
}
}

void mirror(sil::Image &image) {
    for (int x{0}; x < image.width() / 2; x++)
{
    for (int y{0}; y < image.height(); y++)
    {

        std::swap(image.pixel(x, y).r, image.pixel(image.width()-x-1, y).r);
        std::swap(image.pixel(x, y).b, image.pixel(image.width()-x-1, y).b);
        std::swap(image.pixel(x, y).g, image.pixel(image.width()-x-1, y).g);
        
    }
}
}

void invert_colors(sil::Image &image) {
    for (int x{0}; x < image.width(); x++)
{
    for (int y{0}; y < image.height(); y++)
    {
        float red = 1 - image.pixel(x, y).r;
        float green = 1 - image.pixel(x, y).g;
        float blue = 1 - image.pixel(x, y).b;

        image.pixel(x, y).r = red;
        image.pixel(x, y).g = green;
        image.pixel(x, y).b = blue;

    }
}
}

void brightness(sil::Image &image) {
    for (int x{0}; x < image.width(); x++)
{
    for (int y{0}; y < image.height(); y++)
    {
        float red = image.pixel(x, y).r;
        float green = image.pixel(x, y).g;
        float blue = image.pixel(x, y).b;

        image.pixel(x, y).r = powf(red, 0.5);
        image.pixel(x, y).g = powf(green, 0.5);
        image.pixel(x, y).b = powf(blue, 0.5);

    }
}
}

void lessbright(sil::Image &image) {
    for (int x{0}; x < image.width(); x++)
{
    for (int y{0}; y < image.height(); y++)
    {
        float red = image.pixel(x, y).r;
        float green = image.pixel(x, y).g;
        float blue = image.pixel(x, y).b;

        image.pixel(x, y).r = powf(red, 2);
        image.pixel(x, y).g = powf(green, 2);
        image.pixel(x, y).b = powf(blue, 2);

    }
}
}

void rgb_split(sil::Image &image) {
    sil::Image newImage(image.width(), image.height());
    for (int x{0}; x < image.width(); x++)
{
    for (int y{0}; y < image.height(); y++)
    {
        if (x + 30 < image.width()) {
            float red = image.pixel(x + 30, y).r;
            
            newImage.pixel(x, y).r = red;
        }
        float green = image.pixel(x , y).g;    
        newImage.pixel(x, y).g = green;

        if ((x - 30 > 0)) {
            float blue = image.pixel(x - 30, y).b;
            
            newImage.pixel(x, y).b = blue;
        }
    }
}
newImage.save("output/pouet.png");
}

void rotation(sil::Image &image) {
    sil::Image newImage(image.height(), image.width());
        for (int x{0}; x < newImage.width(); x++)
    {
        for (int y{0}; y < newImage.height(); y++)
        {
            newImage.pixel(x, y).r = image.pixel(y, x).r;
            newImage.pixel(x, y).g = image.pixel(y, x).g;
            newImage.pixel(x, y).b = image.pixel(y, x).b;


        }
}
newImage.save("output/pouet.png");
}

void noise(sil::Image &image) {
    for (int x{0}; x < image.width(); x++)
{
    for (int y{0}; y < image.height(); y++)
    {
        int randomizer = random_int(0,10);
        if (randomizer < 4) {
        image.pixel(x, y).r = random_float(0,1);
        image.pixel(x, y).g = random_float(0,1);
        image.pixel(x, y).b = random_float(0,1);
        }

    }
}
}

void gradient(sil::Image &image) {
    for (int x{0}; x < image.width(); x++)
{
    for (int y{0}; y < image.height(); y++)
    {
        image.pixel(x, y).r = x/300.;
        image.pixel(x, y).g = x/300.;
        image.pixel(x, y).b = x/300.;
    }
}
}

int main()
{
    sil::Image image{"images/logo.png"};
    // TODO: modifier l'image
    //sil::Image image{300/*width*/, 200/*height*/};
    brightness(image);
    image.save("output/pouet.png");
}




