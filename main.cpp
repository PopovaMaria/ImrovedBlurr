#include <QCoreApplication>
// Internal
#include "image.h"

#include <math.h>

#include <QDebug>
#include <vector>
#include <QSize>
#include "color_chooser.h"


#include "file.h"

using std::vector;

/*template<size_t size>
auto getNormalizeMatrix(const double& sigma = 1)
{
    std::array<std::array<double, size>, size> kernel;

    double mean = size / 2;
    double sum = 0.0;

    for (size_t x = 0; x < size; ++x)
    {
        for (size_t y = 0; y < size; ++y)
        {
            kernel[x][y] = exp( -0.5 * (pow((x-mean)/sigma, 2.0) + pow((y-mean)/sigma,2.0))) / (2 * M_PI * sigma * sigma);
            sum += kernel[x][y];
        }
    }

    for (size_t x = 0; x < size; ++x)
    {
        for (size_t y = 0; y < size; ++y)
        {
            kernel[x][y] /= sum;
        }
    }

    return kernel;
}
*/

int main(int argc, char *argv[])
{


   Matrix filter = getGaussian(30, 30, 10.0);
    //Matrix filter = Clarity(3,3);
    //Matrix filter = Erosion();
    cout << "Loading image..." << endl;
    Image image = loadImage("/home/user/Data/Self/Blurr/Blurr/resources/2.png");
    cout << "Applying filter..." << endl;
    Image newImage = applyFilter(image, filter);
    cout << "Saving image..." << endl;
    saveImage(newImage, "/tmp/newImage.png");
    cout << "Done!" << endl;
}
