#include<iostream>
#include<cstring>
typedef unsigned char u_char;
typedef unsigned long u_long;
typedef unsigned short u_short;
using namespace std;

struct b_FileHeader {
	u_char b_type[2];
	u_char b_size[2];
	u_char b_reverse_1[2];
	u_char b_reverse_2[2];
	u_char b_Offset[4];
};
struct RGB {
	u_char R;
	u_char G;
	u_char B;
};
struct b_FileInfor {
	u_long b_Size;
	u_long b_Width;
	u_long b_Heigth;
	u_short b_planes;
	u_short b_PerPixel;
	u_long b_Compression;
	u_long b_ImageSize;
	u_long b_XpixelsperMeter;
	u_long b_YpixelsperMeter;
};
bool bmp_reverves(const char* bmp_path, const char* bmp_path_reverse)
{
	FILE* read;
	b_FileHeader  FileHeader;
	b_FileInfor   FileInfor;
	u_char* ImageData;
	read = fopen(bmp_path, "rb");
	if (!read)
	{
		std::cout << "Is not Openfile" << std::endl;
		return false;
	}
	fread(&FileHeader, sizeof(b_FileHeader), 1, read);
	if (FileHeader.b_type[0] != 0x42 || FileHeader.b_type[1] != 0x4D)
	{
		std::cout << "Not is file.BMP" << std::endl;
		fclose(read);
		return false;
	}
	fread(&FileInfor, sizeof(b_FileInfor), 1, read);
	int Padding = (FileInfor.b_Width * 3) / 4;
	int SizeImage = FileInfor.b_Width * FileInfor.b_Heigth * 3 + Padding * FileInfor.b_Heigth;
	ImageData = new u_char[SizeImage];
	if (!ImageData)
	{
		delete[]ImageData;
		fclose(read);
		return false;
	}
	memset(ImageData, 0x00, sizeof(ImageData));
	fread(ImageData, SizeImage, 1, read);
	if (!ImageData)
	{
		fclose(read);
		return false;
	}
	fclose(read);
	read = fopen(bmp_path_reverse, "wb");
	if (!read)
	{
		std::cout << "Is Not Open File";
		return false;
	}
	fwrite(&FileHeader, sizeof(b_FileHeader), 1, read);
	fwrite(&FileInfor, sizeof(b_FileInfor), 1, read);
	RGB* new_RGB = new RGB[FileInfor.b_Heigth * FileInfor.b_Width];
	if (!new_RGB)
	{
		delete[]new_RGB;
		return false;
	}
	memset(new_RGB, 0x00, FileInfor.b_Heigth * FileInfor.b_Width);
	for (int y = FileInfor.b_Heigth - 1; y >= 0; y--)
	{
		for (int x = 0; x < FileInfor.b_Width; x++)
		{
			new_RGB[y * FileInfor.b_Width + x].R = *(ImageData++);
			new_RGB[y * FileInfor.b_Width + x].G = *(ImageData++);
			new_RGB[y * FileInfor.b_Width + x].B = *(ImageData++);
		}
		ImageData += Padding;
	}
	u_char* image_reverse = new u_char[SizeImage];
	if (!image_reverse)
	{
		delete[]image_reverse;
		return false;
	}
	memset(image_reverse, 0x00, SizeImage);
	u_char* temp = image_reverse;
	for (int y = 0; y < FileInfor.b_Heigth; y++)
	{
		for (int x = 0; x < FileInfor.b_Width; x++)
		{
			*(temp++) = new_RGB[y * FileInfor.b_Width + x].R;
			*(temp++) = new_RGB[y * FileInfor.b_Width + x].G;
			*(temp++) = new_RGB[y * FileInfor.b_Width + x].B;
		}
		for (int i = 0; i < Padding; i++)
		{
			*(temp) = 0;
		}
	}
	fwrite(image_reverse, SizeImage, 1, read);
	fclose(read);
	delete[]ImageData;
	delete[]new_RGB;
	delete[]image_reverse;
	return true;
}
int main()
{
	if (bmp_reverves("Image.bmp", "Create.bmp"))
	{
		std::cout << "creat is file";
	}
	return 0;
}
