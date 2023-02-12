#include <bmp.hpp>

namespace em::images
{

    BMP::BMP()
    {
        m_width = 0;
        m_height = 0;
    }

    BMP::BMP(int width, int height)
    {
        m_width = width;
        m_height = height;
        m_pixels = new Pixel * [m_height];
        for (int i = 0; i < m_height; i++)
            m_pixels[i] = new Pixel[m_width];


        for (int i = 0; i < m_height; i++)
            for (int j = 0; j < m_width; j++)
                m_pixels[i][j] = { 0,0,0 };
    }

    BMP::BMP(const BMP& bmp)
    {
        if (m_pixels != nullptr)
        {
            for (int i = 0; i < m_height; i++)
                delete[] m_pixels[i];
            delete[] m_pixels;
        }

        m_width = bmp.m_width;
        m_height = bmp.m_height;

        m_pixels = new Pixel * [m_height];
        for (int i = 0; i < m_height; i++)
            m_pixels[i] = new Pixel[m_width];

        for (int i = 0; i < m_height; i++)
            for (int j = 0; j < m_width; j++)
                m_pixels[i][j] = bmp.m_pixels[i][j];
    }

    BMP& BMP::operator=(const BMP& bmp)
    {
        if (m_pixels != nullptr)
        {
            for (int i = 0; i < m_height; i++)
                delete[] m_pixels[i];
            delete[] m_pixels;
        }

        m_width = bmp.m_width;
        m_height = bmp.m_height;

        m_pixels = new Pixel * [m_height];
        for (int i = 0; i < m_height; i++)
            m_pixels[i] = new Pixel[m_width];

        for (int i = 0; i < m_height; i++)
            for (int j = 0; j < m_width; j++)
                m_pixels[i][j] = bmp.m_pixels[i][j];

        return *this;
    }

    BMP::~BMP()
    {
        for (int i = 0; i < m_height; i++)
            delete[] m_pixels[i];
        delete[] m_pixels;
    }

    void BMP::Fill(Pixel pixel)
    {
        for (int i = 0; i < m_height; i++)
            for (int j = 0; j < m_width; j++)
                m_pixels[i][j] = pixel;
    }

    void BMP::SpecialEffects()
    {
        for (int i = 0; i < m_height; i++)
            for (int j = 0; j < m_width; j++)
            {
				int m = (m_pixels[i][j].r + m_pixels[i][j].b) / 2;
                m_pixels[i][j].r = m;
                m_pixels[i][j].g = 162;
                m_pixels[i][j].b = m;
            }
    }

    void BMP::Open(const std::string& filename)
    {
        // Reading a file
        std::ifstream in(filename, std::ios::binary); // open the file for binary reading
        if (!in) {
            std::cout << "Please, add a picture in file with project(Not CMake)" << std::endl;
        }
        else {
            BMPHEADER bmpHeader;
            // Read 14 bytes byte by byte and fill in the BMPHEADER structure
            in.read(reinterpret_cast<char*>(&bmpHeader), sizeof(BMPHEADER));

            BMPINFO bmpInfo;
            in.read(reinterpret_cast<char*>(&bmpInfo), sizeof(BMPINFO));

            if (m_pixels != nullptr)
            {
                for (int i = 0; i < m_height; i++)
                    delete[] m_pixels[i];
                delete[] m_pixels;
            }

            m_width = bmpInfo.Width;
            m_height = bmpInfo.Height;

            m_pixels = new Pixel * [m_height];
            for (int i = 0; i < m_height; i++)
                m_pixels[i] = new Pixel[m_width];

            for (int i = 0; i < bmpInfo.Height; i++)
            {
                for (int j = 0; j < bmpInfo.Width; j++)
                    in.read(reinterpret_cast<char*>(&m_pixels[i][j]), sizeof(Pixel));

                if ((3 * bmpInfo.Width) % 4 != 0)
                    for (int j = 0; j < 4 - (3 * bmpInfo.Width) % 4; j++)
                    {
                        char c;
                        in.read(&c, 1);
                    }
            }
        std::cout<< "The program is working correctly. Please, cheak your file!" << std::endl;
        }
    }

    void BMP::Save(const std::string& filename)
    {
        if (m_width == 0 || m_height == 0)
            throw std::exception("Zero height or width");

        // Write File
        std::ofstream out(filename, std::ios::binary);

        // Header Formation
        BMPHEADER bmpHeader_new;
        bmpHeader_new.Type = 0x4D42; // Data type: .bmp
        bmpHeader_new.Size = 14 + 40 + (3 * m_width * m_height);
        if (m_width % 4 != 0)
            bmpHeader_new.Size += (4 - (3 * m_width) % 4) * m_height;
        bmpHeader_new.OffBits = 54;
        bmpHeader_new.Reserved1 = 0;
        bmpHeader_new.Reserved2 = 0;

        out.write(reinterpret_cast<char*>(&bmpHeader_new), sizeof(BMPHEADER));

        // Formation of information about the image
        BMPINFO bmpInfo_new;
        bmpInfo_new.BitCount = 24;
        bmpInfo_new.ClrImportant = 0;
        bmpInfo_new.ClrUsed = 0;
        bmpInfo_new.Compression = 0;
        bmpInfo_new.Height = m_height;
        bmpInfo_new.Planes = 1;
        bmpInfo_new.Size = 40;
        bmpInfo_new.SizeImage = bmpHeader_new.Size - 54;
        bmpInfo_new.Width = m_width;
        bmpInfo_new.XPelsPerMeter = 0;
        bmpInfo_new.YPelsPerMeter = 0;

        out.write(reinterpret_cast<char*>(&bmpInfo_new), sizeof(BMPINFO));

        // Record Pixels
        for (int i = 0; i < bmpInfo_new.Height; i++)
        {
            for (int j = 0; j < bmpInfo_new.Width; j++)
                out.write(reinterpret_cast<char*>(&m_pixels[i][j]), sizeof(Pixel));

            if ((3 * bmpInfo_new.Width) % 4 != 0)
                for (int j = 0; j < 4 - (3 * bmpInfo_new.Width) % 4; j++)
                {
                    char c = 0;
                    out.write(&c, 1);
                }
        }
    }
}

