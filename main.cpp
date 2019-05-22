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

int main(int argc, char *argv[])
{


   Matrix filter = getGaussian(30, 30, 10.0);
    cout << "Loading image..." << endl;
    Image image = loadImage("/home/user/Data/Self/Blurr/Blurr/resources/2.png");
    cout << "Applying filter..." << endl;
    Image newImage = applyFilter(image, filter);
    cout << "Saving image..." << endl;
    saveImage(newImage, "/tmp/newImage3.png");
    cout << "Done!" << endl;
}
