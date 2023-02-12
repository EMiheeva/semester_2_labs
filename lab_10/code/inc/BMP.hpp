#pragma once
#include <string>
#include <fstream>
#include <mathutils/matrix.hpp>

using em::math::Vec2d;
using em::math::Mat22d;

namespace em::images
{

	#pragma pack(1)
	struct Pixel
	{
		unsigned char r;
		unsigned char g;
		unsigned char b;
	};
	#pragma pack()

	class BMP
	{
	public:
        BMP();
        BMP(int width, int height);
        BMP(const BMP& bmp);
        BMP& operator=(const BMP& bmp);
        ~BMP();
        void Fill(Pixel pixel);
        void SpecialEffect();
        void Open(const std::string& filename);
        void Save(const std::string& filename);
        void Rotate(double angle);
        void FindArtefact(); 
        bool ItsBlack(int x, int y); 

	private:
		int m_width, m_height;
		Pixel** m_pixels = nullptr;
        Vec2d** m_coordinates = nullptr;

    private:
        #pragma pack(1) 
        struct BMPHEADER
        {
            unsigned short    Type;
            unsigned int      Size;
            unsigned short    Reserved1;
            unsigned short    Reserved2;
            unsigned int      OffBits;
        };
        #pragma pack()

        #pragma pack(1)
        struct BMPINFO
        {
            unsigned int    Size;
            int             Width;
            int             Height;
            unsigned short  Planes;
            unsigned short  BitCount;
            unsigned int    Compression;
            unsigned int    SizeImage;
            int             XPelsPerMeter;
            int             YPelsPerMeter;
            unsigned int    ClrUsed;
            unsigned int    ClrImportant;
        };
        #pragma pack()
	};

}
