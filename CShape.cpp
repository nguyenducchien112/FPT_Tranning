#include<iostream>
#include"CShape.h"
using namespace std;

CCircle::CCircle(int circle_radius, int color) {
	this->radium = circle_radius;
	this->color = color;
}

void CCircle::draw(int a, int b, HDC c) {
	COLORREF colorr = RGB(color >> 16, (color & 0xff00) >> 8, color & 0xff);
	HPEN pen = CreatePen(PS_SOLID, 3, colorr);
	SelectObject(c, pen);
	Ellipse(c, a - radium, b - radium, a + radium, b + radium);
}

CLine::CLine(int length, int color) {
	this->length = length;
	this->color = color;
}

void CLine::draw(int a, int b, HDC c) {
	COLORREF colorr = RGB(color >> 16, (color & 0xff00) >> 8, color & 0xff);
	HPEN pen = CreatePen(PS_SOLID, 5, colorr);
	SelectObject(c, pen);
	MoveToEx(c, a, b, NULL);
	LineTo(c, a + length, b);
}

CRectangle::CRectangle()
{
	this->width = 0;
	this->heigh = 0;
}

CRectangle::CRectangle(int width, int heigh, int color) {
	this->width = width;
	this->heigh = heigh;
	this->color = color;
}

void CRectangle::draw(int a, int b, HDC c) {
	COLORREF colorr = RGB(color >> 16, (color & 0xff00) >> 8, color & 0xff);
	HPEN pen = CreatePen(PS_SOLID, 3, colorr);
	SelectObject(c, pen);
	Rectangle(c, a - width / 2, b - heigh / 2, a + width / 2, b + heigh / 2);
}

CSquare::CSquare(int size, int color) {
	this->width = size;
	this->heigh = size;
	this->color = color;
}

void CSquare::draw(int a, int b, HDC c) {
	COLORREF colorr = RGB(color >> 16, (color & 0xff00) >> 8, color & 0xff);
	HPEN pen = CreatePen(PS_SOLID, 3, colorr);
	SelectObject(c, pen);
	Rectangle(c, a - width / 2, b - heigh / 2, a + width / 2, b + heigh / 2);
}

int main() {
	CPicture C_Pic;
	C_Pic.picture[0] = new CLine(100, 0xff0000);
	C_Pic.picture[1] = new CCircle(10, 0x00ff00);
	C_Pic.picture[2] = new CRectangle(20, 10, 0x0000ff);
	C_Pic.picture[3] = new CSquare(20, 0xaabbcc);
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	int line = 70;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (j != i) {
				for (int k = 0; k < 4; k++) {
					if (k != j && k != i) {
						for (int l = 0; l < 4; l++) {
							if (l != k && l != j && l != i) {
								C_Pic.picture[i]->draw(100, line, device_context);
								C_Pic.picture[j]->draw(300, line, device_context);
								C_Pic.picture[k]->draw(500, line, device_context);
								C_Pic.picture[l]->draw(700, line, device_context);
								line += 50;
							}
						}
					}
				}
			}
		}
	}
	ReleaseDC(console_handle, device_context);
	return 0;
}