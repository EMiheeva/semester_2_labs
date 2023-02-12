#include <BMP.hpp>
#include <iostream>

int main()
{
    em::images::BMP pic_bmp(500, 500); 
    pic_bmp.Open("in.bmp");
    pic_bmp.Rotate((acos(-1))/2);
    pic_bmp.FindArtefact();//decision lab 10
    pic_bmp.Save("test.bmp");
    return 0;
}
