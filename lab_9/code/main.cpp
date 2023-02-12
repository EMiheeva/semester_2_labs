#include <BMP.hpp> 
#include <iostream>

int main()
{
    em::images::BMP pic_bmp(500, 500);
    pic_bmp.Open("in.bmp");
	pic_bmp.SpecialEffects();
    pic_bmp.Save("out.bmp");
    return 0;
}
